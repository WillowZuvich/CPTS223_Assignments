//
// Created by Willow Zuvich on 9/8/23.
//

#include "testQueue.h"

/* Test ID: Queue Size Check - QSC
 * Unit: queue::size()
 * Description: test to determine if queue::size()
 * returns 0 if the queue object contains 0 items
 * Test Steps:
 *      1. Construct a queue object containing 0 items
 *      2. Invoke queue::size()
 *      3. Conditionally evaluate the value returned by
 *          queue::size()
 * Test data: size = 0
 * Precondition: queue object contains 0 items
 * Postcondition: queue object still contains 0 items
 * Expected Result: queue size is 0, 0 is returned
 * Actual result: 1 is returned
 * Status: test failed
 * */
void testSize()
{
    //construct queue
    queue q;
    //invoke queue::size()
    //conditionally evaluate value returned
    cout << "test QSC results: " << endl;
    if(q.size() == 0)
    {
        std::cout << "test QSC passed: expected value returned" << std::endl;
    }
    else
    {
        std::cout << "test QSC failed: unexpected value returned: " << q.size() << std::endl;
    }

}

/* Test ID: Empty Queue Check - EQC
 * Unit: queue::isEmpty()
 * Description: test to determine if queue::isEmpty()
 * returns 1 if queue object is empty
 * Test Steps:
 *      1. Construct empty queue object
 *      2. Invoke queue::isEmpty()
 *      3. Conditionally evaluate value returned by
 *          queue::isEmpty()
 * Test Data: size = 0
 * Precondition: queue object is empty
 * PostCondition: queue object is still empty
 * Expected Result: queue is empty, 1 is returned
 * Actual Result: 0 is returned
 * Status: test failed
 * */
void testIsEmpty()
{
    //construct empty queue object
    queue q;
    //invoke queue::isEmpty()
    //conditionally evaluate value returned
    cout << "test EQC results: " << endl;
    if(q.isEmpty() == 1)
    {
        cout << "test EQC passed: expected value returned" << endl;
    }
    else
    {
        cout << "test EQC failed: unexpected value returned: " << q.isEmpty() << endl;
    }
}

/* Test ID: Full Queue Check - FQC
 * Unit: queue::isFull()
 * Description: test to determine if queue::isFull()
 * returns 1 if a queue object is full
 * Test Steps:
 *      1. Construct a queue object with a size of 1
 *      2. Populate the queue object with one item
 *      3. Invoke queue::isFull
 *      4. Conditionally evaluate value returned
 *      by queue::isFull
 * Test Data: size = 1
 * Precondition: queue contains one item
 * PostCondition: queue still contains one item
 * Expected Result: queue is full, 1 is returned
 * Actual Result: 1 is returned
 * Status: test passed
 * */
void testIsFull()
{
    //Construct queue object with size 1
    queue q(1);
    //populate queue
    cout << "test FQC results: " << endl;
    q.enqueue(1);
    //invoke queue::isFull
    //Conditionally evaluate value returned
    if(q.isFull() == 1)
    {
        cout << "test FQC passed: expected value returned" << endl;
    }
    else
    {
        cout << "test FQC failed: unexpected value returned" << endl;
    }

}

/* Test ID: Dequeue on Empty Queue Check - DEQC
 * Unit: queue::dequeue
 * Description: test to determine if underflow is detected
 * when queue object is empty
 * Test Steps:
 *      1. Create empty queue object
 *      2. Invoke queue::dequeue
 * Test Data: size = 0
 * Precondition: queue object is empty
 * PostCondition: queue object is still empty
 * Expected Result: Queue is empty, output to screen "UnderFlow
 * \n Program Terminated"
 * Actual Result: output : "Removing 0"
 * Status: test failed
 * */
void testDequeueEmpty()
{
    //construct empty queue
    queue q;
    //invoke queue::dequeue
    cout << "test DEQC results: " << endl;
    q.dequeue();
}

