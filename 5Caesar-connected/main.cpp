#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include <cctype>
#include <codecvt>
#include <regex>
using namespace std;

string decoder(string s, int key)
{
    int i=0;
s = regex_replace(s, regex("№"), " ");
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i]) || ispunct (s[i]) || isblank (s[i])) {
cout << "Ошибка"<<endl;
return s;
        }
    }
// Возведение к верхнему регистру
 locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
 wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
 wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 in UTF-32
 for (wchar_t & wc: ws) {
 wc = toupper(wc,loc);
 }
 int size;
 size=ws.size();
 for (i=0; i<size; i++) {
 ws[i]=ws[i] + key%32;
 if (ws[i]>=1072) ws[i]=ws[i]-32;

 }
 s = codec.to_bytes(ws); // перекодируем из UTF-32 in UTF-8
 cout << "Зашифрованная строка :" << endl;
 cout << s << "\n";

 return s;
}

string coder(string s, int key)
{
 int i=0;
 s = regex_replace(s, regex("№"), " ");
    for (int i = 0; s[i] != '\0'; i++) { //Пробегаем по строке циклом (слева направо)
        if (isalnum(s[i]) || ispunct (s[i]) || isblank (s[i])) { //Условие, что символ не является буквой или цифрой
            s.erase(i, 1); //Удаляем найденный символ
            i--; //Сдвигаем индекс после удаления
        }
    }
 // Возведение к верхнему регистру
 locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
 wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
 wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 in UTF-32
 for (wchar_t & wc: ws) {
 wc = toupper(wc,loc);
  }
 int size;
 size=ws.size();
 for (i=0; i<size; i++) {
            ws[i]=ws[i] + key%32;
 if (ws[i]>=1072) ws[i]=ws[i]-32; 

 }
 s = codec.to_bytes(ws); // перекодируем из UTF-32 in UTF-8
 cout << s << "\n";

 return s;
}
int main()
{
 string s;
 cout <<"Введите строку: ";
 getline(cin, s);
 int key;
 cout << "Введите ключ (key): "<< endl;
 cin>>key;
  cout << "Для зашифровки введите 0 / Для расшифровки введите 1"<<endl;
 int dei;
 cin>>dei;
 string new_s;
 if (dei==0) {
 coder(s,key);
 } else if (dei == 1) {
 decoder(s,key);
 } else {
 cout<<"Данного действия не существует"<<endl;
 }
  return 0;
}