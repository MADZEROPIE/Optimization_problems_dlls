#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TGoldsteinProblem::TGoldsteinProblem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::SetDimension(int dimension)
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
int TGoldsteinProblem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::Initialize()
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
void TGoldsteinProblem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -2;
      upper[i] = 2;
    }
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  value = 0.0;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  point[0] = 0;
  point[1] = -1;

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TGoldsteinProblem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TGoldsteinProblem::CalculateFunctionals(const double* x, int fNumber)
{
  double res = 0.;
  double x1 = x[0], x2 = x[1];
  double fact1a = (x1 + x2 + 1) * (x1 + x2 + 1);
  double fact1b = 19 - 14 * x1 + 3 * x1 * x1 - 14 * x2 + 6 * x1 * x2 + 3 * x2 * x2;
  double fact1 = 1 + fact1a * fact1b;

  double fact2a = (2 * x1 - 3 * x2) * (2 * x1 - 3 * x2);
  double fact2b = 18 - 32 * x1 + 12 * x1 * x1 + 48 * x2 - 36 * x1 * x2 + 27 * x2 * x2;
  double fact2 = 30 + fact2a * fact2b;
  res = fact1 * fact2;
  return res;
}

// ------------------------------------------------------------------------------------------------
TGoldsteinProblem::~TGoldsteinProblem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TGoldsteinProblem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------