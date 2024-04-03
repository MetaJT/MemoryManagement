# Programming Assignment #3: Memory Management and Address Translation
_**Goal:** To gain a better understanding of memory management concepts, by implementing a program that translates logical addresses to physical addresses using a page/frame table._


Using the vector `pageFrameTable`, the table is initialized with -1 indicating no mapping initially. Using sample data, I inserted the frame numbers into `pageFrameTable`. 

After initializing the table, the `translateAddress` function takes in an `int logicalAddress` and `std::vector<int> pageTable`. Within the function we first find `pageNumber` by taking logical shift right of `logicalAddress` 8 times and
then using the & operator to get the last 8 bits. 
For `offset` we take the `logicalAddress` and BITWISE & with `0xFF` to get the first 8 bits.

