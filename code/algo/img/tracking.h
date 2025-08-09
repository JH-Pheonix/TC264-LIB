#ifndef _ALGO_TRACKING_H_
#define _ALGO_TRACKING_H_

#include "zf_common_headfile.h"

#define CCD_PIXEL_NUM 128  // CCD像素数量
#define THRESHOLD 50       // 二值化阈值
#define EDGE_THRESHOLD 50  // 边缘检测阈值
#define MIDDLE_POSITION 64 // 中心位置

#define EXPECTED_LINE_WIDTH 40 // 预期白线宽度（像素）
#define MIN_LINE_WIDTH 20      // 最小白线宽度
#define MAX_LINE_WIDTH 80      // 最大白线宽度
#define WIDTH_FILTER_FACTOR 7  // 宽度滤波系数（越大越平滑）

typedef struct
{
    uint8_t left_found;         // 是否找到左边界
    uint8_t right_found;        // 是否找到右边界
    uint8_t left_edge;          // 左边界位置
    uint8_t right_edge;         // 右边界位置
    uint8_t current_line_width; // 当前线宽
    uint8_t center_line;        // 中线位置
    int16_t deviation;
} tracking_result_t;

void tracking_init(void);
tracking_result_t tracking_process(uint16_t *ccd_data);

uint8_t binary_ostu(uint16_t *data, uint16_t data_len);
void binarize_array(uint16_t *input_data, uint8_t *output_data, uint16_t data_len, uint8_t threshold);
void binary_process(uint16_t *ccd_data);
int16_t find_widest_line_center(uint8_t *binary_data, uint16_t data_len);

extern int16_t abs_threshold;

#endif