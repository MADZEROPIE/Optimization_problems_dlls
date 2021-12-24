#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TLinearProblem::TLinearProblem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::SetDimension(int dimension)
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
int TLinearProblem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::Initialize()
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
void TLinearProblem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -2.2;
      upper[i] = 1.8;
    }
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  value = 0.0;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  for (int i = 0; i < mDimension; ++i) {
      point[i] = 0;
  }

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TLinearProblem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TLinearProblem::CalculateFunctionals(const double* x, int fNumber)
{
  double sum = 0.;
  for (int i = 0; i < mDimension; ++i) {
      sum += x[i] * x[i];
  }
  return sum;
}

// ------------------------------------------------------------------------------------------------
TLinearProblem::~TLinearProblem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TLinearProblem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------