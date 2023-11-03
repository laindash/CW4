#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw4_functions.h"


bool isDataCorrectCW4(std::ifstream& file) { //The function checks if the data loaded from the file is valid
    if (file.eof()) {
        std::cout << "���� ����!";
        return false;
    }
    return true;
}

std::string checkFileCW4() {
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do {
        std::cout << "������� ���� � �����: ";
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path)) {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error)) {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file) {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!isDataCorrectCW4(file)) {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void getTextFromFile(std::string& text, std::string& path, int &encryptionType) {
    std::ifstream file(path);
    std::string input{};

    while (!file.eof()) {
        getLine(file, input, CW4_INPUT, FILE_INPUT);
        if (input == "CAESAR") {
            encryptionType = CAESAR;
        }
        else if (input == "GRONSFELD") {
            encryptionType = GRONSFELD;
        }
        else if (input == "TRITEMIUS") {
            encryptionType = TRITEMIUS;
        }
        else {
            text += (input);
            if (!file.eof())
                text += '\n';
        }
    }

    std::cout << "����� ��������!" << std::endl;
    file.close();
}

void saveToFile(const std::string& originalText, const std::string& decryptedText, const std::string& encryptedText,
                int encryptionType, int saveChoice) {
    std::ofstream file;
    std::string path{};
    bool isOpened = false;
    std::error_code error{};
    do {
        std::cout
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);
        if (std::ifstream(path)) {
            if (!std::filesystem::is_regular_file(path, error)) {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (getKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);


    if (saveChoice == SAVE_ORIGINAL) {
        file << originalText;
    }

    else if (saveChoice == SAVE_DECRYPTED) {
        file << decryptedText;
    }

    else if (saveChoice == SAVE_ENCRYPTED) {
        if (encryptionType == CAESAR) {
            file << "CAESAR" << std::endl;
        }
        else if (encryptionType == GRONSFELD) {
            file << "GRONSFELD" << std::endl;
        }
        else if (encryptionType == TRITEMIUS) {
            file << "TRITEMIUS" << std::endl;
        }
        file << encryptedText;
    }

    std::cout << "������� ��������� � " << path << std::endl;
}
