#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
TODO:
Handle integer overflow in all cases
*/

// Enum for ease of use
enum operandType
{
	INTEGER,
	STRING,
	INVALID
};

// Get inputs
char* GetExpressionInput(int* expressionLength);
char* GetOperand1(char* expression, int expressionLength, int* operandLen);
char* GetOperand2(char* expression, int expressionLength, int* operandLen);

// Get information from strings
int GetOperator(char* expression, int expressionLength, char* operation);
int GetOperandType(char* operand, int operandLen);

// Boolean checks
int IsOperator(char curChar);
int IsNumeric(char curChar);
int IsAlpha(char curChar);
int IsInvalidCharacter(char curChar);
int CheckOpForOverflow(char* op ,int oplen);

// Arithmetic operations
int SafeAdd(int num1, int num2, int* result);
int SafeMultiply(int num1, int num2, int* result);

// Process inputs
char* CalculateResult(char* operand1, char* operand2, int operand1Len, int operand2Len, int op1Type, int op2Type, char operation);
char* HandleAddition(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type);
char* HandleSubtraction(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type);
char* HandleMultiplication(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type);
char* HandleDivision(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type);
char* HandleModulus(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type);

// String processing
char* ConcatStrings(char* str1, char* str2, int str1Len, int str2Len);
char* ShiftString(char* str, int strLen, int key);
char* CutNCharactersFromString(char* str, int strLen, int cutNum);
char* AppendStringsByChar(char* dst, char* src, int srcLen, int* curLen);

char* GetValidInput(int* expressionLength, int* operand1Len, int* operand2Len, int* op1Type, int* op2Type, char** operand1, char** operand2, char* operation);

int main()
{
	// Get expression
	int expressionLength = 0;
	int operand1Len = 0;
	int operand2Len = 0;
	int op1Type = INVALID;
	int op2Type = INVALID;

	char* operand1 = NULL;
	char* operand2 = NULL;
	char* expression = NULL;
	char* result = NULL;

	char operation = 'e';

	expression = GetValidInput(&expressionLength, &operand1Len, &operand2Len, &op1Type, &op2Type, &operand1, &operand2, &operation);

	result = CalculateResult(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type, operation);

	printf("Result: %s\n", result);
	exit(0);
}

//-----------FUNCTIONS TO GET INPUTS-----------
char* GetExpressionInput(int* expressionLength) // Get expression from terminal
{
	(*expressionLength) = 0;

	int bufSize = 120;
	char* buffer = (char*)malloc(sizeof(char) * bufSize);

	printf("Enter an expression: ");

	// Read input from stdio
	fgets(buffer, bufSize - 1, stdin);

	// Strip newline
	for(int i = 0; i < bufSize; i++)
	{
		if(buffer[i] == '\n')
		{
			buffer[i] = '\0';
		}
	}

	// Count length of expression
	for(int i = 0; buffer[i] != '\0' && i < bufSize; i++)
	{
		(*expressionLength)++;
	}

	if(*expressionLength > 100)
	{
		while (getchar() != '\n');
	}

	// Set the last character to be a '\0'
	buffer[bufSize - 1] = '\0';
	return buffer;
}

char* GetOperand1(char* expression, int expressionLength, int* operandLen)// Return NULL if error, operand1 otherwise
{
	// Get length of operand1
	for(int i = 0; i < expressionLength && !IsOperator(expression[i]); i++)
	{
		(*operandLen)++;
	}

	char* buffer = (char*)malloc(sizeof(char) * (*operandLen));

	for(int i = 0; i < *operandLen; i++)
	{
		buffer[i] = expression[i];
	}

	buffer[(*operandLen)] = '\0';

	if((*operandLen) > 0)
	{
		return buffer;
	}

	return NULL;
}

char* GetOperand2(char* expression, int expressionLength, int* operandLen)// Return NULL if error, operand1 otherwise
{
	int operatorIndex = 0;

	for(int i = 0; i < expressionLength && !IsOperator(expression[i]); i++)
	{
		operatorIndex++;
	}

	(*operandLen) = expressionLength - operatorIndex - 1;

	char* buffer = (char*)malloc(sizeof(char) * (*operandLen));

	for(int i = 0; i < (*operandLen); i++)
	{
		buffer[i] = expression[i + operatorIndex + 1];
	}

	buffer[(*operandLen)] = '\0';

	if((*operandLen) > 0)
	{
		return buffer;
	}

	return NULL;
}


