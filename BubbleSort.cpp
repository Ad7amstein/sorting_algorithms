#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
template<class T>
void BubbleSort(vector<T>v, int n);
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
            BubbleSort(arr, arr.size());
            auto end_time = std::chrono::high_resolution_clock::now();
            double run_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            total_time += run_time;
        }
        double avg_time = total_time / num_runs;
        cout << "Average time for array size " << size << " is " << avg_time << " ms" << std::endl;
    }
}
template<class T>
void BubbleSort(vector<T>v, int n)
{

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);

        }
}