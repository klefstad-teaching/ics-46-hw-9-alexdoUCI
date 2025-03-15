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