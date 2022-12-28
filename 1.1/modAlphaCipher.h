/**
* @file modAlphaCipher.h
* @author Шепталин В.С.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 22.12.2022
* @copyright ИБСТ ПГУ
*/

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
using namespace std;
/// @brief  Класс, осуществляющий шифрование  методом "Гронсвельда"  
class modAlphaCipher
{
private:
/// @brief  Алфавит для текста,  использующийся в данной программе
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    /// @brief  Ассоциативный массив "номер по символу"
    std::map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    /// @brief  Атрибут для ключа
    std::vector <int> key; //ключ
    /** @brief  Преобразование строк в вектор чисел
     * @details В векторе типа "int" с именем "result" формируются числа
     * @code
     *  vector<int> result;
     *   for(auto c:s) {
     *       result.push_back(alphaNum[c]);
     *   }
     * @endcode
     * @return std::vector <int>, в котором хранятся индексы букв алфавита
     */
    std::vector<int> convert(const std::wstring& s);
    /** @brief Преобразование вектора чисел в строку
     *  @details "wstring" переменная типа  с именем "result", в которой формируется строка по индексам алфавита "numAlpha".
     *  @code
     *  wstring result;
     *   for(auto i:v) {
     *       result.push_back(numAlpha[i]);
     *   }
     *  @endcode
     *  @return  "result" - строка текста типа "wstring"
     */
    std::wstring convert(const std::vector<int>& v);
    /** @brief  Проверка ключа
     * @details Ключ проверяется на пустоту. Если проверка закончилась успешно, то ключ проверяется на наличие недопустимых символов. 
     * @throw cipher_error, если ключ является пустым или в нём присутствуют недопустимые символы
     * @return "result" - строка текста типа "wstring"
     */
    std::wstring getValidKey(const std::wstring & s);
    /** @brief  проверка текста
     *  @details Сначала текст проверяется на пустоту . Если проверка закончилась успешно, то текст проверяется на наличие недопустимых символов. 
     *  @throw cipher_error, если текст является пустым или в нём присутствуют недопустимые символы
     *  @return строка текста типа "wstring"
     */
    std::wstring getValidText(const std::wstring & s);
public:
    //! Конструктор без параметоров.
    modAlphaCipher()=delete;
    /** @brief  Конструктор для ключа
      * @details Цикл "for" построен по строке-алфавиту 
      * @code
      *     for (unsigned i=0; i<numAlpha.size(); i++) {
      *          alphaNum[numAlpha[i]]=i;
      *      }
      * @endcode
      * @param строка текста типа "wstring"
      */ 
    modAlphaCipher(const std::wstring& skey); 
    /**
     * @brief Зашифрование
     * @details Формируется вектор "work" из строки  текста с помощью метода
     *   convert().  Происходит проверка текста на наличие ошибки методом getValidAlphabetText().
     *  @code
     *       vector<int> work = convert(getValidAlphabetText(open_text));
     * @endcode
     *  В цикле каждому элементу вектора прибавляется элемент ключа по модулю  размера
     *   алфавита. 
     *  @code
     *   for(unsigned i=0; i < work.size(); i++) {
     *      work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
     *   }
     * @endcode
     * @param wstring open_text - текст, для зашифрования
     * @throw cipher_error - строка, пришедшея на вход, кторая оказывается пустой или в ней есть недопустимые символы
     * @return строка зашифрованного текста типа "wstring"
     */
    std::wstring encrypt(const std::wstring& open_text);
    /**
     * @brief 	Расшифрование
     * @details Формируется вектор "work" из строки  зашифрованного текста с помощью метода
     *   convert().  А также   зашифрованный текст проверяется на наличие ошибки  методом getValidAlphabetText().
     *  @code
     *       vector<int> work = convert(getValidAlphabetText(cipher_text));
     * @endcode
     *  Если при зашифровывании прибавляется значение ключа, то при расшифровывании значения ключа вычитается.
     *  @code
     *   for(unsigned i=0; i < work.size(); i++) {
     *           work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
     *   }
     * @endcode
     *
     * @param wstring cipher_text - текст расшифрования
     * @throw cipher_error - строка, пришедшея на вход, кторая оказывается пустой или в ней есть недопустимые символы
     * @return  строка расшифрованного текста типа "wstring"
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};

//! @class cipher_error - возбуждение исключений.
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg): 
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
