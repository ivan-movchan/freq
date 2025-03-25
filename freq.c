// See LICENSE for copyright and licensing details.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define VERSION  "1.1"
#define YEARS    "2025"
#define AUTHOR   "Ivan Movchan <ivan.movchan.07@gmail.com>"
#define HOMEPAGE "https://github.com/ivan-movchan/freq"

#define MAX_CHAR UCHAR_MAX

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		if (!strcmp(argv[1], "-v"))
		{
			printf("freq %s\nCopyright (C) %s %s\n%s\n", VERSION, YEARS, AUTHOR, HOMEPAGE);
			return EXIT_SUCCESS;
		};
	};

	int counts[MAX_CHAR], len = 0;
	memset(counts, 0, (MAX_CHAR * sizeof(counts[0])));

	while (!feof(stdin))
	{
		counts[fgetc(stdin)]++;
		len++;
	};

	len -= ((len > 1) ? 1 : 0);

	for (int i = 0; i < MAX_CHAR; ++i)
	{
		if (counts[i] > 0)
		{
			printf("0x%02X:  %d (%.2f%%)\n", i, counts[i], (counts[i] * 100.0 / len));
		};
	};

	return EXIT_SUCCESS;
}
