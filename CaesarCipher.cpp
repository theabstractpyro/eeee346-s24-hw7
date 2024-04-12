#include "CaesarCipher.h"

const string CaesarCipher::CIPHER_NAME = "Caesar";

CaesarCipher::CaesarCipher(int shift) : Cipher(CIPHER_NAME), shift(shift){}

bool CaesarCipher::encode(string decodedMsg) {
 encoded = "";

  for (char& messageChar : decodedMsg) {
    if (isValidCharacter(messageChar)) {
      int alphabetNumber = messageChar - 'A';
      int shiftedNumber = alphabetNumber - shift;
            
      if (shiftedNumber > 25) {
        shiftedNumber -= 26;
      } else if (shiftedNumber < 0) {
        shiftedNumber += 26;
      }
            
      char encodedChar = shiftedNumber + 'A';
            
      encoded += encodedChar;
    } else {
      return false;
    }
  }
  return true;
}

bool CaesarCipher::decode(string encodedMsg) {
    decoded = "";

    // Calculate the decoding shift value by subtracting the encoding shift from 26
    int decodeShift = 26 - shift;

    for (char& encodedChar : encodedMsg) {
        if (isValidCharacter(encodedChar)) {
            if (encodedChar != ' ') { // Check if the character is not a space
                int alphabetNumber = encodedChar - 'A';
                int shiftedNumber = alphabetNumber - decodeShift; // Adjusted for decoding

                if (shiftedNumber < 0) {
                    shiftedNumber += 26;
                }

                char decodedChar = shiftedNumber + 'A';

                decoded += decodedChar;
            } else {
                decoded += ' '; // Preserve the space
            }
        } else {
            return false;
        }
    }
    return true;
}



bool CaesarCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
