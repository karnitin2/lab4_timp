#pragma once
#include <iostream>
#include <string>
using namespace std;
/** @brief Шифрование методом маршрутной перестановки
 * @details Ключ передается как аргумент в методах encrypt и decrypt.
 * Для зашифровывания предназначен - encrypt, для расшифровывания - decrypt.
 * @warning Реализация только для английского языка
 */
class Encryptor {
public:
string encrypt(string in, const int key); ///Зашифровывание
string decrypt(string in, const int key); ///Расшифровывание
};
/** @brief Обработка исключений
 * @details Вызывается при обработке исключительных ситуаций
 */
class cipher_error: public invalid_argument{
public:
explicit cipher_error(const string& what_arg): /// what_arg содержит сообщение вызываемое при исключительной ситуации
invalid_argument(what_arg) {}
};
