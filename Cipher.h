#ifndef CYPHER_H
#define CYPHER_H

#include <string>

using namespace std;

// abstract base class
class Cipher {
public:
  /*
   * encode(): abstract (pure virtual) function for encoding
   * @param decodedMsg - original message that requires encoding
   * @return true if encode was successful
   */
  virtual bool encode(string decodedMsg) = 0;

  /*
   * decode(): abstract (pure virtual) function for decoding
   * @param encodedMsg - encoded message that requires decoding
   * @return true if decode was successful
   */
  virtual bool decode(string encodedMsg) = 0;

  /*
   * isValidCharacter(): abstract helper function (pure virtual) to check if a character is valid for a cipher
   * @param c - character to check
   * @return true if character may be used in the cipher
   */
  virtual bool isValidCharacter(char c) = 0;

  /*
   * getters
   */ 
  string getEncoded() { return encoded; }
  string getDecoded() { return decoded; }
  string getCipherName() { return cipherName; }

protected:
  /*
   * constructor that sets the Cipher name but may only be called by derived classes
   * @param name - name to set for cipherName
   */
  Cipher(string name) : cipherName(name) {}
  
  /*
   * string to store a decoded message
   */
  string decoded;

  /*
   * string to store an encoded message
   */
  string encoded;

  /*
   * string to store the name of a cipher
   */
  string cipherName;
};
#endif
