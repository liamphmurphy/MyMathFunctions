#include <stdio.h>
#include <unistd.h>
#include <math.h>

struct QuadraticAnswers {
    double quadraticPlus;
    double quadraticMinus;
};

double radians(double degrees) {
    double const pi = 3.14159265359;
    double radians;

    radians = (pi/180) * degrees;
    return radians;
}

double degrees(double radians) {
    double const pi = 3.14159265359;
    double degrees;

    degrees = (180/pi) * radians;
    return degrees;
}

// Could have used standard pow function, but wanted to write my own for practice
double mypow(int base, int power) {
    int newBase = 0;
    int valuePow = 0;

    if (power == 2) {
        valuePow = base * base;
    } else {
        for (int x = 0; x < power - 1; x = x + 1) {
            if (newBase == 0) {
                newBase = base * base;
            } else {
                newBase = newBase * base;
                valuePow = newBase;
            }
        }
    }

    return valuePow;
}

int myabs(int num) {
    if (num < 0) {
        num = num * -1;
    }
    return num;
}

// Uses the quadratic formula to find all possible x values
struct QuadraticAnswers solveQuadratic(double a, double b, double c) {
    struct QuadraticAnswers r;
    double formulaPlus = ((b * -1) + sqrt(mypow(b, 2) - (4 * a * c))) / (2 * a);
    double formulaMinus = ((b * -1) - sqrt(mypow(b, 2) - (4 * a * c))) / (2 * a);

    r.quadraticPlus = formulaPlus;
    r.quadraticMinus = formulaMinus;
    
    return r;
}

int main() 
{
    /* Radians to degrees
    printf("%lf degrees", degrees(0.89));
    */

    /* Degrees to radians
    printf("%lf radians", radians(90));
    */

    /* Absolute value
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    int value = myabs(x);
    printf("value: %d", value);
    */

    /* Quadratic Formula
    double a, b, c;
    printf("enter a: ");
    scanf("%lf", &a);
    printf("enter b: ");
    scanf("%lf", &b);
    printf("enter c: ");
    scanf("%lf", &c);
    
    struct QuadraticAnswers value = solveQuadratic(a, b, c);
    printf("x plus is: %lf", value.quadraticPlus);
    printf("\nand x minus: %lf", value.quadraticMinus);
    //printf("value: %d", value); 
    */

    return 0;
}