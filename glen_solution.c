#include <stdio.h>

int main(int argc, char **argv)
{

    int input_array[] = {11, 2, 10, 4, 5, 6, 7, 8, 1, 9};

    size_t num_elements = sizeof(input_array) / sizeof(input_array[0]);

    if (num_elements == 0) {
        printf("empty input array\n");
    } else if (num_elements == 1) {
        printf("input array only has one element\n");
    } else {
        int sum = 0;
        int expected_sum = 0;
        int min = input_array[0];
        int max = input_array[0];

        for (int i = 0; i < num_elements; i++) {
            sum += input_array[i];

            if (input_array[i] < min) {
                min = input_array[i];
            } else if (input_array[i] > max) {
                max = input_array[i];
            }
        }

        expected_sum = (num_elements + 1) * (min + max) / 2;
        printf("missing number: %d\n", expected_sum - sum);
    }   
    return 0;
}