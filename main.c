#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Pearson Correlation Co-efficient Program
// Using Structs and Dynamic Memory
// Sample Program for Statistics

typedef struct {
    float data;
} Values;

float correlation(Values *x, Values *y, int n);
char *relationship_degree(float r_coefficient);
void linear_regression(Values *x, Values *y, int x_input, int n);

int main()
{
    int num, x_predict;

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

    printf("\n=== Correlation Co-efficient Results ===\n");

    printf("\nPearson Correlation Co-efficient: %.2f\n", r);

    if (r > 0) {
        printf("Both x and y values have a positive correlation\n");
    } else if (r < 0) {
        printf("Both x and y values have a negative correlation\n");
    } else {
        printf("No linear correlation\n");
    }

    printf("Degree of Relationship: %s\n", relationship_degree(r));

    printf("\nEnter x-input to predict y using regression: ");
    scanf("%d", &x_predict);

    linear_regression(x, y, x_predict, num);

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

void linear_regression(Values *x, Values *y, int x_input, int n)
{
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;

    float m_slope, b_intercept, y_output;

    for (int i = 0; i < n; i++) {
        float x_idx = x[i].data;
        float y_idx = y[i].data;

        sum_x += x_idx;
        sum_y += y_idx;
        sum_xy += x_idx * y_idx;
        sum_x2 += x_idx * x_idx;
        sum_y2 += y_idx * y_idx;
    }

    m_slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    b_intercept = (sum_y - m_slope * sum_x) / n;
    y_output = m_slope * x_input + b_intercept;

    printf("\n=== Linear Regression ===\n");
    printf("\nRegression Line: y = %.3fx + %.3f\n", m_slope, b_intercept);
    printf("\nPredicted Regression for Y as X = %d: %.3f\n", x_input, y_output);
}


