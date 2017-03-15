#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH 1024

void caesarCipher(char* input, int key)
{
	for(int i=0;i<strlen(input)-1;i++)
	{
		if((input[i] > 64) && (input[i] < 91))
		{
			if((input[i] + key) > 90)
			{
				input[i] = input[i] - 26;
				input[i] = input[i] + key;
			}
			else 
			{
				input[i] = input[i] + key;
			}
		}
		
		if((input[i] > 96) && (input[i] < 123))
		{
			if((input[i] + key) > 122)
			{
				input[i] = input[i] - 26;
				input[i] = input[i] + key;
			}
			else 
			{
				input[i] = input[i] + key;
			}
		}
	}
}

int main() {
		
		puts("");
		puts("/           CAESAR CIPHER               /");
		puts("/           Ayush Newatia               /");
		puts("/               2012                    /");
		puts("/_______________________________________/");
		puts("");
		

	    char* buffer = (char *) malloc(BUFFER_LENGTH*sizeof(char));
	    
	    printf("Enter a word or sentence: ");
	    fgets(buffer, BUFFER_LENGTH, stdin);
	    
	    if (buffer[BUFFER_LENGTH - 1] == '\n') 
	    {
	        buffer[BUFFER_LENGTH - 1] = '\0';
	    }
	   
		char* userInput = (char *) malloc((strlen(buffer) + 1) *sizeof(char));
		for(int i=0;i<strlen(buffer) + 1;i++)
		{
			userInput[i] = buffer[i];
		}
		free(buffer);
		
		
		
		char* keyString = (char *) malloc(10*sizeof(char));
		
		keyInput:
		printf("Enter a key between 1 and 25: ");
		fgets(keyString, 10, stdin);
		
		if (keyString[1] == '\n') 
			    {
			       keyString[1] = '\0';
			    }
		
		int key = atoi(keyString);
		
		
		if(key < 1 || key > 25)
		{
			goto keyInput;
		}
		free(keyString);
		
		caesarCipher(userInput, key);
		
		puts("");
		printf("Encrypted Text: %s", userInput);
		printf("Use decrypter to decrypt. \n");
		
		free(userInput);
		puts("");
		printf("Press <Enter> to exit.");
		getchar();
		return 0;
}