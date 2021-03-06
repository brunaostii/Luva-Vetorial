#include<Wire.h>
const int mpu = 0x68; 
int16_t AX,AY,AZ,Tmp,GX,GY,GZ; // A para acelerometro e G para giroscópio
float pitch, roll, aux1,aux2;

void setup(){
  Wire.begin();
  Wire.beginTransmission(mpu);
  Wire.write(0x6B);  
  Wire.write(0);     
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop(){
  
  Wire.beginTransmission(mpu);
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(mpu,14,true); 
  
  //Leitura dos dados//
  AX=Wire.read()<<8|Wire.read();  
  AY=Wire.read()<<8|Wire.read();  
  AZ=Wire.read()<<8|Wire.read(); 
  Tmp=Wire.read()<<8|Wire.read(); 
  GX=Wire.read()<<8|Wire.read();  
  GY=Wire.read()<<8|Wire.read(); 
  GZ=Wire.read()<<8|Wire.read();  
  
  //Impressão dos angulos no monitor serial//
  aux1 = pow(AY,2)+ pow(AZ,2);
  aux2 = pow(AX,2)+ pow(AZ,2);

  aux1 = atan2(AX,sqrt(aux1));
  pitch = (aux1* 180)/3.1418;
  
  aux2 = atan2(AY,sqrt(aux2));
  roll = (aux2*180)/3.1418;

  Serial.print("\npitch: ");Serial.print(pitch);
  Serial.print("\nroll: ");Serial.print(roll);
  delay(300);
}
