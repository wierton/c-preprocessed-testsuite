/*
 * This is a RANDOMLY GENERATED PROGRAM.
 *
 * Generator: csmith 2.4.0
 * Git version: c05ee1d
 * Options:   (none)
 * Seed:      443394314
 */

#include "csmith.h"


static long __undefined;

/* --- Struct/Union Declarations --- */
union U3 {
   uint16_t  f0;
   const int64_t  f1;
   int32_t  f2;
};

/* --- GLOBAL VARIABLES --- */
static uint64_t g_2[4] = {2UL,2UL,2UL,2UL};
static int32_t g_3 = 0x47ADF1ADL;
static int32_t g_4 = 0x2D2C87A7L;
static union U3 g_6 = {0UL};


/* --- FORWARD DECLARATIONS --- */
static uint16_t  func_1(void);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : g_3 g_2
 * writes: g_3 g_4
 */
static uint16_t  func_1(void)
{ /* block id: 0 */
    union U3 *l_5[10] = {(void*)0,(void*)0,&g_6,(void*)0,(void*)0,&g_6,(void*)0,(void*)0,&g_6,(void*)0};
    int32_t l_7 = 0x08FB0B44L;
    int i;
    for (g_3 = 0; (g_3 <= 3); g_3 += 1)
    { /* block id: 3 */
        int i;
        g_4 = g_2[g_3];
    }
    l_5[2] = l_5[2];
    return l_7;
}




/* ---------------------------------------- */
int main (int argc, char* argv[])
{
    int i;
    int print_hash_value = 0;
    if (argc == 2 && strcmp(argv[1], "1") == 0) print_hash_value = 1;
    platform_main_begin();
    crc32_gentab();
    func_1();
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_2[i], "g_2[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_6.f0, "g_6.f0", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

/************************ statistics *************************
XXX max struct depth: 0
breakdown:
   depth: 0, occurrence: 3
XXX total union variables: 0

XXX non-zero bitfields defined in structs: 0
XXX zero bitfields defined in structs: 0
XXX const bitfields defined in structs: 0
XXX volatile bitfields defined in structs: 0
XXX structs with bitfields in the program: 0
breakdown:
XXX full-bitfields structs in the program: 0
breakdown:
XXX times a bitfields struct's address is taken: 0
XXX times a bitfields struct on LHS: 0
XXX times a bitfields struct on RHS: 0
XXX times a single bitfield on LHS: 0
XXX times a single bitfield on RHS: 0

XXX max expression depth: 2
breakdown:
   depth: 1, occurrence: 5
   depth: 2, occurrence: 1

XXX total number of pointers: 1

XXX times a variable address is taken: 2
XXX times a pointer is dereferenced on RHS: 0
breakdown:
XXX times a pointer is dereferenced on LHS: 0
breakdown:
XXX times a pointer is compared with null: 0
XXX times a pointer is compared with address of another variable: 0
XXX times a pointer is compared with another pointer: 0
XXX times a pointer is qualified to be dereferenced: 0
XXX number of pointers point to pointers: 0
XXX number of pointers point to scalars: 0
XXX number of pointers point to structs: 0
XXX percent of pointers has null in alias set: 100
XXX average alias set size: 2

XXX times a non-volatile is read: 4
XXX times a non-volatile is write: 3
XXX times a volatile is read: 0
XXX    times read thru a pointer: 0
XXX times a volatile is write: 0
XXX    times written thru a pointer: 0
XXX times a volatile is available for access: 0
XXX percentage of non-volatile access: 100

XXX forward jumps: 0
XXX backward jumps: 0

XXX stmts: 4
XXX max block depth: 1
breakdown:
   depth: 0, occurrence: 3
   depth: 1, occurrence: 1

XXX percentage a fresh-made variable is used: 75
XXX percentage an existing variable is used: 25
FYI: the random generator makes assumptions about the integer size. See platform.info for more details.
********************* end of statistics **********************/

