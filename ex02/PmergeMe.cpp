#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &s_PmergeMe) {
    *this = s_PmergeMe;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &s_PmergeMe) {
    if (this != &s_PmergeMe) {
    }
    return *this;
}

void PmergeMe::sortSequence(std::vector<int>& sequence) {
    printSequence(sequence, "Before: ");

    std::vector<int> temp(sequence.size());

    mergeSort(sequence, 0, sequence.size() - 1, temp);

    printSequence(sequence, "After: ");
}

void PmergeMe::sortSequence(std::deque<int>& sequence) {
    std::deque<int> temp(sequence.size());

    mergeSort(sequence, 0, sequence.size() - 1, temp);
}

void PmergeMe::printSequence(const std::vector<int>& sequence, const std::string& message) {
    std::cout << message;
    for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void PmergeMe::printSequence(const std::deque<int>& sequence, const std::string& message) {
    std::cout << message;
    for (std::deque<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void PmergeMe::insertionSort(std::vector<int>& sequence, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = sequence[i];
        int j = i - 1;

        while (j >= left && sequence[j] > key) {
            sequence[j + 1] = sequence[j];
            --j;
        }
        sequence[j + 1] = key;
    }
}

void PmergeMe::insertionSort(std::deque<int>& sequence, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = sequence[i];
        int j = i - 1;

        while (j >= left && sequence[j] > key) {
            sequence[j + 1] = sequence[j];
            --j;
        }
        sequence[j + 1] = key;
    }
}

void PmergeMe::mergeSort(std::vector<int>& sequence, int left, int right, std::vector<int>& temp) {
    if (right - left < 10) {
        insertionSort(sequence, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeSort(sequence, left, mid, temp);
        mergeSort(sequence, mid + 1, right, temp);
        merge(sequence, left, mid, right, temp);
    }
}

void PmergeMe::mergeSort(std::deque<int>& sequence, int left, int right, std::deque<int>& temp) {
    if (right - left < 10) {
        insertionSort(sequence, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeSort(sequence, left, mid, temp);
        mergeSort(sequence, mid + 1, right, temp);
        merge(sequence, left, mid, right, temp);
    }
}

void PmergeMe::merge(std::vector<int>& sequence, int left, int mid, int right, std::vector<int>& temp) {
    for (int i = left; i <= right; ++i) {
        temp[i] = sequence[i];
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) {
            sequence[k] = temp[j++];
        } else if (j > right) {
            sequence[k] = temp[i++];
        } else if (temp[j] < temp[i]) {
            sequence[k] = temp[j++];
        } else {
            sequence[k] = temp[i++];
        }
    }
}

void PmergeMe::merge(std::deque<int>& sequence, int left, int mid, int right, std::deque<int>& temp) {
    for (int i = left; i <= right; ++i) {
        temp[i] = sequence[i];
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) {
            sequence[k] = temp[j++];
        } else if (j > right) {
            sequence[k] = temp[i++];
        } else if (temp[j] < temp[i]) {
            sequence[k] = temp[j++];
        } else {
            sequence[k] = temp[i++];
        }
    }
}