//------------PULL INFORMATION FROM STRINGS--------
int GetOperandType(char* operand, int operandLen)// Returns INTEGER, STRING, or INVALID
{
	int qInt = 0;
	int qString = 0;

	for(int i = 0; i < operandLen; i++)
	{
		// Track flag for string
		if(IsAlpha(operand[i]))
		{
			qString = 1;
		}

		// Track flag for int
		if(IsNumeric(operand[i]))
		{
			qInt = 1;
		}

		if(IsInvalidCharacter(operand[i]))
		{
			return INVALID;
		}

		// Operand contains an operator
		if(IsOperator(operand[i]))
		{
			return INVALID;
		}
	}

	// Handle mixed input
	if(qInt && qString)
	{
		return INVALID;
	}

	// Handle return types
	if(qInt)
	{
		return INTEGER;
	}

	if(qString)
	{
		return STRING;
	}

	return INVALID;
}

int GetOperator(char* expression, int expressionLength, char* operation)// Return 1 on success, 0 on failure
{
	// Check for valid string
	if(expression == NULL)
	{
		printf("ERROR: Null expression!\n");
		return 0;
	}

	// For every character in expression, check if it is an operator. If so, return it. Otherwise, return 'e'.
	for(int i = 0; i < expressionLength; i++)
	{
		if(!IsOperator(expression[i]))
		{
			continue;
		}

		*operation = expression[i];
		return 1;
	}

	// If no character, return 0
	return 0;
}


//------------BOOLEAN CHECKS--------------
int IsOperator(char curChar)
{
	if(curChar == '+' || curChar == '-' || curChar == '*' || curChar == '/' || curChar == '%')
	{
		return 1;
	}

	return 0;
}

int IsNumeric(char curChar)
{
	if(curChar < '0' || curChar > '9')
	{
		return 0;
	}

	return 1;
}

int IsAlpha(char curChar)
{
	if(curChar >= 'a' && curChar <= 'z')
	{
		return 1;
	}

	if(curChar >= 'A' && curChar <= 'Z')
	{
		return 1;
	}

	return 0;
}

int IsInvalidCharacter(char curChar)
{
	if(!IsOperator(curChar) && !IsNumeric(curChar) && !IsAlpha(curChar))
	{
		return 1;
	}

	return 0;
}

int CheckOpForOverflow(char* op, int oplen)
{
	char res[oplen];
	sprintf(res, "%i", atoi(op));

	// convert result from atoi back to string and compare. If not the same, there has been overflow
	if(strcmp(op, res) != 0)
	{
		return 0;
	}

	return 1;
}


//----------------ARITHMETIC OPERATIONS-----------
int SafeAdd(int num1, int num2, int* result)//Add and check for buffer overflow, 0 on failure, 1 on success
{
	(*result) = 0;

	// num1 + num2 > INT_MAX -> num > INT_MAX - NUM2
	if(num1 > INT_MAX - num2)
	{
		return 0;
	}

	// num1 - num2 < INT_MIN -> num1 < INT_MIN + num2
	if(num1 < INT_MIN + num2)
	{
		return 0;
	}

	(*result) = num1 + num2;
	return 1;
}

int SafeMultiply(int num1, int num2, int* result)
{
    // Check for overflow by comparing against INT_MAX and INT_MIN
    if (num1 != 0 && (num2 > INT_MAX / num1 || num2 < INT_MIN / num1)) {
        // Overflow detected
        *result = 0;
        return 0;
    }

    // Safe to multiply
    *result = num1 * num2;
    return 1;
}


//---------------PROCESS INPUTS-------------
char* CalculateResult(char* operand1, char* operand2, int operand1Len, int operand2Len, int op1Type, int op2Type, char operation)
{
	/*
	printf("operand1: %s\n", operand1);
	printf("operand2: %s\n", operand2);
	printf("op1Len: %i\n", operand1Len);
	printf("op2Len: %i\n", operand2Len);
	printf("op1Type: %i\n", op1Type);
	printf("op2Type: %i\n", op2Type);
	printf("operation: %c\n", operation);
	*/

	switch(operation)
	{
		case('+'):
			return HandleAddition(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type);

		case('-'):
			return HandleSubtraction(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type);

		case('*'):
			return HandleMultiplication(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type);

		case('/'):
			return HandleDivision(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type);

		case('%'):
			return HandleModulus(operand1, operand2, operand1Len, operand2Len, op1Type, op2Type);
	
		default:
			printf("Unexpected charcter for operation: %c\n", operation);
			return "";
	}
}

