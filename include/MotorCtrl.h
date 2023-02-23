#include "driver/gpio.h"
#if !defined(MotorCtrl_H)
#define MotorCtrl_H

typedef struct MotorConfig
{
    gpio_num_t pin_m11;
    gpio_num_t pin_e1;
    gpio_num_t pin_m12;
    gpio_num_t pin_m22;
    gpio_num_t pin_m21;
    gpio_num_t pin_e2;
} motor_config_t;

class MotorController
{
public:
    enum direction
    {
        FORWARD,
        BACKWARD,
        LEFTWARD,
        RIGHTWARD
    };

    void ctrlInit(motor_config_t config);
    void setDirection(direction direct);

private:
    gpio_num_t e1;
    gpio_num_t e2;
    gpio_num_t m11;
    gpio_num_t m12;
    gpio_num_t m21;
    gpio_num_t m22;
};

#endif // MotorCtrl_H
