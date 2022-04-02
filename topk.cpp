#include <stdio.h>
#include <stdlib.h>
#include<unordered_map>
#include<iostream>
#include <algorithm>  
#include<vector>
#include<cstring>
#define MAX_LINE 2000
using namespace std;
unordered_map<int,int> allbadexe;
unordered_map<int,int> allgoodexe;

int cmp(const pair<int, int>& x, const pair<int, int>& y)    
{    
    return x.second > y.second;    
}    
void sortMapByValue(unordered_map<int, int>& x,vector<pair<int, int> >& y)    
{    
    for (unordered_map<int, int>::iterator it = x.begin(); it != x.end(); it++)     
        y.push_back(make_pair(it->first, it->second));      
     
    sort(y.begin(), y.end(), cmp);    
}    
     
int main(int argc, char const *argv[])

{  /* char bufff[MAX_LINE];  
     FILE *fppp;           
     int len2;             
     if((fppp = fopen("./virus/name.txt","r")) == NULL)
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
         vector<pair<int,int>> vec;
         char buf[1];
           
         FILE *fp = NULL;
        int cnt = 0;
        string filename=bufff;
        filename="./virus/"+filename;
        
        
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
    
    sortMapByValue(mp,vec);
    cout<<vec[1].first<<endl;
    cout<<vec[1].second<<endl;
      //将每个文件最高频的三十个特征加入到哈希表中，出现一次就加一。
      for(int i=0;i<30;++i)
      {
      allbadexe[vec[i].first]=vec[i].second;
      }
  }  
    vector<pair<int,int>> finalans1;
    sortMapByValue(allbadexe,finalans1);
    cout<<endl;
    for(int i=0;i<10;++i)
    {
          cout<<finalans1[i].first<<" "<<finalans1[i].second<<endl;
    //输出出现频率最高的10维向量
    }
     printf("success identify badxe\n");
    
    cout<<"next we identify goodexe"<<"-------------------------------------"<<endl;*/
    char buff[MAX_LINE];  
     FILE *fpp;            
     int len1;             
     if((fpp = fopen("./normal/name.txt","r")) == NULL)
     {
         perror("not found the name");
         exit (1) ;
     }
     while(fgets(buff,MAX_LINE,fpp) != NULL)
     {
         len1 = strlen(buff);
         buff[len1-1] = '\0';  
         printf("%s %d \n",buff,len1 - 1);
         unordered_map<int,int> mp;
         vector<pair<int,int>> vec;
         char buf[1];
           
         FILE *fp = NULL;
        int cnt = 0;
        string filename=buff;
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
    
    sortMapByValue(mp,vec);
    cout<<vec[1].first<<endl;
    cout<<vec[1].second<<endl;
      //将每个文件最高频的三十个特征加入到哈希表中，出现一次就加一。
      for(int i=0;i<30;++i)
      {
      allgoodexe[vec[i].first]=vec[i].second;
      }
  }  
    vector<pair<int,int>> finalans;
    sortMapByValue(allgoodexe,finalans);
    cout<<endl;
    for(int i=0;i<10;++i)
    {
          cout<<finalans[i].first<<" "<<finalans[i].second<<endl;
    //输出出现频率最高的10维向量
    }
    
    printf("success identify goodexe\n");
   
    

    
   
    return 0; 
}
