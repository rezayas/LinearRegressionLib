#include "linreg.hpp"
#include "poly.hpp"

namespace ComputationalLib {
  class PolynomialRegression {
  public:
    inline PolynomialRegression(int order, int nvars, double omega = 0) :
      PolynomialRegression(Polynomial(order, nvars), omega) {}
    inline PolynomialRegression(const Polynomial &p, double omega = 0) :
      plin(p.monomials,omega), ppoly(p) {}
    inline const Polynomial &poly() const {
      return(ppoly);
    }
    inline const LinearRegression &lin() const {
      return(plin);
    }
    bool updateCoefficients(const vec &x, double y, double lambda = 1);
  private:
    LinearRegression plin;
    Polynomial ppoly;
  };
}
