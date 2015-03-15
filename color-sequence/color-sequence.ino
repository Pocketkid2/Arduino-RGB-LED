/**************************************************************************/
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 9 
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 10 
/***************************************************************************/
unsigned char r; // Current displayed color (in RGB form)
unsigned char g;
unsigned char b;
/****************************************************************************/
void setup() {
  // Set outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
/*****************************************************************************/
// This function gradually fades the current color into the golor given by the parameters in RGB form
void colormorph(unsigned char red, unsigned char green, unsigned char blue) {
  while (red != r || green != g || blue != b) {
    if (r > red) r--;
    if (r < red) r++;
    if (g > green) g--;
    if (g < green) g++;
    if (b > blue) b--;
    if (b < blue) b++;
    color(r,g,b);
    delay(10);
  }
}
/*******************************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  r = g = b = 0;
  // Red
  colormorph(255, 0, 0);
  // Orange
  colormorph(255, 128, 0);
  // Yellow
  colormorph(255, 255, 0);
  // Lime
  colormorph(125, 255, 0);
  // Green
  colormorph(0, 255, 0);
  // Teal
  colormorph(0, 255, 128);
  // Light blue
  colormorph(0, 255, 255);
  // Medium blue
  colormorph(0, 128, 255);
  // Blue
  colormorph(0, 0, 255);
  // Violet
  colormorph(127, 0, 255);
  // Purple
  colormorph(255, 0, 255);
  // Dark-ish pink?
  colormorph(255, 0, 127);
  // Gray
  colormorph(128, 128, 128);
  
}
/**********************************************************************************/
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(bluePin, blue); 
  analogWrite(greenPin, green); 
}
