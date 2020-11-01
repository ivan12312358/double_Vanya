#pragma once
const double EPS = 1e-8; ///< EPS === 0

const int NULL_ = -1;    ///< NULL_ means "No roots"

const int INF = 8;       ///< INF means "Infinity roots"


//{----------------------------------------------------------------------------
//! @mainpage   SolvIn - Solving a second-order or linear equation, v 2.2 (c) double_Vanya.
//!             The program solves square and linear equations and prints the roots.
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
/**
   \brief       Description:
                 function scans coefficients
   \param [in]  Arguments:

   @param        number_or_char - checks the input data type

   @param        a, b, c - addresses of coefficients or equation

   \param [out] Return_values:

   @param        a, b, c - coefficients of equation
*/
//}----------------------------------------------------------------------------
void input_values(double* a, int coeff);
//{----------------------------------------------------------------------------
/**
   \brief       Description:
                    function of decision equation
   \param [in]  Arguments:

   @param           EPS - value close to zero

   @param           a, b, c - values of coefficients

   @param           x_1, x_2 - addresses of roots

   \param [out] Return_values:

   @param           x_1, x_2 - values of roots
 */
//}----------------------------------------------------------------------------
int decision(double a, double b, double c, double* x_1, double* x_2);

//{----------------------------------------------------------------------------
//! \brief Description:
//!            function solves linear equation
//}----------------------------------------------------------------------------

int line_equation(double b, double c, double *x_1, double* x_2);
//{----------------------------------------------------------------------------
/**
   \brief Description:
            function tests decision of equation
*/
//}----------------------------------------------------------------------------
void unittest();
//{----------------------------------------------------------------------------
/**
   \brief        Description:
                    function prints roots

   \param [in]   Arguments:

   @param           x_1, x_2 - values of roots

   @param           marker

   \param [out]  Return_values:

   @param           x_1 - Root_1

   @param           x_2 - Root_2
*/
//}----------------------------------------------------------------------------
void print_roots(int res_cnt, double x_1, double x_2);
