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

	// Open file
	FILE* file = stdin;

	if (path) // - If not a nullpointer
	{
		file = fopen(path, "r"); // r --> read
		if (file == NULL || !file)
		{
			//printf("Datei exisiert nicht");
			perror("Datei exisiert nicht");
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

	const* defaultPath = "DefaultNumbers.txt";
	int defaultNummbers = 10;

	const* path = malloc(255 * sizeof(char));
	int numbers;
	int maxNumber = -1;

	if (argc > 4)
	{
		printf("Zu viele Argumente angebeben\n");
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

	//printf("ReadFromSource\n\n");
	ReadFromSource(numbers, maxNumber, path);

	exit(EXIT_SUCCESS);
}