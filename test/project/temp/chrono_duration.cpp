// duration constructor
#include <iostream>
#include <vector>
#include<algorithm>

int main ()
{
  std::vector<int> v = { 1, 2, 3, 4, 5, 6 ,7,8};
int even_count = 0;
for_each( v.begin(), v.end(), [&even_count](int val)
        {
            if (!(val & 1))  // val % 2 == 0
            {
                ++ even_count;
            }
        });
std::cout << "The number of even is " << even_count << std::endl;
}



