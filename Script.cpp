#include <iostream>
#include <string>
#include <windows.h>    

std::wstring caesar(std::wstring x, int y){
    std::wstring ru = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::wstring ruh = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring eng = L"abcdefghijklmnopqrstuvwxyz";
    std::wstring engh = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    
    std::wstring specials = L" !%$#@?*()-_=+";

    for (wchar_t& c : x){
        
        
        if (specials.find(c) != -1) {
            continue; 
        }

        int index = eng.find(c);
        if (index != -1) { 
            c = eng[(index + y) % 26]; 
            continue; 
        }
        
        int index_h = engh.find(c);
        if (index_h != -1) {
            c = engh[(index_h + y) % 26];
            continue;
        }

        
        int index_ru = ru.find(c);
        if (index_ru != -1) {
            c = ru[(index_ru + y) % 33];
            continue;
        }

        int index_ruh = ruh.find(c);
        if (index_ruh != -1) {
            c = ruh[(index_ruh + y) % 33];
            continue;
        }
    }
    return x;
}

int main(){
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    while(true){
        
        std::wcout << L"Введите текст для шифрования!\n";
        std::wcout << L"Input text for encryption!\n";

        std::wstring text;

        std::getline(std::wcin, text);

        if (text == L"exit"){
            break;
        }

        std::wcout << caesar(text, 3) << L"\n\n";
    }

    return 0;
}