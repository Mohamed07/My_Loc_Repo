#include <iostream>
#include "math.h"
#include <string>

using namespace std;


int merge_sort(int arr[], int sorted[], int start, int end);
int split_merge(int arr[], int sorted[], int start, int end);


int main(int argc, char * argv[])
{
    if(argc == 1)
    {
        cout << "-Usage: ./merge arr_size array_elements_2b_sorted\n";
    }
    else if(argc - 2 != stoi(argv[1]))
    {
        cout << "-Please provide " << stoi(argv[1]) << " elements\n";
    }
    else
    {
        // Array Size
        int arr_size = stoi(argv[1]);

        // Allocating space for array to be sorted
        int *arr = new int[ arr_size ];
        int *sorted_arr = new int [ arr_size ];

        // Fill the array with the given elements
        for(int i=0; i < arr_size; i++)
            arr[i] = stoi( argv[i+2] );
        
        // sorting and measuring similarity        
        int similarity_measure = merge_sort( arr, sorted_arr, 0, arr_size-1);
        cout << "=============================\n";
        cout << "-Total Num. of Inversions = " << similarity_measure << "\n";

        cout << "=============================\n";
        cout << "-Sorted Array : \n";
        cout << "=============================\n";

        for(int i=0; i < arr_size; i++)
            cout << " " << sorted_arr[i] << " ";
        cout << "\n=============================\n";
    }   

}

int merge_sort(int arr[], int sorted[], int start, int end)
{

    if( end > start )
    {
        int mid = (end + start)/2;
        cout <<"start= " << start << " ,mid = " << mid << " ,end = " << end << "\n";
        int lhs_inv   = merge_sort(arr, sorted, start, mid);
        int rhs_inv   = merge_sort(arr, sorted, mid+1, end);
        int split_inv = split_merge(arr, sorted, start, end);

        return (lhs_inv + rhs_inv + split_inv);
    }
    return 0;
}

int split_merge(int arr[], int sorted[], int start, int end)
{
    int mid = (end + start)/2;

    int i = start, j = mid+1, k = start;
    
    int inversions = 0;
    while( (i <= mid) && (j <= end) )
    {
        if(arr[i] < arr[j])
        {
            sorted[k] = arr[i];
            i++; k++;
        }
        else if (arr[i] > arr[j])
        {
            inversions += (mid+1) - i;
            sorted[k] = arr[j];
            j++; k++;
        }
    }

    while( i <= mid )
    {
        sorted[k] = arr[i];
        i++; k++;
    }

    while( j <= end )
    {
        sorted[k] = arr[j];
        j++; k++;
    }

    for(i = start; i <= end; i++)
       arr[i] = sorted[i];
    return inversions;
}
