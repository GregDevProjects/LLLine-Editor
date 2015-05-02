// As1v2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"


//Each node is consists of two fields. The first field holds the value or data and
//the second field holds the reference to the next node or null if the linked list is empty.
using namespace std;


string lineNumber(int number)
{
	 std::string s = std::to_string(number);

	return "You are at line " + s;
}



int main(int argc, char** argv)
{

	string readFile = "";
	string writeFile = "";

	int currentLineNumber = 0;

	Validation val;

	LinkedList list;

	list.head = NULL;

	
	
	bool startVal = val.passesStartupValidation(argc, argv);
	//if starting parameters don't pass validation 
	if (!startVal)
	{
		string errorMessage = "Parameters entered incorrectly, use EDIT <inputfile> <outputfile>";
		cout << errorMessage << endl;
		_getch();

	}
	else
	{
		readFile = argv[2];
		writeFile = argv[3];

		list.readFile(readFile);

		list.lPress();

		currentLineNumber = list.countNodes();

		cout << lineNumber(currentLineNumber) << endl;

		string lineInput;
		int insertLine;
		int endLine;
		string input;
		int deleteReturn;
		string insertQuery = "Enter data to be inserted at ";
		string substituteQuery = "Enter data to be substituted at ";
		string lineError = "Cannot execute the command, it is outside the buffer range";
		string inputError = "Command entered incorrectly";

		bool continueCommands = true;

		while (continueCommands)
		{
			cin >> input;
			int totalLines = list.countNodes();
			int tryCommand = val.inputValidation(input, currentLineNumber,totalLines);

			switch (tryCommand)
			{
				//an i press with no nodes left 
			case 0:
				cout << insertQuery << currentLineNumber << endl;
				cin >> lineInput;
				list.addNodeFirst(lineInput);
				break;
			case 1:
				//an i press with no parameters
				cout << insertQuery << currentLineNumber << endl;
				cin >> lineInput;
				list.iPress(currentLineNumber, lineInput);
				break;
			case 2:
				//an i press with one parameter
				insertLine =val.parseOneParamaterLine(input);
				
				if (val.passesLineBufferValidation(totalLines, insertLine, true))
				{
					cout << insertQuery << insertLine << endl;
					cin >> lineInput;
					list.iPress(insertLine, lineInput);
				}
				else
				{
					cout << lineError << endl;
				}
				break;		
			case 3:
				// a q press
				continueCommands = false;
				break;
			case 4:
				// an e press
				lineInput = val.parseOneParameterFile(input);
				list.writefile(lineInput);
				cout << "save sucessful, press any key to quit" << endl;
				continueCommands = false;
				_getch();		
				break;
			case 5:
				// a d press with no parameters 
				deleteReturn = list.dPress(currentLineNumber, currentLineNumber);
				//if user wants to delete everything 
				if (deleteReturn == 0)
				{
					list.head = NULL;
				}
				break;
			case 6:
				//a d press with one parameter 
				insertLine = val.parseOneParamaterLine(input);
				if (val.passesLineBufferValidation(totalLines, insertLine,false))
				{
					deleteReturn = list.dPress(insertLine, insertLine);

					if (deleteReturn == 0)
					{
						list.head = NULL;
					}
				}
				else
				{
					cout << lineError << endl;
				}
				break;
			case 7:
				//a d press with two parameters 
				insertLine = val.parseTwoParameterLine(input, true);
				endLine = val.parseTwoParameterLine(input, false);

				if (val.passesLineBufferValidation(totalLines, insertLine,false) && val.passesLineBufferValidation(totalLines, endLine,false))
				{
					deleteReturn = list.dPress(insertLine, endLine);
					if (deleteReturn == 0)
					{
						list.head = NULL;
					}
				}
				else
				{
					cout << lineError << endl;
				}
				break;
			case 8:
				//a v press 
				list.showNodes();
				break;
			case 9:
				// a g press
				currentLineNumber = list.gPress(NULL);
				break;
			case 10:
				// a g press with parameters 
				insertLine = val.parseOneParamaterLine(input);
				currentLineNumber = list.gPress(insertLine);	
				break;
			case 11:
				// a l press
				list.lPress();
				break;
			case 12:
				//an s press
				if (val.passesLineBufferValidation(totalLines, currentLineNumber,false))
				{
					cout << substituteQuery << currentLineNumber << endl;
					cin >> input;
					list.sPress(currentLineNumber, input);
					list.lPress();
				}
				else
				{
					cout << lineError << endl;
				}
				break;
			case 13:
				//an s press with parameters 
				insertLine = val.parseOneParamaterLine(input);
				if (val.passesLineBufferValidation(totalLines, insertLine, false))
				{
					cout << substituteQuery << currentLineNumber << endl;
					cin >> input;
					list.sPress(insertLine, input);
					list.lPress();
				}
				else
				{
					cout << lineError << endl;
				}
				break;
			case 100:
				//if input doesn't match any regex patteren
				cout << inputError << endl;
				break;
			default: 
				break;
			}

		
			if (currentLineNumber > list.countNodes())
			{
				currentLineNumber = list.countNodes();
			}

			cout << lineNumber(currentLineNumber) << endl;
		}
	

	}
	return 0;
}

