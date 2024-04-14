#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Heap Sort";

template<class T>
void heapify(std::vector<T> &array, int n, int i, int l) {
    int largest = i; 
    int left = 2 * i + 1 - l; 
    int right = 2 * i + 2 - l; 

    // If left child is larger than root
    if (left < n && array[l + left] > array[l + largest])
        largest = left;

    // If right child is larger than largest 
    if (right < n && array[l + right] > array[l + largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(array[l + i], array[l + largest]);

      
        heapify(array, n, largest, l);
    }
}
template<class T>
void sort(std::vector<T> &array, int l, int r) {
    int n = r - l + 1;
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i, l);

   
    for (int i = n - 1; i > 0; i--) {
        
        std::swap(array[l], array[l + i]);

       
        heapify(array, i, 0, l);
    }
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
