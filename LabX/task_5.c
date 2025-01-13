#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int a, b, c, result;

    // Ask the user to input the values
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    printf("Enter the third integer: ");
    scanf("%d", &c);

    // Pass values by reference to the add function
    add(&a, &b, &c, &result);

    // Print the result
    printf("The sum of %d, %d, and %d is: %d\n", a, b, c, result);

    return 0;
}
