#include <iostream>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

  int ED[str1.length() + 1][str2.length() + 1];

  for(int i=0; i <= str1.length(); i++)
  {
    for(int j=0; j <= str2.length(); j++)
    {
      if(i == 0)
        ED[i][j] = j;
      else if (j == 0)
        ED[i][j] = i;
      else
      {
        int d1, d2, d3;
        d1 = ED[i-1][j] + 1;
        d2 = ED[i][j-1] + 1;
        d3 = (str1[i-1] == str2[j-1]) ? ED[i-1][j-1] : ED[i-1][j-1] + 1;

        ED[i][j] = min(min(d1,d2),d3);
      }
      
    }
  }

  // for(int j=0; j <= str2.length(); j++)
  // {
  //   if(j == 0)
  //     std::cout << "      ";
  //   else
  //     std::cout << str2[j-1] << " ";

  //   if(j == str2.length())
  //   std::cout <<"\n";
  // }

  // for(int i=0; i <= str1.length(); i++)
  // {
  //   if(i == 0)
  //     std::cout << "  : ";
  //   else
  //     std::cout << str1[i-1] << " : ";
  //   for(int j=0; j <= str2.length(); j++)
  //   {
  //     std::cout << ED[i][j] << " ";
  //   }
  //   std::cout << "\n";
  // }

  return ED[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
