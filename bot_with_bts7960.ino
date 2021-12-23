/*  Arif 1703026, 23rd December, 2021
 *  This is a sample code for simple operation of a footbot driven by a pair of BTS7960 modules
 *  Necessary comments have been added for a better understanding
 *  One may need to alter/change their motor connection(s) for desired direction of rotation,
 *  Here it is assumed that right side motors are controlled by arduino pin 5 and 6
    and left side motors are controlled by arduino pin 9 and 10, these are PWM pins
 *  The bluetooth module is connected to arduino pin 0 and 1 for serial communication
 */



void setup() {
Serial.begin(9600);  //initializing serial communication(bluetooth module) at 9600 bps
pinMode(2,OUTPUT);   //for first BTS L_EN/R_EN pin
pinMode(3,OUTPUT);   //for first BTS L_EN/R_EN pin
pinMode(5,OUTPUT);   //for first BTS L_PWM/R_PWM pin
pinMode(6,OUTPUT);   //for first BTS L_PWM/R_PWM pin
pinMode(12,OUTPUT);   //for second BTS L_EN/R_EN pin
pinMode(13,OUTPUT);   //for second BTS L_EN/R_EN pin
pinMode(9,OUTPUT);   //for second BTS L_PWM/R_PWM pin
pinMode(10,OUTPUT);  //for second BTS L_PWM/R_PWM pin
}
void loop() {
digitalWrite(2, HIGH);   //these are all R_EN and L_EN pins(2,3,12,13)
digitalWrite(3, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);

if(Serial.available()>0)  //checks if any serial port is connected and available
{
  char letter=Serial.read(); //anything that is read in serial port is stored in a variable
  Serial.println(letter);    //displays it in serial monitor

  
  if(letter=='F')        //if 'F' comes from mobile (forward)
  {  
    //goes forward
    analogWrite(9, 255); //full forward drive for left side motors
    analogWrite(10,0);   //zero reverse drive for left side motors
    analogWrite(5,255);  //full forward drive for right side motors
    analogWrite(6,0);    //zero reverse drive for right side motors
    //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
  }
  
    if((letter=='B')||(letter=='H')||(letter=='J'))  //if 'B'/'J'/'H' comes from mobile(backward/left backward/right backward
  {
    //goes backward
    analogWrite(9, 0);   //zero forward drive for left side motors
    analogWrite(10,255); //full reverse drive for left side motors
    analogWrite(5,0);    //zero forward drive for right side motors
    analogWrite(6,255);  //full reverse drive for right side motors
    //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
  }
  
    if((letter=='R')||(letter=='I'))  //if 'R'/'I' comes from mobile(right/forward right)
  {
    //turns right side
    analogWrite(9, 255);  //full forward drive for left side motors
    analogWrite(10,0);    //zero reverse frive for left side motors
    analogWrite(5,0);     //zero forward drive for right side motors
    analogWrite(6,255);   //full reverse drive for right side motors
    //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
  }
  
    if((letter=='L')||(letter=='G'))  //if 'L'/'G' comes from mobile(left/forward left)
  {
    //turns left side
    analogWrite(9, 0);    //zero forward drive for left side motors
    analogWrite(10,255);  //full reverse drive for left side motors
    analogWrite(5,255);   //full forward drive for right side motors
    analogWrite(6,0);     //zero reverse drive for right side motors
    //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
  }
  
    if(letter=='S')   //if 'S' comes from mobile(continuously comes if no button is pressed while connected)
  {
    //no motion
    analogWrite(9, 0);  //zero forward drive for left side motors
    analogWrite(10,0);  //zero reverse drive for left side motors
    analogWrite(5,0);   //zero forward drive for right side motors
    analogWrite(6,0);   //zero revers drive for right side motors
  }

  //that's it!
}

}
