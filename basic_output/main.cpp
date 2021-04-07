#include <iostream>
#include <cstdlib>   // Enables use of rand()
#include <ctime>     // Enables use of time()
using namespace std;
int main()
{
   int seedVal = 0;
   seedVal = time(0);  ///this will change the seed each second
   srand(seedVal);
   cout << rand() % 50 + 100 << endl;
   cout << rand() % 50 + 100 << endl;
   return 0;
}
