#include <stdio.h>
#include <stdlib.h>

/* ---------------- GLOBAL + STATIC VARIABLES ---------------- */

/* Global variables */
int g_init = 42;          // initialized global → DATA
int g_uninit;             // uninitialized global → BSS

/* File-scope static variables */
static int s_init = 100;  // initialized static → DATA
static int s_uninit;      // uninitialized static → BSS

/* Global pointer to string literal*/
const char *global_str = "hello_global"; // literal lives in read only mem (.rodata) and global pointer - *global_str lives in data seg since its global +initialized

/* ---------------- RECURSION TO SHOW STACK GROWTH ---------------- */ 

void recurse(int level) 
{
    int local_rec = level;   // stack variable
// print recusrion depth and stack frame address each time the same function calls by recursion
// to know address use -- &local_rec -- But Why it is casted to void is -- since %p -- pointer format to avaoid compiler errors so cast it to void*
// Tip --pointer of heap --> stored in stack/ data/bss based on declaration ... memory is allocated in heap
    
    printf("Recursion level %d + &local_rec = %p\n", level, (void *)&local_rec); 

    if (level > 0)
        recurse(level - 1); //recursion function calls it till exit 
}

/* ---------------- MAIN MEMORY LAYOUT  ---------------- */

void show_memory_layout(void)
{
    int local_var = 10;          // stack
    // STATIC LOCAL SCOPE --> STORED IN DATA/BSS-- 
    //TIP -- When used in recurrent func calling , these values would be retained acrross fucn calls not overwritten / re-initialized
    static int local_static = 7; 
    int *heap_var = malloc(sizeof(int)); // heap ; but *heap_var stores in stack since its local func pointer ...malloc-- memory on heap

    if (!heap_var) //heap_var pointer would have either NULL(0)-- if malloc fails / VALID MEM ADDR -- if malloc success 
    {
        perror("malloc"); // prints the last s/m fail msg to avoid dereferencing null and segemntation fault
        return;
    }
    *heap_var = 123; //stores value in the address the heap pointer is pointing to

    const char *local_str = "hello_local"; // literal in rodata and pointer is local -- stack

    printf("\n=== MEMORY LAYOUT ADDRESSES ===\n\n");

//TIP -- IF U WANT TO PRINT ADDRR -- USE & to get the address of any variable --since its points to the region addr
// EG: &g_init --> Itself is a pointer --> where -- g_initis variable and &g_init gives to address of g_init whihc makes it a pointer
    /* Globals */
    printf("Global init        &g_init      : %p\n", (void *)&g_init); 
    printf("Global uninit      &g_uninit    : %p\n", (void *)&g_uninit);

    /* Statics */
    printf("Static init        &s_init      : %p\n", (void *)&s_init);
    printf("Static uninit      &s_uninit    : %p\n", (void *)&s_uninit);
    printf("Local static       &local_static: %p\n", (void *)&local_static);

    /* Stack */
    printf("Local variable     &local_var   : %p\n", (void *)&local_var);

    /* Heap */
    printf("Heap (malloc)      heap_var     : %p\n", (void *)heap_var);

    /* String literals */
    printf("Global string literal  global_str: %p\n", (void *)global_str);
    printf("Local string literal   local_str : %p\n", (void *)local_str);

    printf("\n=== STACK GROWTH USING RECURSION ===\n");
    recurse(5);

    free(heap_var); // to free heap memory
}

int main(void)
{
    show_memory_layout();
    return 0;
}

