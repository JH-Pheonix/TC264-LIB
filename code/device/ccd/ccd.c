#include "ccd.h"

uint8 exp_time = 5;

void ccd_init(uint8 index)
{
    tsl1401_init(index);
}

void ccd_collect_pit_callback(void)
{
    tsl1401_collect_pit_handler();
}

ccd_data_t ccd_get_data(uint8 index)
{
    ccd_data_t data;
    if (index < 2)
    {
        memcpy(data.data, tsl1401_data[index], sizeof(data.data));
    }
    return data;
}

void ccd_send_data(uart_index_enum uart_n, uint8 index)
{
    if (index < 2)
    {
        tsl1401_send_data(uart_n, index);
    }
}