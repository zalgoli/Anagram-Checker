#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>


using CharIntPairVector = std::vector<std::pair<char, int>>;


CharIntPairVector letter_frequencies(const std::string& input_word)
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

std::string vectorToString(const CharIntPairVector& vec) {
    std::string result;
    for (const auto& pair : vec) {
        result += pair.first;
        result += std::to_string(pair.second);
    }
    return result;
}

std::vector<std::vector<std::string>> anagram_groups(const std::vector<std::string>& input_list) {
    std::unordered_map<std::string, std::vector<std::string>> hash{};
    std::vector<std::vector<std::string>> result{};

    for (const std::string& word : input_list) {
        std::vector<std::pair<char, int>> key = letter_frequencies(word);
        std::string keyString = vectorToString(key);
        hash[keyString].push_back(word);
    }

    for (auto unit : hash) {
        result.push_back(unit.second);
    }

    return result;
}


int main()
{

    std::cout << "CHECKING A SINGLE PAIR OF WORDS FOR ANAGRAMS: \n";
    std::string word1{ "Apple" };
    std::string word2{ "ppleA" };
    CharIntPairVector word1freq{ letter_frequencies(word1) };
    CharIntPairVector word2freq{ letter_frequencies(word2) };
    std::string result_string{ word1freq == word2freq ? "The two words are anagrams." : "The two words are NOT anagrams." };
    std::cout << result_string;


    std::cout << "\n\nCHECKING AN ARRAY OF WORDS FOR ANAGRAM GROUPS:\n";
    std::vector<std::string> inputs{ "act", "cat", "listen", "silent", "enlist", "hello", "world", "dog",
                                    "god", "heart", "earth", "tear", "break", "baker", "react", "trace", "care",
                                    "acre", "cinema", "iceman", "debit", "bide", "bore", "robe", "bread", "beard", "angle",
                                    "glean", "listen", "enlist", "silent", "artist", "traits", "star", "rats", "arts", "post", "stop",
                                    "tops", "elbow", "below", "bowel", "lamp", "palm", "maple", "ample", "debit", "bide", "cinema", "iceman" };

    std::vector<std::vector<std::string>> result = anagram_groups(inputs);

    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << "Group " << i + 1 << ": ";
        for (const auto& word : result[i])
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    
}