#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void trieWalk (trie_t *t, const char *word)
{
	int i;

	if (t->sentinel)
		printf("%s\n", word);

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i]) {
			char *current_word = malloc(strlen(word) + 1);
			strncat(current_word, word, strlen(word));
			strncat(current_word, (char*) &i, 1);

			trieWalk(t->chars[i], current_word);
		}
}

void trieComplete (trie_t *t, const char *prefix)
{
	const char* original_prefix = prefix;
	int c;

	while ((c = *prefix++)) {
		if (t->chars[c] == NULL)
			return;

		t = t->chars[c];
	}

	trieWalk (t, original_prefix);
}

int main (void)
{
	DIR* bin = opendir("/bin");
	trie_t *t = trieInit();
	struct dirent *ent;

	while ((ent = readdir(bin)))
		if (ent->d_name[0] == 'n')
			printf("%s\n", ent->d_name);
	printf("\n");

	trieAdd(t, "nano");
	trieAdd(t, "nc");
	trieAdd(t, "nc.traditional");
	trieAdd(t, "netcat");
	trieAdd(t, "netstat");
	trieAdd(t, "nisdomainname");
	trieAdd(t, "ntfs-3g");
	trieAdd(t, "ntfs-3g.probe");
	trieAdd(t, "ntfs-3g.secaudit");
	trieAdd(t, "ntfs-3g.usermap");
	trieAdd(t, "ntfscat");
	trieAdd(t, "ntfsck");
	trieAdd(t, "ntfscluster");
	trieAdd(t, "ntfscmp");
	trieAdd(t, "ntfsdump_logfile");
	trieAdd(t, "ntfsfix");
	trieAdd(t, "ntfsinfo");
	trieAdd(t, "ntfsls");
	trieAdd(t, "ntfsmftalloc");
	trieAdd(t, "ntfsmove");
	trieAdd(t, "ntfstruncate");
	trieAdd(t, "ntfswipe");

	trieComplete(t, "n");

	trieFree(t);

	return 0;
}
