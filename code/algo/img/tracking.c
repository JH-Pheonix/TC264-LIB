#include "tracking.h"
#include "lcd.h"

int16_t abs_threshold = 50;

static tracking_result_t tracking_result;

void tracking_init(void)
{
    tracking_result.left_found = 0;
    tracking_result.right_found = 0;
    tracking_result.left_edge = 0;
    tracking_result.right_edge = CCD_PIXEL_NUM - 1;
    tracking_result.center_line = MIDDLE_POSITION;
    tracking_result.deviation = 0;
    tracking_result.current_line_width = EXPECTED_LINE_WIDTH; // 初始化线宽
}

void binarize_array(uint16_t *input_data, uint8_t *output_data, uint16_t data_len, uint8_t threshold)
{
    for (uint16_t i = 0; i < data_len; i++)
    {
        output_data[i] = (input_data[i] > threshold) ? 1 : 0;
    }
}

uint8_t binary_ostu(uint16_t *data, uint16_t data_len)
{
    uint32_t histogram[256] = {0};
    uint32_t total_pixels = data_len;

    for (uint16_t i = 0; i < data_len; i++)
    {
        // 确保数据在0-255范围内
        uint8_t pixel_value = (data[i] > 255) ? 255 : (uint8_t)data[i];
        histogram[pixel_value]++;
    }

    uint32_t sum_total = 0;
    for (int i = 0; i < 256; i++)
    {
        sum_total += i * histogram[i];
    }

    uint32_t w0 = 0;   // 背景像素数
    uint32_t sum0 = 0; // 背景像素值总和
    float max_variance = 0.0;
    uint8_t best_threshold = 0;

    for (int t = 0; t < 256; t++)
    {
        w0 += histogram[t];
        if (w0 == 0)
            continue;

        uint32_t w1 = total_pixels - w0;
        if (w1 == 0)
            break;

        sum0 += t * histogram[t];
        float mu0 = (float)sum0 / w0;               // 背景平均灰度
        float mu1 = (float)(sum_total - sum0) / w1; // 前景平均灰度

        // 计算类间方差
        float variance = (float)w0 * w1 * (mu0 - mu1) * (mu0 - mu1);

        // 更新最大方差和最佳阈值
        if (variance > max_variance)
        {
            max_variance = variance;
            best_threshold = t;
        }
    }

    return best_threshold;
}

int16_t find_widest_line_center(uint8_t *binary_data, uint16_t data_len)
{
    uint16_t max_width = 0;
    uint16_t max_start = 0;
    uint16_t current_start = 0;
    uint16_t current_width = 0;
    uint8_t in_line = 0;

    for (uint16_t i = 0; i < data_len; i++)
    {
        if (binary_data[i] == 1) // 白线
        {
            if (!in_line) // 开始新的白线
            {
                current_start = i;
                current_width = 1;
                in_line = 1;
            }
            else
            {
                current_width++;
            }
        }
        else // 黑线
        {
            if (in_line) // 白线结束
            {
                if (current_width > max_width)
                {
                    max_width = current_width;
                    max_start = current_start;
                }
                in_line = 0;
            }
        }
    }

    // 处理末尾还在白线中的情况
    if (in_line && current_width > max_width)
    {
        max_width = current_width;
        max_start = current_start;
    }

    if (max_width > 0)
    {
        return max_start + max_width / 2; // 返回中心位置
    }

    return -1; // 没找到白线
}