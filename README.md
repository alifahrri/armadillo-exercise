### Armadillo Exercise   
An exercise on [armadillo](http://arma.sourceforge.net/) linear algebra & scientific computing   
#### docker   
build docker image
```
bash docker/build.sh
```
run demo program
```
bash docker/run.sh
```
#### Results   
see [demo-03.cpp](src/demo-03.cpp)
```
v
   1.0000
   2.0000
   3.0000

A
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

Q
[cube slice 0]
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

[cube slice 1]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000


B=A
print(B)
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

C=A
print(C)
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

B.reshape(3,2)
print(B)
   1.0000   5.0000
   4.0000   3.0000
   2.0000   6.0000

C.resize(3,2)
print(C)
   1.0000   2.0000
   4.0000   5.0000
        0        0

v=arma::vectorise(C)
print(v)
   1.0000
   4.0000
        0
   2.0000
   5.0000
        0

D=arma::reshape(A,3,2)
print(D)
   1.0000   5.0000
   4.0000   3.0000
   2.0000   6.0000

arma::reshape(A.t(),3,2)
print(arma::reshape(A.t(),3,2))
   1.0000   4.0000
   2.0000   5.0000
   3.0000   6.0000

A.t()
print(A.t())
   1.0000   4.0000
   2.0000   5.0000
   3.0000   6.0000

arma::fliplr(A)
print(arma::fliplr(A))
   3.0000   2.0000   1.0000
   6.0000   5.0000   4.0000

arma::flipud(A)
print(arma::flipud(A))
   4.0000   5.0000   6.0000
   1.0000   2.0000   3.0000

E=arma::mat(arma::vectorise(B).eval().memptr(),C.n_rows,C.n_cols)
print(E)
   1.0000   5.0000
   4.0000   3.0000
   2.0000   6.0000

iterator(A,arma::span(0,1),arma::span(0,1))
1
4
2
5

E.for_each([](double & e){ e += 33.; })
print(E)
   34.0000   38.0000
   37.0000   36.0000
   35.0000   39.0000

E.transform([](double e){ return e - 33.; })
print(E)
   1.0000   5.0000
   4.0000   3.0000
   2.0000   6.0000

F=E
print(F)
   1.0000   5.0000
   4.0000   3.0000
   2.0000   6.0000

F.each_col()+=arma::ones(F.n_rows)
print(F)
   2.0000   6.0000
   5.0000   4.0000
   3.0000   7.0000

S=Q
print(S)
[cube slice 0]
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

[cube slice 1]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000


S.size()
print(S.size())
12
S.n_rowsS.n_colsS.n_slices
print(S.n_rows,S.n_cols,S.n_slices)
2, 3, 2


S(0,0,0)=99.
print(S)
[cube slice 0]
   99.0000    2.0000    3.0000
    4.0000    5.0000    6.0000

[cube slice 1]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000


R=Q
print(R)
[cube slice 0]
   1.0000   2.0000   3.0000
   4.0000   5.0000   6.0000

[cube slice 1]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000


R.slice(0)=R.slice(1)
print(R)
[cube slice 0]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000

[cube slice 1]
   6.0000   5.0000   4.0000
   3.0000   2.0000   1.0000
```