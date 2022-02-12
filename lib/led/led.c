#include <stdint.h>

#include "led.h"
#include "gd32vf103.h"


#define LED_GPIO_RED GPIOC
#define LED_GPIO_GREEN GPIOA
#define LED_GPIO_BLUE GPIOA

#define LED_PIN_RED GPIO_PIN_13
#define LED_PIN_GREEN GPIO_PIN_1
#define LED_PIN_BLUE GPIO_PIN_2

void led_initialize()
{
    RCU_REG_VAL(RCU_GPIOA) |= BIT(RCU_BIT_POS(RCU_GPIOA));
    RCU_REG_VAL(RCU_GPIOC) |= BIT(RCU_BIT_POS(RCU_GPIOC));

    gpio_init(LED_GPIO_RED, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_PIN_RED);
    gpio_init(LED_GPIO_GREEN, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_PIN_GREEN);
    gpio_init(LED_GPIO_BLUE, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_PIN_BLUE);

    led_off();
}

void led_off()
{
    led_red_off();
    led_green_off();
    led_blue_off();
}

inline void led_red_on()
{
    GPIO_BC(LED_GPIO_RED) = LED_PIN_RED;
}

inline void led_red_off()
{
    GPIO_BOP(LED_GPIO_RED) = LED_PIN_RED;
}

inline void led_green_on()
{
    GPIO_BC(LED_GPIO_GREEN) = LED_PIN_GREEN;
}

inline void led_green_off()
{
    GPIO_BOP(LED_GPIO_GREEN) = LED_PIN_GREEN;
}

inline void led_blue_on()
{
    GPIO_BC(LED_GPIO_BLUE) = LED_PIN_BLUE;
}

inline void led_blue_off()
{
    GPIO_BOP(LED_GPIO_BLUE) = LED_PIN_BLUE;
}