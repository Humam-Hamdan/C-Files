#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Points to the first element of the array

    printf("Using pointer to traverse the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Value at arr[%d] = %d, Address = %p\n", i, *(ptr + i), (void*)(ptr + i));
    }

    // Increment the pointer
    ptr++; // Now points to the second element
    printf("\nAfter incrementing the pointer:\n");
    printf("Value = %d, Address = %p\n", *ptr, (void*)ptr);

    return 0;
}
