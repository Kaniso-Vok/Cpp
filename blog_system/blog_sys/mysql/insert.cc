//////////////////////////////////
//通过此程序使用MySQL API实现数据的插入功能
//////////////////////////////////

#include<cstdio>
#include<cstdlib>
#include<mysql/mysql.h>   //编译器默认从/usr/include 目录中查找头文件，mysql.h是在一个mysql目录中

int main() {
  //1.创建一个数据库连接句柄，方便后续对其他数据库进行操作
  MYSQL* connect_fd=mysql_init(NULL);
  //2.和数据库建立连接（和TCP区分开，这是在应用层建立连接）
  //        连接过程需要指定一些必要的信息
  //        a)连接句柄
  //        b)服务器的IP地址
  //        c)用户名
  //        d)密码
  //        e)数据库名（blog_sys）
  //        f)服务器的端口号
  //        g)unix_sock NULL
  //        h)client_flag 0
  if(mysql_real_connect(connect_fd,"127.0.0.1","root","","blog_sys",3306,NULL,0)==NULL){
    printf("链接失败！ %s\n",mysql_error(connect_fd));
    return 1;
  }
  printf("链接成功！\n");

//3.设置编码方式
//     mysql server 部分最初安装的时候已经设置成了 utf8
//     也得在客户端这边也设置成 utf8
  mysql_set_character_set(connect_fd,"utf8");

//4.拼接 SQL 语句,将sql语句发送到服务器上
  char sql[1024*4] = {0};     //用来表示sql语句
  char title[] = "立一面flag";
  char content[] = "我想成就什么";
  int tag_id = 1;
  char date[] = "2019/12/24";
  sprintf(sql,"insert into blog_table values(null,'%s','%s',%d,'%s')",title,content,tag_id,date);
  printf("sql: %s\n",sql);

//5.让 数 据 库 服务器 执行 SQL
  int ret = mysql_query(connect_fd,sql);
  if(ret < 0){
    printf("执行sql失败! %s\n",mysql_error(connect_fd));
    mysql_close(connect_fd);
    return 1;
  }
  printf("插入成功！\n");

//6.断开链接
  mysql_close(connect_fd);
  return 0;
}
