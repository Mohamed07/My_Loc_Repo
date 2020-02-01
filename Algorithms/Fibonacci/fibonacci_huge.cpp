#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_pisano_period(int m)
{
        std::vector<long> v{1, 1};
    while (true) {
        auto t = (v[v.size() - 1] + v[v.size() - 2]) % m;
        v.push_back(t);
        if (t == 0 && v.size() % 2 == 0 &&
            std::equal(v.begin(), v.begin() + v.size() / 2,
                       v.begin() + v.size() / 2, v.end())) {
            return v.size() / 2;
        }
    }
    return v.size() / 2;
}

long long get_fibonacci_huge_fast(long long n, int m) {
    int prev = 0;
    int curr = 1;
    int pisano_per = get_pisano_period(m);   
    //std::cout<<"::: <<<"<<pisano_per<<"\n";

    if(n % pisano_per == 0)
    return prev;
    for( int i = 2; i < (n % pisano_per) + 1; ++i) {
        int tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr)%m;
        //std::cout<<"curr("<<i<<"): "<<curr<<"\n";
     }
     return curr;
}

int main() {
    
   // while(true)
   // {
    //    long long  n;
   //     n = rand() % 10000 + 1;
        
    //    long long r1, r2;
    //    r1= get_fibonacci_huge_naive(n);
    //    r2= get_fibonacci_huge_naive(n);

   //     if(r1 != r2)
   ///     {
   //         cout<<"\t\tError\nr1 = "<< r1 <<"\tr2 = "<< r2 << '\n';
   //     }
    //    else
    //    {
    //        cout<<"=============================\n\t\tOkay\n";
    //    }
   // }

    long long n;
    int m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n) << '\n';
    std::cout << get_fibonacci_huge_fast(n,m) << '\n';
}
