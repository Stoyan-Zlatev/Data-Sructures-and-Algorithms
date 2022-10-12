#include <iostream>

const int MAX_SIZE = 1e6;
int arr[MAX_SIZE]{};
int odd[MAX_SIZE]{};
int even[MAX_SIZE]{};

int main()
{
    int n;
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int oddIndex = 0;
    int evenIndex = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2)
            odd[oddIndex++] = arr[i];
        else
            even[evenIndex++] = arr[i];
    }

    for (size_t i = 0; i < evenIndex; i++)
    {
        std::cout<<even[i]<<"\n";
    }
    
    for (size_t i = 0; i < oddIndex; i++)
    {
        std::cout<<odd[i]<<"\n";
    }
}