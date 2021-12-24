#ifndef __PARABOLIDPROBLEM_H__
#define __PARABOLIDPROBLEM_H__

#include "../problem_interface.h"

class TParaboloidProblem : public IProblem
{
protected:

  int mDimension;
  bool mIsInitialized;
  static const int mMaxDimension = 50;

public:

  TParaboloidProblem();

  virtual int SetConfigPath(const std::string& configPath);
  virtual int SetDimension(int dimension);
  virtual int GetDimension() const;
  virtual int Initialize();

  virtual void GetBounds(double* lower, double* upper);
  virtual int GetOptimumValue(double& value) const;
  virtual int GetOptimumPoint(double* x) const;

  virtual int GetNumberOfFunctions() const;
  virtual int GetNumberOfConstraints() const;
  virtual int GetNumberOfCriterions() const;

  virtual double CalculateFunctionals(const double* x, int fNumber);

  ~TParaboloidProblem();
};

extern "C" LIB_EXPORT_API IProblem * create();
extern "C" LIB_EXPORT_API void destroy(IProblem * ptr);

#endif
// - end of file ----------------------------------------------------------------------------------