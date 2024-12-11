#include <stdio.h>
#include <stdlib.h>

int GetUserInput(char* result);

// ===== String processing functions =====
void CountVowels(const char* str);
void SumNumbers(char* str);
void StripWhiteSpace(char* str);
void CompressInput(char* str);
void ReverseWords(char* str);
void FindIngWords(char* str);

// ===== Character functions =====
int IsNumeric(char curChar);
int IsEndOfWord(char curChar);

// ===== String functions =====
int MyStrnCmp(const char* str1, const char* str2, int numChars);
int MyStrNLen(const char* str, int n);

const int MAX_STR_SIZE = 999;

int main()
{
    char* userExpression = (char*)malloc(sizeof(char) * MAX_STR_SIZE);

    while(1)
    {
        // Get input
        if(GetUserInput(userExpression) == 0)
        {
            exit(-1);
        }

        // Handle exit condition
        if(MyStrnCmp(userExpression, "exit", MAX_STR_SIZE) == 0)
        {
            printf("Exiting program...\n");
            break;
        }

        // Do the operations
        CountVowels(userExpression);
        ReverseWords(userExpression);
        SumNumbers(userExpression);
        FindIngWords(userExpression);
        StripWhiteSpace(userExpression);
        CompressInput(userExpression);

        // Reset String
        for(int i = 0; i < MAX_STR_SIZE; i++)
        {
            userExpression[i] = '\0';
        }

        break;
    }

    // Free the string
    free(userExpression);
}

int GetUserInput(char* result)
{
    int validInput = 0;

    while(!validInput)
    {
        validInput = 1;

        // Prompt user
        printf("Enter your expression: ");

        // Get input from stdio
        fgets(result, MAX_STR_SIZE, stdin);

        // Strip newline
        for(int i = 0; i < MAX_STR_SIZE; i++)
        {
            if(result[i] == '\n')
            {
                result[i] = '\0';
            }
        }

        /*
        INPUT VALIDATION
        */
       
        // Try again on empty string
        /*if(MyStrnCmp(result, "", sizeof(result)) == 0)
        {
            printf("Input cannot be empty. ");
            validInput = 0;
            continue;
        }*/
    }

    // Empty stdin if overfull
    if(MyStrNLen(result, MAX_STR_SIZE) >= MAX_STR_SIZE - 1)
    {
        while (getchar() != '\n');
    }

    // Null-terminate string
    result[MAX_STR_SIZE - 1] = '\0';

    return 1;
}

void CountVowels(const char* str)
{
    enum Vowels
    {
        A,
        E,
        I,
        O,
        U
    };

    int vowels[5] = {0};

    // Search for the vowels
    for(int i = 0; str[i] != '\0'; i++)
    {
        char curChar = str[i];

        if(curChar == 'a' || curChar == 'A')
        {
            vowels[A]++;
            continue;
        }

        if(curChar == 'e' || curChar == 'E')
        {
            vowels[E]++;
            continue;
        }

        if(curChar == 'i' || curChar == 'I')
        {
            vowels[I]++;
            continue;
        }

        if(curChar == 'o' || curChar == 'O')
        {
            vowels[O]++;
            continue;
        }

        if(curChar == 'u' || curChar == 'U')
        {
            vowels[U]++;
            continue;
        }
    }

    // Print results
    printf("\n===== VOWEL COUNT =====\n");
    printf("A - %i\n", vowels[A]);
    printf("E - %i\n", vowels[E]);
    printf("I - %i\n", vowels[I]);
    printf("O - %i\n", vowels[O]);
    printf("U - %i\n", vowels[U]);
}

void SumNumbers(char* str)
{
    /*
    INTEGER OVERFLOW VULNERABLE
    */
    int sum = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(IsNumeric(str[i]))
        {
            sum += (int)(str[i] - '0');
        }
    }

    printf("\n===== SUM OF DIGITS IN STRING =====\n");
    printf("The sum of the digits in the string is %i\n", sum);
}

void StripWhiteSpace(char* str)
{
    printf("\n===== STRIP WHITESPACE =====\n");

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\t')
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");
}

