#include <xxtea-iot-crypt.h>

void setup() {
  Serial.begin(115200);

  Serial.println();

  // Texto a encriptar. Desventaja: No debe ser más de 80 byts
  String plaintext = F("Hola soy Yaeru y merezco abundancia");

  xxtea.setKey("Soy una llave");

  // Encriptacion
  Serial.print(F(" Encrypted Data: "));
  String result = xxtea.encrypt(plaintext);
  result.toLowerCase(); // (Optional)
  Serial.println(result);

  // Desencriptacion
  Serial.print(F(" Decrypted Data: "));
  Serial.println(xxtea.decrypt(result));
}

void loop() {}
