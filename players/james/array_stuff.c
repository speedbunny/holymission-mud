/* this is an attempt at implementing a 128x128 array of single-bit
   values, using a global integer array of size 512. The
   array must be indexed in the range 0-127. 
*/

#define INDEX (x<<2) + (y>>5)
#define BIT   (y & 31)

store_array(x,y) { data[INDEX] |= (1<<BIT); }
clear_array(x,y) { data[INDEX] &= !(1<<BIT); }
test_array(x,y)  { return(data[INDEX] & (1<<BIT)) != 0; }
