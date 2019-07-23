// cJSONSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include "cJSON.h"
#include <string.h>
#include <stdlib.h>
void CParsejson()
{
	const cJSON *sport = NULL;
    //char* data = "{\"name\":\"Messi\",\"age\":\"29\"}";
	char* data = "{\"name\":\"Messi\",\"age\":\"29\",\"love\": [\"乒乓球\",\"高尔夫\",\"斯诺克\",\"羽毛球\",\"LOL\",\"撩妹\"]}}";
	printf("000000\n");
     //从缓冲区中解析json结构
    cJSON* root = cJSON_Parse(data);

	printf("000001\n");
    if (data == NULL)
    {
        printf("11111\n");
		return;
    }
    printf("2222\n");
    cJSON* itemName = cJSON_GetObjectItem(root, "name");

    if (itemName)
    {
        cout << "name: "<< itemName->valuestring << endl;
    }

    cJSON* itemAge = cJSON_GetObjectItem(root, "age");
    if (itemAge)
    {
        cout << "age: " << itemAge->valuestring << endl;
    }
	cJSON* itemLove = cJSON_GetObjectItem(root, "love");
	cJSON_ArrayForEach(sport, itemLove)
    {
		cout << "sport: " << sport->valuestring << endl;
	}
    //讲json结构占用的数据空间释放
    cJSON_Delete(root);
}
void WriteJson()
{
    char *char_json = "{\"hello\":\"你好\"}";

    //从缓冲区中解析出JSON结构
    cJSON *json = cJSON_Parse(char_json);

    if (json == NULL)
    {
        return;
    }

    //将传入的JSON结构转化为字符串 
    char *buf = NULL;
     buf = cJSON_Print(json);

    //打开一个info.json文件，并写入json内容
    FILE *fp = fopen("info.json", "w");
    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);//关闭文件
    free(buf);//释放资源
    cJSON_Delete(json);//释放资源
}
char * create1()

{

     cJSON *root,*dir1,*dir2,*dir3;

     char *out;

     //创建json数组型结构体

     root = cJSON_CreateArray();

     //为数组添加对象

     cJSON_AddItemToArray(root,dir1=cJSON_CreateObject());

     //为对象添加字符串键值对

     cJSON_AddStringToObject(dir1,"name",".");

     cJSON_AddStringToObject(dir1,"path","uploads/");

     cJSON_AddStringToObject(dir1,"flag","true");

     cJSON_AddItemToArray(root,dir2=cJSON_CreateObject());

     cJSON_AddStringToObject(dir2,"name","..");

     cJSON_AddStringToObject(dir2,"path","uploads");

     cJSON_AddStringToObject(dir2,"flag","true");

     cJSON_AddItemToArray(root,dir3=cJSON_CreateObject());

     cJSON_AddStringToObject(dir3,"name","wang.txt");

     cJSON_AddStringToObject(dir3,"path","uploads/wang.txt");

     cJSON_AddStringToObject(dir3,"flag","false");

     //将json结构体转换为字符串

     out=cJSON_Print(root);

     //删除

     cJSON_Delete(root);

     return out;

}

 

char * create2()

{

     cJSON *root,*dir,*child,*subdir,*dir1,*dir2,*dir3;

     char *out;

     root=cJSON_CreateObject();

    

     cJSON_AddItemToObject(root,"Root",dir=cJSON_CreateObject());

     cJSON_AddStringToObject(dir,"name","/");

     cJSON_AddStringToObject(dir,"path","/");

     cJSON_AddStringToObject(dir,"flag","true");

 

     cJSON_AddItemToObject(root,"Child",subdir = cJSON_CreateArray());

     cJSON_AddItemToObject(subdir,"dira",dir1=cJSON_CreateObject());

     cJSON_AddStringToObject(dir1,"name",".");

     cJSON_AddStringToObject(dir1,"path","/./");

     cJSON_AddStringToObject(dir1,"flag","true");

     cJSON_AddItemToObject(subdir,"dira",dir2=cJSON_CreateObject());

     cJSON_AddStringToObject(dir2,"name","..");

     cJSON_AddStringToObject(dir2,"path","/../");

     cJSON_AddStringToObject(dir2,"flag","true");

     cJSON_AddItemToObject(subdir,"dira",dir3=cJSON_CreateObject());

     cJSON_AddStringToObject(dir3,"name","uploads");

     cJSON_AddStringToObject(dir3,"path","/uploads/");

     cJSON_AddStringToObject(dir3,"flag","true");

        

     out=cJSON_Print(root);

     cJSON_Delete(root);

     return out;

}

 

 

