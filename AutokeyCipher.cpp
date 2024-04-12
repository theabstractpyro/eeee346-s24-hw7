#include "AutokeyCipher.h"

const string AutokeyCipher::CIPHER_NAME = "Autokey";

AutokeyCipher::AutokeyCipher(string primer) : Cipher(CIPHER_NAME), primer(primer) {}

bool AutokeyCipher::encode(string decodedMsg) {
  encoded = "";

  string key = primer + decodedMsg;

  for (size_t i = 0; i < decodedMsg.length(); ++i) {
    char messageChar = decodedMsg[i];
    char keyChar = key[i];

    if (isValidCharacter(messageChar)) {
      char encodedChar = (messageChar + keyChar - 2 * 'A') % 26 + 'A';
      encoded += encodedChar;
    } else {
      return false;
    }
  }
  return true;
}

bool AutokeyCipher::decode(string encodedMsg) {
  decoded = "";

  string key = primer;

  for (size_t i = 0; i < encodedMsg.length(); ++i) {
    char encodedChar = encodedMsg[i];
    char keyChar = key[i];

    if (isValidCharacter(encodedChar)) {
      char decodedChar = (encodedChar - keyChar + 26) % 26 + 'A';
      if (decodedChar < 'A') {
         decodedChar += 26;
      }
        decoded += decodedChar;
        key += decodedChar;
      } else {
        return false;
      }
    }
  return true;
}

bool AutokeyCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
