#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void error(string word1, string word2, string msg)
{
    cerr << "ERROR:  " << msg << word1 << "to " << word2 << endl;
}

vector<string> generate_word_ladder(const string& begin_word, const string& word, const set<string>& word_list)
{
    queue<vector<string>> ladder_queue;
    ladder_queue.push(vector<string>({begin_word}));
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string& words : word_list) {
            if (is_adjacent(last_word, words) && visited.find(words) == visited.end()) {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(words);

                if (words == word)
                    return new_ladder;

                visited.insert(words);
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}

bool is_adjacent(const string& word1, const string& word2) // what the fuck even is this shit
{
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int str1_size = str1.size();
    int str2_size = str2.size();
    int diff_count = 0;
    if (std::abs(str1_size - str2_size) > d) return false;
    for (int i = 0, j = 0; i < str1_size && j < str2_size; ) {
        if (str1[i] != str2[j]) {
            if (++diff_count > d) return false;
            if (str1_size > str2_size) ++i; 
            else if (str1_size < str2_size) ++j;
            else { ++i; ++j; } 
        } else {
            ++i; ++j; 
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

void print_word_ladder(const vector<string>& ladder)
{
    for (word : ladder)
        cout << word << endl;
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}