// University of Arkansas at Little Rock 
// Department of Computer Science 
// CPSI 28003: Algorithms 
// Fall 2025 
// Project 2: Infix to Postfix Conversion 
// Due Date: November 20, 2025 
// Name: Isaac Fredricks 
// T-number (Last 4 Digits): 4922 
// Description of the Program (2-3 sentences): This program is an infix (ex 1 + 2) to post fix converter (1 2 +). Spaces in the input in between numbers and operands does not matter since it will clean it up automatically with AddDelimitersToStr(char* str). The program runs infinitly until you press ctrl+c.
// Date Written: November 3rd, 2025
// Date Revised: 
#include <iostream> 
#include <string> 
#include <stack> 
#include <signal.h>//for exiting the program when you hit ctrl + c
using namespace std;

volatile sig_atomic_t stop;//for ending when ctrl-c

void intHand(int signal) {
	stop = 1;
}

// you can type an arithmetic expression with no, one or more than one spaces 
// between each operator and operand 
// If no spaces is given between each operator and operand, this function will add 
// spaces to them 

/*Isaac's steps for InfixToPostFix(char* str):
[J]create 1 stack for operands
[J]put numbers in a temporary string called num
[J]traverse the char * str
[J]find operands and put them in a stack. use precedence (*,/ > +,-)
[J]store in another string with numbers from 1st to last and operands second from last to first and evenly spaced. Except for parantheses, their operators have precedence
*/
string InfixToPostfix(char* str) {//psuedocode source: https://blackboard.ualr.edu/ultra/courses/_277313_1/outline/file/_5520041_1
	string tempString;
	stack<char> operands;//operands only 1 character so char
	//where I sort out the numbers and operands for the char *:
	for (int i{ 0 }; str[i] != '\0'; i++) {//I know that the string will be at most 80 characters
		//str[i] != '\0' checks if empty
		if (str[i] == ' ') {//just want program to keep going when a space occurs
			//cout << "space or parentheses here\n";//uncomment when done testing
		}
		else if (str[i] == '(') {//makes sure 3 + (4/2) * (5 * 6) -> 3 4 2 / 5 6 * * +
			operands.push(str[i]);//will get rid '(' later
		}
		else if (str[i] == ')') {
			while (!operands.empty() && operands.top() != '(') {
				tempString += operands.top();
				tempString += ' ';
				operands.pop();
			}
			if (!operands.empty() && operands.top() == '(') {
				operands.pop();//gets rid of parantheses
			}

		}
		else if (isdigit(str[i])) {//source: https://en.cppreference.com/w/cpp/string/byte/isdigit.html
			tempString += str[i];
			tempString += ' ';//want to add spaces seperately or else wierd behavior
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {//for storing operands
			int opPrecedence;//for operator precedence
			if (str[i] == '*' || str[i] == '/') {
				opPrecedence = 2;// * or / higher precedence than + or -
			}
			else {
				opPrecedence = 1;
			}
			while (!operands.empty()) {
				char topOperand = operands.top();
				int topOpPrecedence;//want seperate variable for this

				if (topOperand == '*' || topOperand == '/') {
					topOpPrecedence = 2;
				}
				else if (topOperand == '+' || topOperand == '-') {
					topOpPrecedence = 1;
				}
				else {//just in case
					topOpPrecedence = 0;
				}

				if (topOpPrecedence >= opPrecedence) {
					tempString += operands.top();
					tempString += ' ';//want to add spaces seperately or else wierd behavior
					operands.pop();
				}
				else {
					break;
				}
			}
			operands.push(str[i]);
			
		}
		else {
			//cout << "invalid input!!!\n";//I don't want the program to end when invalid input so I'll leave it commented out when submitting
		}
	}

	while (!operands.empty()) {//gets rid of any remaining operands
		tempString += operands.top();
		tempString += ' ';//have to add space seperately
		operands.pop();//removes top element from stack
	}

	return tempString;
}

char* AddDelimetersToStr(char* str)
{
	int spacesNeeded = 0;

	int length = 0;

	while (str[length] != '\0')  // hit enter on my computer,  
		// it produces \0, maybe your computer may produce different  
	{
		if (str[length] != ' ')
			spacesNeeded = spacesNeeded + 1;
		length = length + 1;
	}

	int size = length + spacesNeeded + 1;
	char* adjustedStr = new char[size];
	// insert delimeters between operands and operators 
	int newInx = 0;
	for (int inx = 0; inx < length; inx++)
	{
		if (str[inx] != ' ')
		{
			adjustedStr[newInx] = str[inx];
			newInx = newInx + 1;
			adjustedStr[newInx] = ' ';
			newInx = newInx + 1;
		}
	}
	adjustedStr[newInx] = '\0';

	//cout << "string with delimteres: " << adjustedStr << endl; 
	//system("PAUSE"); 
	return adjustedStr;
}

void main()
{
	// input arithmetic expression should be less than 79 characters 
	char* str = new char[80];
	signal(SIGINT, intHand);//checks if ctrl+c is pressed
	while (1) // type ccontrol_c to exit the loop 
	//source: https://stackoverflow.com/questions/26965508/infinite-while-loop-and-control-c
	{
		if (stop) {
			//cout << "Exiting program, goodbye.\n";//comment out when submitting
			break;//exits program if ctrl-c pressed
		}
		// you can assume legal arithemic expressions only 
		cout << "Enter an arithmetic equation..." << endl;  					
		cin.getline(str, 80);//stores input string
		//I did the same thing again plus || string because it would print the cout a few more times when ctrl+c without it
		if (stop || cin.fail()) {//added it another time to check again after inputting. also checks cin doesn't input correctly
			break;//exits program if ctrl-c pressed
		}
		str = AddDelimetersToStr(str);//adds needed spacing and removes unneeded spacing
		cout << InfixToPostfix(str) << endl;

	}

}
