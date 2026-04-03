#include "lcd_06281.h"
#include <stdint.h>



static void LCD_GPIO_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();


  HAL_GPIO_WritePin(GPIOC, SEG2_A_Pin|SEG2_B_Pin|SEG2_C_Pin|SEG2_D_Pin
                          |SEG2_E_Pin|SEG2_F_Pin|SEG2_G_Pin|SEG2_K_Pin, GPIO_PIN_RESET);



  HAL_GPIO_WritePin(GPIOB, SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG1_K_Pin, GPIO_PIN_RESET);



  GPIO_InitStruct.Pin = SEG2_A_Pin|SEG2_B_Pin|SEG2_C_Pin|SEG2_D_Pin
                          |SEG2_E_Pin|SEG2_F_Pin|SEG2_G_Pin|SEG2_K_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


  GPIO_InitStruct.Pin = SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG1_K_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}


void LCD_init(LCD_t *lcd)
{
    LCD_GPIO_init();

    lcd->segment[LCD_SEG_A].port = SEG1_A_GPIO_Port;
    lcd->segment[LCD_SEG_A].pin = SEG1_A_Pin;

    lcd->segment[LCD_SEG_B].port = SEG1_B_GPIO_Port;
    lcd->segment[LCD_SEG_B].pin = SEG1_B_Pin;

    lcd->segment[LCD_SEG_C].port = SEG1_C_GPIO_Port;
    lcd->segment[LCD_SEG_C].pin = SEG1_C_Pin;

    lcd->segment[LCD_SEG_D].port = SEG1_D_GPIO_Port;
    lcd->segment[LCD_SEG_D].pin = SEG1_D_Pin;

    lcd->segment[LCD_SEG_E].port = SEG1_E_GPIO_Port;
    lcd->segment[LCD_SEG_E].pin = SEG1_E_Pin;

    lcd->segment[LCD_SEG_F].port = SEG1_F_GPIO_Port;
    lcd->segment[LCD_SEG_F].pin = SEG1_F_Pin;

    lcd->segment[LCD_SEG_G].port = SEG1_G_GPIO_Port;
    lcd->segment[LCD_SEG_G].pin = SEG1_G_Pin;

    lcd->segment[LCD_SEG_K].port = SEG1_K_GPIO_Port;
    lcd->segment[LCD_SEG_K].pin = SEG1_K_Pin;
}




void LCD_init2(LCD_t *lcd)
{
    lcd->segment[LCD_SEG_A].port = SEG2_A_GPIO_Port;
    lcd->segment[LCD_SEG_A].pin = SEG2_A_Pin;

    lcd->segment[LCD_SEG_B].port = SEG2_B_GPIO_Port;
    lcd->segment[LCD_SEG_B].pin = SEG2_B_Pin;

    lcd->segment[LCD_SEG_C].port = SEG2_C_GPIO_Port;
    lcd->segment[LCD_SEG_C].pin = SEG2_C_Pin;

    lcd->segment[LCD_SEG_D].port = SEG2_D_GPIO_Port;
    lcd->segment[LCD_SEG_D].pin = SEG2_D_Pin;

    lcd->segment[LCD_SEG_E].port = SEG2_E_GPIO_Port;
    lcd->segment[LCD_SEG_E].pin = SEG2_E_Pin;

    lcd->segment[LCD_SEG_F].port = SEG2_F_GPIO_Port;
    lcd->segment[LCD_SEG_F].pin = SEG2_F_Pin;

    lcd->segment[LCD_SEG_G].port = SEG2_G_GPIO_Port;
    lcd->segment[LCD_SEG_G].pin = SEG2_G_Pin;

    lcd->segment[LCD_SEG_K].port = SEG2_K_GPIO_Port;
    lcd->segment[LCD_SEG_K].pin = SEG2_K_Pin;
}




void LCD_write(LCD_t *lcd, uint8_t value)
{
    lcd->data = value;

    switch (value) {
    case 0:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_RESET);

        break;
    case 1:
         HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_RESET);
        break;
    case 2:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 3:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 4:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 5:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 6:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 7:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_RESET);
        break;
    case 8:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    case 9:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
        break;
    default:
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_A].port, lcd->segment[LCD_SEG_A].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_B].port, lcd->segment[LCD_SEG_B].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_C].port, lcd->segment[LCD_SEG_C].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_D].port, lcd->segment[LCD_SEG_D].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_E].port, lcd->segment[LCD_SEG_E].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_F].port, lcd->segment[LCD_SEG_F].pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(lcd->segment[LCD_SEG_G].port, lcd->segment[LCD_SEG_G].pin, GPIO_PIN_SET);
    }
}



void LCD_blink(LCD_t *lcd, LCD_t *lcd2, uint16_t time)
{
    if(lcd != (LCD_t *)NULL)
    {
        HAL_GPIO_TogglePin(lcd->segment[LCD_SEG_K].port, lcd->segment[LCD_SEG_K].pin);
    }
    if (lcd2 != (LCD_t *) NULL) 
    {
        HAL_GPIO_TogglePin(lcd2->segment[LCD_SEG_K].port, lcd2->segment[LCD_SEG_K].pin);
    }

    HAL_Delay(time);

    if(lcd != (LCD_t *) NULL)
    {
        HAL_GPIO_TogglePin(lcd->segment[LCD_SEG_K].port, lcd->segment[LCD_SEG_K].pin);
    }
    if (lcd2 != (LCD_t *) NULL) 
    {
        HAL_GPIO_TogglePin(lcd2->segment[LCD_SEG_K].port, lcd2->segment[LCD_SEG_K].pin);
    }
}

void LCD_double_write(LCD_t *lcd1, LCD_t *lcd2, uint8_t value)
{
    LCD_write(lcd1, (uint8_t)((value - value%10)/10));
    LCD_write(lcd2, (uint8_t)(value%10));
}
