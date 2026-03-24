#include <stdio.h>

int main()
{
    int arr[] = {10, 18, 23, 35, 49, 57, 81, 95, 108};
    int sum = 0, i, l = 9, max = arr[0], min = arr[0];
    float avg;

    // Calculate sum
    for(i = 0; i < l; i++)
    {
        sum = sum + arr[i];
    }

    printf("Sum of the array is: %d\n", sum);

    // Calculate average
    avg = (float)sum / l;
    printf("Average of the array is: %.2f\n", avg);

    // Find max and min
    for(i = 1; i < l; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
