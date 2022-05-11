#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void ReadFromSource(int maxNumbers, int maxNumber, char* path)
{
	// Open file
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
		if (maxNumbers > 0 && counter == maxNumbers)
			break;

		int bufferAsInt = atoi(buffer); // Read and parse string to int

		if (bufferAsInt > 0 && (bufferAsInt < maxNumber || maxNumber == -1))
		{
			bufferAsInt *= 2;
			printf("%d\n", bufferAsInt);
			counter++;
		}
	}
}

int main(int argc, char* argv[])
{
	// Enable to attach with debugger
	 //printf("Double_Num\n");
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
	else // keine extra Parameter --> Verwende default Werte
	{
		numbers = defaultNummbers;
		path = defaultPath;
	}

	//
	ReadFromSource(numbers, maxNumber, path);

	// Exit application with success-code
	exit(EXIT_SUCCESS);
}