#include "PCS.h"

//监听端口
char *localPort="8787";

//HTTP代理IP
char *remote_http="10.0.0.172:80";

//HTTPS代理IP
char *remote_https="10.0.0.172:80";

//CONNECT代理IP
char *remote_connect="10.0.0.172:80";



//修改所有[p_host]为代理Host

//uid root


//初始化函数
int PCS_init(char *l,char *r_http,char *r_https,char *r_connect)
{
 //设置为后台运行
 daemon();
 
 //设置UID
 set_uid(3004);
 //后面请勿修改
 sprintf(l,"%s",localPort);
 sprintf(r_http,"%s",remote_http);
 sprintf(r_https,"%s",remote_https);
 sprintf(r_connect,"%s",remote_connect);
	return 0;
}


//GET请求
int request_GET(char*header,int*plen)
{
 atob(header,"X-Online-Host","Host",plen);		
 rem_header(header,"Connection",plen);
 str_replace(header,"\nHost","\nX-Online-Host",plen);
 char *request_uri=get_upath(header,plen);
 
 set_first_line(header,plen,"GET http://wap.gd.10086.cn%s HTTP/1.1\r\nHost:\wap.gd.10086.cn\nConnection: keep-alive\nHost:\wap.gd.10086.cn\nX-Online-Host: \n",request_uri);
 
 free(request_uri);
 
 
 return 0;
}


//POST请求
int request_POST(char *header,int*plen)
{	
 atob(header,"X-Online-Host","Host",plen);		
 rem_header(header,"Connection",plen);
 str_replace(header,"\nHost","\nX-Online-Host",plen);
 char *request_uri=get_upath(header,plen);
 
 set_first_line(header,plen,"GET http:/wap.gd.10086.cn/%s HTTP/1.1\r\nHost:\wap.gd.10086.cn\nConnection: keep-alive\nHost:\wap.gd.10086.cn\nX-Online-Host: \n",request_uri);
 
 free(request_uri);
 

 return 0;
}

//浏览器发出的HTTPS请求(CONNECT请求)
int request_HTTPS(char *header,int*plen)
{

 return 0;
}

//TCP链接转换后的CONNECT请求
int request_CONNECT(char *header,int*plen)
{

 return 0;
}

//HEAD OPTIONS DELETE TRACE 请求(HTTP协议)
int request_OTHERS(char *header,int*plen)
{
 atob(header,"X-Online-Host","Host",plen);		
 rem_header(header,"Connection",plen);
 str_replace(header,"\nHost","\nX-Online-Host",plen);
 char *request_uri=get_upath(header,plen);
 
 set_first_line(header,plen,"GET http:/wap.gd.10086.cn/%s HTTP/1.1\r\nHost:\wap.gd.10086.cn\nConnection: keep-alive\nHost:\wap.gd.10086.cn\nX-Online-Host: \n",request_uri);
 
 free(request_uri);

	return 0;
}


