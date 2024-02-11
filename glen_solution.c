#include <stdio.h>

int main(int argc, char **argv)
{

    int input_array[] = {11, 2, 10, 4, 5, 6, 7, 8, 1, 9};

    size_t size_in_bytes = sizeof(input_array);
    size_t num_elements = 0;

    if (size_in_bytes) {
        num_elements = size_in_bytes / sizeof(input_array[0]);
    }

    int sum = 0;
    int expected_sum = 0;
    int min = input_array[0];
    int max = input_array[0];

    for (int i = 0; i < num_elements; i++) {
        sum += input_array[i];

        if (input_array[i] < min) {
            min = input_array[i];
        }

        if (input_array[i] > max) {
            max = input_array[i];
        }
    }

    expected_sum = (num_elements + 1) * (min + max) / 2;
    printf("missing number: %d\n", expected_sum - sum);

    return 0;
}