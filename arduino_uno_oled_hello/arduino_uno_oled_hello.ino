#include <Wire.h>
#include <avr/pgmspace.h>
#include "OLED.h"

//static uint8_t updateBuffer[BUFFER_SIZE];

void setup() {

  Serial.begin(9600);
  Serial.println("---- SETUP ----");
  
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  delay(300);

  Wire.begin();

  send_command(0xAE);
  send_command_data(0xD5, __osc_freq << 4 | __clk_div);
  send_command_data(0xA8, __mux_ratio);
  send_command_data(0xd3, 0x00);
  send_command_data(0x8d, 0x14);
  send_command(0x40);
  send_command(0xa6);
  send_command(0xa4);
  send_command(0xa1);
  send_command(0xc8);
  // Horizontal mode
  send_command(0x20);
  send_command(0x00);

  send_command_data(0xda, 0x12);
  send_command_data(0x81, __contrast);
  send_command_data(0xd9, 0xf1);
  send_command_data(0xdb, 0x40);
  send_command(0xaf);

  clear_screen();
  print_text(1,"Hello,");
  print_text(2,"World!");
  drawLine(1,35,128,35);
  
  print_smtext(7,(unsigned char *)"Rickard E, first test",1);
  update();
  delay(5000);
}

void loop() {
  

  for(int i = 0; i < 128; i++) {
    memset(buffer, 0, BUFFER_SIZE);
    print_text(2,"Progress:  ");
    drawLine(1,35,i,35);

    char sOut[8];
    sprintf( sOut, "CNT=%d",i);
    print_text(4,sOut);
    update();
    delay(50);
  }
}