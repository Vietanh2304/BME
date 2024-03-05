#include <Arduino.h>
#include "display_app.h"

LiquidCrystal_I2C lcd(0x27,16,2); 

void display_init(){
    lcd.init();      
    lcd.backlight();

    for(int i=0; i<3; i++)
    {   
        lcd.clear(); 
        lcd.setCursor(7,0);
        lcd.print("x");
        delay(150);
        lcd.clear(); 
        lcd.setCursor(8,0);
        lcd.print("x");
        delay(150);
        lcd.clear(); 
        lcd.setCursor(8,1);
        lcd.print("x");
        delay(150);
        lcd.clear(); 
        lcd.setCursor(7,1);
        lcd.print("x");   
        delay(150);
    }
}

void display_clear(){
    lcd.clear();
    lcd.setCursor(0,0);
}

void display_clear_rect(int x1, int y1, int x2, int y2){
    for(int i=x1; i<=x2; i++)
    for(int j=y1; j<=y2; j++){
        lcd.setCursor(i,j);
        lcd.print(" ");
    }
}

void display_num(int x, int y, int num){
    lcd.setCursor(x,y);
    lcd.print(num);
}

void display_text(int x, int y, String text){
    lcd.setCursor(x,y);
    lcd.print(text);
}