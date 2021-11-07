void main() {
   int x;
   ANSELA = 0xFF;
   ANSELD = 0;
   ANSELC = 0;

   TRISA = 0xFf;
   TRISD = 0;
   UART1_Init(9600);
   Delay_ms(100);

   while(1)
   {
   x = ADC_Read(1);

   if(x > 1500)
   {
   PORTD = 0xff;
   Delay_ms(1000);
   UART1_Write_Text(" light is present ");
   }
   else
   {
   PORTD = 0x00;
   Delay_ms(1000);
   UART1_Write_Text(" light is absent ");
   }
   }
}