void CountOff( int n, int m, int out[] )
{
    int i=0 , a[n+2] , j=1 , num=0 , k=n;//k����ʣ�µ�����
    for(j=0 ; j<=n+1 ; j++){
        a[j]=1;
    }
    j=1;
   do{
       if(a[num]==1){
           i++;//�����������Ѿ�����̭��
       }
        if(i==m){
            out[num]=j;//��¼������ǵڼ�������̭��
            i=0;//���¿�ʼ����
            j++;
            k--;//ʣ�µ�������һ
            a[num]=0;//������˽��б��
        }
        num++;
        if(num==n){
            num=0;//�µ�һ��
        }
    }while(k>0);
}

