#include <stdio.h>
#include <stdlib.h>

int* create_and_expand_array(int initial_size, int new_size) {
    // Allocate memory for the initial array
    int* array = (int*)malloc(initial_size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Initialize the array with some values
    for (int i = 0; i < initial_size; i++) {
        array[i] = i;
    }

    // Reallocate memory to expand the array
    array = (int*)realloc(array, new_size * sizeof(int));
    if (array == NULL) {
        printf("Memory reallocation failed!\n");
        return NULL;
    }

    // Initialize the newly allocated portion of the array
    for (int i = initial_size; i < new_size; i++) {
        array[i] = i;
    }

    // Return the pointer to the dynamically allocated and expanded array
    return array;
}

int main() {
    int initial_size = 5;
    int new_size = 10;

    // Call the function to create and expand the array
    int* my_array = create_and_expand_array(initial_size, new_size);

    if (my_array != NULL) {
        // Print the elements of the array
        for (int i = 0; i < new_size; i++) {
            printf("%d ", my_array[i]);
        }
        printf("\n");

        // Free the allocated memory when done
        free(my_array);
    }

    return 0;
}
