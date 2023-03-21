#include <iostream>
#include <random>
#include <chrono>
using namespace std;
namespace sortlib{
    template <typename T>
    void insertion_sort(T arr[] ,int n ) {
            for(int i = 1 ;i<n ;i++){
                T tmp = arr[i];
                for(int j = i ; j>0 && arr[j] <arr[j-1] ; j-- ){
                    T t = arr[j] ;
                    arr[j] = arr[j-1] ;
                    arr[j-1] = t ;
                }
            }
    }

    template<typename T >
    int partition (T arr[] ,int l ,int r) {
        T pivot = arr[l] ;
        int i = l+1 , j =r ;
        while(i<j){
            if (arr[i] > pivot){
                if (arr[j]<=pivot){
                    std::swap(arr[i] ,arr[j]) ;
                    i++,j--;
                }
                else
                    j--;
            }
            else
                i++;
        }
        std::swap(arr[l] , arr[i-1]);
        return i-1;
    }

    template<typename T>
    void quick_sort(T arr[] ,int l ,int r ) {
        if (l >= r)
            return;
        int mid = partition(arr ,l ,r) ;
        quick_sort(arr , l , mid-1) ;
        quick_sort(arr , mid+1 , r) ;
    }
    template<typename T>

    void call_quick(T arr[] ,int n){ quick_sort(arr , 0 ,n-1); } ;

    void calc_time(void (*sort)( int arr[] , int n) , int size ) {

        default_random_engine generator;
        uniform_int_distribution<int> distribution(1, 1000);
        vector<int> array_sizes = {200, 500, 1000, 5000};
        for (auto size : array_sizes)
        {
            double total_time = 0;
            int num_runs = 10;
            for (int i = 0; i < num_runs; i++)
            {
                int arr[size];
                for (int j = 0; j < size; j++)
                {
                    arr[j] = (distribution(generator));
                }
                auto start_time = std::chrono::high_resolution_clock::now();
                sort(arr, size);
                auto end_time = std::chrono::high_resolution_clock::now();
                double run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                total_time += run_time;
            }
            double avg_time = total_time / num_runs;
            cout << "Average time for array size " << size << " is " << avg_time << " ms" << std::endl;
        }
    }

    void calc_time(void (*sort)(vector<int>&arr, int n), int size)
    {

        default_random_engine generator;
        uniform_int_distribution<int> distribution(1, 1000);
        vector<int> array_sizes = {200, 500, 1000, 5000};
        for (auto size : array_sizes)
        {
            double total_time = 0;
            int num_runs = 10;
            for (int i = 0; i < num_runs; i++)
            {
                vector<int> arr(size);
                for (int j = 0; j < size; j++)
                {
                    arr[j] = (distribution(generator));
                }
                auto start_time = std::chrono::high_resolution_clock::now();
                sort(arr, size);
                auto end_time = std::chrono::high_resolution_clock::now();
                double run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                total_time += run_time;
            }
            double avg_time = total_time / num_runs;
            cout << "Average time for array size " << size << " is " << avg_time << " ms" << std::endl;
        }
    }
    template <typename T>
    void shell_sort(vector<T> &data, int n)
    {
        for (int i = n / 2, j; i >= 1; i /= 2)
        {
            for (int k = 0, j; k < n; k += i)
            {
                int tmp = data[k];
                for (j = k; j > 0 && tmp < data[j - i]; j -= i)
                    data[j] = data[j - i];
                data[j] = tmp;
            }
        }
    }

    template <class T>
    void SelectionSort(vector<T> &v, int n)
    {
        T i = 0, j = 0, mn = v[0], indx = 0;
        while (i < n)
        {
            j = i;
            mn = v[i];
            indx = i;
            while (j < n)
            {
                if (mn > v[j])
                {
                    mn = v[j];
                    indx = j;
                }
                j++;
            }
            swap(v[i], v[indx]);
            i++;
        }
    }

    template <class T>
    void BubbleSort(vector<T> &v, int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
            {
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
            }
    }

    template <typename T>
    void print_array(const vector<T> &data, int n)
    {
        for (T it : data)
            cout << it << " ";
        cout << endl;
    }
    template <typename T>
    void print_array(T data[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
}
