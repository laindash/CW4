#ifndef INPUT_H
#define INPUT_H

#include <conio.h>
#include <string>
#include <vector>


constexpr auto KEY_ESC = 0x1B; // вычисл€емый на этапе компил€ции тип данных, €вл€ющийс€ константой
constexpr auto KEY_1 = 0x31;
constexpr auto KEY_2 = 0x32;
constexpr auto KEY_3 = 0x33;
constexpr auto KEY_4 = 0x34;
constexpr auto KEY_5 = 0x35;
constexpr auto KEY_6 = 0x36;
constexpr auto KEY_7 = 0x37;
constexpr auto KEY_8 = 0x38;

enum InputMenu {
    FILE_INPUT = KEY_1,
    MANUAL_INPUT = KEY_2,
    MODUL_TESTS = KEY_3,
    RANDOM_INPUT = KEY_4
};

enum MenuCW {
    CW1 = KEY_1,
    CW2 = KEY_2,
    CW3 = KEY_3,
    CW4 = KEY_4,
    QUIT = KEY_ESC
};

enum BoolMenu {
    YES = KEY_1,
    NO = KEY_2
};

enum BoolInput {
    WITHOUT_DIGITS,
    WITH_DIGITS,
    ONLY_DIGITS,
    ALMOST_ALL_DIGITS,
    CW4_INPUT
};

enum MainMenuCW4 {
    SHOW_ORIGINAL = KEY_1,
    SHOW_CURRENT = KEY_2,
    SHOW_DECRYPTED = KEY_3,
    SHOW_ENCRYPTED = KEY_4,
    SAVE_ORIGINAL = KEY_5,
    SAVE_DECRYPTED = KEY_6,
    SAVE_ENCRYPTED = KEY_7
};

enum Encryption {
    CAESAR = KEY_1, 
    GRONSFELD = KEY_2,
    TRITEMIUS = KEY_3
};

enum EncryptionConstants {
    SPACE_CODE = 32,
    TILDA_CODE = 126,
    QUANTITY_SYMBOLS = 95
};


int getKey(int key_min, int key_max);

std::string getLine(std::istream& _Input, std::string& line, int num_exists, int isInput);

int getInt();

#endif