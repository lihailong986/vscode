#include <iostream>
// 必须的头文件
#include <pthread.h>
#include <vector>
using namespace std; 
#define NUM_THREADS 5 
// 线程的运行函数
struct param {
  string str1;
  string str2;
};
void* say_hello(void* args)
{
    param * t = (param  *) args;
    cout<<t->str1<<" "<<t->str2<<endl;
    cout << "Hello Runoob！" << endl;
    return 0;
}
int main()
{
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    param args;
    args.str1 = "hello";
    args.str2 = "world";
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, &args);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}
