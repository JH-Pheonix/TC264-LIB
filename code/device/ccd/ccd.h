#ifndef _DEVICE_CCD_H_
#define _DEVICE_CCD_H_

#include "zf_common_headfile.h"

typedef struct
{
    uint16 data[128]; // 存储两路 TSL1401 数据
} ccd_data_t;

void ccd_init(uint8 index);
void ccd_collect_pit_callback(void);
ccd_data_t ccd_get_data(uint8 index);
void ccd_send_data(uart_index_enum uart_n, uint8 index);

extern uint8 exp_time;

#endif //_DEVICE_CCD_H_
