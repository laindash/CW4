#include "input.h"
#include <iostream>
#include <regex>
#include <unordered_map>

void showDecrypted(const std::string& decryptedText)
{
	std::cout
		<< "Расшифрованный текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< decryptedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}


void showEncrypted(const std::string& encryptedText)
{
	std::cout
		<< "Зашифрованный текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< encryptedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

void showOriginal(const std::string& originalText)
{
	std::cout
		<< "Оригинальный текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< originalText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

void showCurrent(const std::string& currentText)
{
	std::cout
		<< "Текущий текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< currentText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}

bool isCyrillic(char c) {
	return (c >= 'А' && c <= 'я') || (c == 'Ё' || c == 'ё');
}

void inputText(std::string& text)
{
	std::cout << "Введите текст, не содержащий кириллицу. Введите q чтобы завершить ввод." << std::endl;
	std::string input{};
	while (input != "q") {
		getLine(std::cin, input, CW4_INPUT, MANUAL_INPUT);
		if (input != "q") {
			bool containsСyrillic = false;
			for (char c : input) {
				if (isCyrillic(c)) {
					containsСyrillic = true;
					break;
				}
			}

			if (!containsСyrillic) {
				text += (input + '\n');
			}
			else {
				std::cout << "Строка содержала кириллицу и была проигнорирована." << std::endl;
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
		text[i] = static_cast<char>(element); // приведение типа int к char
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
		if (j == endOfKey - 1) j = -1; // так как на следующем цикле j сразу будет = 0
	}
}

void encryptTritemius(std::string &text) {
	int element{}, shift{};
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		element = text[i];
		shift = i + 1; // Сдвиг зависит от позиции символа
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
		if (j == endOfKey - 1) j = -1; // так как на следующем цикле j сразу будет = 0
	}
}

void decryptTritemius(std::string &text) {
	int element{}, shift{};
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		element = text[i];
		shift = i + 1; // Сдвиг зависит от позиции символа
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
		std::cout << "Текст зашифрован шифром Цезаря" << std::endl;
	}
	else if (encryptionType == GRONSFELD) {
		std::cout << "Текст зашифрован шифром Гронсфельда" << std::endl;
	}
	else if (encryptionType == TRITEMIUS) {
		std::cout << "Текст зашифрован шифром Тритемиуса" << std::endl;
	}
}

void decryptText(std::string& text, int& encryptionType) {
	if (encryptionType == CAESAR) {
		int shift;
		std::cout << "Введите значение сдвига для расшифровки текста с шифром Цезаря: " << std::endl;
		shift = getInt();
		decryptCaesar(text, shift);
	}
	else if (encryptionType == GRONSFELD) {
		std::string key{};
		std::cout << "Введите числовой ключ для расшифровки текста с шифром Гронсфельда: " << std::endl;
		getLine(std::cin, key, ONLY_DIGITS, MANUAL_INPUT);
		decryptGronsfeld(text, key);
	}
	else if (encryptionType == TRITEMIUS) {
		std::cout << "Расшифровка текста с шифром Тритемиуса " << std::endl;
		decryptTritemius(text);
	}
	showDecrypted(text);
	encryptionType = 0;
}

void encryptText(std::string& text, int &encryptionType) {
	if (encryptionType) {
		int encChoice{};
		showEncryptionType(encryptionType);
		std::cout << "Расшифровать текст для повторного шифрования? 1 - Да, 2 - Нет." << std::endl;
		encChoice = getKey(YES, NO);
		if (encChoice == YES) {
			decryptText(text, encryptionType);
		}
	}
	else {
		int userChoice{};
		std::cout
			<< "Выберите способ шифрования текста: " << std::endl
			<< "1 - Шифр Цезаря" << std::endl
			<< "2 - Шифр Гронсфельда" << std::endl
			<< "3 - Шифр Тритемиуса" << std::endl;

		userChoice = getKey(CAESAR, TRITEMIUS);

		if (userChoice == CAESAR) {
			std::cout << "Введите шаг для шифра Цезаря: " << std::endl;
			int shift = getInt();
			encryptCaesar(text, shift);
			showEncrypted(text);
			encryptionType = CAESAR;
		}
		else if (userChoice == GRONSFELD) {
			std::cout << "Введите числовой ключ для шифра Гронсфельда: " << std::endl;
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
