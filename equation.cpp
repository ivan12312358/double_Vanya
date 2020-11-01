#include "equation.h"
#include "unittest.h"
#include <stdio.h>
#include <math.h>

//{----------------------------------------------------------------------------
/**
   \brief      Description:
                    prints creator of the program and calls
                    functions of scanning coefficients and decision equation
               Arguments:

   @param           a - first coefficient,

   @param           b - second coefficient,

   @param           c - third coefficient

   @param           x_1 - first root, x_2 - second root
*/
//}----------------------------------------------------------------------------

int main()
{
    printf("SolvIn - Solving a second-order or linear equation, v 2.2 (c) double_Vanya\n\n"

           "Enter \"y\", if you want to make test or enter any other symbol to skip\n");

    int tests = getchar();
    if (tests == 'y') unittest();

    printf("\nEnter coefficients in form:\n     ax^2 + bx + c = 0\n");

    double a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
    int coeff = 'a';
    input_values(&a, coeff);
    coeff++;
    input_values(&b, coeff);
    coeff++;
    input_values(&c, coeff);
    coeff++;

    int res_cnt = decision(a, b, c, &x_1, &x_2);

    print_roots(res_cnt, x_1, x_2);

    return 0;
}

//----------------------------------------------------------------------------

void input_values(double* a, int coeff)
{
    int number_or_char, count = 1;
    while(true)
    {
        printf("                         Enter %c = ", coeff);
        number_or_char = scanf("%lg", a);

        if(number_or_char == 1) break;
        else
        {
            scanf("%*s");
            printf("                         Wrong type %d times!\n", count++);
        }
    }

}

//-----------------------------------------------------------------------------

int decision(double a, double b, double c, double* x_1, double* x_2)
{
    double discr = 0;

    if(b*b - 4*a*c > (-1)*EPS)
        discr = sqrt(b*b - 4*a*c);
    else
    {
        *x_1 = *x_2 = NULL_;
        return 5;
    }

    if (fabs(a) > EPS)
    {
        if (fabs(b) > EPS)
        {
            if(discr > EPS)
            {
                *x_1 = (-b + discr)/(2*a);
                *x_2 = (-b - discr)/(2*a);
                return 0;
            }
            else if (fabs(discr) <= EPS)
            {
                *x_1 = *x_2 = -b/(2*a);
                return 1;
            }
            else
            {
                *x_1 = *x_2 = NULL_;
                return 2;
            }
        }
        else if (c*a < 0)
        {
            *x_1 = sqrt((-1)*c/a);
            *x_2 = (-1)*sqrt((-1)*c/a);
            return 3;
        }
        else if (fabs(c) < EPS)
        {
            *x_1 = *x_2 = 0;
            return 4;
        }
        else if (c*a > 0)
        {
            *x_1 = *x_2 = NULL_;
            return 5;
        }
    }
    else
        return line_equation(b, c, x_1, x_2);

    return -1;
}

//-----------------------------------------------------------------------------

int line_equation(double b, double c, double *x_1, double *x_2)
{
    if (fabs(b) > EPS)
    {
        *x_1 = *x_2 = (-1)*c/b + 0;
        return 6;
    }
    else if (fabs(c) < EPS)
    {
        *x_1 = *x_2 = INF;
        return 7;
    }
    else
    {
        *x_1 = *x_2 = NULL_;
        return 5;
    }
    return -1;
}

//-----------------------------------------------------------------------------

void print_roots(int res_cnt, double x_1, double x_2)
{
    switch (res_cnt)
    {
      case 0: printf("       Root_1 = %lg\n       Root_2 = %lg\n", x_1, x_2); break;
      case 1: printf("       Root_1 = %lg", x_1);                             break;
      case 2: printf("       No valid roots\n");                              break;
      case 3: printf("       Root_1 = %lg       Root_2 = %lg", x_1, x_2);     break;
      case 4: printf("       Root_1 = 0");                                    break;
      case 5: printf("       No valid roots\n");                              break;
      case 6: printf("       Root_1 = %lg\n", x_1);                           break;
      case 7: printf("       Infinite number of roots\n");                    break;
      default:;
    }
}
//------------------------------------------------------------------------------
