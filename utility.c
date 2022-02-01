/*
Dinesh Bhandari
1001802374
Assignment 2
David Levine
CSE 3320-001
// source from profeser code
//https://stackoverflow.com/questions/29182242/creating-multiple-processes-in-c
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct StringView {
  char *First;
  char *Last;
} StringView;

char *FindNextElementEnd(char *str) {
  if (*str == '"') {
    str += 1;
    while (*str) {
      if (*str == '"')
        break;
      str += 1;
    }
  }

  while (*str) {
    if (*str == ',' || *str == '\n' || *str == '\r')
      return str;
    str += 1;
  }

  return NULL;
}

uint32_t CountNumberOfEntries(char *input) {
  uint32_t count = 0;
  char *str = input;
  while (*str) {
    if (*str == '\n' || *str == '\r') {
      count += 1;
      str += 1;
      while (*str && (*str == '\n' || *str == '\r'))
        str += 1;
      continue;
    }
    str += 1;
  }

  return count;
}

void PrintStringView(FILE *fp, StringView str) {
  char *ptr = str.First;
  char *end = str.Last;

  while (ptr != end) {
    fprintf(fp, "%c", *ptr);
    ptr += 1;
  }
}

char *ReadEntireFile(const char *filepath)   // read file
{
  FILE *f = fopen(filepath, "rb");
  if (f == NULL)
    return NULL;

  fseek(f, 0, SEEK_END);                 //  https://www.cplusplus.com/reference/cstdio/fseek/
  long fsize = ftell(f);        //Returns the current value of the position indicator of the stream.          //https://www.cplusplus.com/reference/cstdio/ftell/
  fseek(f, 0, SEEK_SET);

  char *string = malloc(fsize + 1);
  fread(string, 1, fsize, f);
  fclose(f);

  string[fsize] = 0;
  return string;
}

/*
"time,latitude,longitude,depth,mag,magType,nst,gap,dmin,rms,net,id,updated,place,type,horizontalError,depthError,magError,magNst,status,locationSource,magSource\n";
//1        2         3      4  5    6      7   8   9    10  11  12  13     14 15
16             17           18     19      20      21           22
*/

enum EntryKind             //https://stackoverflow.com/questions/1619732/how-to-assign-a-value-to-an-enum-based-on-input-from-a-file-in-c
{
  entry_time,
  entry_latitude,
  entry_longitude,
  entry_depth,
  entry_mag,
  entry_magType,
  entry_nst,
  entry_gap,
  entry_dmin,
  entry_rms,
  entry_net,
  entry_id,
  entry_updated,
  entry_place,
  entry_type,
  entry_horizontalError,
  entry_depthError,
  entry_magError,
  entry_magNst,
  entry_status,
  entry_locationSource,
  entry_magSource,

  ENTRY_COUNT
};
typedef enum EntryKind EntryKind;

typedef struct Entry {
  StringView Member[ENTRY_COUNT];
} Entry;

typedef struct SortPair {
  double Key;
  uint32_t Index;
} SortPair;

void bubble_sort(SortPair *pair, unsigned size);


char *ParseEntry(char *trav, Entry *entry) {
  for (uint32_t comma = 0; comma < ENTRY_COUNT; ++comma) {
    StringView *view = entry->Member + comma;
    view->First = trav;
    view->Last = FindNextElementEnd(trav);
    trav = view->Last + 1;
  }

  while (*trav == '\n' || *trav == '\r')
    trav += 1;
  return trav;
}

void WriteEntry(FILE *fp, Entry *entry) {
  for (uint32_t comma = 0; comma < ENTRY_COUNT - 1; ++comma) {
    PrintStringView(fp, entry->Member[comma]);
    fprintf(fp, ",");
  }
  PrintStringView(fp, entry->Member[ENTRY_COUNT - 1]);
  fprintf(fp, "\n");
}



void bubble_sort(SortPair *pair, unsigned size) {
  for (int i = size - 1; i > 1; i--) {
    for (int j = 0; j < i; j++) {
      if (pair[j].Key > pair[i].Key) {
        SortPair temp = pair[i];
        pair[i] = pair[j];
        pair[j] = temp;
      }
    }
  }
}


int main() {
  double cpu_time;
   clock_t start, end;
 time_t t;
  start = clock();
   t = time(NULL);
 printf("PID : %d PPID : %d Driver time Start: %s ", getpid(), getppid(), ctime(&t));
  char *input = ReadEntireFile("all_month.csv");
  if (!input) {
    fprintf(stderr, "Error: Failed to open all_month.csv file.\n");
    return -1;
  }

  uint32_t entries_count = CountNumberOfEntries(input);
  printf("Number of entries found: %u\n", entries_count);  // count the file size
	// memories allocation for the data
  uint32_t allocated = entries_count - 1;
  Entry *entries = malloc(sizeof(Entry) * allocated);
  SortPair *pairs = malloc(sizeof(SortPair) * allocated);
  Entry header;

  if (!entries || !pairs) {
    fprintf(stderr, "Failed to allocate memory!\n");
    return -1;
  }

  char *trav = ParseEntry(input, &header);

  uint32_t used = 0;
  while (*trav) {
    if (used >= allocated) {
      fprintf(stderr, "Corrupted file.\n");
      return -1;
    }

    Entry *entry = entries + used;
    trav = ParseEntry(trav, entry);
    used += 1;
  }

  if (used != allocated) {
    fprintf(stderr, "Not all entries were parsed. %u out of %u were parsed.\n",
            used, allocated);
  }

  for (uint32_t entry_index = 0; entry_index < used; ++entry_index) {
    SortPair *pair = pairs + entry_index;
    Entry *entry = entries + entry_index;
    pair->Key = atof(entry->Member[entry_latitude].First);
    pair->Index = entry_index;
  }

                         bubble_sort(pairs, used);       // shorting function
 t = time(NULL);
 end = clock();

 printf("PID : %d PPID : %d Driver time End: %s\n", getpid(), getppid(), ctime(&t));

  return 0;
}
