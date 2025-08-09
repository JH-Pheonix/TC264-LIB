#include "test.h"
#include "lcd.h"
#include "key.h"
#include "tracking.h"
#include "ccd.h"

void test_ccd_abs()
{
    lcd_clear(); // 清屏
    pit_ms_init(CCU60_CH0, exp_time);
    while (keymsg.key != KEY_L)
    {
        lcd_clear();
        lcd_show_wave(0, 1, tsl1401_data[0], 128, 256, 19, 3);
        lcd_show_uint(5, 0, abs_threshold, 3);
        uint8_t binary_data[128];
        binarize_array(tsl1401_data[0], binary_data, 128, abs_threshold);
        // lcd_show_wave(0, 5, binary_data, 128, 1, 19, 2);

        // 遍历找边界并画线
        for (uint16_t i = 1; i < 128; i++)
        {
            // 左边界：黑到白
            if (binary_data[i - 1] == 0 && binary_data[i] == 1)
            {
                uint16_t mapped_edge = i * 19 / 128;
                tft180_draw_line(mapped_edge, 1, mapped_edge, tft180_height_max - 1, RGB565_GREEN);
            }
            // 右边界：白到黑
            if (binary_data[i - 1] == 1 && binary_data[i] == 0)
            {
                uint16_t mapped_edge = (i - 1) * 19 / 128;
                tft180_draw_line(mapped_edge, 1, mapped_edge, tft180_height_max - 1, RGB565_RED);
            }
        }
    }
}

void test_ccd_ostu()
{
    lcd_clear(); // 清屏
    pit_ms_init(CCU60_CH0, exp_time);
    while (keymsg.key != KEY_L)
    {
        lcd_clear();
        lcd_show_wave(0, 1, tsl1401_data[0], 128, 256, 19, 3);
        uint8_t threshold = binary_ostu(tsl1401_data[0], 128);
        lcd_show_uint(5, 0, threshold, 3);
        uint8_t binary_data[128];
        binarize_array(tsl1401_data[0], binary_data, 128, threshold);
        // lcd_show_wave(0, 5, binary_data, 128, 1, 19, 2);

        // 遍历找边界并画线
        for (uint16_t i = 1; i < 128; i++)
        {
            // 左边界：黑到白
            if (binary_data[i - 1] == 0 && binary_data[i] == 1)
            {
                uint16_t mapped_edge = i * 19 / 128;
                tft180_draw_line(mapped_edge, 1, mapped_edge, tft180_height_max - 1, RGB565_GREEN);
            }
            // 右边界：白到黑
            if (binary_data[i - 1] == 1 && binary_data[i] == 0)
            {
                uint16_t mapped_edge = (i - 1) * 19 / 128;
                tft180_draw_line(mapped_edge, 1, mapped_edge, tft180_height_max - 1, RGB565_RED);
            }
        }
    }
}

void test_tracking_abs()
{
    lcd_clear(); // 清屏
    pit_ms_init(CCU60_CH0, exp_time);
    while (keymsg.key != KEY_L)
    {
        lcd_clear();
        lcd_show_wave(0, 1, tsl1401_data[0], 128, 256, 19, 3);
        lcd_show_uint(5, 0, abs_threshold, 3);
        uint8_t binary_data[128];
        binarize_array(tsl1401_data[0], binary_data, 128, abs_threshold);
        // lcd_show_wave(0, 5, binary_data, 128, 1, 19, 2);

        int16_t center = find_widest_line_center(binary_data, 128);
        if (center >= 0)
        {
            uint16_t mapped_center = (center * tft180_width_max / 128) - 1;
            tft180_draw_line(mapped_center, 1, mapped_center, tft180_height_max - 1, RGB565_RED);
        }
    }
}

void test_tracking_ostu()
{
    lcd_clear(); // 清屏
    pit_ms_init(CCU60_CH0, exp_time);
    while (keymsg.key != KEY_L)
    {
        lcd_clear();
        lcd_show_wave(0, 1, tsl1401_data[0], 128, 256, 19, 3);
        uint8_t threshold = binary_ostu(tsl1401_data[0], 128);
        lcd_show_uint(5, 0, threshold, 3);
        uint8_t binary_data[128];
        binarize_array(tsl1401_data[0], binary_data, 128, threshold);
        // lcd_show_wave(0, 5, binary_data, 128, 1, 19, 2);

        int16_t center = find_widest_line_center(binary_data, 128);
        if (center >= 0)
        {
            uint16_t mapped_center = (center * tft180_width_max / 128) - 1;
            tft180_draw_line(mapped_center, 1, mapped_center, tft180_height_max - 1, RGB565_RED);
        }
    }
}

void test_ccd(void)
{
    lcd_clear(); // 清屏
    pit_ms_init(CCU60_CH0, exp_time);
    while (keymsg.key != KEY_L)
    {
        lcd_show_wave(0, 1, tsl1401_data[0], 128, 256, 19, 3);
    }
}