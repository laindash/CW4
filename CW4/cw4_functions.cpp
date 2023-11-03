#include "input.h"
#include <iostream>
#include <regex>
#include <unordered_map>

void showDecrypted(const std::string& decryptedText)
{
	std::cout
		<< "�������������� �����: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< decryptedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}


void showEncrypted(const std::string& encryptedText)
{
	std::cout
		<< "������������� �����: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< encryptedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

void showOriginal(const std::string& originalText)
{
	std::cout
		<< "������������ �����: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< originalText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

void showCurrent(const std::string& currentText)
{
	std::cout
		<< "������� �����: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< currentText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

bool isCyrillic(char c) {
	return (c >= '�' && c <= '�') || (c == '�' || c == '�');
}

void inputText(std::string& text)
{
	std::cout << "������� �����, �� ���������� ���������. ������� q ����� ��������� ����." << std::endl;
	std::string input{};
	while (input != "q") {
		getLine(std::cin, input, CW4_INPUT, MANUAL_INPUT);
		if (input != "q") {
			bool contains�yrillic = false;
			for (char c : input) {
				if (isCyrillic(c)) {
					contains�yrillic = true;
					break;
				}
			}

			if (!contains�yrillic) {
				text += (input + '\n');
			}
			else {
				std::cout << "������ ��������� ��������� � ���� ���������������." << std::endl;
			}
		}
	}
}

void encryptCaesar(std::string& text, int shift) {
	int element{};
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		element = text[i];
		if ((element >= SPACE_CODE) && (element <= TILDA_CODE)) {
			element += shift;
			while (element > TILDA_CODE) {
				element -= QUANTITY_SYMBOLS;
			}
			while (element < SPACE_CODE) {
				element += QUANTITY_SYMBOLS;
			}
		}
		text[i] = static_cast<char>(element); // ���������� ���� int � char
	}
}


void encryptGronsfeld(std::string &text, std::string key) {
	int shift{}, element{}, endOfKey = static_cast<int>(key.size());
	for (int i = 0, j = 0; i < static_cast<int>(text.size()); i++, j++) {
		element = text[i];
		shift = key[j] - '0';
		if ((element >= SPACE_CODE) && (element <= TILDA_CODE)) {
			element += shift;
			while (element > TILDA_CODE) {
				element -= QUANTITY_SYMBOLS;
			}
			while (element < SPACE_CODE) {
				element += QUANTITY_SYMBOLS;
			}
		}
		text[i] = static_cast<char>(element);
		if (j == endOfKey - 1) j = -1; // ��� ��� �� ��������� ����� j ����� ����� = 0
	}
}

void encryptTritemius(std::string &text) {
	int element{}, shift{};
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		element = text[i];
		shift = i + 1; // ����� ������� �� ������� �������
		if ((element >= SPACE_CODE) && (element <= TILDA_CODE)) {
			element += shift;
			while (element > TILDA_CODE) {
				element -= QUANTITY_SYMBOLS;
			}
			while (element < SPACE_CODE) {
				element += QUANTITY_SYMBOLS;
			}
		}
		text[i] = static_cast<char>(element);
	}
}

void decryptCaesar(std::string& text, int shift) {
	encryptCaesar(text, -shift);
}

void decryptGronsfeld(std::string& text, std::string key) {
	int shift{}, element{}, endOfKey = static_cast<int>(key.size());
	for (int i = 0, j = 0; i < static_cast<int>(text.size()); i++, j++) {
		element = text[i];
		shift = key[j] - '0';
		if ((element >= SPACE_CODE) && (element <= TILDA_CODE)) {
			element -= shift;
			while (element > TILDA_CODE) {
				element -= QUANTITY_SYMBOLS;
			}
			while (element < SPACE_CODE) {
				element += QUANTITY_SYMBOLS;
			}
		}
		text[i] = static_cast<char>(element);
		if (j == endOfKey - 1) j = -1; // ��� ��� �� ��������� ����� j ����� ����� = 0
	}
}

void decryptTritemius(std::string &text) {
	int element{}, shift{};
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		element = text[i];
		shift = i + 1; // ����� ������� �� ������� �������
		if ((element >= SPACE_CODE) && (element <= TILDA_CODE)) {
			element -= shift;
			while (element > TILDA_CODE) {
				element -= QUANTITY_SYMBOLS;
			}
			while (element < SPACE_CODE) {
				element += QUANTITY_SYMBOLS;
			}
		}
		text[i] = static_cast<char>(element);
	}
}

void showEncryptionType(const int& encryptionType) {
	if (encryptionType == CAESAR) {
		std::cout << "����� ���������� ������ ������" << std::endl;
	}
	else if (encryptionType == GRONSFELD) {
		std::cout << "����� ���������� ������ �����������" << std::endl;
	}
	else if (encryptionType == TRITEMIUS) {
		std::cout << "����� ���������� ������ ����������" << std::endl;
	}
}

void decryptText(std::string& text, int& encryptionType) {
	if (encryptionType == CAESAR) {
		int shift;
		std::cout << "������� �������� ������ ��� ����������� ������ � ������ ������: " << std::endl;
		shift = getInt();
		decryptCaesar(text, shift);
	}
	else if (encryptionType == GRONSFELD) {
		std::string key{};
		std::cout << "������� �������� ���� ��� ����������� ������ � ������ �����������: " << std::endl;
		getLine(std::cin, key, ONLY_DIGITS, MANUAL_INPUT);
		decryptGronsfeld(text, key);
	}
	else if (encryptionType == TRITEMIUS) {
		std::cout << "����������� ������ � ������ ���������� " << std::endl;
		decryptTritemius(text);
	}
	showDecrypted(text);
	encryptionType = 0;
}

void encryptText(std::string& text, int &encryptionType) {
	if (encryptionType) {
		int encChoice{};
		showEncryptionType(encryptionType);
		std::cout << "������������ ����� ��� ���������� ����������? 1 - ��, 2 - ���." << std::endl;
		encChoice = getKey(YES, NO);
		if (encChoice == YES) {
			decryptText(text, encryptionType);
		}
	}
	else {
		int userChoice{};
		std::cout
			<< "�������� ������ ���������� ������: " << std::endl
			<< "1 - ���� ������" << std::endl
			<< "2 - ���� �����������" << std::endl
			<< "3 - ���� ����������" << std::endl;

		userChoice = getKey(CAESAR, TRITEMIUS);

		if (userChoice == CAESAR) {
			std::cout << "������� ��� ��� ����� ������: " << std::endl;
			int shift = getInt();
			encryptCaesar(text, shift);
			showEncrypted(text);
			encryptionType = CAESAR;
		}
		else if (userChoice == GRONSFELD) {
			std::cout << "������� �������� ���� ��� ����� �����������: " << std::endl;
			std::string key{};
			getLine(std::cin, key, ONLY_DIGITS, MANUAL_INPUT);
			encryptGronsfeld(text, key);
			showEncrypted(text);
			encryptionType = GRONSFELD;
		}
		else if (userChoice == TRITEMIUS) {
			encryptTritemius(text);
			showEncrypted(text);
			encryptionType = TRITEMIUS;
		}
	}
}
