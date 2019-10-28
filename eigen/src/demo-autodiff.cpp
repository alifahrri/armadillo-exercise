#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
 
template<typename T>
T function(T const & x) {
  return 2*x*x + 3*x + 1;
};
 
void checkFunctionOne(double & x, double & dfdx) {
  dfdx = 4*x + 3;
}
 
template<typename T>
T function(T const & x, T const & y) {
  return 2*x*x + 3*x + 3*x*y*y + 2*y + 1;
};
 
void checkFunctionTwo(double & x, double & y, double & dfdx, double & dfdy ) {
  dfdx = 4*x + 3 + 3*y*y;
  dfdy = 6*x*y + 2;
}
 
int main () {
   
  double x, y, z, f, g, dfdx, dgdy, dgdz;
  Eigen::AutoDiffScalar<Eigen::VectorXd> xA, yA, zA, fA, gA;
   
  std::cout << "Testing scalar function with 1 input..." << std::endl;

  xA.derivatives() = Eigen::VectorXd::Unit(1, 0);
   
  fA = function(xA);
   
  std::cout << "  AutoDiff:" << std::endl;
  std::cout << "    Function output: " << fA.value() << std::endl;
  std::cout << "    Derivative: " << fA.derivatives() << std::endl;
   
  x = 1;
  checkFunctionOne(x, dfdx);
   
  std::cout << "  Hand differentiation:" << std::endl;
  std::cout << "    Derivative: " << dfdx << std::endl;
   
  std::cout << "Testing scalar function with 2 inputs..." << std::endl;
   
  yA.value() = 1;
  zA.value() = 2;
   
  yA.derivatives() = Eigen::VectorXd::Unit(2, 0);
  zA.derivatives() = Eigen::VectorXd::Unit(2, 1);
   
  gA = function(yA, zA);
   
  std::cout << "  AutoDiff:" << std::endl;
  std::cout << "    Function output: " << gA.value() << std::endl;
  std::cout << "    Derivative: " << gA.derivatives()[0] << ", "
    << gA.derivatives()[1] << std::endl;
   
  y = 1;
  z = 2;
  checkFunctionTwo(y, z, dgdy, dgdz);
   
  std::cout << "  Hand differentiation:" << std::endl;
  std::cout << "    Derivative: " << dgdy << ", "
    << dgdz << std::endl;
   
  return EXIT_SUCCESS;
   
}