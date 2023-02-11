#include <TFT_eSPI.h>
#include "VolosFont.h"


TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(320,170);
}

int i=0;
int change[2]={1,-1};
bool dir=0;


void draw(String n,int x,int y,int size, unsigned short color) 
{
for(int l=0;l<n.length();l++){
  for(int i=0;i<6;i++)
  {
    for(int j=7;j>=0;j--)
    if(bitRead(VFont[int(n.charAt(l))-32][i],j)==1)
    sprite.fillRect(x+(l*6*size)+i*size,y+(7-j)*size,size,size,color);
  }}
}


void loop() {
  sprite.fillSprite(TFT_BLACK);
  draw("STAR",20,10,i,TFT_WHITE);
  draw("WARS",20,10+(i*9),i,TFT_RED);
  sprite.pushSprite(0,0);

  i=i+change[dir];
  if(i==8 or i==0)
  dir=!dir;

  delay(140);
}

