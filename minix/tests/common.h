
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <sys/statvfs.h>

#ifdef __minix
#include <sys/syslimits.h>
#endif

#ifdef __linux
#include <limits.h>
#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif
#endif

#define e(errn) e_f(__FILE__, __LINE__, (errn))
#define em(errn,msg) do { fprintf(stderr, "%s\n", msg); e(errn); } while(0)
#define efmt(...) fail_printf(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#ifdef __minix
#define me(x) e(x)
#else
#define me(x)
#endif

#define BIGVARNAME "BIGTEST"

#define INSTANTDEATHVARNAME "INSTANTDEATH"

#define ITERATIONS_ADAPTIVE (iterations_adaptive(ITERATIONS_FULL, ITERATIONS_QUICK))

void printprogress(char *msg, int i, int max);
void cleanup(void);
int does_fs_truncate(void);
void e_f(char *file, int lineno, int n);
void fail_printf(const char *file, const char *func, int line,
	const char *fmt, ...) __attribute__ ((format(printf, 4, 5)));
int name_max(char *path);
void quit(void);
void rm_rf_dir(int test_nr);
void rm_rf_ppdir(int test_nr);
void start(int test_nr);
void getmem(uint32_t *total, uint32_t *free, uint32_t *cached);
int get_setting_quick_test(void);
int get_setting_use_network(void);
int iterations_adaptive(int itfull, int itquick);

extern int common_test_nr, errct, subtest;
