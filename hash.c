#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
//Ĭ�ϳ�ʼ�����㹻���Ŀռ䣬��������ݺ���
int getpos(hashtable* ht,int key)
{
    return key%(ht->len);
    //��������
}
//��ʼ��ϣ����Ϊ��
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
//�ҵ�һ���ͼ�һ
int addone(hashtable* ht, int key)
{ 
   int pos= getpos(ht,key);
   while(ht->table[pos].state==exist)
   {
       if(ht->table[pos].key==key)
       {
          break;
          //�ҵ���
       }
       else
       {
           ++pos;
       }
   }
   ht->table[pos].value +=1;

   
}
//����
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
//�ҵ�Ӧ�ò����λ��
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
//ɾ��
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
{  //����1����Ϊ��
    return ht->size==0?1:0;
}
void showinfo(hashtable* ht)
{
    printf("total capacity:%d\n",ht->len);
    printf("current capacity:%d\n",ht->size);
}
//֧�ֵĹ�����ӡ�ɾ��������
