#include <iostream>
std::string s;
int a[20]={0,0,0,0,10,1};
int b[20]={0,0,0,0,-3,1};
int x=0;
int main() {
    getline(std::cin,s);
    for(int i=4;i<s.length()-1;i++){
        x+=s[i]/a[i]+b[i];
    }
    std::cout<<x<<'\n';
    std::cout<<(int)s[s.length()-1];
}
