/*ADVANTAGES/DISADVANTAGES LINKED LIST:
 * Advantage: The size of the list can grow or shrink according to the needs of the program. This means no space is wasted.
 * Particularly for this program where the user can add and remove items from the list, this is valuable.
 * Disadvantage: Searching for and deleting items in the list is not efficient. To search for or delete an item at the
 * end of the list, the program must iterate though all the previous items in the list.
*/

/*ADVANTAGES/DISADVANTAGES ARRAY:
 * Advantage: The array allows for random access. This means that if the index of an element is known,
 * the time complexity for accessing it is constant. This is useful for the 'load game' requirement because the
 * position of the profile in the array can be used to access the profile.
 * Disadvantage: Adding new profiles to the front of the array is extremely inefficient. All other items in the array
 * must be moved in order to accommodate the new item. The time and space requirements for this operation are unnecessarily
 * expensive.
 */

#include <iostream>
#include "Game.h"

int main()
{

    //seed random numbers
    srand ((unsigned int)time(NULL));

    Game G1;
    G1.Play();

    return 0;
}
