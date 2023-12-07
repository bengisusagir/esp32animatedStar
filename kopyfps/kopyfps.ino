#include "Arduino_GFX_Library.h"
 

Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
    1 /* CS */, 12 /* SCK */, 11 /* SDA */,
    45 /* DE */, 4 /* VSYNC */, 5 /* HSYNC */, 21 /* PCLK */,
    39 /* R0 */, 40 /* R1 */, 41 /* R2 */, 42 /* R3 */, 2 /* R4 */,
    0 /* G0/P22 */, 9 /* G1/P23 */, 14 /* G2/P24 */, 47 /* G3/P25 */, 48 /* G4/P26 */, 3 /* G5 */,
    6 /* B0 */, 7 /* B1 */, 15 /* B2 */, 16 /* B3 */, 8 /* B4 */
);

Arduino_ST7701_RGBPanel *gfx = new Arduino_ST7701_RGBPanel(
    bus, GFX_NOT_DEFINED /* RST */, 0 /* rotation */,
    false /* IPS */, 480 /* width */, 480 /* height */,
    st7701_type7_init_operations, sizeof(st7701_type7_init_operations),
    true /* BGR */);



void setup()
{  Serial.begin(9600);
    gfx->begin();
  
    gfx->fillScreen( gfx->color565(0,0,0));



  // drawStar(120);

   
}

static int colors2[] = {RED, GREEN, BLUE, WHITE, YELLOW};
 
 
int distance=90; 


void drawStar(int r){
  int k = r; 
  int topX = 240;
  int topY = 240-k;
  int topLeftX = 240 - ((k*sin(18*0.0174532925)*cos(54*0.0174532925))/sin(126*0.0174532925));
  int topLeftY = 240 - ((k*sin(18*0.0174532925)*sin(54*0.0174532925))/sin(126*0.0174532925));
  int leftX =240 - (sin(72*0.0174532925)*k);
  int leftY =240 - (cos(72*0.0174532925)*k);
  int bottomLeftX =240 - ((k*sin(18*0.0174532925)*sin(72*0.0174532925))/sin(126*0.0174532925));
  int bottomLeftY =240 + ((k*sin(18*0.0174532925)*cos(72*0.0174532925))/sin(126*0.0174532925));
  int botLeftArmX =240 - (sin(36*0.0174532925)*k);
  int botLeftArmY =240 + (cos(36*0.0174532925)*k);
  int bottomX =240 ;
  int bottomY =240 + (k*sin(18*0.0174532925)/sin(126*0.0174532925));

/*
  for(int i = topX ; i>topLeftX;i--){
    int k = topY;
      delay(100);
        if(k<topLeftY){
            gfx -> drawLine(topX,topY,i,k,gfx->color565(250 , 0 , 250));  
          k++;
        }

      Serial.println(i);
      
  }*/
 
  gfx -> drawLine(topX,topY,topLeftX,topLeftY,gfx->color565(250 , 0 , 250));  
  gfx -> drawLine(topLeftX,topLeftY,leftX,leftY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(leftX,leftY,bottomLeftX,bottomLeftY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(bottomLeftX,bottomLeftY,botLeftArmX,botLeftArmY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(botLeftArmX,botLeftArmY,bottomX,bottomY,gfx->color565(250 , 0 , 250));

  gfx -> drawLine(480-topX,topY,480-topLeftX,topLeftY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(480-topLeftX,topLeftY,480-leftX,leftY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(480-leftX,leftY,480-bottomLeftX,bottomLeftY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(480-bottomLeftX,bottomLeftY,480-botLeftArmX,botLeftArmY,gfx->color565(250 , 0 , 250));
  gfx -> drawLine(480-botLeftArmX,botLeftArmY,480-bottomX,bottomY,gfx->color565(250 , 0 , 250));
 
distance += 30;
      }
  





long nextUpdate ;
int i =10;
void loop(void)
{   

      if(nextUpdate<millis()){ 
        nextUpdate=millis()+30;
        drawStar(i++);
      }
      if(i==150)
         gfx->fillScreen( gfx->color565(0,0,0));
}