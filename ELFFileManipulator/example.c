#include <stdio.h>

int Add_Two_Nums(int x, int y) {
    return x + y;
}
int Multiply_Two_Nums(int x, int y) {
    return x * y;
}
int Factorial(int x) {
    for (int i = x - 1; i > 0 ; i--) {
        x *= i;
    }
    return x;
}

int main() 
{
    int x = 5;
    int y = 7; 
    
    printf("Sum: %d \n",Add_Two_Nums(x, y));
    printf("Product: %d \n", Multiply_Two_Nums(x, y));
    printf("Factorial %d: %d\n", x, Factorial(x));
    printf("Factorial %d: %d\n", y, Factorial(y));

    return 0;
}