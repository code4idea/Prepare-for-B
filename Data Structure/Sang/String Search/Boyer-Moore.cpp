#include <iostream>

using namespace std;

int skip[256];
int len;

int length(char* c)
{
	for(int i=0;;i++)
	{
		char tmp = *(c+i);
		if(tmp == 0)
		{
			return i;
		}
	}
}

void table(char* c)
{
	len = length(c);
	for(int i = 0;i<256;i++)
	{
		skip[i] = len;
	}
	for(int i = 0;i<len-1;i++)
	{
		skip[c[i]] = len - 1 - i;
	}
}

char *search(char *text, char *key)
{
	int m, n;
	char *p;

	m = length(text);
	n = length(key);

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
