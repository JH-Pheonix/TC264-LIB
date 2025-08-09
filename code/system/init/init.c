#include "init.h"
#include "menu.h"
#include "key.h"
#include "ccd.h"

void system_init(void)
{
    ccd_init(0);
    lcd_init();
    // tracking_init();
    key_init_rewrite(KEY_NUM);
    Read_EEPROM();

    pit_ms_init(CCU60_CH1, 5);

    MainMenu_Set();

    pit_ms_init(CCU60_CH0, exp_time);

    Write_EEPROM();
}
