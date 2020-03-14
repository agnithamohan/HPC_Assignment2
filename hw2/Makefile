default: gs2D-omp gs2D jacobi2Domp jacobi2D omp_solved2 omp_solved3 omp_solved4 omp_solved5 omp_solved6 valgrind


gs2D-omp: gs2D-omp.cpp
	g++-9 -O3  gs2D-omp.cpp -fopenmp -o gs2D-omp ;

gs2D: gs2D.cpp
	g++-9 -O3  gs2D.cpp  -o gs2D;

jacobi2Domp: jacobi2D-omp.cpp
	g++-9 -O3  jacobi2D-omp.cpp -fopenmp -o gs2D-omp  ;

jacobi2D: jacobi2D.cpp
	g++-9 -O3  jacobi2D.cpp  -o gs2D;

omp_solved2: omp_solved2.c 
	gcc-9 omp_solved2.c -fopenmp -o omp_solved2;
omp_solved3: omp_solved3.c
	gcc-9 omp_solved3.c -fopenmp -o omp_solved3;
omp_solved4: omp_solved4.c
	gcc-9 omp_solved4.c -fopenmp -o omp_solved4;
omp_solved5: omp_solved5.c
	gcc-9 omp_solved5.c -fopenmp -o omp_solved5;
omp_solved6: omp_solved6.c
	gcc-9 omp_solved6.c -fopenmp -o omp_solved6;

valgrind: val_test01_solved.cpp val_test02_solved.cpp
	g++ val_test01_solved.cpp -o val_test01_solved;
	g++ val_test02_solved.cpp -o val_test02_solved;