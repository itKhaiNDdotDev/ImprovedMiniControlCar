#include <AFMotor.h>

char blt = 's'; //Biến nhận dữ liệu qua bluetooth
AF_DCMotor motor1(1); //Khai báo động cơ 1
AF_DCMotor motor2(2); //Khai báo động cơ 2

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600); //Mở cổng Serial
  motor1.setSpeed(255);//Đặt tốc độ động cơ
  motor2.setSpeed(255);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if ( Serial.available() > 0 )
  {
      blt = Serial.read();
      Serial.println(blt);
  }
  if ( blt == 'f') //tien
  {
      //Serial.println("MOVE FORWARD!");
      motor1.run(BACKWARD);      // động cơ tiến 
      motor2.run(BACKWARD);
      //blt = 's';    
      delay(5);
  }
  if (blt == 'b') //lui
  {
      //Serial.println("MOVE FORWARD!");
      motor1.run(FORWARD);      // động cơ lui    
      motor2.run(FORWARD);
      //blt = 's';    
      delay(5);
  }
  if (blt == 'l') //xoaytrai
  {
      motor1.run(FORWARD);      // động cơ quay trai 
      motor2.run(BACKWARD);
      //blt = 's';    
      delay(5);
  }
  if (blt == 'r') //xoayphai
  {
      motor1.run(BACKWARD);      // động cơ quay phai
      motor2.run(FORWARD);
      //blt = 's'; 
      delay(5);
  }
  if (blt == 's')//Dung dong co
  {
      //Serial.println("STOP!");
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      //blt = 's';
      delay(5);
  }
  delay(5);
}
