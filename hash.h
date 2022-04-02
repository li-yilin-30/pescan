#ifndef __HASH_H__
#define __HASH_H__
#define HASHSIZE 10240
//对于单个exe是够用了
typedef enum State {empty,exist}State;
//节点属性
//键值对以及是否插入判断
typedef struct node
{
    struct node *next; 
    int key;
    int value; 
    State state;
} hashnode;

typedef struct hashtable
{
    hashnode* table;//用动态数组实现
    int len;
    int size;

}hashtable;
//维护一个表
void init(hashtable* ht,int len);
void destroy(hashtable* ht);
int insert(hashtable* ht, int key,int value);
hashnode* findhs(hashtable* ht, int key);
int removehs(hashtable* ht, int key);
int  isempty(hashtable* ht);
void showinfo(hashtable* ht);
int addone(hashtable* ht, int key);


#endif
