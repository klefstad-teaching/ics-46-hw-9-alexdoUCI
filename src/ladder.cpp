#include "ladder.h"

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
    int len1 = word1.size();
    int len2 = word2.size();
    if (abs(len1 - len2) > 0) return false;
    int diff_count = 0
    for (i = 0, j = 0; i < len1 && j < len2; ) {
        if (word1[i] != word2[j]) return false;
        if (len1 > len2) ++i;
        else if (len1 < len2) ++j;
        else {
            ++i;
            ++j;
        }
    }
    return true;
}

void load_words(set<string>& word_list, const string& file_name)
{
    ifstream input_file(file_name);
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

