
#include<Wire.h>
const int mpu = 0x68; 
int16_t AX,AY,AZ,Tmp,GX,GY,GZ; // A para acelerometro e G para giroscópio

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
  
  //Impressão dos dados no monitor serial//
  Serial.print("AX = "); Serial.print(AX);
  Serial.print(" | AY = "); Serial.print(AY);
  Serial.print(" | AZ = "); Serial.print(AZ);
  Serial.print(" | Temp = "); Serial.print(Tmp/340.00+36.53); 
  Serial.print(" | GX = "); Serial.print(GX);
  Serial.print(" | GY = "); Serial.print(GY);
  Serial.print(" | GZ = "); Serial.println(GZ);
  delay(300);
}
