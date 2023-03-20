#include <iostream>

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
    void quick_sort(T arr[] ,int l ,int r) {
        if (l >= r)
            return;
        int mid = partition(arr ,l ,r) ;
        quick_sort(arr , l , mid-1) ;
        quick_sort(arr , mid+1 , r) ;
    }
}
