/*
 * This is a RANDOMLY GENERATED PROGRAM.
 *
 * Generator: csmith 2.4.0
 * Git version: c05ee1d
 * Options:   (none)
 * Seed:      1958749396
 */

#include "csmith.h"


static long __undefined;

/* --- Struct/Union Declarations --- */
#pragma pack(push)
#pragma pack(1)
struct S3 {
   volatile signed f0 : 12;
   unsigned f1 : 21;
   volatile signed f2 : 31;
};
#pragma pack(pop)

/* --- GLOBAL VARIABLES --- */
static volatile uint64_t g_2[1][3] = {{5UL,5UL,5UL}};
static int32_t g_4[4] = {(-7L),(-7L),(-7L),(-7L)};
static int64_t g_6 = 2L;
static struct S3 g_11 = {-4,1033,-19064};/* VOLATILE GLOBAL g_11 */


/* --- FORWARD DECLARATIONS --- */
static const uint8_t  func_1(void);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : g_2 g_4
 * writes: g_4
 */
static const uint8_t  func_1(void)
{ /* block id: 0 */
    int32_t *l_3 = &g_4[1];
    int32_t *l_5[1];
    uint8_t l_7 = 0x57L;
    struct S3 *l_10 = &g_11;
    struct S3 **l_12 = &l_10;
    int i;
    for (i = 0; i < 1; i++)
        l_5[i] = &g_4[1];
    (*l_3) ^= g_2[0][1];
    ++l_7;
    (*l_12) = l_10;
    return g_4[1];
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
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_2[i][j], "g_2[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_4[i], "g_4[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_11.f0, "g_11.f0", print_hash_value);
    transparent_crc(g_11.f1, "g_11.f1", print_hash_value);
    transparent_crc(g_11.f2, "g_11.f2", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

/************************ statistics *************************
XXX max struct depth: 0
breakdown:
   depth: 0, occurrence: 4
XXX total union variables: 0

XXX non-zero bitfields defined in structs: 3
XXX zero bitfields defined in structs: 0
XXX const bitfields defined in structs: 0
XXX volatile bitfields defined in structs: 2
XXX structs with bitfields in the program: 1
breakdown:
   indirect level: 0, occurrence: 0
   indirect level: 1, occurrence: 1
XXX full-bitfields structs in the program: 0
breakdown:
XXX times a bitfields struct's address is taken: 1
XXX times a bitfields struct on LHS: 0
XXX times a bitfields struct on RHS: 0
XXX times a single bitfield on LHS: 0
XXX times a single bitfield on RHS: 0

XXX max expression depth: 1
breakdown:
   depth: 1, occurrence: 7

XXX total number of pointers: 4

XXX times a variable address is taken: 4
XXX times a pointer is dereferenced on RHS: 0
breakdown:
XXX times a pointer is dereferenced on LHS: 2
breakdown:
   depth: 1, occurrence: 2
XXX times a pointer is compared with null: 0
XXX times a pointer is compared with address of another variable: 0
XXX times a pointer is compared with another pointer: 0
XXX times a pointer is qualified to be dereferenced: 133

XXX max dereference level: 1
breakdown:
   level: 0, occurrence: 0
   level: 1, occurrence: 3
XXX number of pointers point to pointers: 1
XXX number of pointers point to scalars: 2
XXX number of pointers point to structs: 1
XXX percent of pointers has null in alias set: 0
XXX average alias set size: 1

XXX times a non-volatile is read: 2
XXX times a non-volatile is write: 5
XXX times a volatile is read: 1
XXX    times read thru a pointer: 0
XXX times a volatile is write: 0
XXX    times written thru a pointer: 0
XXX times a volatile is available for access: 12
XXX percentage of non-volatile access: 87.5

XXX forward jumps: 0
XXX backward jumps: 0

XXX stmts: 4
XXX max block depth: 0
breakdown:
   depth: 0, occurrence: 4

XXX percentage a fresh-made variable is used: 14.8
XXX percentage an existing variable is used: 85.2
FYI: the random generator makes assumptions about the integer size. See platform.info for more details.
********************* end of statistics **********************/

