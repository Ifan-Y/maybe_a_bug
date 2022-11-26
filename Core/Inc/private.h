//
// Created by IfanY on 2022/11/20.
//

#ifndef FIRMWARE_PRIVATE_H
#define FIRMWARE_PRIVATE_H

#include "stm32f1xx_hal.h"
#include "i2c.h"
#include "spi.h"
#include "usb_device.h"
#include "gpio.h"

void private_main(void);
uint16_t get_temp_humidity(void);

#endif //FIRMWARE_PRIVATE_H
