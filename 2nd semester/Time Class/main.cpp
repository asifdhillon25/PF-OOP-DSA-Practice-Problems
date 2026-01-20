
#include "Time.h"
#include"Time.cpp"
int main() {
  Time obj1(2,34,45),obj2(11,5,46);

Time Result;
obj1++;obj2++;
Result=obj1+obj2;

    Result.ShowTime();

}
