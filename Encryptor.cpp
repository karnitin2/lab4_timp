#include "Encryptor.h"
#include <regex>
#include <iostream>
#include <string>
using namespace std;
/**
 * @brief Зашифровывание
 * @param [in] in Открытый текст. Не должен быть пустой строкой.
 * При наличии неправильных символов выдает исключение.
 * @param [in] key Ключ. Состоит из цифр. Не должен быть меньше 1.
 * @return Зашифрованная строка
 * @throw cipher_error, если текст пустой или текст содержит неправильне символы
 */
string Encryptor::encrypt(string in, const int key)
{
    if (key <= 1)
       throw cipher_error("Encryption is not possible with this key");
    if (in == "")
       throw cipher_error("String contains no characters");
    regex r("[A-Za-z]*");
    if (!regex_match(in, r))
       throw cipher_error("String contains invalid characters");
    int arr_s = in.length();
    int arr_h = (arr_s/key) + ((arr_s%key > 0) ? 1 : 0);
    int lower_str_lenght = in.length()%key;
    int vopr = (lower_str_lenght > 0) ? key - lower_str_lenght : 0;
    char ** tabl = new char*[arr_h];
    for (int i =0; i<arr_h; i++) tabl[i] = new char[key];
    std::string output;
    for (int i = 0; i < vopr; i++) {
       tabl[arr_h-1][(key-1)-i] = '?';
    }
    int charId = 0;
    for (int i = 0; i < arr_h; i++) {
       for (int j = 0; j < key; j++) {
          if (tabl[i][j] == '?') continue;
          tabl[i][j] = in.at(charId);
          charId++;
       }
    }
    for (int i = 0; i < key; i++) {
       for (int j = 0; j < arr_h; j++) {
          if (tabl[j][(key-1)-i] == '?') continue;
          output+=tabl[j][(key-1)-i];
       }
    }
    cout << "\n";
    for (int i = 0; i < arr_h; i++) delete[] tabl[i];
    delete[] tabl;
    return output;
}
/**
 * @brief Расшифровывание
 * @param [in] in Открытый текст. Не должен быть пустой строкой.
 * @param [in] key Ключ. Состоит из цифр. Не должен быть меньше 1.
 * @throw cipher_error, если текст пустой или текст содержит неправильне символы или ключ меньше 1.
 */
string Encryptor::decrypt(string in, const int key)
{
    int arr_h = (in.length()/key) + ((in.length()%key > 0) ? 1 : 0);
    int lower_str_lenght = in.length()%key;
    int vopr = (lower_str_lenght > 0) ? key - lower_str_lenght : 0;
    char ** tabl = new char*[arr_h];
    for (int i =0; i<arr_h; i++) tabl[i] = new char[key];
    std::string output;
       for (int i = 0; i < arr_h; i++) {
          for (int j = 0; j < key; j++) {
          tabl[i][j] = '\0';
       }
    }
    for (int i = 0; i< vopr; i++) {
       tabl[arr_h-1][(key-1)-i] = '?';
    }
    int charId = 0;
    for (int i = 0; i < key; i++) {
       for (int j = 0; j < arr_h; j++) {
          if (tabl[j][(key-1)-i] == '?') continue;
          tabl[j][(key-1)-i] = in.at(charId);
          charId++;
       }
    }
    for (int i = 0; i < in.length(); i++) {
       int y = i/key;
       int x = (i%key);
       char c = tabl[y][x];
       if (c != '\0') {
          output+=c;
       }
    }
    for (int i = 0; i < arr_h; i++) delete[] tabl[i];
    delete[] tabl;
    return output;
}
