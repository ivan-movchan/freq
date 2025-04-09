/*
 * Copyright (c) 2025 Ivan Movchan <ivan.movchan.07@gmail.com>
 *
 * This file is a part of freq.
 *
 * freq is free software released under the terms of MIT License.
 * See LICENSE file for further details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#define VERSION      "1.2"
#define YEARS        "2025"
#define AUTHOR       "Ivan Movchan <ivan.movchan.07@gmail.com>"
#define HOMEPAGE     "https://github.com/ivan-movchan/freq"
#define LICENSE      "MIT License"

void usage()
{
	puts("Usage: freq [-pv] [< input_file]");
	exit(EXIT_SUCCESS);
}

void version()
{
	printf(
		"freq %s — Copyright (C) %s %s.\n"
		"freq is free software released under the terms of %s.\n"
		"%s\n",
		VERSION, YEARS, AUTHOR, LICENSE, HOMEPAGE
	);
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
				version();	
			}
			else
			{
				usage();
			};
		};
	};

	int  counts[MAX_BYTE];
	int  len = 0;
	char c = '\0';

	memset(counts, 0, (MAX_BYTE * sizeof(counts[0])));

	while (!feof(stdin))
	{
		c = fgetc(stdin);
		len++;

		if (c < MAX_BYTE)
		{
			counts[c]++;
		}
		else
		{
			fprintf(stderr, DISPLAY_FORMAT_BYTE, c);
			fputs(" is greater than ", stderr);
			fprintf(stderr, DISPLAY_FORMAT_BYTE, MAX_BYTE);
			fputs(" — skipping.", stderr);
		};
	};

	len -= ((len > 1) ? 1 : 0);

	for (int i = 0; i < MAX_BYTE; ++i)
	{
		if (counts[i] > 0)
		{
			printf(DISPLAY_FORMAT_BYTE, i);
			printf(DISPLAY_FORMAT_COUNT, counts[i]);
			printf(
				(display_percentage ? DISPLAY_FORMAT_PERCENTAGE : ""),
			    (counts[i] * 100.0 / len)
			);
			puts("");
		};
	};

	return EXIT_SUCCESS;
}
