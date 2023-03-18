#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
template<class T>
void SelectionSort(vector<T> v, int n);
int main()
{
    vector<int> arr;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 100);

    vector<int> array_sizes = { 200, 500, 1000, 5000, 10000, 20000, 50000 };
    for (auto size : array_sizes) {
        double total_time = 0;
        int num_runs = 10;
        for (int i = 0; i < num_runs; i++) 
        {
            arr.clear();
            for (int j = 0; j < size; j++) 
            {
                arr.push_back(distribution(generator));
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            SelectionSort(arr , arr.size());
            auto end_time = std::chrono::high_resolution_clock::now();
            double run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            total_time += run_time;
        }
        double avg_time = total_time / num_runs;
        cout << "Average time for array size " << size << " is " << avg_time << " ms" << std::endl;
    }
}
template<class T>
void SelectionSort(vector<T> v, int n)
{
    T i = 0, j = 0, mn = v[0], indx = 0;
    while (i < n)
    {
        j = i;
        mn = v[i]; indx = i;
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