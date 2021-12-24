#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TParaboloidProblem::TParaboloidProblem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::SetDimension(int dimension)
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
int TParaboloidProblem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::Initialize()
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
void TParaboloidProblem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -2.2;
      upper[i] = 1.8;
    }
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;
  double res = 0;
  for (int i = 0; i < mDimension; ++i)
      res += 2 * (-2.2);
  value = res;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  for (int i = 0; i < mDimension; ++i) {
      point[i] = -2.2;
  }

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidProblem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TParaboloidProblem::CalculateFunctionals(const double* x, int fNumber)
{
  double sum = 0.;
  for (int i = 0; i < mDimension; ++i) {
      sum += x[i] * x[i];
  }
  return sum;
}

// ------------------------------------------------------------------------------------------------
TParaboloidProblem::~TParaboloidProblem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TParaboloidProblem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------