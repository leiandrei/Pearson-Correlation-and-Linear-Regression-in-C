#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Pearson Correlation Co-efficient Program
// Using Structs and Dynamic Memory
// Sample Program for Statistics

typedef struct {
    float data;
} Values;

float correlation(Values *x, Values *y, int num);
char *relationship_degree(float r_coefficient);

int main()
{
    int num;

    printf("Enter a number of values for both x & y values: ");
    scanf("%d", &num);

    Values *x = malloc(num * sizeof(Values));
    Values *y = malloc(num * sizeof(Values));

    if (!x || !y) {
        perror("Memory Allocation Failed");
        return 1;
    }

    printf("\nEnter values for Independent Variable (X):\n");
    for (int i = 0; i < num; i++) {
        printf("Value #%d: ", i + 1);
        scanf("%f", &x[i].data);
    }

    printf("\nEnter values for Dependent Variable (Y):\n");
    for (int i = 0; i < num; i++) {
        printf("Value #%d: ", i + 1);
        scanf("%f", &y[i].data);
    }

    float r = correlation(x, y, num);

    printf("\nPearson Correlation Co-efficient: %f\n", r);

    if (r > 0) {
        printf("Both x and y values have a positive correlation\n");
    } else if (r < 0) {
        printf("Both x and y values have a negative correlation\n");
    } else {
        printf("No linear correlation\n");
    }

    printf("Degree of Relationship: %s\n", relationship_degree(r));

    free(x); free(y);
    return 0;
}

float correlation(Values *x, Values *y, int n)
{
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;

    float numerator, denominator;

    for (int i = 0; i < n; i++) {
        float x_idx = x[i].data;
        float y_idx = y[i].data;

        sum_x += x_idx;
        sum_y += y_idx;
        sum_xy += x_idx * y_idx;
        sum_x2 += x_idx * x_idx;
        sum_y2 += y_idx * y_idx;
    }

    numerator = n * sum_xy - sum_x * sum_y;
    denominator = sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));

    return numerator / denominator;
}

char *relationship_degree(float r_coefficient)
{
    float r = fabs(r_coefficient);

    if (r == 1.0) {
        return "Perfect Correlation";
    } else if (r >= 0.8) {
        return "High Correlation";
    } else if (r >= 0.4) {
        return "Moderate Correlation";
    } else if (r >= 0.1) {
        return "Low Correlation";
    } else {
        return "Zero Correlation";
    }
}


