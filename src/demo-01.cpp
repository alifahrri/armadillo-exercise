#include <armadillo>
#include <iostream>

int main(int argc, char **argv)
{
	arma::mat A = arma::randu<arma::mat>(4,5);
	arma::mat B = arma::randu<arma::mat>(4,5);
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << A*B.t() << std::endl;
	return 0;
}
