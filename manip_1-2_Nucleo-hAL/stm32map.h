#include <stdint.h>

#define __IO volatile

//GPIO BASE ADDRESSES REGISTERS
#define   GPIOA_BASE	  (0x40010800)
#define   GPIOB_BASE	  (0x40010C00)
#define   GPIOC_BASE	  (0x40011000)


//Define GPIO_Typedef strcuture containing The GPIO Registers

typedef struct{
	__IO uint32_t CRL;
	__IO uint32_t CRH;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t BRR;
	__IO uint32_t LCKR;
	

}GPIO_Typedef;


//define Pointers to GPIO Strcutures 
	
#define GPIOA  ((GPIO_Typedef*)GPIOA_BASE)
#define GPIOB  ((GPIO_Typedef*)GPIOB_BASE)
#define GPIOC  ((GPIO_Typedef*)GPIOC_BASE)
