SYSCALL_DEFINE3(onedcopy, double**, src, double**, dest, int, len){

    double buffer[5][5];
    if(__copy_from_user(buffer, src, sizeof(double)* (len))){
        return -EFAULT;
    }

    if(__copy_to_user(dest, buffer, sizeof(double)* (len))){
        return -EFAULT;
    }

    return 0;
}