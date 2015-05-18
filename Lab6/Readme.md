************Stable Sort***************
A.
Stable Sort Explaination: My program follows the rules for stable sort because
it places the first occurence of the element in its rightful place before placing
the second occurence right beside it. this is facilitated by the condition 
"if((*j)<(*min))", rather than "if((*j)<=(*min))" , where the first case takes care 
of the order, while the second case marks the last occurence of the similar
valued element as the 'min'



OUTPUT OF THE TEST HARNESS FOR STABLE SORT


**********TEST HARNESS FOR STABLE SORT*************
Defining a vector with 10 random numbers
Displaying the vector
m[0x25a81f0] = 6179
m[0x25a81f4] = 5249
m[0x25a81f8] = 7955
m[0x25a81fc] = 16003
m[0x25a8200] = 20574
m[0x25a8204] = 16759
m[0x25a8208] = 22841
m[0x25a820c] = 28950
m[0x25a8210] = 24031
m[0x25a8214] = 14072
m[0x25a8218] = 16759

Now sorting the vector...
pre:    6179 5249 7955 16003 20574 16759 22841 28950 24031 14072 16759 

Swapping value 5249 at location [0x25a81f4] with value 6179 at location [0x25a81f0] 
Swapping value 14072 at location [0x25a8214] with value 16003 at location [0x25a81fc] 
Swapping value 16003 at location [0x25a8214] with value 20574 at location [0x25a8200] 
Swapping value 16759 at location [0x25a8218] with value 22841 at location [0x25a8208] 
Swapping value 20574 at location [0x25a8214] with value 28950 at location [0x25a820c] 
Swapping value 22841 at location [0x25a8218] with value 24031 at location [0x25a8210] 
Swapping value 24031 at location [0x25a8218] with value 28950 at location [0x25a8214] 


post:   5249 6179 7955 14072 16003 16759 16759 20574 22841 24031 28950 
copies = 0, moves = 21

Displaying the sorted vector
m[0x25a81f0] = 5249
m[0x25a81f4] = 6179
m[0x25a81f8] = 7955
m[0x25a81fc] = 14072
m[0x25a8200] = 16003
m[0x25a8204] = 16759
m[0x25a8208] = 16759
m[0x25a820c] = 20574
m[0x25a8210] = 22841
m[0x25a8214] = 24031
m[0x25a8218] = 28950


In this particular test run we see that the two occurences of 16759 get sorted in 
the order in which they occur in the vector. the first occurence of 16759 which is
at memory location [0x25a8204] is sorted first and placed into the correct 
position i.e at location [0x25a8204]. The second occurence which occurs at 
location  m[0x25a8218] is  sorted into its correct position at sixth place. 
Hence, we see that both occurences of 16759 are sorted according to their order
of occurences, thus proving that this is a stable sort.



