#include "main.h"

/**
 * get flags - claculates flags
 * @format: formatted text in which to print the parameters
 * @i : takes on a parameter
 * return: it rerturn flages
 */

int get_flags(const char *format, int *i)
{
		for (a = 0; FLAGS_CH[j] != '\0'; a++)
			if (format[curr_i] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

