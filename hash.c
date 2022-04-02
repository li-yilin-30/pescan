#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
//默认初始分配足够长的空间，不添加扩容函数
int getpos(hashtable* ht,int key)
{
    return key%(ht->len);
    //返回坐标
}
//初始哈希表并置为空
void init(hashtable* ht,int len)
{
    ht->table=(hashnode*)malloc(sizeof(hashnode)*len);
    ht->len=len;
    ht->size=0;

    for(int i=0;i<len;++i)
    {
        ht->table[i].state=empty;
    }
    printf("create success!\n");
}
void destroy(hashtable* ht)
{
    ht->len=0;
    ht->size=0;
    free(ht->table);
    ht->table=NULL;
}
//找到一个就加一
int addone(hashtable* ht, int key)
{ 
   int pos= getpos(ht,key);
   while(ht->table[pos].state==exist)
   {
       if(ht->table[pos].key==key)
       {
          break;
          //找到了
       }
       else
       {
           ++pos;
       }
   }
   ht->table[pos].value +=1;

   
}
//插入
int insert(hashtable* ht, int key,int value)
{
   int pos= getpos(ht,key);
   while(ht->table[pos].state==exist)
   {
       if(ht->table[pos].key==key)
       {
           return 0;
       }
       else
       {
           ++pos;
       }
   }
   ht->table[pos].state = exist;
   ht->table[pos].key = key;
   ht->table[pos].value = value;
   ht->size++;
}
//找到应该插入的位置
hashnode* findhs(hashtable* ht, int key)
{
  int pos= getpos(ht,key);
   while(ht->table[pos].state!=empty)
   {
       if(ht->table[pos].key==key)
       {
           return &ht->table[pos];
       }
       else
       {
           ++pos;
       }
   }
  // printf("not find");
   return NULL;
}
//删除
int removehs(hashtable* ht, int key)
{
    hashnode* node=findhs(ht,key);
    if(node)
    {
        ht->size--;
        node->state=empty;
        return 1;
    }
    printf("delete fail");
    return 0;
}
int  isempty(hashtable* ht)
{  //返回1代表为空
    return ht->size==0?1:0;
}
void showinfo(hashtable* ht)
{
    printf("total capacity:%d\n",ht->len);
    printf("current capacity:%d\n",ht->size);
}
//支持的功能添加、删除、查找
