#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>



std::vector<std::pair<char, int>> letter_frequencies(const std::string& input_word)
{
    std::unordered_map<char, int> word_frequencies{};

    // Basic logic for introducing values into the hashmap
    for (char letter : input_word)
    {
        auto it = word_frequencies.find(letter);

        if (it == word_frequencies.end())
        {
            word_frequencies[letter] = 1;
        }
        else
        {
            ++it->second;
        }
    }

    // Moving hashmap elements into the result vector
    std::vector<std::pair<char, int>> result{};

    for (auto unit : word_frequencies)
    {
        result.push_back(unit);
    }

    // Sorting result vector
    auto sortDescendingAndAlphabetical = [](const auto& lhs, const auto& rhs) {
        if (lhs.second == rhs.second) {
            // If frequencies are equal, sort alphabetically
            return lhs.first < rhs.first;
        }
        // Otherwise, sort by frequency in descending order
        return lhs.second > rhs.second;
        };

    
    std::sort(result.begin(), result.end(), sortDescendingAndAlphabetical);

    return result;
}

int main()
{
    std::string word1{ "Apple" };
    std::string word2{ "ppleA" };

    using CharIntPairVector = std::vector<std::pair<char, int>>;

    CharIntPairVector word1freq{ letter_frequencies(word1) };
    CharIntPairVector word2freq{ letter_frequencies(word2) };
    std::string result{ word1freq == word2freq ? "The two words are anagrams." : "The two words are NOT anagrams." };

    std::cout << result;
    
}