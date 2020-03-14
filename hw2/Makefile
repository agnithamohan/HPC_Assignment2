default: gs2D-omp gs2D jacobi2D-omp jacobi2D omp_solved valgrind mat-mult


gs2D: gs2D.cpp
	g++ -O3  gs2D.cpp  -o gs2D;

jacobi2D: jacobi2D.cpp
	g++ -O3  jacobi2D.cpp  -o jacobi2D;

gs2D-omp: gs2D-omp.cpp
	g++ -O3  gs2D-omp.cpp -fopenmp -o gs2D-omp ;


jacobi2D-omp: jacobi2D-omp.cpp
	g++ -O3  jacobi2D-omp.cpp -fopenmp -o jacobi2D-omp;


omp_solved: omp_solved2.c omp_solved3.c omp_solved4.c omp_solved5.c omp_solved6.c
	gcc omp_solved2.c -fopenmp -o omp_solved2; gcc omp_solved3.c -fopenmp -o omp_solved3; 
	gcc omp_solved4.c -fopenmp -o omp_solved4; gcc omp_solved5.c -fopenmp -o omp_solved5;
	gcc omp_solved6.c -fopenmp -o omp_solved6;

valgrind: val_test01_solved.cpp val_test02_solved.cpp
	g++ val_test01_solved.cpp -o val_test01_solved;
	g++ val_test02_solved.cpp -o val_test02_solved;

mat-mult:
	g++ -O3 -march=native MMult1.cpp -fopenmp -o MMult1;


	

 