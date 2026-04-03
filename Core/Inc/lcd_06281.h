#ifndef LCD_06281_H
#define LCD_06281_H


#include <stdint.h>
#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "stm32l4xx_hal_gpio.h"
#include <stdio.h>

#define SEG1_A_Pin GPIO_PIN_0
#define SEG1_A_GPIO_Port GPIOB
#define SEG1_B_Pin GPIO_PIN_1
#define SEG1_B_GPIO_Port GPIOB
#define SEG1_C_Pin GPIO_PIN_2
#define SEG1_C_GPIO_Port GPIOB
#define SEG1_D_Pin GPIO_PIN_10
#define SEG1_D_GPIO_Port GPIOB
#define SEG1_E_Pin GPIO_PIN_11
#define SEG1_E_GPIO_Port GPIOB
#define SEG1_F_Pin GPIO_PIN_12
#define SEG1_F_GPIO_Port GPIOB
#define SEG1_G_Pin GPIO_PIN_13
#define SEG1_G_GPIO_Port GPIOB
#define SEG1_K_Pin GPIO_PIN_14
#define SEG1_K_GPIO_Port GPIOB


#define SEG2_A_Pin GPIO_PIN_0
#define SEG2_A_GPIO_Port GPIOC
#define SEG2_B_Pin GPIO_PIN_1
#define SEG2_B_GPIO_Port GPIOC
#define SEG2_C_Pin GPIO_PIN_2
#define SEG2_C_GPIO_Port GPIOC
#define SEG2_D_Pin GPIO_PIN_3
#define SEG2_D_GPIO_Port GPIOC
#define SEG2_E_Pin GPIO_PIN_6
#define SEG2_E_GPIO_Port GPIOC
#define SEG2_F_Pin GPIO_PIN_7
#define SEG2_F_GPIO_Port GPIOC
#define SEG2_G_Pin GPIO_PIN_8
#define SEG2_G_GPIO_Port GPIOC
#define SEG2_K_Pin GPIO_PIN_9
#define SEG2_K_GPIO_Port GPIOC


typedef enum {
    LCD_SEG_A = 0,
    LCD_SEG_B,
    LCD_SEG_C,
    LCD_SEG_D,
    LCD_SEG_E,
    LCD_SEG_F,
    LCD_SEG_G,
    LCD_SEG_K
} LCD_Segment_t;

typedef struct{
    GPIO_TypeDef* port;
    uint16_t pin;
}LCD_GPIO_t;

typedef struct{
    uint8_t data;
    LCD_GPIO_t segment[8];
}LCD_t;


extern void LCD_write(LCD_t *lcd, uint8_t value);
extern void LCD_double_write(LCD_t *lcd1, LCD_t *lcd2, uint8_t value);
extern void LCD_blink(LCD_t *lcd, LCD_t *lcd2, uint16_t time);
extern void LCD_init(LCD_t *lcd);
extern void LCD_init2(LCD_t *lcd);
//static void LCD_GPIO_init(void);










#endif /* LCD_06281_H */