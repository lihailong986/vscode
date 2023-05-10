#include <iostream> 
#include <string>
using namespace std;
int main()
{
    string path = "/system/app/test.hap";
     
    //1.获取不带路径的文件名
    string::size_type iPos = path.find_last_of('/') + 1;
    string filename = path.substr(iPos, path.length() - iPos);
    cout << filename << endl;
  
    //2.获取不带后缀的文件名
    string name = filename.substr(0, filename.rfind("."));
    cout << name << endl;
  
    //3.获取后缀名
    string suffix_str = filename.substr(filename.find_last_of('.') + 1);
    cout << suffix_str << endl;
    return 0;
}