#include <TFT_eSPI.h>
#include "VolosFont.h"


TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);



void setup() {

  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
 
 
  
  sprite.createSprite(320,170);
 

}

byte word2[4][6]={
{50,73,73,73,38,0},
{64,64,127,64,64,0},
{31,63,100,63,31,0},
{127,72,76,74,49,0}};



void draw(String n,int x,int y,int w, int h, int space, unsigned short color, unsigned short color2) 
{
for(int l=0;l<n.length();l++){
  for(int i=0;i<6;i++)
  {
    for(int j=7;j>=0;j--)
    if(bitRead(VFont[int(n.charAt(l))-32][i],j)==1)
    sprite.fillRect((space*i)+x+(l*6*w)+i*w,(space*(7-j))+y+(7-j)*h,w,h,color);
    else
    sprite.fillRect((space*i)+x+(l*6*w)+i*w,(space*(7-j))+y+(7-j)*h,w,h,color2);
  }}
}
int i=0;
int change[2]={1,-1};
bool dir=0;

int chosen=65;


void loop() {
  sprite.fillSprite(TFT_WHITE);

  for(int i=0;i<20;i++)
    if(i%5==0)
    sprite.fillRect(0,(i*8)-1,9,2,TFT_BLACK);
    else
    sprite.drawLine(0,i*8,5,i*8,TFT_BLACK);

    for(int i=0;i<40;i++)
    if(i%5==0)
    sprite.fillRect((i*8)-1,160,2,10,TFT_BLACK);
    else
    sprite.drawLine(i*8,164,i*8,170,TFT_BLACK);
   

  draw(String(char(chosen)),20,20,12,14,1,TFT_BLACK,0x9492);
  draw("0 1 2 3 4 5",26,8,1,1,0,TFT_BLACK,TFT_WHITE);

  draw("ASCII:",120,17,3,3,0,0x7000,TFT_WHITE);
  draw("HEX: ",120,45,3,3,0,0x7000,TFT_WHITE);

   draw(" "+String(chosen)+" ",240,17,3,3,0,TFT_BLACK,0xFEDB);
  draw("0X"+String(chosen,HEX),240,45,3,3,0,TFT_BLACK,0xFEDB);

  draw("B0    B1    B2",120,80,2,2,0,TFT_BLACK,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][0],BIN),120,100,1,1,0,0x8C51,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][1],BIN),192,100,1,1,0,0x8C51,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][2],BIN),264,100,1,1,0,0x8C51,TFT_WHITE);

  draw("B3    B4    B5",120,114,2,2,0,TFT_BLACK,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][3],BIN),120,134,1,1,0,0x8C51,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][4],BIN),192,134,1,1,0,0x8C51,TFT_WHITE);
  draw("0B"+String(VFont[chosen-32][5],BIN),264,134,1,1,0,0x8C51,TFT_WHITE);
  
  sprite.pushSprite(0,0);

  chosen++;
  if(chosen==91)
  chosen=64;

  delay(1000);
}

