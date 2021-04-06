#include <iostream>
#include <string>

int main()
{
    std::string n;
    std::cout<<"Сколько верблюдов было в караване?"<<std::endl;
    std::cin>>n;
    int num = stoi(n.substr(0,3));
    if ((num % 10==1) && (num != 11)) n="В караване был "+n+" верблюд";
    else
    {
    if ((num%10 <= 4) && (num/10!=1)) n="В караване было "+n+" верблюда";
    else n="В караване было "+n+" верблюдов";
    }
    std::cout<<n<<std::endl;
    return 0;
}
