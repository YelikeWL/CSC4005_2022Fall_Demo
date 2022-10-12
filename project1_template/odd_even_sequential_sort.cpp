#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main(int argc, char **argv){

	int num_elements; // number of elements to be sorted
	num_elements = atoi(argv[1]); // convert command line argument to num_elements
    
	int elements[num_elements]; // store elements
	int sorted_elements[num_elements]; // store sorted elements
	
	std::ifstream input(argv[2]);
	int element;
	int i = 0;
	while (input >> element) {
		elements[i] = element;
		i++;
	}
	
	std::cout << "actual number of elements:" << i << std::endl;

	std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double> time_span;
    t1 = std::chrono::high_resolution_clock::now(); // record time

//clock_t t1 = clock();	// record time

	/* START sequential odd even transposition sort */
    int temp;
    bool isSorted = false; 	// assume array start as an unsorted array

	while (!isSorted) {
		isSorted = true;

		// Odd comparison
		for (int i = 0; i <= num_elements-2; i += 2) {
            if (elements[i] > elements[i+1]) {
                temp = elements[i];
				elements[i] = elements[i+1];
				elements[i+1] = temp;
                isSorted = false;
              }
		}

		// Even comparison
		for (int i = 1; i <= num_elements-2; i += 2) {
            if (elements[i] > elements[i+1]) {
                temp = elements[i];
				elements[i] = elements[i+1];
				elements[i+1] = temp;
                isSorted = false;
            }
        }
	}
	
	for (int i = 0; i < num_elements; i++) {
        sorted_elements[i] = elements[i];
    }
    /* END */

//clock_t t2 = clock();
//double time_span = (double)(t2 - t1) / (double) CLOCKS_PER_SEC;

	t2 = std::chrono::high_resolution_clock::now();  
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	
	std::cout << "Student ID: " << "119010529" << std::endl; // replace it with your student id
    std::cout << "Name: " << "Yelike Winne Lukito" << std::endl; // replace it with your name
    std::cout << "Assignment 1" << std::endl;
    std::cout << "Run Time: " << time_span << " seconds" << std::endl;
    std::cout << "Input Size: " << num_elements << std::endl;
    std::cout << "Process Number: " << 1 << std::endl;   
    
    std::ofstream output(argv[2]+std::string(".seq.out"), std::ios_base::out);
    for (int i = 0; i < num_elements; i++) {
        output<< sorted_elements[i] << std::endl;
    }

	return 0;
}
