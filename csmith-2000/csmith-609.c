/*
 * This is a RANDOMLY GENERATED PROGRAM.
 *
 * Generator: csmith 2.4.0
 * Git version: c05ee1d
 * Options:   (none)
 * Seed:      2979058532
 */

#include "csmith.h"


static long __undefined;

/* --- Struct/Union Declarations --- */
#pragma pack(push)
#pragma pack(1)
struct S0 {
   signed f0 : 17;
   uint32_t  f1;
   signed f2 : 3;
   unsigned f3 : 3;
   volatile int8_t  f4;
};
#pragma pack(pop)

/* --- GLOBAL VARIABLES --- */
static struct S0 g_2[9] = {{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L},{-91,0x0194DDBCL,1,0,-1L}};


/* --- FORWARD DECLARATIONS --- */
static const uint32_t  func_1(void);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : g_2
 * writes: g_2
 */
static const uint32_t  func_1(void)
{ /* block id: 0 */
    struct S0 *l_3 = &g_2[2];
    (*l_3) = g_2[0];
    return g_2[0].f0;
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
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_2[i].f0, "g_2[i].f0", print_hash_value);
        transparent_crc(g_2[i].f1, "g_2[i].f1", print_hash_value);
        transparent_crc(g_2[i].f2, "g_2[i].f2", print_hash_value);
        transparent_crc(g_2[i].f3, "g_2[i].f3", print_hash_value);
        transparent_crc(g_2[i].f4, "g_2[i].f4", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

/************************ statistics *************************
XXX max struct depth: 1
breakdown:
   depth: 0, occurrence: 0
   depth: 1, occurrence: 1
XXX total union variables: 0

XXX non-zero bitfields defined in structs: 3
XXX zero bitfields defined in structs: 0
XXX const bitfields defined in structs: 0
XXX volatile bitfields defined in structs: 0
XXX structs with bitfields in the program: 1
breakdown:
   indirect level: 0, occurrence: 1
XXX full-bitfields structs in the program: 0
breakdown:
XXX times a bitfields struct's address is taken: 1
XXX times a bitfields struct on LHS: 0
XXX times a bitfields struct on RHS: 1
XXX times a single bitfield on LHS: 0
XXX times a single bitfield on RHS: 1

XXX max expression depth: 1
breakdown:
   depth: 1, occurrence: 3

XXX total number of pointers: 1

XXX times a variable address is taken: 1
XXX times a pointer is dereferenced on RHS: 0
breakdown:
XXX times a pointer is dereferenced on LHS: 1
breakdown:
   depth: 1, occurrence: 1
XXX times a pointer is compared with null: 0
XXX times a pointer is compared with address of another variable: 0
XXX times a pointer is compared with another pointer: 0
XXX times a pointer is qualified to be dereferenced: 0

XXX max dereference level: 1
breakdown:
   level: 0, occurrence: 0
   level: 1, occurrence: 1
XXX number of pointers point to pointers: 0
XXX number of pointers point to scalars: 0
XXX number of pointers point to structs: 1
XXX percent of pointers has null in alias set: 0
XXX average alias set size: 1

XXX times a non-volatile is read: 2
XXX times a non-volatile is write: 2
XXX times a volatile is read: 0
XXX    times read thru a pointer: 0
XXX times a volatile is write: 0
XXX    times written thru a pointer: 0
XXX times a volatile is available for access: 3
XXX percentage of non-volatile access: 100

XXX forward jumps: 0
XXX backward jumps: 0

XXX stmts: 2
XXX max block depth: 0
breakdown:
   depth: 0, occurrence: 2

XXX percentage a fresh-made variable is used: 50
XXX percentage an existing variable is used: 50
FYI: the random generator makes assumptions about the integer size. See platform.info for more details.
********************* end of statistics **********************/

