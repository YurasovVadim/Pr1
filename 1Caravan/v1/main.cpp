#include <iostream>
#include <string>

int main()
{
    std::string n;
    std::cout<<"Сколько верблюдов было в караване?"<<std::endl;
    std::cin>>n;
    std::cout<<"В караване был";
    int num = stoi(n.substr(0,3));
    if ((num % 10==1) && (num != 11)) std::cout<<n<<" верблюд"<<std::endl;
    else
    {
    if ((num%10 <= 4) && (num/10!=1)) std::cout<<"о "<<n<<" верблюда"<<std::endl;
    else std::cout<<"о "<<n<<" верблюдов"<<std::endl;
    }
    return 0;
}
