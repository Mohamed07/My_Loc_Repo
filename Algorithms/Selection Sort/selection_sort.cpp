#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(int & a, int & b)
{
    a += b;
    b = a - b;
    a -= b;
}

void selection_sort(vector<int> & vec)
{
    int min = vec[0];
    for(int i=0; i < vec.size(); i++)
    {
        min = vec[i];
        for(int j=i+1; j < vec.size(); j++)
        {
            if(vec[j] < min)
            {
                min = vec[j];
                swap(vec[i], vec[j]);
            }
        }
    }

}

int main(int argc, char* argv[]) {
  if(argc == 1)
  {
    std::cout<< "Usage: ./sort #size_of_list #list_members\n";
  }
  else if( argc - 2 == std::stoi(argv[1]))
  {
    vector<int> a(std::stoi(argv[1]));

    for (size_t i = 0; i < a.size(); ++i) {
        a[i] = std::stoi(argv[i+2]);
    }
    selection_sort(a);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
   }else{
     std::cout<< "length of list = "<< std::stoi(argv[1]) << "\n";
     std::cout<< "provieded items >< \n";
    }
}
