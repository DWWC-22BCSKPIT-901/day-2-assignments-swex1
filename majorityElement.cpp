//majority Element
#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = 0, count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Majority Element: %d\n", majorityElement(nums, numsSize));
    return 0;
}
