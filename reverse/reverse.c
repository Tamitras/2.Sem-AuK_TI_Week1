#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void ReadFromSource(int maxNumbers, int maxNumber, char* path)
{
	int bufferLength = 255;
	char* buffer = malloc(bufferLength * sizeof(char));
	int counter = 0;

	int * reverseList = malloc(sizeof(int) * maxNumbers == -1 ? 65536 : maxNumbers); /* n is the length of the array */

	// Open file
	FILE* file = stdin;

	if (path) // - If not a nullpointer
	{
		file = fopen(path, "r"); // r --> read
		if (file == NULL || !file)
		{
			//printf("Datei exisiert nicht");
			perror("Datei exisiert nicht (DoubleNumm)");
			exit(EXIT_FAILURE);
		}
	}

	while (fgets(buffer, bufferLength, file))			// Read line by line
	{
		if (maxNumbers > 0 && counter == maxNumbers)
			break;

		int bufferAsInt = atoi(buffer); // Read and parse string to int

		if (bufferAsInt > 0 && (bufferAsInt < maxNumber || maxNumber == -1))
		{
			reverseList[counter] = bufferAsInt;
			counter++;
		}
	}
	for (int i = counter-1; i>= 0; i--)
	{
		int temp = reverseList[i];
		printf("%d\n", temp);
	}
}

int main(int argc, char* argv[])
{
	// Enable to attach with debugger
	 //printf("Double_Num\n");
	 //Sleep(8000);

	const* defaultPath = NULL;
	int defaultNummbers = 10;

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

	//printf("ReadFromFile\n\n");
	ReadFromSource(numbers, maxNumber, path);

	exit(EXIT_SUCCESS);
}