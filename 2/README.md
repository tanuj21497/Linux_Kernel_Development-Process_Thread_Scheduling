What I had to do in this part?

In this part, we have to write a system call kernel_2d_memcpy(oned_copy in my case), using kernel functions like __copy_from_user and __copy_to_user 

How I do it:


Then I added my system call description in syscall_64.tbl on 451th system call number.(I will use this number to call the system call from a c code to test it. Also when I will do it, it will use the diff code which i created to run that system call 451)
I created a diff file which i will add inside my linux-5.19.9/kernel having sys.c file.

Then i will recompile my kernel with ending name hocus_pocus_3 to differntiate between my previous kernel and recompiled kernel with having the strength of using system call 451.

Then i made a test file copy2d_test which will test if my system call 451 is working properly.

how i made diff and test file:
As given in tut-7 how to use copy from user and copy to user function, i used them by passing a double(as float was giving errors during recompilation) type 2d matrix of src & dest(which i will get during copy2d_test.c), i copy the matrix in double type buffer matrix and copied bytes by passing to __copy_from user, similarly for __copy_to_user i used dest matrix to get data from buffer Matrix after giving it size of data. As these funtions set EFAULT error flag so i used them to detect errors.

Then i made test file that will use syscall function which will take as much parameters as i defined in SYSCALL_DEFINE function in diff, it will take syscall number and then will pass source and destination Matrix of double type(src_arr will get copied to dest_arr), If it return 0 . I will use check function to check if both are equal which will return Successfull if both are equal. Then print the dest_arr.