/* Test ID: Dequeue Check - DC
 * Unit: queue::dequeue()
 * Description: test to determine if when queue::dequeue() is invoked on
 * non-empty queue object, the correct removed value is reported
 * Test Steps:
 *      1. Create empty queue object
 *      2. Populate the queue with one data item: 3
 *      3. Invoke queue::dequeue()
 * Test Data: size = 1
 * Precondition: Queue contains one data item (3)
 * PostCondition: Queue is empty
 * Expected Result: Output to screen: "Inserting 3\n
 * Removing 3"
 * Actual Result: "Inserting 3\nRemoving 1"
 * Status: test failed
 * */
void testDequeue()
{
    //construct queue object
    queue q;
    //populate queue with data item
    cout << "test DC results: " << endl;
    q.enqueue(3);
    //invoke queue::dequeue()
    q.dequeue();
}

/* Test ID: Enqueue check - EC
 * Unit: queue::enqueue()
 * Description: test to determine that when queue::enqueue() is invoked
 * on a non-full queue object, "Inserting (item)" is output
 * to the screen
 * Test Steps:
 *      1. Create queue object
 *      2. Invoke queue::enqueue() with data 3
 * Test Data: size = 0
 * Precondition: queue object is empty
 * PostCondition: queue object contains one data item
 * Expected Result: output to screen : "Inserting 3"
 * Actual Result: "Inserting 3"
 * Status: passed
 * */
void testEnqueue()
{
    //create queue object
    queue q;
    //invoke queue::enqueue()
    cout << "test EC results: " << endl;
    q.enqueue(3);
}

/* Test ID: Full Queue Enqueue Check - FQEC
 * Unit: queue::enqueue()
 * Description: test to determine that queue::enqueue() terminates
 * when queue object is full
 * Test Steps:
 *      1. Construct queue Object of size 1
 *      2. Populate queue with one data item (1)
 *      3. Invoke queue::enqueue(), insert data 1
 * Test Data: size = 2
 * Precondition: Queue object is full
 * PostCondition: Queue object is still full
 * Expected Result: Queue is full, Output to screen:
 * "Inserting 1\nOverFlow\n
 * Program Terminated"
 * Actual Result:"Inserting 1\nOverFlow\n
 * Program Terminated"
 * Status: passed
 * */
void testEnqueueFull()
{
    //construct queue object with size 1
    queue q(1);
    cout << "test FQEC results: " << endl;
    //Populate queue with one data item (1)
    q.enqueue(1);
    //Invoke queue::enqueue(), insert data 1
    q.enqueue(1);

}

/* Test ID: Empty Queue Peek Check - EQPC
 * Unit: queue::peek()
 * Description: test to determine if underflow is
 * detected by queue::peek() when queue object is
 * empty
 * Test Steps:
 *      1. Construct empty queue object
 *      2. Invoke queue::peek()
 * Test Data: size = 0
 * Precondition: queue object is empty
 * PostCondition: queue object is empty
 * Expected Result: queue is empty, "Overflow\n
 * Program Terminated"
 * Actual Result: ""
 * Status: test failed
 * */
void testPeekEmpty()
{
    //construct empty queue object
    queue q;
    //Invoke queue::peek()
    cout << "test EQPC results: " << endl;
    q.peek();

}

/* Test ID: Peek Check - PC
 * Unit: queue::peek()
 * Description: test to determine if correct value is
 * displayed when queue::peek is invoked
 * Test Steps:
 *      1. Construct queue object
 *      2. Populate queue with two data items, 3 and 1
 *      3. Invoke queue::peek()
 *      4. Conditionally evaluate output
 * Test Data: size = 2
 * Precondition: queue contains two data item
 * PostCondition: queue contains two data item
 * Expected Result: value at front of queue = 3, 3 is returned
 * Actual Result: 2 is returned
 * Status: test failed
 * */
void testPeek()
{
    //Construct queue object
    queue q;
    //Populate queue with two data items, 3 and 1
    q.enqueue(3);
    q.enqueue(1);
    //Invoke queue::peek()
    //Conditionally evaluate output
    cout << "test PC results: " << endl;
    if(q.peek() == 3)
    {
        cout << "test PC passed: expected value returned" << endl;
    }
    else
    {
        cout << "test PC failed: unexpected value returned: " << q.peek() << endl;
    }

}