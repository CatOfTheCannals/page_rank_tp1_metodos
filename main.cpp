#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>

#include "src/sparse_page_rank.h"

using namespace std;



int main(int argc, char** argv){

	if (argc != 3){
		cout << endl<<"	Unable to run program" << endl;
		cout << "	Three parameters are expected:    program_name.exe  in_file.txt  p_number" << endl;
		return 1;
	}
	
	// leo el archivo de test -->la entrada i,j indica un 1 en la posicion [j][i]

	std::cout << "argv[0]: " << argv[0] << std::endl;
	std::cout << "argv[1]: " << argv[1] << std::endl;
	std::cout << "argv[2]: " << argv[2] << std::endl;

	string inFile(argv[1]);
	string outFile(argv[1]);
	outFile += ".out";
	double p = std::atof(argv[2]);

	std::cout << "outFile: " << outFile << std::endl;
	std::cout << "p: " << p << std::endl;

	string line;
	int pagecount, links, i, j;
	ifstream f_test(inFile);
	
    if ( f_test.is_open() ){ f_test >> pagecount >> links;} 
    else { cout << "Unable to open file." << endl; return 1; }
    
	
	/**/ // leo basura, hay q lograr sacarla
	getline(f_test, line);	
	istringstream lineStream(line);
	lineStream >> i >> j;

	/**/ // fin basura
	
	
	//********* levanto W (POR COLUMNAS) y armo C al mismo tiempo ***********
	Sparse_matrix_2 W = Sparse_matrix_2(pagecount, pagecount);
	while( getline(f_test, line) ){ //asumo que el archivo de entrada no termina con salto de linea (en ese caso se vuelve a cargar en W y se suma uno de más a C )
		istringstream lineStream(line);
		lineStream >> i >> j;
		W.setIndex(i, j, 1);
	}
	f_test.close();
	auto C = colSumDiag(W);
	
	//***********fin levantar W************
	
	auto output_rank = page_rank(W, C, p);
	
	std::cout << output_rank << std::endl;
  
  return 0;
}

