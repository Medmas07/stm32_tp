#include <gpio.h>



uint8_t GPIO_TestPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN)
{
    return ( (GPIOx->IDR & GPIO_PIN) ? 1 : 0 );
}

void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN)
{
    GPIOx->BSRR = GPIO_PIN;
}

void GPIO_ResetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN)
{
    GPIOx->BRR = GPIO_PIN;
}

void GPIO_Config(GPIO_Typedef* GPIOx, GPIO_Struct *cfg)
{
    uint8_t pin = 0;

    while (!(cfg->GPIO_PIN & (1 << pin))) pin++;

    if (pin < 8)
    {
        GPIOx->CRL &= ~(0xF << (pin * 4));
        GPIOx->CRL |=  (cfg->GPIO_Mode << (pin * 4));
    }
    else
    {
        pin -= 8;
        GPIOx->CRH &= ~(0xF << (pin * 4));
        GPIOx->CRH |=  (cfg->GPIO_Mode << (pin * 4));
    }
}
