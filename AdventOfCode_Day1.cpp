#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath> 

// Function to calculate the total distance between two lists
int calculateTotalDistance(std::vector<int>& leftList, std::vector<int>& rightList) {
    // Sort both lists
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;

    // Calculate the absolute difference for each pair
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

int main() {
    std::ifstream inputFile("distanceList.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file!" << std::endl;
        return 1;
    }

    std::vector<int> leftList, rightList;
    int left, right;

    // Read data from the input file
    while (inputFile >> left >> right) {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    inputFile.close();

    if (leftList.size() != rightList.size() || leftList.empty()) {
        std::cerr << "Error: Lists are empty or mismatched in size!" << std::endl;
        return 1;
    }

    // Calculate the total distance
    int totalDistance = calculateTotalDistance(leftList, rightList);

    // Output the result
    std::cout << "Total distance between the lists: " << totalDistance << std::endl;

    return 0;
}
