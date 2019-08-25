#include <iostream>

int gcd(int x, int y){
    if(y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x%y);
    }
}

long long lcm_naive(long a, long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long a, long b) {
    long long l = (a*b) / gcd(a,b);
    return l;
}

int main() {
  //while(true)
  //{
  //  int a, b;
  //  a = rand() % 10000 + 1;
 //   b = rand() % 10000 + 1;
 //   long long r1, r2;
 //   std::cout<<"Naive\n";
 //   r1 = lcm_naive(a,b);
 //   std::cout<<"Fast\n";
 //   r2 = lcm_r2(a,b);
 //   if(r1 != r2)
 //   {
 //       std::cout<<"\t\tERROR\nr1 = "<<r1<<"\tr2 = "<<r2<<"\n";
 //       break; 
 //   }
 //   else
 //   {
 //       std::cout<<"=============================\n\t\tOk\n";
 //   }
 // }
  long long a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;

  return 0;
}

