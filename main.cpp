// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

/*Attributes:
 * 1. There are very few comments describing the purpose of each statement
 * within the queue functions.
 * 2. A destructor is defined, but not a copy constructor or a copy assignment operator.
 * 3. several if statements are terminated with 'return;'. Instead, an else statement could
 * be used.
 * 4. The parameters of enqueue and the constructor should be const so they are not accidentally
 * modified.
 * 5. Both isEmpty() and isFull() function call size() unnecessarily. Queue contains a parameter
 * (count) that tracks the size of the queue. Utilizing this instead of size() would be
 *  more efficient.
 *  */

#include "testQueue.h"

// main function
int main()
{
    // call your test functions here!
    testSize();

    testIsEmpty();

    testIsFull();

    testDequeueEmpty();

    testDequeue();

    testEnqueueFull();

    testEnqueue();

    testPeekEmpty();

    testPeek();

    return 0;
}