char * create3()

{

     cJSON *root,*img,*thm;

     char *out;

     int nums[4]={100,200,300,400};

     root=cJSON_CreateObject();

     cJSON_AddItemToObject(root, "Root", img=cJSON_CreateObject());

     cJSON_AddNumberToObject(img,"key",800);

     cJSON_AddNumberToObject(img,"value",600);

     cJSON_AddStringToObject(img,"Title","Sugon");

     cJSON_AddItemToObject(img,"child",thm=cJSON_CreateObject());

     cJSON_AddNumberToObject(thm,"key",125);

     cJSON_AddStringToObject(thm,"value","100");

         cJSON_AddStringToObject(thm,"Url","www.sugon.com");

     cJSON_AddItemToObject(img,"nums", cJSON_CreateIntArray(nums,4));

     out=cJSON_Print(root);

     cJSON_Delete(root);

     return out;

}

 

char * create4()

{

     cJSON *root,*dir1,*dir2;

     char *out;

     const char *ro = "Root";

     root=cJSON_CreateObject();

     cJSON_AddItemToObject(root,ro,dir1=cJSON_CreateArray());

     cJSON_AddNumberToObject(dir1,"key",800);

     cJSON_AddNumberToObject(dir1,"value",600);

     cJSON_AddStringToObject(dir1,"Title","key and value");

     cJSON_AddItemToObject(root,ro,dir2=cJSON_CreateArray());

     cJSON_AddNumberToObject(dir2,"value",125);

     cJSON_AddStringToObject(dir2,"key","100");

     cJSON_AddStringToObject(dir2,"Title","value and key");

     out=cJSON_Print(root);

     cJSON_Delete(root);

     return out;

}

 

void parse1(char *out)

{

     cJSON * root,*arrayItem,*item,*name,*path,*flag;  

     int i = 0,size = 0;

     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;

 

     //将字符串解析成json结构体

     root = cJSON_Parse(out);

     //根据结构体获取数组大小

     size = cJSON_GetArraySize(root);

     //printf("%d\n",size);

     //遍历数组

     for(i=0;i<size;i++)

     {

         //获取第i个数组项

         arrayItem = cJSON_GetArrayItem(root,i);

         if(arrayItem)

         {

              //printf("%s\n","start......");

              //讲json结构体转换成字符串

              pr = cJSON_Print(arrayItem);

              item = cJSON_Parse(pr);

              name = cJSON_GetObjectItem(item,"name");

              path = cJSON_GetObjectItem(item,"path");

              flag = cJSON_GetObjectItem(item,"flag");

              na = cJSON_Print(name);

              pa = cJSON_Print(path);

              fl = cJSON_Print(flag);

              //printf("%s\n",pr);

              printf("name:%s\n",na);

              printf("path:%s\n",pa);

              printf("flag:%s\n\n",fl);

         }

     }

}

 

void parse2(char *out)

{

     cJSON * root,*Root,*Child,*arrayItem,*item,*name,*path,*flag;   

     int i = 0,size = 0;

     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;

     root = cJSON_Parse(out);

     if(root)

     {

         Root = cJSON_GetObjectItem(root,"Root");

         if(Root)

         {

              name = cJSON_GetObjectItem(Root,"name");

              path = cJSON_GetObjectItem(Root,"path");

              flag = cJSON_GetObjectItem(Root,"flag");

              na = cJSON_Print(name);

              pa = cJSON_Print(path);

              fl = cJSON_Print(flag);

              printf("Root:\n");

              printf("name:%s\n",na);

              printf("path:%s\n",pa);

              printf("flag:%s\n\n",fl);

         }

         Child = cJSON_GetObjectItem(root,"Child");

         if(Child)

         {

              size = cJSON_GetArraySize(Child);

              //printf("%d\n",size);

              printf("Child:\n");

              for(i=0;i<size;i++)

              {

                   arrayItem = cJSON_GetArrayItem(Child,i);

                   if(arrayItem)

                   {

                       //printf("%s\n","start......");

                       pr = cJSON_Print(arrayItem);

                       item = cJSON_Parse(pr);

                       name = cJSON_GetObjectItem(item,"name");

                       path = cJSON_GetObjectItem(item,"path");

                       flag = cJSON_GetObjectItem(item,"flag");

                       na = cJSON_Print(name);

                       pa = cJSON_Print(path);

                       fl = cJSON_Print(flag);

                       //printf("%s\n",pr);

                       printf("name:%s\n",na);

                       printf("path:%s\n",pa);

                       printf("flag:%s\n\n",fl);

                   }

              }

         }

     }   

}

