//     Test Shortest Job First scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest1
//      SCHED_SJF algorithm
//      Order of arrival: A, B, C, D, E
//      Process  Burst Time  Priority  Arrival
//        P1         23          1         13
//        P2          9          4         0
//        P3          7          9         20
//        P4         26          10        18
//        P5          5          5         10
//        P6         33          1         13
//        P7         11          4         0
//        P8         12          9         20
//----------------------------------------------------------------------

void ThreadTest1()
{
 
    int  numThreads = 8;
    int  startTime[] = {13,0,20,18,10,13,0,20};
    int  burstTime[] = { 23,  9, 7, 26, 5, 33 ,11 ,12 };
    int   priority[] = { 1,4,9,10,5,1,4,9 };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_SJF);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

