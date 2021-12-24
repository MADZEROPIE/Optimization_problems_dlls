#include "problem.h"

#define _USE_MATH_DEFINES
#include <math.h>

// ------------------------------------------------------------------------------------------------
TSCHWEFELProblem::TSCHWEFELProblem()
{
  mIsInitialized = false;
  mDimension = 2;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::SetConfigPath(const std::string& configPath)
{
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::SetDimension(int dimension)
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
int TSCHWEFELProblem::GetDimension() const
{
  return mDimension;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::Initialize()
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
void TSCHWEFELProblem::GetBounds(double* lower, double* upper)
{
  if (mIsInitialized)
    for (int i = 0; i < mDimension; i++)
    {
      lower[i] = -500;
      upper[i] = 500;
    }
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::GetOptimumValue(double& value) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;

  value = 0.0;
  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::GetOptimumPoint(double* point) const
{
  if (!mIsInitialized)
    return IProblem::UNDEFINED;
  for (int i = 0; i < mDimension; ++i)
      point[i] = 420.9687;

  return IProblem::OK;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::GetNumberOfFunctions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::GetNumberOfConstraints() const
{
  return 0;
}

// ------------------------------------------------------------------------------------------------
int TSCHWEFELProblem::GetNumberOfCriterions() const
{
  return 1;
}

// ------------------------------------------------------------------------------------------------
double TSCHWEFELProblem::CalculateFunctionals(const double* x, int fNumber)
{
  double sum = 0.;
  for (int i = 0; i < mDimension; ++i)
      sum+=x[i]* sin(sqrt(abs(x[i])));
  double res = 418.9829 * mDimension - sum;
  return res;
}

// ------------------------------------------------------------------------------------------------
TSCHWEFELProblem::~TSCHWEFELProblem()
{

}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API IProblem* create()
{
  return new TSCHWEFELProblem();
}

// ------------------------------------------------------------------------------------------------
LIB_EXPORT_API void destroy(IProblem* ptr)
{
  delete ptr;
}
// - end of file ----------------------------------------------------------------------------------