#include <Arduino.h>
#include <Servo.h>     //Servo library
#include<LiquidCrystal_I2C.h>  //LCD Library
LiquidCrystal_I2C lcd(0x27, 16, 2);   //LCD dimensions initialization
Servo myservo1;  //Variable for Servo
int ir1 = 2;  //First Infrared sensor pin
int ir2 = 3;   //Second Infrared Sensor pin 
int ir1Read;  //Variable to read first Infrared sensor
int ir2Read;  //Variable to read 2nd Infrared sensor
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //Starting the Serial monitor
  myservo1.attach(4);   //Servo pin
  pinMode(ir1, INPUT);  //pinMode for first infrared Sensor
  pinMode(ir2, INPUT);  //pinMode for 2nd infrared Sensor
  lcd.init();           //Starts the LCD
  lcd.backlight();      //Turn on the LCD Backlight
  lcd.setCursor(0, 0);  //Set cursor at First Line
  lcd.print("Welcome");  //Print message
  delay(2000);           //delay before clearing the message
  lcd.clear();           //Clear the screen



}

void loop() {
  // put your main code here, to run repeatedly:
  ir1Read = digitalRead(ir1);  //Read the value of first infrared Sensor
  ir2Read = digitalRead(ir2);
  if (ir1Read == LOW && ir2Read == HIGH) 
  {
    
    lcd.setCursor(0, 0);
    lcd.print("Door is");
    lcd.setCursor(0, 1);
    lcd.print("OPEN");

    myservo1.write(90);

  }

  if (ir1Read == HIGH && ir2Read == LOW) 
    {
    
      lcd.setCursor(0, 0);
      lcd.print("Door is");
      lcd.setCursor(0, 1);
      lcd.print("OPEN");

      myservo1.write(90);

  }

  if (ir1Read == HIGH && ir2Read == HIGH)
   {
    
    lcd.setCursor(0, 0);
    lcd.print("Door is");
    lcd.setCursor(0, 1);
    lcd.print("CLOSED");

    myservo1.write(0);

  }
  



  
  
  
}