#include "GenericArray.h"
#include <iostream>

int main() {
    GenericArray<int> int_array;
    
    for (int i = 0; i < 10; ++i) {
        int_array.addElement(i * 2);
    }

    std::cout << "Size: " << int_array.size() << std::endl;
    std::cout << "Sum: " << int_array.sum() << std::endl;
    std::cout << "Max/Min: " << int_array.max() << "/" << int_array.min() << std::endl;
    
    try {
        int* sliced = int_array.slice(2, 4);
        std::cout << "Slice [2-4]: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << sliced[i] << " ";
        }
        std::cout << std::endl;
        delete[] sliced;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
