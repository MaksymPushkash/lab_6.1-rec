#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int SIZE = 27;
const int LOWER_BOUND = -35;
const int UPPER_BOUND = 25;


void generateArray(int arr[], int size) {
    if (size == 0) return; 
    arr[SIZE - size] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND; 
    generateArray(arr, size - 1); 
}


void printArray(const int arr[], int size) {
    if (size == 0) return; 
    std::cout << std::setw(4) << arr[SIZE - size]; 
    printArray(arr, size - 1); 
}


int countElements(const int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return 0; 
    return criteria(arr[SIZE - size]) + countElements(arr, size - 1, criteria); 
}


int sumElements(const int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return 0; // Базовий випадок
    return (criteria(arr[SIZE - size]) ? arr[SIZE - size] : 0) + sumElements(arr, size - 1, criteria); 
}


void replaceWithZero(int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return; 
    if (criteria(arr[SIZE - size])) {
        arr[SIZE - size] = 0; 
    }
    replaceWithZero(arr, size - 1, criteria); 
}


bool isPositive(int num) {
    return num > 0;
}


bool isOdd(int num) {
    return num % 2 != 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int arr[SIZE];

    
    generateArray(arr, SIZE);
    
    
    std::cout << "Згенерований масив: ";
    printArray(arr, SIZE);
    std::cout << std::endl;

    
    int countPos = countElements(arr, SIZE, isPositive);
    int sumPos = sumElements(arr, SIZE, isPositive);
    replaceWithZero(arr, SIZE, isPositive);

    
    std::cout << "Кількість парних елементів: " << countPos << std::endl;
    std::cout << "Сума парних елементів: " << sumPos << std::endl;

    
    std::cout << "Змінений масив після заміни нулями: ";
    printArray(arr, SIZE);
    std::cout << std::endl;

    
    int countOdd = countElements(arr, SIZE, isOdd);
    int sumOdd = sumElements(arr, SIZE, isOdd);
    replaceWithZero(arr, SIZE, isOdd);

    
    std::cout << "Кількість непарних елементів: " << countOdd << std::endl;
    std::cout << "Сума непарних елементів: " << sumOdd << std::endl;

    
    std::cout << "Останній модифікований масив після заміни нулями: ";
    printArray(arr, SIZE);
    std::cout << std::endl;

    return 0;
}
