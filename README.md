# Pearson-Correlation-Co-efficient
Pearson Correlation Co-efficient Program in C using Functions, Structs, and Dynamic Memory.

#Functions

    float correlation(Values *x, Values *y, int num)
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
