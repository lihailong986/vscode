#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, vector<string>> umap;
    //向 umap 容器添加新键值对
    vector<string> path;
    vector<string> path1;
  //  path.emplace("/system/app/entry.hap");
    path.push_back("/system/app/entry.hap");
    path.push_back("/system/app/entry1.hap");
   umap.emplace("com.example.myapplication",path);
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second[0] << endl;
        cout << iter->first << " " << iter->second[1] << endl;    
    }

  /*  if(umap.find("com.example.myapplication")!=umap.end())
    {
        umap.erase("com.example.myapplication");

    }*/
    path1.push_back("test1.hap");
    path1.push_back("test.hap");
    path1.push_back("test2.hap");
 //   umap.emplace("com.example.myapplication",path1);
    umap["com.example.myapplication"] = path1;
    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second[0] << endl; 
        cout << iter->first << " " << iter->second[1] << endl;
        cout << iter->first << " " << iter->second[2] << endl;
    }


    return 0;
}