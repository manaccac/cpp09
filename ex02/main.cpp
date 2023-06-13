#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Please provide a sequence of numbers.\n";
        return 1;
    }


    std::vector<int> sequenceVec;
    std::deque<int> sequenceDeq;

    for (int i = 1; i < argc; ++i) {
        int number = std::stoi(argv[i]);
		if (number < 0) {
			std::cout << "Error: negative number.\n";
			return 1;
		}
        sequenceVec.push_back(number);
        sequenceDeq.push_back(number);
    }

    PmergeMe sorter;
    sorter.sortSequence(sequenceVec);
    sorter.sortSequence(sequenceDeq);

    return 0;
}
