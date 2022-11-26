//
// Created by IfanY on 2022/11/20.
//

#include "private.h"

void private_main(void)
{
    for (;;)
    {
        uint16_t t_and_h = get_temp_humidity();
        HAL_Delay(100);
    }
}

uint16_t get_temp_humidity(void)
{
    uint8_t buf[6];
    uint16_t humidity_s;
    uint16_t temp_s;
    uint8_t humidity;
    uint8_t temp;
    HAL_I2C_Mem_Read(&hi2c2, 0x44 << 1, 0x2c06, I2C_MEMADD_SIZE_16BIT, buf, 6, 1000);

    temp_s = (buf[0] << 8) + buf[1];
    humidity_s = (buf[3] << 8) + buf[4];

    temp = 175 * temp_s / 65535 - 45;
    humidity = 100 * humidity_s / 65535;
    uint16_t all = (temp << 8) + humidity;
    return all;
}
