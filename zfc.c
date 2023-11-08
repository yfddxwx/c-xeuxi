//#include<stdio.h>
//#include<string.h>
//
//int main(){
//	int i = 0,j=0;
//	char arr1[] = {'h','e','l','l','o'};
//	char arr2[] = "hello";
//	while(arr1[i]!='\0'){
//		printf("%c",arr2[i]);
//		i++;
//	}
//	char name[100] = "fathe";
//	char name1[] = "fathe";
//	i=0;
//	while(name[i]!='\0'){
//		printf("%c",name[i]);
//		i++;
//	}i=0;
//	while(name[i]!='\0'){
//		if(name[i]==name1[i]){
//			j++;
//		}i++;
//	}if(j==i){
//		printf("YES");
//	}else{
//		printf("NO");
//	}
//	if()
//}
//#include <stdio.h>
//#include <string.h>
//int main(){
//    char str1[101] = { 0 };
//    char str2[50] = { 0 };
//    gets(str1);
//    gets(str2);
//    strcat(str1, str2);
//    puts(str1);
//
//    return 0;
//}
#include <stdio.h>
#include <string.h>
int main(){
    char name1[100] = "abcdfe";
    char name2[100];
    int len = strlen(name1);
    printf("%d",len);
	int a=strcmp(name1,name2);
    return 0;
}

