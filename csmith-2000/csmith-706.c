/*
 * This is a RANDOMLY GENERATED PROGRAM.
 *
 * Generator: csmith 2.4.0
 * Git version: c05ee1d
 * Options:   (none)
 * Seed:      748123160
 */

#include "csmith.h"


static long __undefined;

/* --- Struct/Union Declarations --- */
/* --- GLOBAL VARIABLES --- */
static uint64_t g_2 = 18446744073709551606UL;
static int32_t g_4[2][1] = {{9L},{9L}};
static int32_t * volatile g_3 = &g_4[0][0];/* VOLATILE GLOBAL g_3 */


/* --- FORWARD DECLARATIONS --- */
static int8_t  func_1(void);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : g_2 g_3 g_4
 * writes: g_4
 */
static int8_t  func_1(void)
{ /* block id: 0 */
    int32_t *l_5 = &g_4[0][0];
    int32_t *l_6[5];
    uint32_t l_7[9];
    int i;
    for (i = 0; i < 5; i++)
        l_6[i] = &g_4[1][0];
    for (i = 0; i < 9; i++)
        l_7[i] = 0xDE0184DCL;
    (*g_3) = g_2;
    --l_7[3];
    return g_4[0][0];
}




/* ---------------------------------------- */
int main (int argc, char* argv[])
{
    int i, j;
    int print_hash_value = 0;
    if (argc == 2 && strcmp(argv[1], "1") == 0) print_hash_value = 1;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_4[i][j], "g_4[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

/************************ statistics *************************
XXX max struct depth: 0
breakdown:
   depth: 0, occurrence: 2
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

XXX max expression depth: 1
breakdown:
   depth: 1, occurrence: 5

XXX total number of pointers: 3

XXX times a variable address is taken: 3
XXX times a pointer is dereferenced on RHS: 0
breakdown:
XXX times a pointer is dereferenced on LHS: 1
breakdown:
   depth: 1, occurrence: 1
XXX times a pointer is compared with null: 0
XXX times a pointer is compared with address of another variable: 0
XXX times a pointer is compared with another pointer: 0
XXX times a pointer is qualified to be dereferenced: 43

XXX max dereference level: 1
breakdown:
   level: 0, occurrence: 0
   level: 1, occurrence: 1
XXX number of pointers point to pointers: 0
XXX number of pointers point to scalars: 3
XXX number of pointers point to structs: 0
XXX percent of pointers has null in alias set: 0
XXX average alias set size: 1

XXX times a non-volatile is read: 2
XXX times a non-volatile is write: 2
XXX times a volatile is read: 0
XXX    times read thru a pointer: 0
XXX times a volatile is write: 1
XXX    times written thru a pointer: 0
XXX times a volatile is available for access: 4
XXX percentage of non-volatile access: 80

XXX forward jumps: 0
XXX backward jumps: 0

XXX stmts: 3
XXX max block depth: 0
breakdown:
   depth: 0, occurrence: 3

XXX percentage a fresh-made variable is used: 20
XXX percentage an existing variable is used: 80
********************* end of statistics **********************/

