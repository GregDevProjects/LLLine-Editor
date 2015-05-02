#include "stdafx.h"
#include "LinkedList.h"



void LinkedList::showNodes()
{
	cout << endl;
	node *currNode = head;

	while (currNode != NULL)
	{
		cout << "data = " << currNode->data << endl;

		currNode = currNode->next;
	}
}

void LinkedList::sPress(int replacePosition, string input)
{
	node* currentNode = head;
	node* replaceNode = new node();
	replaceNode->data = input;
	
	for (int i = 1; i < replacePosition + 1; i++)
	{
	
		if (i == replacePosition)
		{
			currentNode->data = input;
		}
		currentNode = currentNode->next;
	}
}


int LinkedList::gPress(int input)
{
	int linesInBuffer = countNodes();
			
			if (linesInBuffer == 0)
			{
				return 0;
			}
	
	
			if (input == NULL)
			{
				return 1;
			}
	
			if (input > linesInBuffer)
			{
				return 1;
			}
	
			return input;
}


void LinkedList::writefile(string location)
{
	ofstream myfile;
	myfile.open(location);
	
	
	
	node *currNode = head;
	
	while (currNode != NULL)
	{
	
	
		myfile << currNode->data << "\n";
		currNode = currNode->next;
	}
	
		
	myfile.close();
	
}


void LinkedList::lPress()
{
			cout << endl;
			node *currNode = head;
	
			if (head == NULL)
			{
				cout << "Buffer empty" << endl;
			}
	
			int i = 1;
			while (currNode != NULL)
			{
				cout << i << " " << currNode->data << endl;
	
				currNode = currNode->next;
	
				i++;
			}
}

int LinkedList::countNodes()
{
	//if no nodes
			if (head == NULL)
			{
				return 0;
			}
			else
			{
				int nodeNumber = 1;
	
				node *thisNode = head;
	
				while (thisNode->next != NULL)
				{
					thisNode = thisNode->next;
					nodeNumber++;
				}
	
				return nodeNumber;
			}
	
	
}

int LinkedList::dPress(int start, int finish)
{

	node *currentNode = head;
	node *beforeDelete = head;
	node *afterDelete = new node();

	int numberofNodes = countNodes();

	//check if user wants to delete all nodes
	if ((start == 1) && (finish == numberofNodes))
	{

		return 0;

	}
	else
	{
		//gets the node before and after deletion
		for (int i = 1; i < finish + 2; i++)
		{

			if (i == start - 1)
			{
				beforeDelete = currentNode;
			}

			if (i == finish + 1)
			{
				afterDelete = currentNode;
			}

			if (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
			else
			{
				if (finish == countNodes())
				{
					afterDelete = NULL;
				}
			}


		}


		if (start == 1)
		{
			*beforeDelete = *afterDelete;
		}
		else
		{
			beforeDelete->next = afterDelete;
		}
		currentNode = NULL;

		return 1;
	}
}

void LinkedList::iPress(int currentPosition, string input)
{
	//If the letter I is entered with a number n following it, then insert the
	//	text to be followed before line n.
	//	o If I is not followed by a number, then insert the text before the
	//	current line.

	//subtract 2 as we want to instert before the current line 
	int beforeInsertPosition = currentPosition - 1;
	int afterInsertPostion = currentPosition;

	node* currentNode = head;
	node* beforeInsertNode = new node();
	node* afterInsertNode = new node();
	node* newNode = new node();

	newNode->data = input;

	if (beforeInsertPosition == 0 && countNodes() < 2)
	{

		string oldHead = head->data;
		node *oldNode = new node;
		oldNode->data = oldHead;
		oldNode->next = NULL;


		*head = *newNode;

		head->next = oldNode;


		//head->next = oldHead;
	}
	else if (currentPosition == countNodes() + 1)
	{
		addNodeLast(input);
	}
	else
	{
		//go to the node before current node and set its next value to the new node 
		for (int i = 1; i < currentPosition + 1; i++)
		{



			if (i == beforeInsertPosition)
			{
				beforeInsertNode = currentNode;


			}

			if (i == afterInsertPostion)
			{
				afterInsertNode = currentNode;
			}

			if (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
		}


		cout << "before insert -> " << beforeInsertNode->data << " after insert -> " << afterInsertNode->data;

		if (beforeInsertPosition != 0)
		{
			beforeInsertNode->next = newNode;
			newNode->next = afterInsertNode;

		}
		else
		{

			head = newNode;
			head->next = afterInsertNode;

		}


	}
}

void LinkedList::addNodeLast(string data)
{
	node *n = new node();
	n->data = data;
	//head->next = n;
	//n->next = NULL;


	//ALTER THIS CODE 
	node *currNode = head;
	node *prevNode = NULL;


	for (int i = 0; i < countNodes(); i++)
	{
		prevNode = currNode;
		currNode = currNode->next;

	}



	if (prevNode != NULL)
	{
		prevNode->next = n;
		n->next = NULL;
	}
}

void LinkedList::readFile(string location)
{

	try{
		string line;
		ifstream myfile(location);
		if (myfile.is_open())
		{
			int i = 0;
			while (getline(myfile, line))
			{


				if (i == 0)
				{
					addNodeFirst(line);
				}
				else
				{
					addNodeLast(line);
				}

				i++;
			}
			myfile.close();
		}
	}
	catch (exception e)
	{
		cout << "Unable to open file ";
	}


}

void LinkedList::addNodeFirst(string input)
{

	{

		if (countNodes() == 0)
		{

			head = new node;
			head->data = input;
			head->next = NULL;

		}
		else
		{
			head->data = input;
		}


	}
}