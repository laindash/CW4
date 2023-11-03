#ifndef FILEFUNCTIONS_CW4_H
#define FILEFUNCTIONS_CW4_H
#include <filesystem>
#include <fstream>

bool isDataCorrectCW4(std::ifstream& file);
std::string checkFileCW4();
void getTextFromFile(std::string& text, std::string& path, int &encryptionType);
void saveToFile(const std::string& originalText, const std::string& decryptedText, const std::string& encryptedText, 
int encryptionType, int saveChoice);

#endif