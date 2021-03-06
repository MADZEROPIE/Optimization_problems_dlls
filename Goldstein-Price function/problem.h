#ifndef __GOLDSTEINPROBLEM_H__
#define __GOLDSTEINPROBLEM_H__

#include "../problem_interface.h"

class TGoldsteinProblem : public IProblem
{
protected:

  int mDimension;
  bool mIsInitialized;
  static const int mMaxDimension = 2;

public:

  TGoldsteinProblem();

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

  ~TGoldsteinProblem();
};

extern "C" LIB_EXPORT_API IProblem * create();
extern "C" LIB_EXPORT_API void destroy(IProblem * ptr);

#endif
// - end of file ----------------------------------------------------------------------------------