#include <iostream>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <vector>
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
    void merge(vector<T> &data, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<T> v1(n1);
        vector<T> v2(n2);
        for (int i = 0; i < n1; ++i)
            v1[i] = data[i + l];
        for (int i = 0; i < n2; ++i)
            v2[i] = data[mid + i + 1];
        int k = l, i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (v1[i] < v2[j])
                data[k] = v1[i++];
            else
                data[k] = v2[j++];
            k++;
        }
        while (i < n1)
            data[k++] = v1[i++];
        while (j < n2)
            data[k++] = v2[j++];
    }

    template <typename T>
    void merge_sort(vector<T> &data, int n, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        merge_sort(data, n, l, mid);
        merge_sort(data, n, mid + 1, r);
        merge(data, l, mid, r);
    }
    template<typename T>
    void call_merge(vector<T>&arr, int n) { merge_sort(arr, n, 0, n - 1); };

    template <typename T>
    void shell_sort(vector<T> &data, int n)
    {
        for (int i = n / 2, j; i >= 1; i /= 2)
        {
            for (int k = 0, j; k < n; k += i)
            {
                T tmp = data[k];
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

    void count_sort(vector<int> &data, int n)
    {
        int max = *max_element(data.begin(), data.end());
        int min = *min_element(data.begin(), data.end());

        vector<int> res(n);
        vector<int> c(max - min + 1);

        for (int i = 0; i < data.size(); i++)
            c[data[i] - min]++;

        for (int i = 1; i < c.size(); i++)
            c[i] += c[i - 1];

        for (int i = data.size() - 1; i >= 0; i--)
        {
            res[c[data[i] - min] - 1] = data[i];
            c[data[i] - min]--;
        }

        data = res;
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
