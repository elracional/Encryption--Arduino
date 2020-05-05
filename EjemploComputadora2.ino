#include <xxtea-iot-crypt.h>

void setup() {
  Serial.begin(115200);

  Serial.println();
  uint8_t keybuf[] = "soy la llave";
  uint8_t plaintext[] = "Soy Yaeru y merezco abundancia";
  uint8_t buffer[200];
  size_t len = 200, i;

  // configuración de la llave
  if(xxtea_setup(keybuf, strlen((char *)keybuf)) != XXTEA_STATUS_SUCCESS) {
    Serial.println(" Assignment Failed!");
    return;
  }

  // Encriptar
  len = 200;  // Tamaño máxiimo del buffer
  if(xxtea_encrypt(plaintext, strlen((char*)plaintext), buffer, &len) != XXTEA_STATUS_SUCCESS) {
    Serial.println(" Encryption Failed!");
    return;
  } else {
    Serial.println(" Encrypted Data: ");
    for(i = 0;i<len;i++)
      Serial.print(buffer[i], HEX);
    Serial.println();
  }

  // Desencriptar
  if(xxtea_decrypt(buffer, len) != XXTEA_STATUS_SUCCESS) {
    Serial.println(" Decryption Failed!");
    return;
  } else {
    Serial.print(" Decrypted Data: ");
    Serial.println((char *)buffer);
  }
}

void loop() {}
