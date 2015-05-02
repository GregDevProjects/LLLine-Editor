#ifndef RATIONAL_H
#define RATIONAL_H 
#include <string>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

struct node
{
public:
	string data;               // will store information
	node *next;             // the reference to the next node
};

class LinkedList{
public:
	void addNodeFirst(string input);
	void readFile(string location);
	void addNodeLast(string data);
	void iPress(int currentPosition, string input);
	void writefile(string location);
	void sPress(int replacePosition, string input);
	int dPress(int, int);
	void lPress();
	node *head;
	int countNodes();
	int gPress(int input);
	void showNodes();

};

class Validation{
public:
	bool passesLineBufferValidation(int totalLines, int inputLine, bool isIPress);
	string parseOneParameterFile(string input);
	int parseOneParamaterLine(string input);
	int parseTwoParameterLine(string input, bool returnFirstParameter);
	bool passesStartupValidation(int argc, char** argv);
	int inputValidation(string input, int line, int maxLines);

};
#endif