char *json_loader(char *path)
{
  FILE *f;
  long len;
  char *content;
  f=fopen(path,"rb");
  fseek(f,0,SEEK_END);
  len=ftell(f);
  fseek(f,0,SEEK_SET);
  content=(char*)malloc(len+1);
  fread(content,1,len,f);
  fclose(f);
  return content;
}
void parseArray1()
{
	/*
	{
		"iplist": [{
			"ip": "1111",
			"mask": "1111"
		}, {
			"ip": "2222",
			"mask": "22222"
		}]
	}
	*/
	char* clientlist_str = "{\"iplist\":[{\"ip\":\"1111\",\"mask\":\"1111\"}, {\"ip\":\"2222\",\"mask\":\"22222\"}]}";
	cJSON* clientlist = cJSON_Parse(clientlist_str);
	cJSON *ip_arry     = cJSON_GetObjectItem( clientlist, "iplist");  //clientlist 是使用 cjson对象
	if( NULL != ip_arry ){
		cJSON *client_list  = ip_arry->child;
		if( client_list != NULL ){ 
			char * ip   = cJSON_GetObjectItem( client_list , "ip")->valuestring ;
			char * mask = cJSON_GetObjectItem( client_list , "mask")->valuestring ;
			printf("ip: %s  mask: %s\n",ip,mask);
			client_list = client_list->next ;
		}
	} 
}
void parseArray2()
{
	/*
	{
	"maclist": ["11111", "22222", "3333"]
	}
	*/
	char* clientlist_str = "{\"maclist\":[\"11111\",\"22222\",\"3333\"]}";
	cJSON* clientlist = cJSON_Parse(clientlist_str);
	cJSON *MAC_arry     = cJSON_GetObjectItem( clientlist, "Maclist");
	if( MAC_arry != NULL ){
		int  array_size   = cJSON_GetArraySize ( MAC_arry );

		for( int iCnt = 0 ; iCnt < array_size ; iCnt ++ ){
			cJSON * pSub = cJSON_GetArrayItem(MAC_arry, iCnt);
			if(NULL == pSub ){ continue ; }

			char * ivalue = pSub->valuestring ;
			printf("Maclist[%d] : %s\n",iCnt,ivalue);
		}
	}
}
void parseArrayFromFile()
{
	/*
	[{
		"sponsor": "111111",
		"name": "11111 name"
	}, {
		"sponsor": "22222",
		"name": "2222 name"
	}, {
		"sponsor": "3333",
		"name": "3333 name"
	}]
	*/
	char *content = json_loader("json_output.txt");
	cJSON* root = cJSON_Parse(content);
	
	int sponsors_array_size = cJSON_GetArraySize(root);
	for(int i=0; i< sponsors_array_size; i++) 
	{
		cJSON * sponsor = cJSON_GetArrayItem(root, i);
		if(NULL == sponsor ){ continue ; }
		char * sponsorid   = cJSON_GetObjectItem( sponsor , "sponsor")->valuestring ;
		char * sponsorname = cJSON_GetObjectItem( sponsor , "name")->valuestring ;
		printf("Sponsors[%d] : %s %s\n",i,sponsorid, sponsorname);
	}
}
int main(int argc, char* argv[])
{
	CParsejson();
	WriteJson();

	char *out1 = create1();
	char *out2 = create2();
	char *out3 = create3();
	char *out4 = create4();
	printf("%s\n\n\n",out1);
	parse1(out1);
	printf("%s\n\n\n",out2);
	parse2(out2);
	printf("%s\n\n\n",out3);
	printf("%s\n\n\n",out4);
	printf("Hello World!\n");


	parseArray1(); 

	parseArray2();

	parseArrayFromFile();
	return 0;
}