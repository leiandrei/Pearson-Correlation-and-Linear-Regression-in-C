# Pearson Correlation and Linear Regression in C

## Technologies Used:
- 🌐 C Language
- ✅ GNUPlot
- ✅ Standard Math Library (math.h)

This is a **C-Based Language** Pearson Correlation Co-efficient Analyser and Linear Regresion Model made from scratch using C concepts such as: Dynamic Structs and Arrays, Functions, and such. It performs both inferential statistics and analysis using Pearson Correlation and Linear Regression. In addition, allowing users to plot and visualize their statistical analysis using GNUPlot.

## ✅ Pearson Correlation Co-efficient Formula
This is the **Karl Pearson's Correlation Co-efficient** formula that was used for this model.
<img width="600" height="432" alt="image" src="https://github.com/user-attachments/assets/c42393a2-3821-45cd-aac4-caf9318ea7fb" />

## ✅ Linear Regression Formula
This is the Linear Regression formula for this model. The regression model uses an **OLS (Ordinary Least Squares) Regression Analysis**. This analysis aims to create a linear equation to describe relationships between variables. (from **GeeksforGeeks**)
<img width="600" height="432" alt="image" src="https://github.com/user-attachments/assets/960a4a71-2103-48ec-8c7b-831e4af42282" />
- 📌 This model uses the **y = mx + b** formula.
- 📌 **Dependent Variable: Y**
- 📌 **Independent Variable: X**
- 📌 Includes Statistical Data Metrics: **Mean Squared Error**, **Total Sum of Squares**, **Residual Sum of Squares**, and **Co-efficient of Determinants**.

## Features
- 📌 Uses Dynamic Structs to hold specific data values.
- 📌 Allows users to input variables and data values.
- 📌 Clear console output

## Further Improvements:
- 📌 Implementation of File Handling.
- 📌 Implementation of Multiple Regression Analysis.
- 📌 Allowing users to input CSV files.

## 💻 Test Run: Input
```text
Enter a number of values for both x & y values: 5

Enter the (X - Independent Variable) to be tested: Study Hours
Enter the (Y - Dependent Variable) to be tested: Exam Score

Enter values for Independent Variable (X):
Value #1: 2
Value #2: 3
Value #3: 4
Value #4: 5
Value #5: 6

Enter values for Dependent Variable (Y):
Value #1: 65
Value #2: 70
Value #3: 75
Value #4: 80
Value #5: 85

Enter x-input to predict y using regression: 7

```
## 💻 Test Run: Output
```text
=== Correlation Co-efficient Results ===

Independent Variable (x): Study Hours
Dependent Variable (y): Exam Score

Pearson Correlation Co-efficient: 1.00
Correlation Type: Both x and y values have a positive correlation
Degree of Relationship: Perfect Correlation

=== Linear Regression ===

Regression Line: y = 5.000x + 55.000
Predicted Regression for Y as X = 7.000: 90.000

=== Data Metrics ===

Mean Squared Error: 0.00
Total Sum of Squares: 250.00
Residual Sum of Squares: 0.00
Co-efficient of Determination: 1.00

```
## 📈 Test Run: Linear Regression Plot using GNUPlot
