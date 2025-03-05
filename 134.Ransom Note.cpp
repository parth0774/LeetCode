#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> ransomNoteCount;
    unordered_map<char, int> magazineCount;
    
    // Count occurrences of characters in ransomNote
    for (char c : ransomNote) {
        ransomNoteCount[c]++;
    }
    
    // Count occurrences of characters in magazine
    for (char c : magazine) {
        magazineCount[c]++;
    }
    
    // Check if magazine has enough characters for ransomNote
    for (auto& pair : ransomNoteCount) {
        char charInRansom = pair.first;
        int countInRansom = pair.second;
        
        if (magazineCount[charInRansom] < countInRansom) {
            return false;  // Not enough characters
        }
    }
    
    return true;  // All characters can be constructed
}

int main() {
    // Example test cases
    cout << canConstruct("a", "b") << endl;    // Output: 0 (false)
    cout << canConstruct("aa", "ab") << endl;  // Output: 0 (false)
    cout << canConstruct("aa", "aab") << endl; // Output: 1 (true)
    
    return 0;
}