void CompressInput(char* str)
{
    printf("\n===== COMPRESSED INPUT =====\n");
    for(int i = 0; str[i] != '\0'; i++)
    {
        // There will always be at least one of the current character
        int charCount = 1;
        printf("%c", str[i]);

        // Count duplicate characters in strings
        while(str[i] == str[i+1])
        {
            charCount++;
            i++;

            /*
            OUT OF BOUNDS EXCEPTION
            */

            // Check bounds
            /*if(i >= MAX_STR_SIZE)
            {
                break;
            }*/
        }

        // Ignore the counter for single characters
        if(charCount != 1)
        {
            printf("%i", charCount);
        }
    }

    printf("\n");
}

void ReverseWords(char* str)
{
    // Get the word count and construct a 2d array
    int wordCount = 1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            wordCount++;
        }
    }

    char** words = (char**)malloc(sizeof(char*) * wordCount);

    // Init the 2d array
    for(int i = 0; i < wordCount; i++)
    {
        words[i] = (char*)malloc(sizeof(char) * MAX_STR_SIZE);
    }

    // Set all of the strings to '\0'
    for(int i = 0; i < wordCount; i++)
    {
        for(int j = 0; j < MAX_STR_SIZE; j++)
        {
            words[i][j] = '\0';
        }
    }

    // Get each word from the string
    int curIndex = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            curIndex++;
            continue;
        }

        sprintf(words[curIndex], "%s%c", words[curIndex], str[i]);
    }

    // Print results
    printf("\n===== REVERSED WORDS =====\n");
    for(int i = wordCount - 1; i >= 0; i--)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Free the array
    for(int i = 0; i < wordCount; i++)
    {
        free(words[i]);
    }

    /*
    USE AFTER FREE
    */

    printf("%s\n", words[0]);
    free(words);
}

void FindIngWords(char* str)
{
    // Make string pointer
    char* ingPtr = str;
    char* wordPtr = str;

    int ingCount = 0;
    int wordLen = 0;
    int curMaxWordLen = 0;

    char* maxWord = NULL;

    printf("\n===== ING WORDS =====\n");
    printf("All \"-ing\" words:\n");

    // Loop till end of instring
    for(int i = 0; (ingPtr + 3)[0] != '\0'; i++)
    {
        // Adjust pointer
        ingPtr = &(str[i]);

        if(ingPtr == str || IsEndOfWord((ingPtr - 1)[0]))
        {
            wordPtr = ingPtr;
        }
        
        // Look for "ing" words
        if(ingPtr[0] == 'i' && ingPtr[1] == 'n' && ingPtr[2] == 'g' && IsEndOfWord(ingPtr[3]))
        {
            ingCount++;

            wordLen = 0;
            // Print word using word pointer
            printf("  ");
            for(int j = 0; !IsEndOfWord(wordPtr[j]); j++)
            {
                printf("%c", wordPtr[j]);
                wordLen++;
            }
            printf("\n");

            // Update maxWord
            if(wordLen > curMaxWordLen)
            {
                curMaxWordLen = wordLen;
                maxWord = wordPtr;
            }
        }
    }

    // Print statistics
    /*
    NULL DEREFERENCE
    */
    //if(maxWord != NULL)
    {
        printf("\nBiggest \"-ing\" word: ");
        while(!IsEndOfWord(maxWord[0]))
        {
            printf("%c", maxWord[0]);
            maxWord++;
        }
        printf("\n");
    }
    printf("\nNumber of \"-ing\" words: %i\n", ingCount);
}

int IsEndOfWord(char curChar)
{
    const char validEndChars[8] = {' ', '.', ',', '!', '\t', '?', '\0', '\n'};

    for(int i = 0; i < 8; i++)
    {
        if(curChar == validEndChars[i])
        {
            return 1;
        }
    }

    return 0;
}

int IsNumeric(char curChar)
{
    if(curChar >= '0' && curChar <= '9')
    {
        return 1;
    }

    return 0;
}

int MyStrnCmp(const char* str1, const char* str2, int numChars)
{
    int differences = 0;

    for(int i = 0; i < numChars; i++)
    {
        if(str1[i] != str2[i])
        {
            differences++;
        }

        if(str1[i] == '\0' || str2[i] == '\0')
        {
            break;
        }
    }

    return differences;
}

int MyStrNLen(const char* str, int n)
{
    int strSize = 0;

    for(int i = 0; i < n && str[i] != '\0'; i++)
    {
        strSize++;
    }

    return strSize;
}