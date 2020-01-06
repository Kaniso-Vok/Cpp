#include<cstdio>
#include<cstdlib>
#include<mysql/mysql.h>

int main() {
  //1.创建一个数据库连接句柄，方便后续对其他数据库进行操作
  MYSQL* connect_fd=mysql_init(NULL);
  //2.建立链接
  if(mysql_real_connect(connect_fd,"127.0.0.1","root","","blog_sys",3306,NULL,0)==NULL){
        printf("链接失败！ %s\n",mysql_error(connect_fd));
            return 1;
              
  }
    printf("链接成功！\n");

    //3.设置编码方式
    ////     mysql server 部分最初安装的时候已经设置成了 utf8
    ////     也得在客户端这边也设置成 utf8
  mysql_set_character_set(connect_fd,"utf8");
    
  //4.拼接 SQL 语句,将sql语句发送到服务器上
  char sql[1024 * 4] = "select * from blog_table";
  //5.执行 SQL 语句
  int ret = mysql_query(connect_fd,sql);
  if(ret < 0){
    printf("mysql_query failed! %s\n",mysql_error(connect_fd));
    mysql_close(connect_fd);
    return 1;
  }
  //6.遍历结果集合,MYSQL_RES 表示select得到的结果集合
  MYSQL_RES* result = mysql_store_result(connect_fd);
  //a)获取到结果集合中的行数和列数
  int rows = mysql_num_rows(result);  //行数
  int fields = mysql_num_fields(result);  //字段数（列数）
  //b)根据行数和列数遍历结果
  for(int i = 0 ; i < rows; ++i){
    //一次获取一行数据
    MYSQL_ROW row = mysql_fetch_row(result);
    for(int j=0;j < fields; ++j){
      printf("%s\t",row[j]);
    }
    printf("\n");
  }
  //释放结果集合，容易遗忘!
  mysql_free_result(result);

  mysql_close(connect_fd);
  return 0;
}
