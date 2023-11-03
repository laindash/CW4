#include "filefunctions_cw4.h"
#include "input.h"
#include "cw_info.h"
#include "cw4_functions.h"
#include "tests_cw4.h"
#include <iostream>
#include <string>


void startCW4(void) {
    int user_choice{};
    do {
        std::string text{}, file_path{}, originalText{}, encryptedText{}, decryptedText{};
        int encryptionType{};
        bool isLoopMenu = false;
        UnitTestCW4 tests{};

        infoCW4();
        showMainMenuCW4();

        switch (user_choice = getKey(FILE_INPUT, MODUL_TESTS)) {
            case FILE_INPUT:
                isLoopMenu = true;
                file_path = checkFileCW4();
                getTextFromFile(text, file_path, encryptionType);
                break;

            case MANUAL_INPUT:
                isLoopMenu = true;
                inputText(text);
                break;

            case MODUL_TESTS:
                tests.runAllTests();
                break;

            case QUIT:
                break;
        }
        originalText = text;

        while (isLoopMenu) {
            showMenuCW4();
            switch (user_choice = getKey(SHOW_ORIGINAL, SAVE_ENCRYPTED)) {

                case SHOW_ORIGINAL:
                    showOriginal(originalText);
                    break;

                case SHOW_CURRENT:
                    showCurrent(text);
                    break;

                case SHOW_DECRYPTED:
                    decryptText(text, encryptionType);
                    break;

                case SHOW_ENCRYPTED:
                    encryptText(text, encryptionType);
                    break;

                case SAVE_ORIGINAL:
                    saveToFile(originalText, decryptedText, encryptedText, encryptionType, SAVE_ORIGINAL);
                    break;

                case SAVE_DECRYPTED:
                    if (encryptionType) {
                        std::cout << "Сначала расшифруйте текст!" << std::endl;
                        decryptText(text, encryptionType);
                    }
                    decryptedText = text;
                    saveToFile(originalText, decryptedText, encryptedText, encryptionType, SAVE_DECRYPTED);
                    break;

                case SAVE_ENCRYPTED:
                    if (!encryptionType) {
                        std::cout << "Сначала зашифруйте текст!" << std::endl;
                        encryptText(text, encryptionType);
                    }
                    encryptedText = text;
                    saveToFile(originalText, decryptedText, encryptedText, encryptionType, SAVE_ENCRYPTED);
                    break;

                case QUIT:
                    isLoopMenu = false;
                    break;
            }
        }

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать контрольную, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}
