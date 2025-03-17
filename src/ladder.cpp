#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cerr << "ERROR:  " << msg << word1 << "to " << word2 << endl;
}

vector<string> generate_word_ladder(const string& begin_word, const string& word, const set<string>& word_list)
{
    queue<vector<string> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        string ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);

                if (word == end_word)
                    return new_ladder;

                visited.insert(word);
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}

bool is_adjacent(const string& word1, const string& word2) // what the fuck even is this shit
{
    int word_size1 = word1.size();
    int word_size2 = word2.size();
    if (abs(word_size1 - word_size2) > 1) return false;
    for (int i = 0, int j = 0, int diff_count = 0 ; i < word_size1 && j < word_size2; ) {
        if (word1[i] != word2[j]) return false;
        if (word_size1 > word_size2) ++i;
        else if (word_size1 < word_size2) ++j;
        else {
            ++i;
            ++j;
        }
    }
    return true;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int str1_size = str1.size();
    int str2_size = str2.size();
    int diff_count = 0
    if (std::abs(str1_size - str2_size) > d) return false;
    for (int i = 0, int j = 0; i < str1_size && j < str2_size; ) {
        if (str1_size[i] != str2_size[j]) {
            if (++diff_count > d) return false;
            if (str1_size > str2_size) ++i; // Skip a character in str1 (deletion)
            else if (str1_size < str2_size) ++j; // Skip a character in str2 (insertion)
            else { ++i; ++j; } // Substitution
        } else {
            ++i; ++j; // Characters match, move forward
        }
    }
    diff_count += std::abs(str1_size - str2_size);
    return diff_count <= d;
}

void load_words(set<string>& word_list, const string& file_name)
{
    ifstream input_file(file_name);
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

