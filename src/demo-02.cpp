#include <armadillo>
#include <iostream>

int main(int argc, char **argv)
{
	/* create a random 64x64 matrix */
	arma::mat A(64,64,arma::fill::randu);
	/* create a random 16x16 matrix */
	arma::mat B(16,16,arma::fill::randu);
	/* convolve A with B "kernel" */
	/* note that using auto results C & D deduced as */
	/* arma::Glue<Mat<double>, Mat<double>, arma::glue_conv2>*/
	/* some lazy eval stuff (?) */
	auto C = conv2(A,B);
	auto D = conv2(A,B,"same");
	std::cout << "A(" 
		<< A.n_rows << "," 
		<< A.n_cols << ")"
		<< std::endl;
	std::cout << "B(" 
		<< B.n_rows << "," 
		<< B.n_cols << ")"
		<< std::endl;
	std::cout << "C(" 
		<< arma::mat(C).n_rows << "," 
		<< arma::mat(C).n_cols << ")"
		<< std::endl;
	std::cout << "D(" 
		<< arma::mat(D).n_rows << "," 
		<< arma::mat(D).n_cols << ")"
		<< std::endl;
	// std::cout << A << std::endl;
	// std::cout << B << std::endl;
	// std::cout << C << std::endl;
	// std::cout << D << std::endl;
	return 0;
}
