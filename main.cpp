#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <sec_api/tchar_s.h>

void connectRussian() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU.UTF8");
}

void task1() {
    int type = GetKeyboardType(0);
    if (type == 0x4) {
        std::cout << "Улучшенные клавиатуры со 101 или 102 клавишами (и совместимые)" << std::endl;
    } else if (type == 0x7) {
        std::cout << "Японская клавиатура" << std::endl;
    } else if (type == 0x8) {
        std::cout << "Корейская клавиатура" << std::endl;
    } else {
        DWORD error = GetLastError();
        std::cerr << "Неизвестный тип клавиатуры. Код ошибки: " << error << std::endl;
    }
}

void task2() {
    if (GetKeyState(VK_SHIFT) & 1) {
        std::cout << "Клавиша Shift нажата" << std::endl;
    } else {
        std::cout << "Клавиша Shift не нажата" << std::endl;
    }
}

void task3() {
    if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
        std::cout << "Клавиша Enter нажата" << std::endl;
    } else {
        std::cout << "Клавиша Enter не нажата" << std::endl;
    }
}

void task4() {
    BYTE keyboardState[256];
    GetKeyboardState(keyboardState);
    if (keyboardState[VK_SHIFT] & 0x80) {
        std::cout << "Клавиша Shift нажата" << std::endl;
    } else {
        std::cout << "Клавиша Shift не нажата" << std::endl;
    }
}

void task5() {
    UINT blinkTime = GetCaretBlinkTime();
    std::cout << "Стандартный интервал времени мигания курсора: " << blinkTime << std::endl;
}

void task6() {
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);
    std::cout << "Разрешение экрана: " << width << " x " << height << std::endl;
}

void task7() {
    bool cursor = true;
    while (true) {
        if (cursor) {
            ShowCursor(TRUE);
        } else {
            ShowCursor(FALSE);
        }
        std::cout << "Курсор видим: " << (cursor ? "Да" : "Нет") << std::endl;
        cursor = !cursor;
        Sleep(1000);
    }
}

void task8() {
    UINT blinkTime = 2000;
    if (SetCaretBlinkTime(blinkTime)) {
        std::cout << "Интервал времени мигания курсора изменен на: " << blinkTime << " мс" << std::endl;
    } else {
        std::cerr << "Не удалось изменить интервал мигания курсора" << std::endl;
    }
}

void task9() {
    RECT clipRect = {0, 0, 800, 600};
    RECT fullClipRect = {0, 0, 1920, 1080};
    if (ClipCursor(&clipRect)) {
        std::cout << "Движение курсора ограничено " << clipRect.right << " x " << clipRect.bottom << std::endl;
        Sleep(5000);
        std::cout << "Движение курсора увеличено до " << fullClipRect.right << " x " << fullClipRect.bottom << std::endl;
        ClipCursor(&fullClipRect);
    } else {
        std::cerr << "Не удалось ограничить движение курсора" << std::endl;
    }
}

void task10() {
    char fileName[10];
    strcpy(fileName, "C:\\Users\\mazaf\\CLionProjects\\lab2\\wallpaper.bmp");
    if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, &fileName, SPIF_SENDWININICHANGE) == true) {
        std::cout << "Обои изменены" << std::endl;
    } else {
        std::cerr << "Не удалось изменить обои" << std::endl;
    }
}

int main() {
    connectRussian();
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
    //task8();
    task9();
    return 0;
}







