#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l < r) {
        // Partitioning index
        T pivot = array[r];
        int i = (l - 1);

        for (int j = l; j <= r - 1; j++) {
            // If current element is smaller than the pivot
            if (array[j] < pivot) {
                i++;    // increment index of smaller element
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[r]);

        // Recursively sort elements before
        // partition and after partition
        int pi = i + 1;
        sort(array, l, pi - 1);
        sort(array, pi + 1, r);
    }
}

template void sort(std::vector<Edge> &array, int l, int r);
template void sort(std::vector<int> &array, int l, int r);