char* HandleAddition(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type)
{
	// Add numbers and return
	if(op1Type == INTEGER && op2Type == INTEGER)
	{
		char* result = (char*)malloc(sizeof(char) * 101);
		int resNum = 0;

		// Perform addition using SafeAdd
		if(!(SafeAdd(atoi(operand1), atoi(operand2), &resNum)))
		{
			printf("Integer overflow!\n");
		}

		sprintf(result, "%i", resNum);
		return result;
	}

	// operand1 is int, operand2 is string
	if(op1Type == INTEGER && op2Type == STRING)
	{
		return ShiftString(operand2, op2Len, atoi(operand1));
	}

	// operand1 is string, operand2 is int
	if(op1Type == STRING && op2Type == INTEGER)
	{
		return ShiftString(operand1, op1Len, atoi(operand2));
	}
}

char* HandleSubtraction(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type)
{
	// Add numbers and return. Overflow not possible since at least one operand is positive
	if(op1Type == INTEGER && op2Type == INTEGER)
	{
		char* result = (char*)malloc(sizeof(char) * 101);
		int resNum = atoi(operand1) - atoi(operand2);
		sprintf(result, "%i", resNum);
		return result;
	}

	// operand1 is int, operand2 is string
	if(op1Type == INTEGER && op2Type == STRING)
	{
		return ShiftString(operand2, op2Len, -1 * atoi(operand1));
	}

	// operand1 is string, operand2 is int
	if(op1Type == STRING && op2Type == INTEGER)
	{
		return ShiftString(operand1, op1Len, -1 * atoi(operand2));
	}
}

char* HandleMultiplication(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type)
{
	// Multiply numbers and return
	if(op1Type == INTEGER && op2Type == INTEGER)
	{
		char* result = (char*)malloc(sizeof(char) * 101);
		int resNum = 0;

		if(!SafeMultiply(atoi(operand1), atoi(operand2), &resNum))
		{
			printf("Integer overflow!\n");
		}

		sprintf(result, "%i", resNum);
		return result;
	}

	// operand1 is int, operand2 is string
	if(op1Type == INTEGER && op2Type == STRING)
	{
		// Some variables concerning length
		int totalChars = atoi(operand1) * op2Len;
		int curLen = 0;

		// Cap length
		if(totalChars > 1024)
		{
			printf("Too long! Truncating result...\n");
			totalChars = 1024;
		}

		// Malloc
		char* result = (char*)malloc(sizeof(char) * totalChars);

		// Append strings limited to n characters
		for(int i = 0; i < atoi(operand1); i++)
		{
			result = AppendStringsByChar(result, operand2, op2Len, &curLen);

			if(curLen >= 1024)
			{
				return result;
			}
		}

		return result;
	}

	// operand1 is string, operand2 is int
	if(op1Type == STRING && op2Type == INTEGER)
	{
		int totalChars = atoi(operand2) * op1Len;
		int curLen = 0;

		if(totalChars > 1024)
		{
			printf("Too long! Truncating result...\n");
			totalChars = 1024;
		}

		char* result = (char*)malloc(sizeof(char) * totalChars);

		for(int i = 0; i < atoi(operand2); i++)
		{
			result = AppendStringsByChar(result, operand1, op1Len, &curLen);

			if(curLen >= 1024)
			{
				return result;
			}
		}

		return result;
	}
}

char* HandleDivision(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type)
{
	// Divide numbers and return. Overflow not possible because its always 2 pos operands
	if(op1Type == INTEGER && op2Type == INTEGER)
	{
		char* result = (char*)malloc(sizeof(char) * 101);
		sprintf(result, "%i", atoi(operand1) / atoi(operand2));
		return result;
	}

	// operand1 is int, operand2 is string
	if(op1Type == INTEGER && op2Type == STRING)
	{
		return(CutNCharactersFromString(operand2, op2Len, atoi(operand1)));
	}

	// operand1 is string, operand2 is int
	if(op1Type == STRING && op2Type == INTEGER)
	{
		return(CutNCharactersFromString(operand1, op1Len, atoi(operand2)));
	}
}

char* HandleModulus(char* operand1, char* operand2, int op1Len, int op2Len, int op1Type, int op2Type)
{
	// Divide numbers and return
	if(op1Type == INTEGER && op2Type == INTEGER)
	{
		char* result = (char*)malloc(sizeof(char) * 101);
		sprintf(result, "%i", atoi(operand1) % atoi(operand2));
		return result;
	}

	// operand1 is int, operand2 is string
	if(op1Type == INTEGER && op2Type == STRING)
	{
		return "\0";
	}

	// operand1 is string, operand2 is int
	if(op1Type == STRING && op2Type == INTEGER)
	{
		return "\0";
	}
}


