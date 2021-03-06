/* Author:  Jonathan Plona
   Date:    January 17, 2008 */
   
void merge_sort(int data[], int size, int start);
/* IN: An array, a size, and a starting index.
 * OUT: Sorts the array in place.
 */
 
void merge(int data[], int size, int start);
/* IN: An array, the combined size of the sub-arrays, and a starting index.
 * OUT: Merges the two sub-arrays contained within the main array.
 */
 
void merge_sort_pub(int data[], int size);
/* IN: And array and a size.
 * OUT: Calls merge_sort(data, size, 0) for compatibility with function pointer in driver program.
 */
 
void merge_sort_pub(int data[], int size)
{
    merge_sort(data, size, 0);
}
 
void merge_sort(int data[], int size, int start)
{
    //BASE CASE
    //If sub-array is size 1, it is sorted.
    if(size == 1) return;
    
    //Sort first half.
    merge_sort(data, size/2, start);
    
    //Sort second half.
    merge_sort(data, size - size/2, start + size/2);
    
    //Merge two halves.
    merge(data, size, start);    
}//merge_sort



void merge(int data[], int size, int start)
{
    //Compute middle and upper bounds of sub-arrays. ('start' is lower bound)
    int upper = start + size - 1;
    int middle = start + size/2;
    
    //Keep track of sub-array sizes
    int lenleft = size/2;
    int lenright = size - size/2;
    
    //Declare sub-arrays 'left' and 'right'
    int left[lenleft];
    int right[lenright];
    
    //Fill sub-arrays
    for(int x = start; x < middle; ++x) {
        left[x - start] = data[x];
    }
    for(int x = middle; x <= upper; ++x) {
        right[x - middle] = data[x];
    }
    
    //Create access pointers to the arrays
    int *rightptr = right;
    int *leftptr = left;
    
    //Loop through the section of the array we're merging
    for(int x = start; x <= upper; ++x) {
        //Create a variable to store the smallest element.
        int temp; 
        
        /* If both sub-arrays still contain elements, 
         * check the first element of each and assign the smaller to 'temp'.
         * Otherwise, take whatever remains.
         *
         * Each time an element is taken from a sub-array,
         * decrement that sub-array's length variable
         * and increment its access pointer.
         */
        if((lenright > 0) && (lenleft > 0)) {
            if(rightptr[0] < leftptr[0]) {
                temp = rightptr[0];
                rightptr = rightptr + 1;
                --lenright;
            }
            else {
                temp = leftptr[0];
                leftptr = leftptr + 1;
                --lenleft;
            }
        }
        else if(lenright > 0) {
            temp = rightptr[0];
            rightptr = rightptr + 1;
            --lenright;
        }
        else if(lenleft > 0) {
            temp = leftptr[0];
            leftptr = leftptr + 1;
            --lenleft;
        }
        else {
            //cout << "Shouldn't be here 1" << endl; //This should never happen.
            temp = 0;
        }
        
        //Assign element to the array.
        data[x] = temp; 
    }
}//merge
