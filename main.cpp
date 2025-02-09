#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int* shuffle_one(int array[], int size) {
    int* copy = new int[size];
    int n = size;
    int i;
 
    std::copy(array, array + size, copy);

    while (n > 0) {
        i = rand() % n;

        std::swap(copy[i], copy[n - 1]);
        n--;
    }
    
    return copy;
}

int* shuffle_two(int array[], int size){
    int* copy = new int[size];
    std::copy(array, array + size, copy);

    int n = size;
    while (n > 1) {
        int i = rand() % n;
        std::swap(copy[i], copy[n - 1]);
        n--;
    }

    return copy;
}

int* shuffle_three(int array[], int size){
    int* copy = new int[size];
    std::copy(array, array + size, copy);

    int m = size;
    int t;
    while (m > 0){
        int i = rand() % m;
        t = copy[m - 1];
        copy[m - 1] = copy[i];
        copy[i] = t;
        m--;
    }

    return copy;
}

void print_array(int array[], int size, bool shuffled_state) {
    if (shuffled_state == 0) {
        cout << "Original array: ";
    } else {
        cout << "Shuffled array: ";
    }
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i != size -1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    srand(time(0));

    int array1[] = {1, 2, 3, 4};
    int array2[] = {1, 2, 2, 3, 3, 4};
    int array3[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int array4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    int size4 = sizeof(array4) / sizeof(array4[0]);

    for (int i = 0; i < 4; i++) {
        int* shuffled1 = shuffle_one(array1, size1);
        print_array(array1, size1, 0);  
        print_array(shuffled1, size1, 1); 
        delete[] shuffled1;

        int* shuffled2 = shuffle_one(array2, size2);
        print_array(array2, size2, 0); 
        print_array(shuffled2, size2, 1);  
        delete[] shuffled2;

        int* shuffled3 = shuffle_one(array3, size3);
        print_array(array3, size3, 0);  
        print_array(shuffled3, size3, 1);  
        delete[] shuffled3;

        int* shuffled4 = shuffle_one(array4, size4);
        print_array(array4, size4, 0);
        print_array(shuffled4, size4, 1);  
        delete[] shuffled4;
    }

    for (int i = 0; i < 4; i++) {
        int* shuffled5 = shuffle_two(array1, size1);
        print_array(array1, size1, 0); 
        print_array(shuffled5, size1, 1); 
        delete[] shuffled5;

        int* shuffled6 = shuffle_two(array2, size2);
        print_array(array2, size2, 0);  
        print_array(shuffled6, size2, 1);  
        delete[] shuffled6;

        int* shuffled7 = shuffle_two(array3, size3);
        print_array(array3, size3, 0);  
        print_array(shuffled7, size3, 1);  
        delete[] shuffled7;

        int* shuffled8 = shuffle_two(array4, size4);
        print_array(array4, size4, 0);  
        print_array(shuffled8, size4, 1);  
        delete[] shuffled8;
    }

    for (int i = 0; i < 4; i++) {
        int* shuffled9 = shuffle_three(array1, size1);
        print_array(array1, size1, 0);  
        print_array(shuffled9, size1, 1); 
        delete[] shuffled9;

        int* shuffled10 = shuffle_three(array2, size2);
        print_array(array2, size2, 0); 
        print_array(shuffled10, size2, 1);  
        delete[] shuffled10;

        int* shuffled11 = shuffle_three(array3, size3);
        print_array(array3, size3, 0); 
        print_array(shuffled11, size3, 1);  
        delete[] shuffled11;

        int* shuffled12 = shuffle_three(array4, size4);
        print_array(array4, size4, 0); 
        print_array(shuffled12, size4, 1);  
        delete[] shuffled12;
    }
    
    cout << "All shuffling is complete!" << endl;
    return 0;
}