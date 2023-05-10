#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
void *wait(void *t)
{
   int i = *((int *)t);
   
   sleep(1);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << i<< "  ...exiting " << endl;
   pthread_exit(NULL);
}
 
int main ()
{
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;
   // 初始化并设置线程为可连接的（joinable）
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   for(int i= 0 ;i<NUM_THREADS;i++){
    cout << "main() : creating thread, " << i << endl;
    pthread_create(&threads[i], &attr, wait, (void *)&i );
    pthread_join(threads[i], NULL);
   }
   // 删除属性，并等待其他线程
   pthread_attr_destroy(&attr);
   pthread_exit(NULL);
   return 0;
}
