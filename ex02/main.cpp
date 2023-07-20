#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Please provide a sequence of numbers.\n";
        return 1;
    }

    std::vector<int> sequenceVec;
    std::deque<int> sequenceDeq;

    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(argv[i]);
        if (number < 0) {
            std::cout << "Error: negative number.\n";
            return 1;
        }
        sequenceVec.push_back(number);
        sequenceDeq.push_back(number);
    }

    PmergeMe sorter;
    
    std::chrono::high_resolution_clock::time_point startVec = std::chrono::high_resolution_clock::now();
    sorter.sortSequence(sequenceVec);
    std::chrono::high_resolution_clock::time_point endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedVec = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec);

    std::chrono::high_resolution_clock::time_point startDeq = std::chrono::high_resolution_clock::now();
    sorter.sortSequence(sequenceDeq);
    std::chrono::high_resolution_clock::time_point endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedDeq = std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq);

	std::cout << std::fixed << std::setprecision(5);  // Ajoutez ceci avant l'affichage des temps

	std::cout << "Time to process a range of " << sequenceVec.size() << " elements with std::vector: " << elapsedVec.count() << " us\n";
	std::cout << "Time to process a range of " << sequenceDeq.size() << " elements with std::deque: " << elapsedDeq.count() << " us\n";

    return 0;
}
