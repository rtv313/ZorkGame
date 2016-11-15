#pragma once
#include<string>
#include<vector>
using namespace std;

class Dialog{
public:
	Dialog(const vector<string>*PlayerSentences, const vector<string>*NpcSentences, const char* NoteName);
	~Dialog();
	const vector<string>* PlayerSentences;
	const vector<string>* NpcSentences;
	string NoteName;
};

