/** @file
 * @author Илья Участкин
 * @warning Это учебный вариант
 * @brief main.cpp файл Cipher
 */
#include <iostream>
#include <string>
#include "Encryptor.h"
using namespace std;
void check(const string& text1, const int& KEY)
{
using namespace std;
void check(const string& text1, const int& KEY)
{
    try {
       Encryptor a;
       string privat_text = a.encrypt(text1, KEY);
       string decode_text = a.decrypt(privat_text, KEY);
       cout << text1 << "\tIncoming text" << endl;
       cout << privat_text << "\tEncrypted" <<endl;
       cout << decode_text << "\tDeciphered" << endl;
    } catch (const cipher_error& e) {
       cerr << "\nError: " << e.what() << endl<< endl;
    }
}
int main(int argc, char **argv)
{
    cout << "Correct:\n";
    check("WELCOMETOHELL", 4);
    cout << "\nIncorrect:\n";
    check("",10);
    cout << "\nIncorrect:\n";
    check("HELLOWORLD1234",5);
    cout << "\nIncorrect:\n";
    check("HELLOWORLD1234",5);
    cout << "\nIncorrect:\n";
    check("HELLOWORLD1234",0);
    return 0;
}
