#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void ReadFromSource(int maxNumbers, int maxNumber, char* path)
{	// Open file
	FILE* file = stdin;

	int counter = 0;
	int bufferLength = 255;

	char* buffer = malloc(bufferLength * sizeof(char));

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

	while (fgets(buffer, bufferLength, file))			// Read file, line by line
	{
		int bufferAsInt = atoi(buffer); // Read and parse string to int

		if (maxNumbers > 0 && counter == maxNumbers)
			break;

		if (bufferAsInt > 0 && (bufferAsInt < maxNumber || maxNumber == -1))
		{
			// prints current number
			printf("%d\n", bufferAsInt);
			counter++;
		}
	}
}

/// <summary>
/// .\rand_seq_1.exe 15 100000 "E:\Dev\Studium\TI_Week1\TI_Week1\Numbers\listn_000100.txt" 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	// argc         Anzahl der Argummente
	// argv[0] =    Name der Anwendung
	// argv[1...n]  n Argumente

	// argv[1] --> Anzahl der zu generierenden Zahlen
	// argv[2] --> Max Number
	// argv[3] --> DateiName

	// Enable to attach with debugger
	//printf("Start Rand_Seq_1\n");
	//Sleep(8000);

	// defaults
	const* defaultPath = "DefaultNumbers.txt";
	int defaultNummbers = 10;

	// variables for args
	const* path = malloc(255 * sizeof(char));
	int numbers;
	int maxNumber = -1;

	if (argc > 4)
	{
		perror("To many arguments (Reverse)");
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