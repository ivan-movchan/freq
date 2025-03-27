// See LICENSE file for copyright and licensing details.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION      "1.2"
#define YEARS        "2025"
#define AUTHOR       "Ivan Movchan <ivan.movchan.07@gmail.com>"
#define HOMEPAGE     "https://github.com/ivan-movchan/freq"

const int  MAX_BYTE = 256;

const char *DISPLAY_FORMAT_BYTE       = "0x%02X\t";
const char *DISPLAY_FORMAT_COUNT      = "%d";
const char *DISPLAY_FORMAT_PERCENTAGE = "\t\t%.2f%%";

const char *LOW_ASCII_BYTES[] = {
	"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
	" BS", " HT", " LF", " VT", " FF", " CR", " SO", " SI",
	"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
	"CAN", " EM", "SUB", "ESC", " FS", " GS", " RS", " US",
	" SP"
};

void usage()
{
	puts("Usage: freq [-pv] [< input_file]");
	exit(EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
	int display_percentage = 0;
	
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			if (!strcmp(argv[i], "-p"))
			{
				display_percentage = 1;
			}
			else if (!strcmp(argv[i], "-v"))
			{
				printf("freq %s\nCopyright (C) %s %s\n%s\n", VERSION, YEARS, AUTHOR, HOMEPAGE);
				return EXIT_SUCCESS;
			}
			else
			{
				usage();
			};
		};
	};

	int counts[MAX_BYTE], len = 0;
	memset(counts, 0, (MAX_BYTE * sizeof(counts[0])));

	while (!feof(stdin))
	{
		counts[fgetc(stdin)]++;
		len++;
	};

	len -= ((len > 1) ? 1 : 0);

	for (int i = 0; i < MAX_BYTE; ++i)
	{
		if (counts[i] > 0)
		{
			printf(DISPLAY_FORMAT_BYTE, i);
			printf("\t");
			printf(DISPLAY_FORMAT_COUNT, counts[i]);
			printf((display_percentage ? DISPLAY_FORMAT_PERCENTAGE : ""), (counts[i] * 100.0 / len));
			puts("");
		};
	};

	return EXIT_SUCCESS;
}
