#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[]){
time_t  nowtime;
struct tm *ptm;
time(&nowtime);
ptm=localtime(&nowtime);

if(argc==5){
printf("%s = %s\n",argv[1],argv[3]);
printf("%s = %s\n",argv[2],argv[4]);
}

else if(argc==4){
printf("%s = %s\n",argv[1],argv[3]);
printf("%s = %02d %02d %02d\n",argv[2],ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
}

else if(argc==3){
printf("%s = %d %02d %02d\n",argv[1],ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);

printf("%s = %02d %02d %02d\n",argv[2],ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
}

else{
printf("ERROR\n");
}


return 0;
}
