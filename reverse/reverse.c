#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/// <summary>
/// Initialize Multi(MxN) Array for write pointer in pointer
/// </summary>
/// <param name="array"></param>
/// <param name="arrayLength"></param>
/// <param name="elementLength"></param>
void initMultiArray(char** array, int arrayLength, int elementLength)
{
	// dynamically allocate memory of size `n` for each row
	for (int i = 0; i < arrayLength; i++)
	{
		array[i] = (int*)calloc(elementLength, sizeof(char));
	}
}

void ReadFromSource(int maxNumbers, int maxNumber, char* path)
{
	// Open file
	FILE* file = stdin;

	int counter = 0;
	int bufferLength = 255;

	char* buffer = malloc(bufferLength * sizeof(char));
	char** numbers = malloc(bufferLength * sizeof(char*));

	// Init MultiArray
	initMultiArray(numbers, maxNumber, bufferLength);


	if (path) // - If not a nullpointer
	{
		file = fopen(path, "r"); // i --> read
		if (file == NULL || !file)
		{
			// Exit application with error message
			perror("File does not exist. (Reverse)");
			exit(EXIT_FAILURE);
		}
	}

	while (fgets(buffer, bufferLength, file)) // Read file, line by line
	{
		int bufferAsInt = atoi(buffer); // Read and parse string to int

		if (maxNumbers > 0 && counter == maxNumbers)
			break;

		// buffer must > 0 AND less maxNumber OR maxnumber equal -1
		// -1 means infinite or until file terminates/ memory leaks
		if (bufferAsInt > 0 && (bufferAsInt < maxNumber || maxNumber == -1))
		{
			// copy buffer with new ref at starting pointer at index counter
			strcpy(numbers[counter++], buffer);
		}
	}

	// print the list of numbers in reverse order
	for (int i = counter - 1; i >= 0; i--)
	{
		printf("%s", numbers[i]);
	}
}

int main(int argc, char* argv[])
{
	// Enable to attach with debugger
	//printf("Double_Num\elementLength");
	//Sleep(8000);

	// defaults
	const* defaultPath = NULL;
	int defaultNummbers = 10;

	// variables for args
	const* path = malloc(255 * sizeof(char));
	int numbers;
	int maxNumber = -1;

	if (argc > 4)
	{
		exit(EXIT_FAILURE);
	}
	else if (argc == 4) // Alle benötigten Parameter wurden übergeben
	{
		numbers = atoi(argv[1]);
		maxNumber = atoi(argv[2]);
		path = argv[3];
	}
	else if (argc == 3) // Nur Anzahl und MaxNumber für Zahlen wurde angegeben --> verwende temp-pfad
	{
		numbers = atoi(argv[1]);
		maxNumber = atoi(argv[2]);
		path = defaultPath;
	}
	else if (argc == 2) // Nur Anzahl und MaxNumber für Zahlen wurde angegeben --> verwende temp-pfad
	{
		numbers = atoi(argv[1]);
		path = defaultPath;
	}
	else
	{
		numbers = defaultNummbers;
		path = defaultPath;
	}

	// case: param char* instead of int
	if (numbers == 0)
		numbers = defaultNummbers;

	if (maxNumber == 0)
		maxNumber = -1;

	//
	ReadFromSource(numbers, maxNumber, path);

	// Exit application with success-code
	exit(EXIT_SUCCESS);
}