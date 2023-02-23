#include "MotorCtrl.h"

void MotorController::ctrlInit(motor_config_t config)
{
    this->e1 = config.pin_e1;
    this->e2 = config.pin_e2;
    this->m11 = config.pin_m11;
    this->m12 = config.pin_m12;
    this->m21 = config.pin_m21;
    this->m22 = config.pin_m22;

    gpio_set_direction(config.pin_m11, GPIO_MODE_OUTPUT);
    gpio_set_direction(config.pin_m12, GPIO_MODE_OUTPUT);
    gpio_set_direction(config.pin_m21, GPIO_MODE_OUTPUT);
    gpio_set_direction(config.pin_m22, GPIO_MODE_OUTPUT);

    gpio_set_level(this->e1, 1);
    gpio_set_level(this->e2, 1);
}

void MotorController::setDirection(direction direct)
{
    switch (direct)
    {
    case FORWARD:
        gpio_set_level(this->m11, 0);
        gpio_set_level(this->m12, 1);
        gpio_set_level(this->m22, 1);
        gpio_set_level(this->m21, 0);
        break;
    case BACKWARD:
        gpio_set_level(this->m11, 1);
        gpio_set_level(this->m12, 0);
        gpio_set_level(this->m22, 0);
        gpio_set_level(this->m21, 1);
        break;
    case LEFTWARD:
        gpio_set_level(this->m11, 0);
        gpio_set_level(this->m12, 1);
        gpio_set_level(this->m22, 0);
        gpio_set_level(this->m21, 1);
        break;
    case RIGHTWARD:
        gpio_set_level(this->m11, 1);
        gpio_set_level(this->m12, 0);
        gpio_set_level(this->m22, 1);
        gpio_set_level(this->m21, 0);
        break;
    }
}