#include "tests_cw4.h"
#include "cw4_functions.h"
#include "filefunctions_cw4.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "input.h"

bool UnitTestCW4::testCaseOne() { // test encrypt and decrypt Caesar
	const int shift = 3;
	std::string
		testString = "testovaya kotokrevetka 12345",
		resultString = testString,
		expectedResult{};
	encryptCaesar(resultString, shift);
	expectedResult = "whvwryd|d#nrwrnuhyhwnd#45678";

	if (resultString != expectedResult) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	decryptCaesar(resultString, shift);

	if (resultString != testString) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << testString << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseTwo() { // test encrypt and decrypt Gronsfeld
	std::string
		testString = "testovaya kotokrevetka 12345",
		resultString = testString,
		expectedResult{};
	const std::string shift = "246";
	encryptGronsfeld(resultString, shift);
	expectedResult = "viyvs|c}g\"ouvsqti|gxqc$747:7";

	if (resultString != expectedResult) {
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	decryptGronsfeld(resultString, shift);

	if (resultString != testString) {
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << testString << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseThree() { // test encrypt and decrypt Tritemius
	std::string
		testString = "testovaya kotokrevetka 12345",
		resultString = testString,
		expectedResult{};
	encryptTritemius(resultString);
	expectedResult = "ugvxt|h\"j*v{\"}z#v)x)!w7IKMOQ";

	if (resultString != expectedResult) {
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	decryptTritemius(resultString);

	if (resultString != testString) {
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << testString << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseFour() { // test getting status of encryptionType
	std::string
		path = "test4.txt",
		resultString{};
	int expectedResult = CAESAR;
	int encryptionType{};
	if (!std::ifstream(path)) {
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}
	getTextFromFile(resultString, path, encryptionType);

	if (encryptionType != expectedResult) {
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseFive() { // check getting text from file
	std::string 
		path = "test5.txt", 
		resultString{},
		expectedResult = "Kotokrevetka vetka Fedin\n";
	int encryptionType{};
	if (!std::ifstream(path)) {
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}
	getTextFromFile(resultString, path, encryptionType);

	if (resultString != expectedResult) {
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}


void UnitTestCW4::runAllTests() {
	UnitTestCW4 test{};
	if (test.testCaseOne() && test.testCaseTwo() && test.testCaseThree() && test.testCaseFour() && test.testCaseFive()) {
		system("cls");
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	}
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
