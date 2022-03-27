#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TParaboloidElongated1Problem::TParaboloidElongated1Problem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::SetDimension(int dimension)
{
  if (dimension == 2)
  {
    mDimension = dimension;
    return IProblem::OK;
  }
  else
    return IProblem::ERROR;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::Initialize()
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
void TParaboloidElongated1Problem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -2.2;
      upper[i] = 1.8;
    }
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;
  
  value = 0.0;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  for (int i = 0; i < mDimension; ++i) {
      point[i] = 0;
  }

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TParaboloidElongated1Problem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TParaboloidElongated1Problem::CalculateFunctionals(const double* x, int fNumber)
{
  double sum = 0.;
  sum = 100 * x[0] * x[0] + x[1] * x[1];
  return sum;
}

// ------------------------------------------------------------------------------------------------
TParaboloidElongated1Problem::~TParaboloidElongated1Problem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TParaboloidElongated1Problem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------