void CountOff( int n, int m, int out[] )
{
    int i=0 , a[n+2] , j=1 , num=0 , k=n;//k代表剩下的人数
    for(j=0 ; j<=n+1 ; j++){
        a[j]=1;
    }
    j=1;
   do{
       if(a[num]==1){
           i++;//报数，跳过已经被淘汰的
       }
        if(i==m){
            out[num]=j;//记录这个人是第几个被淘汰的
            i=0;//重新开始报数
            j++;
            k--;//剩下的人数减一
            a[num]=0;//将这个人进行标记
        }
        num++;
        if(num==n){
            num=0;//新的一轮
        }
    }while(k>0);
}

