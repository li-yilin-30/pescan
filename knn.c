#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define KK  7 //选择最近的十个邻居来考虑
int predlabel[400];
typedef struct disandlabel
{
    float  distance;
    int label;
}dlb;

float **createarray(int n,int s)
{
    int i;
    float **array;
    array=(float**)malloc(n*sizeof(float*));
    for( i=0; i<n; i++ )
    {
    array[i] = (float*)malloc(sizeof(float)*s);
    }
   return array;
}
void loaddata(int *n,int *d,float ***array,char* path,int flag)
{   int x=0;
    FILE *fp;
    if((fp=fopen(path,"r"))==NULL)
        printf("open txt failed!\n");
    if(fscanf(fp,"N=%d,D=%d",n,d)!=2)
        printf("not a valid dataset!\n");
    *array=createarray(*n,*d);
    int i,j;
    //存储数据
    float unuse;
    for(i=0;i<*n;i++)
    {
        for(j=0;j<*d;j++)
        {
            fscanf(fp,"%5f",&(*array)[i][j]);
          
           
        }
        if(flag==1)
        {
         fscanf(fp,"%3f",&predlabel[x]);
         x++;
        }
    }
    fclose(fp);
   
}
float getdistance(int n,float*a,float *b)
{   
    float dis=0.0;
  
    for(int i=0;i<n;++i)
    {      
        float x=pow((a[i]-b[i]),2);
       
        dis+=pow((a[i]-b[i]),2);
        
    }
    return sqrt(dis);
}
void show(int *a,int *b,float***c)
{
    for(int i=0;i<*a;i++)
    {
        for(int j=0;j<*b;j++)
        {    
           printf("%3f ",(*c)[i][j]);
        }
        printf("\n");
    }
}  
int  judge(dlb a[],int x)
{
    int label1,label2;
    label1=0;
    label2=0;
    for(int i=0;i<x;++i)
    {
        a[i].label==1?label1++:label2++;
    }
    return label1>label2?1:0;
}

void sort_dlb(dlb a[],int x)   
{ float temp1;
  int temp2;
  for(int i=0;i<x;i++)
	{
		for(int j=0;j<x-1-i;j++)
		{
			if(a[j].distance>a[j+1].distance)
			{
				temp1 =a[j+1].distance;
                temp2 =a[j+1].label;
				a[j+1].distance=a[j].distance;
				a[j+1].label=a[j].label;
                a[j].distance=temp1;
				a[j].label=temp2;
 
			}
		}
	}
} 
void showdlb(dlb a[],int x)

{
          for(int i=0;i<x;++i)
    {
        printf("%3f\n",a[i].distance);
        printf("%d\n",a[i].label);
    }

}
int main()
{
    float **array=NULL;
    float **predict_array=NULL;
    int D,N;
    int PD,PN;
    int pred[400];
    
    int predi=0;
    //最多预测一百条数据
    loaddata(&N,&D,&array,"data.txt",0);
    loaddata(&PN,&PD,&predict_array,"predict_data.txt",1);
   // show(&N,&D,&array);
    //show(&PN,&PD,&predict_array);
    //存储距离
    for(int w=0;w<PN;++w)
 { 
    dlb  ans[N];

    for(int i=0;i<N;++i)
    {
       ans[i].distance=getdistance(PD,predict_array[w],array[i]);

       ans[i].label=array[i][D-1];
      
    }
    sort_dlb(ans,N);
   // showdlb(ans,N);
    pred[w]=judge(ans,KK);
   // printf("%d\n",pred[w]);
 }
    //释放空间
       for( int i=0; i<N; i++ )
    {
       free(array[i]);
       if(array[i]!=NULL)
       array[i]=NULL;
    }
    free(array);
    if(array!=NULL)
    array=NULL;
    float right=0;
    for(int i=0;i<27;++i)
    if(pred[i]==0)
    ++right;
    for(int i=27;i<56;++i)
    if(pred[i]==1)
    ++right;
    printf("使用K阶近邻法模型的正确率为：\n");
    printf("%f\n",(right/56));
  //  printf("%f\n",predlabel[2] );
     return 0;
}