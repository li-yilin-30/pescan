#include <stdio.h>
#include <stdlib.h>
#include<unordered_map>
#include<iostream>
#include<fstream>
#include <algorithm>  
#include<vector>
#include<cstring>
#define MAX_LINE 2000
using namespace std;
vector<int> vec={12336,4626,18504,10504,47205,53199,10557,11304,14888,55962,20051,33984,65313,60397,9766,8486,9892,60927,65515,15615};
int main(int argc, char const *argv[])

{  ofstream os;     //创建一个文件输出流对象
    	os.open("good.txt");//将对象与文件关联
 char bufff[MAX_LINE];  
     FILE *fppp;           
     int len2;             
     if((fppp = fopen("./normal/name.txt","r")) == NULL)
     {
         perror("not found the name");
         exit (1) ;
     }
     while(fgets(bufff,MAX_LINE,fppp) != NULL)
     {
         len2 = strlen(bufff);
         bufff[len2-1] = '\0';  
         printf("%s %d \n",bufff,len2 - 1);
         unordered_map<int,int> mp;
      
         char buf[1];
           
         FILE *fp = NULL;
        int cnt = 0;
        string filename=bufff;
        filename="./normal/"+filename;
        
        
         fp = fopen(filename.c_str(), "rb");
    char lastchar;
    char windows[2];
    if(!fp){
        fputs("open failed!", stderr);
        return 1;
    }
    
    fread(buf, sizeof(char), 1, fp);
    lastchar = buf[0];
    int num=0;
    while((cnt = fread(buf, sizeof(char), 1, fp))){
          ++num;
            windows[0]=lastchar;
            windows[1]=buf[0];
        
         int left=(unsigned char)windows[0];
         int right=(unsigned char)windows[1];
         int tmp=left*256+right;
        mp[tmp]++;
        lastchar = buf[0];
        
    }
     
        for(int i=0;i<20;++i)     
    	os<<mp[vec[i]]<<' '; 
    	os<<0;
    	os<<endl;  //将输入的内容放入txt文件中
    	


  }  

 os.close();
    

    
   
    return 0; 
}
