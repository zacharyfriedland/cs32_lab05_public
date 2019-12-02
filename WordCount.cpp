// WordCount.cpp

#include "WordCount.h"
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int totWords = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			totWords+= table[i][j].second;
		}
	}
	return totWords;

}

int WordCount::getNumUniqueWords() const {
	int totWords = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			totWords++;
		}
	}
	return totWords;

}

int WordCount::getWordCount(std::string word) const {
	word = stripWord(word);
	if(word.length() < 1)
		return 0;
	std::transform(word.begin(), word.end(),word.begin(), ::toupper);
		for(size_t j = 0; j < table[hash(word)].size(); j++){
			if(word == table[hash(word)][j].first)
				return table[hash(word)][j].second;
		}
	return 0;

}

int WordCount::incrWordCount(std::string word) {
	word = stripWord(word);
	if(word.length() < 1)
		return 0;
	std::transform(word.begin(), word.end(),word.begin(), ::toupper);
		for(size_t j = 0; j < table[hash(word)].size(); j++){
			if(word == table[hash(word)][j].first){
				table[hash(word)][j].second++;
				return table[hash(word)][j].second;
			}
		}
	std::pair<std::string, size_t> temp;
	temp.first = word;
	temp.second = 1;
	table[hash(word)].push_back(temp);
	return 1;
}


bool WordCount::isWordChar(char c) {
	return isalpha(c);
}


std::string WordCount::stripWord(std::string word) {
	if(word.length() < 1)
		return "";
	std::string stripped = "";
	int firstLet, lastLet = 0;;
	for(size_t i = 0; i < word.length(); i++){
		if(isWordChar(word[i])){
			firstLet = i;
			break;
		}
		firstLet++;
	}
	for(size_t j = word.length()-1; j > 0; j--){
		if(isWordChar(word[j])){
			lastLet = j;
			break;
		}
	}
	for(int x = firstLet; x <= lastLet; x++){
		if(isalpha(word[x]) || word[x] == '-' || word[x] == '\'')
			stripped += word[x];
	}
	return stripped;

}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	set<pair<string, size_t>> ordered;
	pair<string, int> temp;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			temp = make_pair(table[i][j].first, table[i][j].second);
			ordered.insert(temp);
		}
	}
	
	for(auto x: ordered){
		out << x.first << "," << x.second << "\n";
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	set<pair<string, size_t>> ordered;
	pair<string, size_t> temp;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			temp = make_pair(table[i][j].first, table[i][j].second);
			ordered.insert(temp);
		}
	}
	
	set<pair<string,size_t>>::iterator highest;
	while(ordered.size() > 0){
		highest = ordered.begin();
		for(set<pair<string,size_t>>::iterator x = ordered.begin();
				x != ordered.end(); x++){
			
			if((*x).second > (*highest).second){
				highest = x;
			}
		}
		out << (*highest).first << "," << (*highest).second << "\n";
		ordered.erase((*highest));
	}





}

void WordCount::addAllWords(std::string text) {
	string word = "";
	for(size_t i = 0; i < text.length(); i++){
		if(text[i] == ' ' || text[i] == '\n'){
			incrWordCount(word);
			word = "";
		}
		else if(i == text.length()-1){
			word += text[i];
			incrWordCount(word);
			word = "";
		}
		else{
			word += text[i];
		}
	}
}

