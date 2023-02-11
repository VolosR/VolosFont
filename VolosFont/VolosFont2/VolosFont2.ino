#include <TFT_eSPI.h>


TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(320,170);

}

byte word2[5][6]={
{124,2,1,2,124,0},
{62,65,65,65,62,0},
{127,1,1,1,1,0},
{62,65,65,65,62,0},
{50,73,73,73,38,0}};

void draw()
{
sprite.fillSprite(TFT_BLACK);
for(int l=0;l<5;l++)
  for(int i=0;i<6;i++)
  {
    for(int j=7;j>=0;j--)
    if(bitRead(word2[l][i],j)==1)
    sprite.fillRect((l*60)+i*10,(7-j)*10,6,6,TFT_RED);
  }
sprite.pushSprite(0,0);
}

void loop() {
  draw();
}

