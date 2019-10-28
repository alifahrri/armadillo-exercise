#include <armadillo>
#include <iostream>

#define EXPR3(X,Y,Z) std::cout << (#X) << (#Y) << (#Z) << std::endl; (X); (Y); (Z);
#define EXPR2(X,Y) std::cout << (#X) << (#Y) << std::endl; (X); (Y);
#define EXPR1(X) std::cout << (#X) << std::endl; (X);
#define EXPR(X) EXPR1(X)

auto print(const auto &c)
{
	std::cout << c << std::endl;
}

template <typename ...Args>
auto print(auto c, Args...args)
{
	std::cout << c << ", ";
	print(args...);
	std::cout << std::endl;
}

int main(int argc, char**argv)
{
	arma::vec v{1,2,3};
	arma::mat A{{1,2,3},{4,5,6}};
	/* won't compiled */
	// arma::cube Q{{{1,2},{3,4}},{{5,6},{7,8}}};
	arma::cube Q(A.n_rows,A.n_cols,2);
	Q.slice(0) = A;
	Q.slice(1) = arma::fliplr(arma::flipud(A));

	EXPR(v); print(v);
	EXPR(A); print(A);
	EXPR(Q); print(Q);

	/* placeholder */
	arma::mat B, C, D, E, F;
	arma::cube R, S, T;

	/* print expression 	 || 			print result */
	EXPR(B=A); 								EXPR(print(B));
	EXPR(C=A); 								EXPR(print(C));
	EXPR(B.reshape(3,2)); 					EXPR(print(B));
	EXPR(C.resize(3,2)); 					EXPR(print(C));
	EXPR(v=arma::vectorise(C)); 			EXPR(print(v));
	EXPR(D=arma::reshape(A,3,2));			EXPR(print(D));
	EXPR(arma::reshape(A.t(),3,2));			EXPR(print(arma::reshape(A.t(),3,2)));
	EXPR(A.t());							EXPR(print(A.t()));
	EXPR(arma::fliplr(A));					EXPR(print(arma::fliplr(A)));
	EXPR(arma::flipud(A));					EXPR(print(arma::flipud(A)));
	EXPR(E=arma::mat(arma::vectorise(B).eval().memptr(),C.n_rows,C.n_cols));
											EXPR(print(E));
	auto iterator = [](auto A, auto s0, auto s1){
		for(double& val : A(s0,s1)){
			std::cout << val << std::endl;
		}
		std::cout << std::endl;
	};
	EXPR(iterator(A,arma::span(0,1),arma::span(0,1)));
	EXPR(E.for_each([](double & e){
		e += 33.;
	}));									EXPR(print(E));
	EXPR(E.transform([](double e){
		return e - 33.;
	}));									EXPR(print(E));
	EXPR(F=E);								EXPR(print(F));
	EXPR(F.each_col()+=arma::ones(F.n_rows));	EXPR(print(F));

	EXPR(S=Q);								EXPR(print(S));
	EXPR(S.size());							EXPR(print(S.size()));
	EXPR3(S.n_rows,S.n_cols,S.n_slices);	EXPR(print(S.n_rows,S.n_cols,S.n_slices));
	EXPR(S(0,0,0)=99.)						EXPR(print(S));
	EXPR(R=Q);								EXPR(print(R));
	EXPR(R.slice(0)=R.slice(1));			EXPR(print(R));
	return 0;
}
