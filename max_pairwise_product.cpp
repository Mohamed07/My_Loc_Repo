#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define DEBUG
using std::vector;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
               ((long long)numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

long long MaxPairwiseProduct_Fast(const std::vector<int>& numbers){
    long long max_product = 0;
    int n = numbers.size();

    int max_index1 = 0;
    for(int i = 1; i < n; ++i)
    {
        if( numbers[i] > numbers[max_index1] )
            max_index1 = i;
    }

    int max_index2 = -1;
    for(int j = 0; j < n; ++j)
    {
        if( (numbers[j] > numbers[max_index2]) && ( j != max_index1 ) )
            max_index2 = j;
    }
    
    #ifdef DEBUG
        std::cout<<"MAX1:  "<<numbers[max_index1];
        std::cout<<"\nMAX2: "<<numbers[max_index2]<<"\n";
    #endif
    max_product = ((long long) numbers[max_index1] * numbers[max_index2]);
    return max_product;

}

int main() {
    
    while(true)
    {
        int n = rand() % 1000 + 2;            // Random Size of a sequence of numbers ( modulo 10 plus 2 = { 2 => 11 }
        std::cout<< n << "\n";
        std::vector<int> a;
        for(int i=0; i < n; ++i)
        {
            a.push_back(rand() % 1000000);
            std::cout<<a[i]<<" ";
      }

        std::cout<<"\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProduct_Fast(a);
        if(res1 != res2)
        {
            std::cout<< "Wrong Answer: "<<res1 <<"\t" << res2 << "\n";
            break;
        }
        else
        {
            std::cout<<"===========================================\n\t \t OK \n===========================================\n";
        }
    }


    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\t"<< MaxPairwiseProduct_Fast(numbers)<< "\n";
    return 0;
}
