#include<stdio.h>

#include<stdlib.h>
#include<wait.h>
#include<string.h>

#include<unistd.h>



#include<pthread.h>

#include<sys/wait.h>


#include<time.h>



float time1 =0;

float time2 =0;

float time3 =0;



struct timespec t_initial;

clockid_t c_intial;

struct timespec tA;

struct timespec tB;

struct timespec tC;



struct sched_param param1;

struct sched_param param2;

struct sched_param param3;

int r;











void* countA(void* arg){

    clockid_t c=0;

    r = pthread_setschedparam(pthread_self(), SCHED_FIFO, &param1);



    for(long long int i=1;i<(int)pow(2, 32);i++){

        

    }



    int val = clock_gettime(c, &tA);



    if(val == -1){

        printf("Cannot get time properly in clock_gettime in thread A");

        return NULL;

    }



    time1 = tA.tv_sec-t_initial.tv_sec  + (tA.tv_nsec-t_initial.tv_nsec)/1e9; 



    pthread_exit(NULL);

    return NULL;

}



void* countB(void* arg){



    clockid_t c=0;

    r = pthread_setschedparam(pthread_self(), SCHED_RR, &param2);

    printf("%d\n", r);





    for(long long int i=1;i<(int)pow(2, 32);i++){

    

    }



    int val = clock_gettime(c, &tB);



    if(val == -1){

        printf("Cannot get time properly in clock_gettime in thread B");



        return NULL;

    }



    time2 = tB.tv_sec-t_initial.tv_sec  + (tB.tv_nsec -t_initial.tv_nsec )/1e9; 



    pthread_exit(NULL);







    

    return NULL;

}



void* countC(void* arg){



    clockid_t c =0;

    r = pthread_setschedparam(pthread_self(), SCHED_OTHER, &param3);

    printf("%d\n", r);





    for(long long int i=1;i<(int)pow(2, 32);i++){

    }



    int val = clock_gettime(c, &tC);



    if(val == -1){

        printf("Cannot get time properly in clock_gettime in thread C");



        return NULL;

    }

    time3 = tC.tv_sec - t_initial.tv_sec + (t_initial.tv_nsec - tC.tv_nsec)/1e9; 




    pthread_exit(NULL);

    

    return NULL;

}



int main(){



    int v_initial = clock_gettime(c_intial, &t_initial);



    pthread_t A;

    pthread_t B;

    pthread_t C;



    int ret = 0;







    int j=0;

    for(int i=0; i<10; i++){



    

    param1.sched_priority = 1+j;



    param2.sched_priority = 1+j;

    param3.sched_priority = 0;

    

    

    pthread_create(&A, NULL, countA, NULL);

 



    pthread_create(&B, NULL, countB, NULL);





    pthread_create(&C, NULL, countC, NULL);





    pthread_join(A, NULL);

    pthread_join(B, NULL);

    pthread_join(C, NULL);



    printf("Time for Thread A in sec = %f\n", time1);

    printf("Time for Thread B in sec = %f\n", time2);

    printf("Time for Thread C in sec = %f\n\n", time3);







    v_initial = clock_gettime(c_intial, &t_initial);

    if(v_initial<0){

        printf("yes");

    }





    j++;



    }









    return 0;

}