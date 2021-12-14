#include <iostream>

// Task 1
void cezarCrypt (char* message, int key)
{
	int idx = 0;
	while(message[idx] != '\0')
	{
		message[idx++] += key;
	}
}

void cezarEncrypt(char* message, int key)
{
	int idx = 0;
	while (message[idx] != '\0')
	{
		message[idx++] -= key;
	}
}

void printStr(char* string)
{
	int idx = 0;
	while (string[idx] != '\0')
	{
		printf("%c", string[idx++]);
	}
	printf("\n");
}

// Task 2

void transposCrypt (char* message, int key)
{
	int len = 0;
	while (message[len] != '\0') len++;

	char* table = new char[len];

	int idx = 0;
	int nCol = (len % key == 0) ? len / key : len / key + 1;
	for (int step = 0; step < key; step++)
		for(int i = 0; i < nCol; i++)
		{
			if (i * key + step < len)
				table[idx++] = message[i * key + step];
		}
	
	idx = 0;
	while (message[idx] != '\0')
	{
		message[idx] = table[idx++];
	}
	delete[] table;
}

void transposEncrypt(char* message, int key)
{
	int len = 0;
	while (message[len] != '\0') len++;

	char* table = new char[len];

	int idx = 0;
	int nCol = (len % key == 0) ? len / key : len / key + 1;
	
	for (int step = 0; step < nCol; step++)
		for (int i = 0; i < len / nCol; i++)
			if ((i * nCol + step) < len)
				table[idx++] = message[i * nCol + step];
	idx = 0;
	while (message[idx] != '\0')
	{
		message[idx] = table[idx++];
	}

	delete[] table;
}

int main ()
{
	char message[] = "Hello World!";
	const int KEY = 6;
	
	// Task 1
	printStr(message);
	cezarCrypt(message, KEY);
	printStr(message);
	cezarEncrypt(message, KEY);
	printStr(message);
	
	// Task 2
	transposCrypt(message, KEY);
	printStr(message);
	transposEncrypt(message, KEY);
	printStr(message);

	return 0;
}