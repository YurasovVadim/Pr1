#include <iostream>
#include <string>
int main()
{
 std::string url = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\n\
deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\n\
deb http://security.debian.org/ stretch/updates main contrib non-free\n\
deb-src http://security.debian.org/ stretch/updates main contrib non-free\n\
deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n\
deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n\
deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n\
deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
 while (true)
 {
 int start_pos = url.find(".mephi")+1;
 if (start_pos!=0) 
 {
 int len = url.find(".ru", start_pos) - start_pos;
 url.replace(start_pos,len,"yandex");
 start_pos=0;
 }
 else break;
 }
 std::cout<<url<<std::endl;
 return 0;
}
