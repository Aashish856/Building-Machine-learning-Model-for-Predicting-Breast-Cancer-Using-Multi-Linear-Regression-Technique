# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
    int N;
    cout << "Enter the value of N" << '\n';
    cin >> N;
    cout << '\n';
    float Y[N];  // Dependent variable.
    float A[N], E[N], F[N], G[N];  // Introduced a list of 4 independent variables involved in Breast Cancer prediction.

    cout << "Enter the Mean_Radius values : " << '\n';
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << '\n';
    cout << "Enter the Mean_Smoothness values : " << '\n';
    for (int i = 0; i < N; i++)
    {
        cin >> E[i];
    }
    cout << '\n';
    cout << "Enter the Mean_Compactness values : " << '\n';
    for (int i = 0; i < N; i++)
    {
        cin >> F[i];
    }
    cout << '\n';
    cout << "Enter the Mean_Concave_Points values : " << '\n';
    for (int i = 0; i < N; i++)
    {
        cin >> G[i];
    }
    cout << '\n';
    cout << "Enter the Mean_Concavity values : " << '\n';
    for (int i = 0; i < N; i++)
    {
        cin >> Y[i];
    }
    cout << '\n';
    float M[5][5];  // Introduced a matrix M[5][5].
    M[0][0] = N;  // Initialising the 1st element of matrix M.
    // Determining the other elements of matrix M[5][5]; 
    float sum1 = 0, sum5 = 0, sum6 = 0, sum7 = 0;
    for (int i = 0; i < N; i++)
    {
        sum1 = sum1 + A[i];
        sum5 = sum5 + E[i];
        sum6 = sum6 + F[i];
        sum7 = sum7 + G[i];
    }
    float L0[4] = {sum1,sum5,sum6,sum7};
    float a0 = 0, a1 = 0, a5 = 0, a6 = 0, a7 = 0;
    for (int i = 0; i < N; i++)
    {
        a0 = a0 + A[i];
        a1 = a1 + A[i]*A[i];
        a5 = a5 + A[i]*E[i];
        a6 = a6 + A[i]*F[i];
        a7 = a7 + A[i]*G[i];
    }
    float L1[5] = {a0,a1,a5,a6,a7};
    float e0 = 0, e1 = 0, e5 = 0, e6 = 0, e7 = 0;
    for (int i = 0; i < N; i++)
    {
        e0 = e0 + E[i];
        e1 = e1 + E[i]*A[i];
        e5 = e5 + E[i]*E[i];
        e6 = e6 + E[i]*F[i];
        e7 = e7 + E[i]*G[i];
    }
    float L5[5] = {e0,e1,e5,e6,e7};
    float f0 = 0, f1 = 0, f5 = 0, f6 = 0, f7 = 0;
    for (int i = 0; i < N; i++)
    {
        f0 = f0 + F[i];
        f1 = f1 + F[i]*A[i];
        f5 = f5 + F[i]*E[i];
        f6 = f6 + F[i]*F[i];
        f7 = f7 + F[i]*G[i];
    }
    float L6[5] = {f0,f1,f5,f6,f7};
    float g0 = 0, g1 = 0, g5 = 0, g6 = 0, g7 = 0;
    for (int i = 0; i < N; i++)
    {
        g0 = g0 + G[i];
        g1 = g1 + G[i]*A[i];
        g5 = g5 + G[i]*E[i];
        g6 = g6 + G[i]*F[i];
        g7 = g7 + G[i]*G[i];
    }
    float L7[5] = {g0,g1,g5,g6,g7};
    float Sum0 = 0, Sum1 = 0, Sum5 = 0, Sum6 = 0, Sum7 = 0;
    for (int i = 0; i < N; i++)
    {
        Sum0 = Sum0 + Y[i];
        Sum1 = Sum1 + Y[i]*A[i];
        Sum5 = Sum5 + Y[i]*E[i];
        Sum6 = Sum6 + Y[i]*F[i];
        Sum7 = Sum7 + Y[i]*G[i];
    }
    float Z[5] = {Sum0,Sum1,Sum5,Sum6,Sum7};  // Z[5] is Y matrix in RHS of matrix eqn A * x = Y. Here A is 'M' and x is 'v'
    
    for (int i = 1; i < 5; i++)
    {
        M[i][0] = L0[i-1];
    }
    for (int i = 0; i < 5; i++)
    {
        M[i][1] = L1[i];
        M[i][2] = L5[i];
        M[i][3] = L6[i];
        M[i][4] = L7[i];
    }
    // Solving the equations by Gauss Elimination Method :
    int p;
    int n = 5;
    float Big, dummy;
    for (int k = 0; k < n-1; k++)
    {
        p = k;
        Big = abs(M[k][k]);
        for (int i = k+1; i < n; i++)
        {
            dummy = abs(M[i][k]);
            if (dummy > Big)
            {
                Big = dummy;
                p = i;
            }
        }

        if (p != k)
        {
            for (int j = k; j < n; j++)
            {
                dummy = M[p][j];
                M[p][j] = M[k][j];
                M[k][j] = dummy;
            }
            dummy = Z[p];
            Z[p] = Z[k];
            Z[k] = dummy;
        }

        if (M[k][k] != 0)
        {
            for (int i = k+1; i < n; i++)
            {
                float temp = M[i][k];
                for (int j = k; j < n; j++)
                {
                    M[i][j] = M[i][j] - temp / M[k][k] * M[k][j];
                }
                Z[i] = Z[i] - temp / M[k][k] * Z[k];
            }
        }   
    }
    float v[n];  // v[n] is an array of regression equation coefficients(vi's).
    for (int i = n-1; i >= 0; i--)
    {
        float p1 = Z[i];
        for (int j = i+1; j < n; j++)
        {
            p1 -= M[i][j] * v[j];
        }
        v[i] = p1 / M[i][i]; 
    }
    cout << "Regression Equation coefficients are : " << '\n' << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(9) << "v" << i << " = " << v[i] << '\n';
    }
    cout << '\n' << '\n';

    // Now calculating predicted Y :
    float Y_pred[N];
    for (int i = 0; i < N; i++)
    {
        Y_pred[i] = v[0] + v[1]*A[i] + v[2]*E[i] + v[3]*F[i] + v[4]*G[i]; 
    }
    cout << "Predicted values of Y are :" << '\n' << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << fixed << setprecision(15) << "Y_pred[" << i << "]" << " = " << Y_pred[i] << '\n'; 
    }
    cout << '\n' << '\n';

    // Now calculating the error in actual and predicted values of Y :
    float Err;
    cout << "Errors in actual and predicted values of Y are : " << '\n' << '\n';
    for (int i = 0; i < N; i++)
    {
        Err = abs(Y[i] - Y_pred[i]);
        cout << fixed << setprecision(15) << "Err in Y[" << i << "] = " << Err <<'\n';
    }
    return 0;
}