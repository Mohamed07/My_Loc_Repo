#include <iostream>
#include <algorithm>

using namespace std;

int get_fibonacci_last_digit_naive(int n, int m) {

    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fibonacci_last_digit_fast(int n, int m)
{
    int current = 1, previous = 0;
    for(int i = 0; i < n-1; i++)
    {
        int tmp = current;
        current = (previous + current) % m;
        previous = tmp;
    }
    return current;
}

int main() {

    while(true)
    {
        int n = rand() % 25 + 1;
        int m = rand() % 26 + 1;

        int r1 = get_fibonacci_last_digit_naive(n, m);
        int r2 = get_fibonacci_last_digit_fast(n, m);
        if(r1 != r2)
        {
            cout<<"==========================\n\tError Not Equal Results\n";
            cout<<"n = "<<n<<" ,m = "<<m<< " r1 = "<<r1<< " r2 = "<<r2<<"\n";
            break;
        }
        else
        {
            cout<<"==========================\n\t\t Okay\n";
        }     
    }

    int n, m;
    cin >> n >> m;
    int c = get_fibonacci_last_digit_naive(n, m);
    cout << c << '\n';

    int r = get_fibonacci_last_digit_fast(n, m);
    cout << r << '\n';

    }
