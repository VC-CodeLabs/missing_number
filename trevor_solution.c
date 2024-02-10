#include <stdio.h>

#define SIZEOF(a) sizeof(a)/sizeof(*a)

int missing_number(int nums[], int len) {
  int a = nums[0], c = 0;
  for (int i = 0; i < len; i++) {
    if (nums[i] < a) {
      a = nums[i];
    }
    c += nums[i];
  }
  return ((2 * a + len) * (len + 1) / 2 - c);
}

int main(void) {

  int nums1[] = {3, 7, 1, 2, 8, 4, 5};
  int nums2[] = {11, 2, 10, 4, 5, 6, 7, 8, 1, 9};
  int nums3[] = {4, 3, 1, 5};
  int nums4[] = {23, 24, 22, 26, 28, 21, 20, 27, 19, 32, 31, 30, 29};

  printf("Missing number is %d\n", missing_number(nums1, SIZEOF(nums1)));
  printf("Missing number is %d\n", missing_number(nums2, SIZEOF(nums2)));
  printf("Missing number is %d\n", missing_number(nums3, SIZEOF(nums3)));
  printf("Missing number is %d\n", missing_number(nums4, SIZEOF(nums4)));
  
  return 0;
}
