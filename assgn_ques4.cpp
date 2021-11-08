#include <iostream>
#include <cstring>

template <typename T>
void print(T* const arr, size_t n)
{
    if(n == 0) { std::cout << "\n"; return; }
    std::cout << *arr << " ";
    print(arr+1, n-1);
}

int main()
{
    int arr[] = { 1,2,3,4,5 };
    const char* arr2[] = { "hello", "there" };
    const char* arr3 = "<FirstNameHere>";
    
    print(arr, sizeof(arr) / sizeof(arr[0]));
    print(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print(arr3, strlen(arr3));
}
