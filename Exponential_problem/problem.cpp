#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TExponentialProblem::TExponentialProblem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::SetDimension(int dimension)
{
  if (dimension > 0 && dimension <= mMaxDimension)
  {
    mDimension = dimension;
    return IProblem::OK;
  }
  else
    return IProblem::ERROR;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::Initialize()
{
  if (mDimension > 0)
  {
    mIsInitialized = true;
    return IProblem::OK;
  }
  else
    return IProblem::ERROR;
}

// ------------------------------------------------------------------------------------------------
void TExponentialProblem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -8;
      upper[i] = 8;
    }
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  value = -2.0;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  point[0] = 2;
  point[1] = 2;

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TExponentialProblem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TExponentialProblem::CalculateFunctionals(const double* x, int fNumber)
{
  double res = 0.;
  double exp1 = -0.5 * exp((-(x[0] + 2) * (x[0] + 2) - (x[1] + 2) * (x[1] + 2)) / 2);
  double exp2 = - exp((-(x[0] + 2) * (x[0] + 2) - (x[1] - 2) * (x[1] - 2)) / 2);
  double exp3 = -1.5 * exp((-(x[0] - 2) * (x[0] - 2) - (x[1] + 2) * (x[1] + 2)) / 2);
  double exp4 = -2.0 * exp((-(x[0] - 2) * (x[0] - 2) - (x[1] - 2) * (x[1] - 2)) / 2);
  res = exp1 + exp2 + exp3 + exp4;
  return res;
}

// ------------------------------------------------------------------------------------------------
TExponentialProblem::~TExponentialProblem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TExponentialProblem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------