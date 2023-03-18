#include <mega8.h>
#include <delay.h> #include
<mylcd.h>
int a[10]={0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F}; initialization
int counter;
void main(){
PORTC=0B00000000;
DDRC=0B00000111;
PORTD=0B10000000;
DDRD=0B00000000;
PORTD=0X00;
DDRD=0X7F;
PORTD=a[0];
lcd_init();
lcd_xy(0,1);
lcd_s("LIFE IS TOO SHO");
lcd_xy(1,0);
lcd_s("RT FOR TRAFFIC");
delay_ms(500);
lcd_cmd(0x01) ;
lcd_xy(0,2);
lcd_s("YOU CAN GO:");
while(1){
if((PIND.7==0)&& (counter<8)){
PORTC.2=1; delay_ms(400);
counter=counter+1 ;
}
PORTD=a[counter];
if(counter==8){
PORTC.0=1;
PORTC.2=0;
lcd_xy(0,2);
lcd_s("PLEASE STOP:"); }
}
