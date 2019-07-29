#include <iostream>
#include <stdexcept>
#include "Array.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
    Array a1;
    std::cout<<"Max size of a1 : "<<a1.max_size()<<endl;
    cout<<"cur size of a1 : "<<a1.size()<<endl;

    Array a2(5);
    cout<<"Max size of a2 : "<<a2.max_size()<<endl;
    cout<<"cur size of a2 : "<<a2.size()<<endl;

    Array a3(10,'s');
    cout<<"Max size of a3 : "<<a3.max_size()<<endl;
    cout<<"cur size of a3 : "<<a3.size()<<endl;

    for(size_t i=0;i<a3.size();i++)
        cout<<i<<":"<<a3[i]<<endl;

    Array a4(a3);
    cout<<"Max size of a4 : "<<a4.max_size()<<endl;
    cout<<"cur size of a4 : "<<a4.size()<<endl;
    for(size_t i=0;i<a4.size();i++)
        cout<<i<<":"<<a4[i]<<endl;

    a4.resize(7);

    Array a5=a4;
    cout<<"Max size of a5 : "<<a5.max_size()<<endl;
    cout<<"cur size of a5 : "<<a5.size()<<endl;
    for(size_t i=0;i<a5.size();i++)
        cout<<i<<":"<<a5[i]<<endl;

    a5.resize(15);

    cout<<"Max size of a5 : "<<a5.max_size()<<endl;
    cout<<"cur size of a5 : "<<a5.size()<<endl;
    for(size_t i=0;i<a5.size();i++)
        cout<<i<<":"<<a5[i]<<endl;

    Array b1(8);
    b1[0]='s';
    b1[1]='h';
    b1[2]='a';
    b1[3]='h';
    b1[4]='b';
    b1[5]='e';
    b1[6]='g';
    b1[7]='h';
    cout<<"Max size of b1 : "<<b1.max_size()<<endl;
    cout<<"cur size of b1 : "<<b1.size()<<endl;
    for(size_t i=0;i<b1.size();i++)
        cout<<i<<":"<<b1[i]<<endl;

    Array c1(b1);
    if(c1==b1)
        cout<<"equal"<<endl;
    else
        cout<<"unequal"<<endl;

    cout<<b1.get(5);

    b1.set(5,'i');
    for(size_t i=0;i<b1.size();i++)
        cout<<i<<":"<<b1[i]<<endl;

    cout<<"a is at index : "<<b1.find('a')<<endl;
    cout<<"for start index as 3,index : "<<b1.find('a',3)<<endl;

    if(c1==b1)
        cout<<"equal"<<endl;
    else
        cout<<"unequal"<<endl;

    c1.reverse();
    for(size_t i=0;i<c1.size();i++)
        cout<<i<<":"<<c1[i]<<endl;


    a5.resize(10);
    cout<<"Max size of a5 : "<<a5.max_size()<<endl;
    cout<<"cur size of a5 : "<<a5.size()<<endl;
    for(size_t i=0;i<a5.size();i++)
        cout<<i<<":"<<a5[i]<<endl;

    a5.shrink();

    cout<<"Max size of a5 : "<<a5.max_size()<<endl;
    cout<<"cur size of a5 : "<<a5.size()<<endl;
    for(size_t i=0;i<a5.size();i++)
        cout<<i<<":"<<a5[i]<<endl;

    return 0;
}
