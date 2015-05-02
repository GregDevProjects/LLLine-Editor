#include "stdafx.h"
#include "LinkedList.h"

bool Validation::passesLineBufferValidation(int totalLines, int inputLine, bool isIPress)
{
	if (isIPress)
	{
		if (totalLines+1 >= inputLine)
		{
			return true;
		}
	}

	if (inputLine > totalLines)
	{
		return false;
	}

	if (inputLine <= 0)
	{
		return false;
	}

	return true;
}

string Validation::parseOneParameterFile(string input)
{
	input.erase(0, 2);
	return input;
}

int Validation::parseOneParamaterLine(string input)
{
	input.erase(0, 2);
	int line = atoi(input.c_str());

	return line;
}

int Validation::parseTwoParameterLine(string input, bool returnFirstParameter)
{
	//erase first two characters from input command 
	input.erase(0, 2);

	bool readingFirstParameter = true;
	bool skippedFirstChar = false;
	string firstParameter;
	string secondParameter;

	int i = 0;
	//loop through input
	for (char& c : input) {
		string currentChar;
		stringstream ss;

		ss << c;
		ss >> currentChar;

		if (currentChar == "-")
		{
			readingFirstParameter = false;
		}

		//read first parameter until encountering a "-"
		if (readingFirstParameter)
		{
			firstParameter.append(currentChar);
		}
		else
		{
			if (skippedFirstChar)
			{
				secondParameter.append(currentChar);
			}
			else
			{
				skippedFirstChar = true;
			}
		}

	}


	//convert parameters to ints 

	int beginLine = atoi(firstParameter.c_str());
	int endLine = atoi(secondParameter.c_str());

	if (returnFirstParameter)
	{
		return beginLine;
	}
	else
	{
		return endLine;
	}


}

bool Validation::passesStartupValidation(int argc, char** argv)
{
	if (argc == 4)
	{
		string firstParameter = argv[1];

		if (firstParameter != "EDIT")
		{
			return false;
		}
		else
		{


			return true;
		}

	}
	else
	{

		return false;
	}
}

int Validation::inputValidation(string input, int line, int maxLines)
{
	string pattern = "^[i|d][-][1-9|0]+";


	regex numberEntered(pattern);

	regex iPress("^[i]");
	regex iWithNumbers("^[i][-][1-9|0]+");

	regex qPress("^[q]");

	regex ePress("^[e][-][a-z|0-9|.]+");

	regex dPress("^[d]");
	regex dPressOneNumber("^[d][-][1-9|0]+");
	regex dPressTwoNumbers("^[d][-][1-9|0]+[-][1-9|0]+");

	regex vPress("^[v]");

	regex gPress("^[g]");
	regex gWithNumbers("^[g][-][1-9|0]+");

	regex lPress("^[l]");

	regex sPress("^[s]");
	regex sWithNumbers("^[s][-][1-9|0]+");

	string query = "Enter data to be inserted at ";

	if (regex_match(input, iPress))
	{

		//RETURN 0 FOR ADDING THE FIRST NODE
		if (line == 0)
		{
			return 0;
			
		}
		//RETURN 1 FOR INSERTING AT A SPECIFIC POSITION
		else
		{
			return 1;
		}
	}
	//RETURN 2 IF INSERTING WITH A PARAMETER
	else if (regex_match(input, iWithNumbers))
	{
		return 2;
	}
	//RETURN 3 IF USER WANTS TO QUIT
	else if (regex_match(input, qPress))
	{
		return 3;
	}
	//RETURN 4 IF USER WANTS TO SAVE AN QUIT
	else if (regex_match(input, ePress))
	{
		return 4;
	}
	//RETURN 5 FOR DELETE WITH NO PARAMETERS
	else if (regex_match(input, dPress))
	{
		return 5;
	}
	//RETURN 6 FOR DELETE WITH ONE PARAMETER 
	else if (regex_match(input, dPressOneNumber))
	{
		return 6;

	}
	//RETURN 7 FOR DELETE WITH TWO PARAMETERS 
	else if (regex_match(input, dPressTwoNumbers))
	{
		return 7;
	}
	//RETURN 8 TO DISPLAY LINES WITHOUT NUMBERS 
	else if (regex_match(input, vPress))
	{
		return 8;
	}
	//RETURN 9 TO GO TO ANOTHER LINE IN THE BUFFER WITH NO PARAMETERS 
	else if (regex_match(input, gPress))
	{
		return 9;
	}
	//RETURN 10 TO GO TO ANOTHER LINE IN THE BUFFER WITH 1 PARAMETER
	else if (regex_match(input, gWithNumbers))
	{
		return 10;
	}
	//RETURN 11 TO LIST ALL NODES WITH NUMBERS 
	else if (regex_match(input, lPress))
	{
		return 11;
	}
	//RETURN 12 TO SUBSTITUTE A LINE 
	else if (regex_match(input, sPress))
	{
		return 12;
	}
	//RETURN 13 TO SUBSTITUTE A LINE WITH PARAMTERS 
	else if (regex_match(input, sWithNumbers))
	{
		return 13;
	}
	return 100;
}