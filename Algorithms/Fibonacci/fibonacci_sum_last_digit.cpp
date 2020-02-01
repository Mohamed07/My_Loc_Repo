#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int fibonacci_sum_fast(long long n){
    n = n + 2;

    int curr = 1, prev = 0;
    if(n % 60 == 0)
    return prev;
    for( int i = 2; i < (n % 60) + 1; ++i){
        int tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr);
        if(curr >= 10 && i+1 < (n%60+1))
            curr %= 10;
        //std::cout<<"curr("<<i<<") = "<<curr<<"\n";
    }

    return (curr - 1)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
