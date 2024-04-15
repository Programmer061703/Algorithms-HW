#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template<class T>
void merge(std::vector<T>& array, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary vectors
    std::vector<T> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    // Merge the temp vectors back into array[l..r]
    int i = 0; 
    int j = 0; 
    int k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Sort first and second halves
        sort(array, l, m);
        sort(array, m + 1, r);

        // Merge the sorted halves
        merge(array, l, m, r);
    }
}

template void sort(std::vector<Edge> &array, int l, int r);
template void sort(std::vector<int> &array, int l, int r);

