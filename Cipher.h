**
* @file Cipher.h
* @author Участкин И.А.
* @version 1.0
* @date 29.05.2023
* @copyright ИБСТ ПГУ
* @warning Это учебный пример
* @brief Заголовочный файл для модуля Cipher
*/

#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * @brief Шифрование методом маршрутной перестановки
 * @details Ключ передается как аргумент в методах cipher и decipher.
 * Для зашифрования и расшифрования предназначены методы cipher и decipher соответственно.
 * @warning Реализация только для английского языка
*/
class Cipher
{
public:
    int key (); ///<Ключ

    /**
     *@brief Зашифрование
     * @param [in] str Открытый текст.
     * @param [in] key Целочисленный ключ.
     * @return Зашифрованная строка
     * @throw cipher_error, если пустой текст или ключ, ключ меньше 1
    */
    string cipher(string str, const int key);


    /**
     *@brief Расшифрование
     * @param [in] str Открытый текст.
     * @param [in] key Целочисленный ключ.
     * @return Расшифрованная строка
     * @throw cipher_error, если пустой текст или ключ, ключ меньше 1
    */
    string decipher(string str, const int key);
};

/// @brief Класс для обработки исключений
class cipher_error : public invalid_argument
{
public:
    explicit cipher_error(const string& what_arg) :
        invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) :
        invalid_argument(what_arg) {}
};