//--------------------STRING PROCESSING--------------------
char* ShiftString(char* str, int strLen, int key)
{
	//key = key % 26;

	char* buffer = (char*)malloc(sizeof(char) * strLen);

	int tmp = 0;

	// Shift each character
	for(int i = 0; i < strLen; i++)
	{
		key = key % 26;

		// Do the shift
		tmp = (int)str[i] + key;

		// Handle overflows
		if(tmp > 'z')
		{
			tmp -= 26;
		}

		if(tmp < 'A')
		{
			tmp += 26;
		}

		if(tmp < 'a' && tmp > 'Z' && key < 0)
		{
			tmp += 26;
		}

		if(tmp < 'a' && tmp > 'Z' && key > 0)
		{
			tmp -= 26;
		}

		buffer[i] = (char)tmp;
	}

	// Append null terminator
	buffer[strLen] = '\0';

	return buffer;
}

char* CutNCharactersFromString(char* str, int strLen, int cutNum)
{
	if(cutNum >= strLen)
	{
		return "\0";
	}

	char* buffer = (char*)malloc(sizeof(char) * (strLen - cutNum));

	for(int i = 0; i < strLen - cutNum; i++)
	{
		buffer[i] = str[i];
	}

	return buffer;
}

char* AppendStringsByChar(char* dst, char* src, int srcLen, int* curLen)
{
	for(int i = 0; i < srcLen; i++)
	{
		sprintf(dst, "%s%c", dst, src[i]);
		(*curLen)++;
		if((*curLen) >= 1024)
		{
			return dst;
		}
	}

	return dst;
}

char* GetValidInput(int* expressionLength, int* operand1Len, int* operand2Len, int* op1Type, int* op2Type, char** operand1, char** operand2, char* operation)
{
	char* expression;
	int validInput = 0;

	do
	{
		// Reset length parameters
		*expressionLength = 0;
		*operand1Len = 0;
		*operand2Len = 0;

		// Get expression
		expression = GetExpressionInput(expressionLength);
		if(strcmp(expression, "") == 0)
		{
			printf("Empty input\n");
			continue;
		}

		// Check for operand1 and exit condition
		*operand1 = GetOperand1(expression, *expressionLength, operand1Len);

		if(*operand1 == NULL)
		{
			printf("Failed to get operand1\n");
			continue;
		}

		if(strcmp(*operand1, "exit") == 0)
		{
			printf("Exiting program...\n");
			exit(0);
		}

		// Check for operator existence
		if(!GetOperator(expression, *expressionLength, operation))
		{
			printf("No operator\n");
			continue;
		}

		// Check for operand 2
		*operand2 = GetOperand2(expression, *expressionLength, operand2Len);

		if(*operand2 == NULL)
		{
			printf("Failed to get operand2\n");
			continue;
		}
		
		// Check for valid operand types
		*op1Type = GetOperandType(*operand1, *operand1Len);
		*op2Type = GetOperandType(*operand2, *operand2Len);

		if(*op1Type == INVALID || *op2Type == INVALID)
		{
			printf("Invalid input(s) detected.\n");
			continue;
		}

		// Check for double string
		if(*op1Type == STRING && *op2Type == STRING)
		{
			printf("Both operands are strings\n");
			continue;
		}

		// Check for divide by 0 and mod by 0
		if((*op1Type == *op2Type) && (*operation == '/' || *operation == '%') && (atoi(*operand2) == 0))
		{
			printf("Divide or mod by 0 error\n");
			continue;
		}

		// Check for mod with string
		if(*operation == '%' && (*op1Type == STRING || *op2Type == STRING))
		{
			printf("Mod with string\n");
			continue;
		}

		// check for length limits
		if(*operand1Len > 100 || *operand2Len > 100)
		{
			printf("Inputs too big!\n");
			continue;
		}

		// Check for overflow on operands
		if((*op1Type == INTEGER) && !CheckOpForOverflow(*operand1, *operand1Len))
		{
			printf("Input contains integer overflow!\n");
			continue;
		}

		// Check for overflow on operands
		if((*op2Type == INTEGER) && !CheckOpForOverflow(*operand2, *operand2Len))
		{
			printf("Input contains integer overflow!\n");
			continue;
		}

		validInput = 1;

	} while(!validInput);
}
