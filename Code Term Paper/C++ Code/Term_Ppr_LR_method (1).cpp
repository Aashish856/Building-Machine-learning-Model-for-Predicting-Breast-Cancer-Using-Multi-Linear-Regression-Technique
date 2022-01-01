# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
    int N1, N5, N6, N7;  // No. of datapoints for each independent and dependent variable.
    cout << "Enter the value of N for Mean Radius" << '\n';
    cin >> N1;
    cout << '\n';
    cout << "Enter the value of N for Mean Smoothness" << '\n';
    cin >> N5;
    cout << '\n';
    cout << "Enter the value of N for Mean Compactness" << '\n';
    cin >> N6;
    cout << '\n';
    cout << "Enter the value of N for Mean Concave Points" << '\n';
    cin >> N7;
    cout << '\n';
    double Y1[N1], Y5[N5], Y6[N6], Y7[N7];  // Introduced 4 Dependent variables.
    double X1[N1], X5[N5], X6[N6], X7[N7];  // Introduced 4 Independent variables.

    // Storing all the data points :
    cout << "Enter the X values corresponding to Mean_Radius values : " << '\n';
    for (int i = 0; i < N1; i++)
    {
        cin >> X1[i];
    }
    cout << '\n';
    cout << "Enter the Y values corresponding to Mean_Radius values : " << '\n';
    for (int i = 0; i < N1; i++)
    {
        cin >> Y1[i];
    }
    cout << '\n';
    cout << "Enter the X values corresponding to Mean_Smoothness values : " << '\n';
    for (int i = 0; i < N5; i++)
    {
        cin >> X5[i];
    }
    cout << '\n';
    cout << "Enter the Y values corresponding to Mean_Smoothness values : " << '\n';
    for (int i = 0; i < N5; i++)
    {
        cin >> Y5[i];
    }
    cout << '\n';
    cout << "Enter the X values corresponding to Mean_Compactness values : " << '\n';
    for (int i = 0; i < N6; i++)
    {
        cin >> X6[i];
    }
    cout << '\n';
    cout << "Enter the Y values corresponding to Mean_Compactness values : " << '\n';
    for (int i = 0; i < N6; i++)
    {
        cin >> Y6[i];
    }
    cout << '\n';
    cout << "Enter the X values corresponding to Mean_Concave_Points values : " << '\n';
    for (int i = 0; i < N7; i++)
    {
        cin >> X7[i];
    }
    cout << '\n';
    cout << "Enter the Y values corresponding to Mean_Concave_Points values : " << '\n';
    for (int i = 0; i < N7; i++)
    {
        cin >> Y7[i];
    }
    cout << '\n' << '\n';

    double s1 = 0,s_1 = 0, s9 = 0,s_9 = 0, s11 = 0,s_11 = 0, s13 = 0,s_13 = 0;
    double s2,s_2, s10,s_10, s12,s_12, s14,s_14;  // each represents average of all data points of particular independent and dependent variable.
    for (int j = 0; j < N1; j++)
    {
        s1 = s1 + X1[j];
        s_1 = s_1 + Y1[j];
    }
    s2 = s1 / N1;
    s_2 = s_1 / N1;

    for (int j = 0; j < N5; j++)
    {
        s9 = s9 + X5[j];
        s_9 = s_9 + Y5[j];
    }
    s10 = s9 / N5;
    s_10 = s_9 / N5;

    for (int j = 0; j < N6; j++)
    {
        s11 = s11 + X6[j];
        s_11 = s_11 + Y6[j];
    }
    s12 = s11 / N6;
    s_12 = s_11 / N6;

    for (int j = 0; j < N7; j++)
    {
        s13 = s13 + X7[j];
        s_13 = s_13 + Y7[j];
    }
    s14 = s13 / N6;
    s_14 = s_13 / N6;

    double a[2], e[2], f[2], g[2];  // Arrays of Regression equation coefficients for 4 variables.
    double sum1 = 0,sum2 = 0, sum9 = 0,sum10 = 0, sum11 = 0,sum12 = 0, sum13 = 0,sum14 = 0;
    double Y1_pred[N1], Y5_pred[N5], Y6_pred[N6], Y7_pred[N7]; // Predicted values of Y for all 4 variables.
    // Calculation of Mean Radius :
    for (int i = 0; i < N1; i++)
    {
        sum1 = sum1 + (X1[i] - s2) * (Y1[i] - s_2);
        sum2 = sum2 + (X1[i] - s2) * (X1[i] - s2); 
    }
    a[1] = sum1 / sum2;
    a[0] = s_2 - a[1] * s2;
    cout << "Regression Equation coefficients of Mean Radius are : " << '\n' << '\n';
    cout << fixed << setprecision(9) << "a0 = " << a[0] << "     " << "a1 = " << a[1] << '\n' << '\n';
    // Now calculating predicted Y :
    cout << "Predicted values of Y for Mean Radius are : " << '\n' << '\n';
    for (int i = 0; i < N1; i++)
    {
        Y1_pred[i] = a[0] + a[1]*X1[i];
        cout << fixed << setprecision(15) << "Y_pred[" << i << "] = " << Y1_pred[i] << '\n'; 
    }
    cout << '\n' << '\n';
    // Calculation of Mean Smoothness :
    for (int i = 0; i < N5; i++)
    {
        sum9 = sum9 + (X5[i] - s10) * (Y5[i] - s_10);
        sum10 = sum10 + (X5[i] - s10) * (X5[i] - s10);
    }
    e[1] = sum9 / sum10;
    e[0] = s_10 - e[1] * s10;
    cout << "Regression Equation coefficients of Mean Smoothness are : " << '\n' << '\n';
    cout << fixed << setprecision(9) << "e0 = " << e[0] << "     " << "e1 = " << e[1] << '\n' << '\n';
    // Now calculating predicted Y :
    cout << "Predicted values of Y for Mean Smoothness are : " << '\n' << '\n';
    for (int i = 0; i < N5; i++)
    {
        Y5_pred[i] = e[0] + e[1]*X5[i];
        cout << fixed << setprecision(15) << "Y_pred[" << i << "] = " << Y5_pred[i] << '\n';
    }
    cout << '\n' << '\n';
    // Calculation of Mean Compactness :
    for (int i = 0; i < N6; i++)
    {
        sum11 = sum11 + (X6[i] - s12) * (Y6[i] - s_12);
        sum12 = sum12 + (X6[i] - s12) * (X6[i] - s12); 
    }
    f[1] = sum11 / sum12;
    f[0] = s_12 - f[1] * s12;
    cout << "Regression Equation coefficients of Mean Compactness are : " << '\n' << '\n';
    cout << fixed << setprecision(9) << "f0 = " << f[0] << "     " << "f1 = " << f[1] << '\n' << '\n';
    // Now calculating predicted Y :
    cout << "Predicted values of Y for Mean Compactness are : " << '\n' << '\n';
    for (int i = 0; i < N6; i++)
    {
        Y6_pred[i] = f[0] + f[1]*X6[i];
        cout << fixed << setprecision(15) << "Y_pred[" << i << "] = " << Y6_pred[i] << '\n';
    }
    cout << '\n' << '\n';
    // Calculation of Mean Concave Point :
    for (int i = 0; i < N7; i++)
    {
        sum13 = sum13 + (X7[i] - s14) * (Y7[i] - s_14);
        sum14 = sum14 + (X7[i] - s14) * (X7[i] - s14);
    }
    g[1] = sum13 / sum14;
    g[0] = s_14 - g[1] * s14;
    cout << "Regression Equation coefficients of Mean Concave Point are : " << '\n' << '\n';
    cout << fixed << setprecision(9) << "g0 = " << g[0] << "     " << "g1 = " << g[1] << '\n' << '\n';
    // Now calculating predicted Y :
    cout << "Predicted values of Y for Mean Concave Point are : " << '\n' << '\n';
    for (int i = 0; i < N7; i++)
    {
        Y7_pred[i] = g[0] + g[1]*X7[i];
        cout << fixed << setprecision(15) << "Y_pred[" << i << "] = " << Y7_pred[i] << '\n';
    }
    return 0;
}