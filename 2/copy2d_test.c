#include<stdio.h>
#include<sys/syscall.h>
#include<linux/kernel.h>
#include<unistd.h>
#include<errno.h>


void check_equal(double lhs[][5], double rhs[][5], int row, int column){

    int i;
    int j;
    for(i=0; i<row; i++){
    for(j=0; j<column; j++){
        if(lhs[i][j]!=rhs[i][j]){
            printf("error!!!!");
            return;
        }
    }

    }
    printf("successfull\n");
}

int main(){
    double src_arr[5][5] ={{1.5,2.5,3.5,4.5,5.5}, {1.5,2.5,3.5,4.5,5.5},{1.5,2.5,3.5,4.5,5.5},{1.5,2.5,3.5,4.5,5.5},{1.5,2.5,3.5,4.5,5.5}};
    double dest_arr[5][5];

    long sys_call_status = syscall(451, src_arr, dest_arr, 25);

    if(sys_call_status!=EFAULT){
        printf("message: 451\n");
        check_equal(src_arr, dest_arr, 5, 5);

    }
int j=0;
for(j=0;j<5;j++){
for(int i=0; i<5;i++){
printf("%f ",dest_arr[j][i]);
}
printf("\n");
}
    
    return 0;
}