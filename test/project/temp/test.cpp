#include <iostream>
using namespace std;

constexpr int GetFive(){return 5;}

void process_value(int& i) 
{ 
  std::cout << "LValue processed: " << i << std::endl; 
} 

void process_value(int&& i) 
{ 
  std::cout << "RValue processed: "<< i  << std::endl; 
} 
int main(){

int some_value[GetFive() + 5]= {'0'};
//cout<<some_value[6]<<endl;

int a = 0; 
  process_value(a);
  int&& x = 3;
  process_value(1000);
}