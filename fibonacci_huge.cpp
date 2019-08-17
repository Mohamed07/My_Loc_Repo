#include <iostream>
#include <algorithm>

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

long long get_fibonacci_huge_fast(long long n) {
    if ( n <= 1 )
        return n;
    long long prev = 0;
    long long curr = 1;
    
    for( long long i = 0; i < n-1; ++i) {
        long long tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr) % 10;
     }
     return curr;
}

int main() {
    
    while(true)
    {
        long long  n;
        n = rand() % 10000 + 1;
        
        long long r1, r2;
        r1= get_fibonacci_huge_naive(n);
        r2= get_fibonacci_huge_naive(n);

        if(r1 != r2)
        {
            cout<<"\t\tError\nr1 = "<< r1 <<"\tr2 = "<< r2 << '\n';
        }
        else
        {
            cout<<"=============================\n\t\tOkay\n";
        }
    }

    long long n;

    std::cin >> n;
    std::cout << get_fibonacci_huge_naive(n) << '\n';
    std::cout << get_fibonacci_huge_fast(n) << '\n';
}
