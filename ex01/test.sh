#!/bin/bash

# Run the RPN program with a few test cases and print the output

echo "Running RPN tests..."

# Test case 1
echo "Test case 1: 8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# Test case 2
echo "Test case 2: 7 7 * 7 -"
./RPN "7 7 * 7 -"

# Test case 3
echo "Test case 3: 1 2 * 2 / 2 * 2 4 - +"
./RPN "1 2 * 2 / 2 * 2 4 - +"

# Test case 4
echo "Test case 4: (1 + 1)"
./RPN "(1 + 1)"

# Test case 5
echo "Test case 5: 1 1 + 1 +"
./RPN "1 1 + 1 +"

# Test case 6
echo "Test case 6: 9 2 /"
./RPN "9 2 /"

# Test case 7
echo "Test case 7: 5 2 * 3 +"
./RPN "5 2 * 3 +"

# Test case 8
echo "Test case 8: 7 2 - 3 *"
./RPN "7 2 - 3 *"

# Test case 9
echo "Test case 9: 4 5 + 6 * 7 -"
./RPN "4 5 + 6 * 7 -"

# Test case 10
echo "Test case 10: 1 2 + 3 * 4 -"
./RPN "1 2 + 3 * 4 -"

echo "Tests finished."
