#include <iostream>
#include <functional>
using namespace std;

int TestFunc(int a, char c, float f)
{
    cout << a << endl;
    cout << c << endl;
    cout << f << endl;

    return a;
}

int main()
{
    auto bindFunc1 = bind(TestFunc, std::placeholders::_1, 'A', 100.1);
    bindFunc1(10);

    cout << "=================================\n";
    //把TestFunc绑定到bindFunc2上，bindFunc2的第二个参数为TestFunc的第一个参数
    //bindFunc2的第一个参数为TestFunc的第二个参数,最后一个参数固定为100.1
    //类似于  TestFunc(bindFunc2's_var_2, bindFunc2's_var_1, 100.1);
    auto bindFunc2 = bind(TestFunc, std::placeholders::_2, std::placeholders::_1, 100.1);
    bindFunc2('B', 10);

    cout << "=================================\n";

    auto bindFunc3 = bind(TestFunc, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
    bindFunc3(100.1, 30, 'C');

    auto bindFunc4 = bind(TestFunc, std::placeholders::_1, std::placeholders::_3, std::placeholders::_2);
    bindFunc4(100, 30, 'C');
    return 0;
}
