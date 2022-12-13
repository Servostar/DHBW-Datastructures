#include "arrays.h"

#ifdef VISUALIZE

static int *ARR;
static int LEN;
static char *NAME;
static int COUNT;

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec) {
  struct timespec ts;
  int res;

  if (msec < 0) {
    errno = EINVAL;
    return -1;
  }

  ts.tv_sec = msec / 1000;
  ts.tv_nsec = (msec % 1000) * 1000000;

  do {
    res = nanosleep(&ts, &ts);
  } while (res && errno == EINTR);

  return res;
}

void draw(int *a, int *b) {
  const char *SOLID_BLOCK = "\u2588";
  const char *YELLOW = "\e[0;33m";
  const char *CYAN = "\e[0;36m";
  const char *RESET = "\e[0m";

  printf("\e[1;1H\e[2J");
  printf("Algorithm: %s Swaps: %d\n", NAME, COUNT);
  for (int y = 0; y < LEN; y++) {
    for (int x = 0; x < LEN; x++) {
      int h = ARR[x];

      char *color = (char *)RESET;
      if (ARR + x == a) {
        color = (char *)YELLOW;
      } else if (ARR + x == b) {
        color = (char *)CYAN;
      }

      printf("%s%s", color, LEN - h <= y ? SOLID_BLOCK : " ");
    }
    printf("%s\n", RESET);
  }
  msleep(50);
}

void init(int *arr, int len, const char *name) {
  COUNT = 0;
  ARR = arr;
  LEN = len;
  NAME = (char *)name;
}

#endif

void gen_worst(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    arr[i] = len - i;
  }
}

void print_array(int *arr, int len) {
  for (int x = 0; x < len; x++) {
    printf("%s%d", x == 0 ? "" : ", ", arr[x]);
  }
  printf("\n");
}

void populate(int *arr, int len) {
  for (int x = 0; x < len; x++) {
    arr[x] = x + 1;
  }
}

void shuffle(int *arr, int len) {
  for (int x = 0; x < len; x++) {
    int y = rand() % len;

    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;

#ifdef VISUALIZE
  COUNT++;
  draw(a, b);
#endif // VISUALIZE
}

bool is_sorted(int *arr, int len) {
  int last = 0;
  for (int x = 0; x < len; x++) {
    if (last > arr[x]) {
      return false;
    }
    last = arr[x];
  }
  return true;
}
