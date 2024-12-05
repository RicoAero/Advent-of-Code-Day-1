#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

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

    if (leftList.empty() || rightList.empty()) {
        std::cerr << "Error: One or both lists are empty!" << std::endl;
        return 1;
    }

    // Create a frequency map for the right list
    std::unordered_map<int, int> rightFrequency;
    for (int num : rightList) {
        rightFrequency[num]++;
    }

    // Calculate the similarity score
    int similarityScore = 0;
    for (int num : leftList) {
        if (rightFrequency.find(num) != rightFrequency.end()) {
            similarityScore += num * rightFrequency[num];
        }
    }

    // Output the similarity score
    std::cout << "Similarity score: " << similarityScore << std::endl;

    return 0;
}

