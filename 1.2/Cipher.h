/**
* @file Cipher.h
* @author Участкин И.А.
* @version 1.0
* @brief Описание класса Cipher
* @date 29.12.2022
* @copyright ИБСТ ПГУ
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/// @brief Класс  расшифрования и шифрования шифра маршрутной табличной перестановки.
class Cipher
{
private:
/// @brief Модуль, который хранит ключ для расшифрования или шифрования.
    int k;
    wstring getValidOpenText(const std::wstring & s);
    wstring getValidCipherText(const std::wstring & s);
    int getValidKey(const int k, const std::wstring & s);
public:
/// @brief Конструктор без параметров.
    Cipher()=delete;
    /// @brief Конструктор для ключа
     /**  @param значение ключа
     */
    Cipher(int w);
    /**
     * @brief шифрование табличной маршрутной перестановки
     * @param образец класса "Cipher", в котором устанавливается ключ
     * @param "wstring" это строка зашифрования
     * @details
     * <p>Для начала вычисляется размер таблицы.
     * @code
     *  if (s.size()%w.k!=0) {
     *     h=s.size()/w.k+1;
     *  } else {
     *    h=s.size()/w.k;
     *  } // Вычисление размера таблицы. 
     * @endcode
     * Затем создаётся двумерный массив "wchar_t"
     * Количество строк по формуле,количество столбцов = ключ в классе "Cipher".</p> 
     * @code
     * wchar_t a[h][w.k];
     * @endcode
     * <p>После в созданный  массив записываются символы строки зашифрования.
     * @code
     * for (int i=0; i<h; i++) {
     *  for (int j=0; j<w.k; j++) {
     *      if (k<s.size()) {
     *          a[i][j]=s[k];
     *          k++;
     *      } else a[i][j]=' ';
     *  }
     *   }
     * @endcode
     * </p>
     * <p>
     * @code
     * for (int i=0; i<w.k; i++) {
     *  for (int j=0; j<h; j++) {
     *       code+=a[j][i];
     *   }
     * }
     * @endcode
     * </p>
     * @return зашифрованная строка типа "wstring"
     */
    wstring zakodirovat(Cipher w, wstring& s);
    /**
     * @brief расшифрование табличной маршрутной перестановки
     * @param образец класса "Cipher", в котором устанавливается ключ
     * @details
     * <p>Сначала вычисляется размер таблицы.
     * @code
     *  if (s.size()%w.k!=0) {
     *   h=s.size()/w.k+1;
     *   } else {
     *   h=s.size()/w.k;
     *   }
     * @endcode
     * Затем создаётся двумерный массив "wchar_t"
	 * Количество строк по формуле,количество столбцов = ключ в классе "Cipher".</p> 
     * @code
     * wchar_t a[h][w.k];
     * @endcode
     * <p>После в созданный  массив записываются символы строки расшифрования
     * @code
     * for (int i=0; i<w.k; i++) {
     *  for (int j=0; j<h; j++) {
     *      a[j][i]=s[k];
     *     k++;
     *      }
     *  }
     * @endcode
     * @param "wstring" это строка  расшифрования
     * </p>
     * <p>
     * @code
     * for (int i=0; i<h; i++) {
     *   for (int j=0; j<w.k; j++) {
     *      decode+=a[i][j];
     *      }
     *  }
     * @endcode
     * </p>
     * @return зашифрованная строка типа "wstring"
     */
    wstring raskodirovat(Cipher w, wstring& s);
};

/// @class cipher_error - класс рассчитанный для возбуждения исключений

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
