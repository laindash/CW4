#ifndef CW4_FUNCTIONS_H
#define CW4_FUNCTIONS_H
#include <vector>
#include <string>
#include <unordered_map>


void inputText(std::string& text);
void showDecrypted(const std::string& decryptedText);
void showEncrypted(const std::string& encryptedText);
void showOriginal(const std::string& originalText);
void showCurrent(const std::string& currentText);
void showEncryptionType(const int& encryptionType);

void encryptText(std::string& text, int &encryptionType);
void decryptText(std::string& text, int &encryptionType);

void encryptCaesar(std::string &text, int shift);
void encryptGronsfeld(std::string &text, std::string key);
void encryptTritemius(std::string &text);

void decryptCaesar(std::string& text, int shift);
void decryptGronsfeld(std::string& text, std::string key);
void decryptTritemius(std::string& text);

#endif
