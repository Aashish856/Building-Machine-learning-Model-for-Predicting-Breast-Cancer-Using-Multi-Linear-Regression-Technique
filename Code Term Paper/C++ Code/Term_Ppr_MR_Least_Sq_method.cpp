# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
    // Important :- Note that this method works only if determinant of inverse matrix is non zero.

    int N;
    cout << "Enter the value of N" << '\n';
    cin >> N;
    cout << '\n';
    double Y[N];  // Dependent variable.
    double A[N], E[N], F[N], G[N];  // Introduced a list of 4 independent variables involved in Breast Cancer prediction.

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

    double a[5];  // Array of Regression equation coefficients.
    double X[N][5];  // X matrix of Least Square Method.
    for (int i = 0; i < N; i++)
    {
        X[i][0] = 1;  // Initialised the 1st column of X matrix by entry 1. 
        X[i][1] = A[i];
        X[i][2] = E[i];  
        X[i][3] = F[i];  
        X[i][4] = G[i];    
    }

    // Now we find the transpose of a matrix:
    double X_tr[5][N];  // X_tr denotes the transpose of a matrix.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N; j++)
        {
            X_tr[i][j] = X[j][i];  // Transpose matrix is symmetric about the diagonal.
        }
    }

    double M[5][5];  // We denote M[5][5] matrix as X^T * X i.e multiplication of X matrix and X_transpose matrix.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            double sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum = sum + X_tr[i][k] * X[k][j];
            }
            M[i][j] = sum;
        }
    }

    // Now we find the inverse of matrix M i.e inverse of matrix X^T * X.
    int i, j, k;
    double M_inv[5][5];  // represents the inverse of M[5][5] matrix.

    // Important :- Note that this method works only if determinant of M_inv matrix is non zero.

    // We initialise the inverse of M[5][5] matrix as identity matrix.
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                M_inv[i][j] = 1;
            }
            else
            {
                M_inv[i][j] = 0;
            }
        }
    }
    // We now perform the Gauss Jordon method to find the inverse of M[5][5] Matrix.
    for (k = 0; k < 5; k++)
    {
        if (M[k][k] != 0)
        {
	    double x = M[k][k];
            for (j = 0; j < 5; j++)
            {
                M_inv[k][j] = M_inv[k][j] / x;
                M[k][j] = M[k][j] / x;    
            }

            for (i = k+1; i < 5; i++)
            {
                double temp = M[i][k];
                for (j = 0; j < 5; j++)
                {
                    M_inv[i][j] = M_inv[i][j] - temp / M[k][k] * M_inv[k][j];
                    M[i][j] = M[i][j] - temp / M[k][k] * M[k][j];
                }
            }

            for (int k = 0; k < 5; k++)
            {
                for (i = 0; i < k; i++)
                {
                    double temp = M[i][k];
                    for (j = 0; j < 5; j++)
                    {
                        M_inv[i][j] = M_inv[i][j] - temp / M[k][k] * M_inv[k][j];
                        M[i][j] = M[i][j] - temp / M[k][k] * M[k][j]; 
                    }                 
                }
            }
        }
    }
    // Now M_inv[5][5] has become the inverse of matrix M[5][5].
    double T[5][5];  // We are copying the elements of M_inv matrix in T matrix.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            T[i][j] = M_inv[i][j];
        }
    }
    // Calculating the determinant of matrix M_inv[5][5] :
    int p;
    int n = 5;
    double Big, dummy;
    for (int k = 0; k < n-1; k++)
    {
        p = k;
        Big = abs(T[k][k]);
        for (int i = k+1; i < n; i++)
        {
            dummy = abs(T[i][k]);
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
                dummy = T[p][j];
                T[p][j] = T[k][j];
                T[k][j] = dummy;
            }
        }
        if (T[k][k] != 0)
        {
            for (int i = k+1; i < n; i++)
            {
                double temp = T[i][k];
                for (int j = k; j < n; j++)
                {
                    T[i][j] = T[i][j] - temp / T[k][k] * T[k][j];
                }
            }
        }   
    }
    double det_M_inv = T[0][0] * T[1][1] * T[2][2] * T[3][3] * T[4][4];
    if (det_M_inv == 0)
    {
        cout << " As determinant of Inverse matrix = 0, we cannot obtain solns by Least Square method" << '\n';
        return 0;
    }

    double P[5][N];  // We denote P[5][N] matrix as (X^T * X)^-1 * X^T i.e multiplication of M_inv matrix and X_transpose matrix.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double sum = 0;
            for (int k = 0; k < 5; k++)
            {
                sum = sum + M_inv[i][k] * X_tr[k][j];
            }
            P[i][j] = sum;
        }
    }

    // Now calculating the Regression equation coefficients ai's :
    for (int i = 0; i < 5; i++)
    {
        double sum = 0;
        for (int k = 0; k < N; k++)
        {
            sum = sum + P[i][k] * Y[k];
        }
        a[i] = sum;
    }
    cout << "Regression Equation coefficients are : " << '\n' << '\n';
    for (int i = 0; i < 5; i++)
    {
        cout << fixed << setprecision(9) << "a" << i << " = " << a[i] << '\n';
    }
    cout << '\n' << '\n';

    // Now calculating predicted Y :
    double Y_pred[N];
    for (int i = 0; i < N; i++)
    {
        Y_pred[i] = a[0] + a[1]*A[i] + a[2]*E[i] + a[3]*F[i] + a[4]*G[i]; 
    }
    cout << "Predicted values of Y are : " << '\n' << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << fixed << setprecision(15) << "Y_pred[" << i << "]" << " = " << Y_pred[i] << '\n'; 
    }
    cout << '\n' << '\n';

    // Now calculating the error in actual and predicted values of Y :
    double Err;
    cout << "Errors in actual and predicted values of Y are : " << '\n' << '\n';
    for (int i = 0; i < N; i++)
    {
        Err = abs(Y[i] - Y_pred[i]);
        cout << fixed << setprecision(15) << "Err in Y[" << i << "] = " << Err <<'\n';
    }
}