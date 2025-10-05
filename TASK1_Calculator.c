// CodeAlpha_Task1_Calculator.c
#include <stdio.h>

int main() {
    double num1, num2, result;
    int choice;

    printf("===== SIMPLE CALCULATOR =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            if(num2 != 0)
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1/num2);
            else
                printf("Error! Division by zero not allowed.\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
