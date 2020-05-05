#include <SoftwareSerial.h>
#include <xxtea-iot-crypt.h>

int enc = 0;
int dec = 0;
int con = 0;
int state = 0;
String message;

void setup() {
    Serial.begin(9600);//Concexion BT
    Serial3.begin(115200);
}
 
void loop() { 

  if (Serial.available()){
       incomingByte = Serial.read();
       
       if(incomingByte == '1'){
            con = 1;
        }
        if(incomingByte == '2'){
            enc = 1;
        }
        if(incomingByte == '3'){
            dec = 1;
        }
        if(incomingByte == '0'){
            con = 0;
        }
  }

  if (enc==1) {
    delay(1000);
    String plaintext = F(Serial.read());
    xxtea.setKey(Serial.read());
    delay(1000);
    Serial3.print(F(" Encrypted Data: "));
    String result = xxtea.encrypt(plaintext);
    result.toLowerCase();
    Serial.println(result);//Mostrar el mensaje encriptado en pantalla
    delay(1000);
    
    enc=0;
  }
  
  if (des==1) {
    Serial3.print(F(" Decrypted Data: "));
    Serial.println(xxtea.decrypt(result));//Mostrar el mensaje encriptado en pantalla
    delay(2000);
    des=0;
  }
  
}
