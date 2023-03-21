#include <iostream>
#include "sortlib.cpp"
using namespace std;

int main(){
    int n = 5;
    cout << "-----------insertion_sort---------------\n";
    int datai[] = {3, 4, -1, 5, 2};
    sortlib::insertion_sort(datai, n);
    sortlib::print_array(datai, n);
    sortlib::calc_time(&(sortlib::insertion_sort), n);
    cout << "-----------selection_sort---------------\n";
    vector<float> dataf = {3.5, 4, 0.32, -5.0, 2.3};
    sortlib::SelectionSort(dataf, n);
    sortlib::print_array(dataf, n);
    sortlib::calc_time(&(sortlib::SelectionSort), n);
    cout << "-----------bubble_sort---------------\n";
    vector<char> datac = {'d', 'e', 'a', 'c', 'b'};
    sortlib::BubbleSort(datac, n);
    sortlib::print_array(datac, n);
    sortlib::calc_time(&(sortlib::BubbleSort), n);
    cout << "-----------shell_sort---------------\n";
    vector<double> datad = {280.78, 0.5, -13, 9, -123.14};
    sortlib::shell_sort(datad, n);
    sortlib::print_array(datad, n);
    sortlib::calc_time(&(sortlib::shell_sort), n);
    cout << "-----------merge_sort---------------\n";
    vector<int> dataii = {5, 200, -24, 0, 1};
    sortlib::merge_sort(dataii, n, 0, n - 1);
    sortlib::print_array(dataii, n);
    sortlib::calc_time(&(sortlib::call_merge), n);
}