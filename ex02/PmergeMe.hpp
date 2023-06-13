#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &s_PmergeMe);
    PmergeMe &operator=(PmergeMe const &s_PmergeMe);

    void sortSequence(std::vector<int>& sequence);
    void sortSequence(std::deque<int>& sequence);

    void printSequence(const std::vector<int>& sequence, const std::string& message);
    void printSequence(const std::deque<int>& sequence, const std::string& message);

private:
    // Sort using insertion sort
    void insertionSort(std::vector<int>& sequence, int left, int right);
    void insertionSort(std::deque<int>& sequence, int left, int right);

    // Sort using merge sort
    void mergeSort(std::vector<int>& sequence, int left, int right, std::vector<int>& temp);
    void mergeSort(std::deque<int>& sequence, int left, int right, std::deque<int>& temp);

    // Merge two sorted lists
    void merge(std::vector<int>& sequence, int left, int mid, int right, std::vector<int>& temp);
    void merge(std::deque<int>& sequence, int left, int mid, int right, std::deque<int>& temp);
};

#endif
