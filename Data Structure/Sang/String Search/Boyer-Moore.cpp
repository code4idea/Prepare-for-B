#include <stdio.h>
#include <string.h>

char *search(char *, char *);
void table(char *);

int skip[256];

int main(void)
{
	static char text[] = "Using the Hecomdmentsllo World guide, you'll stacommentsrt a braHellonch, write comments, and open a pHellcommentsoull request.";
	char *p;
	char key[] = "comments";

	table(key);
	p = search(text, key);
	while (p != NULL) {
		printf("%s\n", p);
		p = search(p + strlen(key), key);
	}

	return 0;
}

void table(char *key)    /* create skip table */
{
	int k, n;

	n = strlen(key);
	for (k = 0; k <= 255; k++)
		skip[k] = n;
	for (k = 0; k < n - 1; k++)
		skip[key[k]] = n - 1 - k;
}

char *search(char *text, char *key)
{
	int m, n;
	char *p;

	m = strlen(text);
	n = strlen(key);

	p = text + n - 1;
	while (p < text + m) {
			bool check = true;
			for (int i = n - 1; i >= 0; i--)
			{
				if (*(p - (n-i-1)) != key[i])
				{
					check = false;
					break;
				}
			}
			if (check) return p - n + 1;

		p = p + skip[*p];
	}

	return NULL;
}
