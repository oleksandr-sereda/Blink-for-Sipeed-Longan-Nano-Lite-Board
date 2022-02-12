#include "gd32vf103.h"
#include "led.h"

#define RED 0
#define GREEN 1
#define BLUE 2

/*
    Wait for specified time ms 
*/
void wait_ms(uint64_t time_ms);

/*
    Infinite loop 
*/
int main(void)
{
    led_initialize();

    uint8_t color = 0;
    while (1)
    {
        led_off();

        switch (color)
        {
        case RED:
            led_red_on();
            color++;
            break;
        case GREEN:
            led_green_on();
            color++;
            break;
        case BLUE:
            led_blue_on();
            color++;
            break;
        default:
            color = 0;
            break;
        }

        wait_ms(1000);
    }
}

void wait_ms(uint64_t time_ms)
{
    uint64_t end_time = get_timer_value() + (SystemCoreClock / 4000.0 * time_ms);

    uint64_t current;
    do
    {
        current = get_timer_value();
    } while (end_time >= current);
}
