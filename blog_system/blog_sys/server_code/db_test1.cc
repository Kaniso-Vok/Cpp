#include"db.hpp"

//使用这个程序来测试封装的mysql操作是否正确
//此处使用单元测试
void TestBlogTable(){
  Json::StyledWriter writer;
  MYSQL* mysql = blog_system::MySQLInit();
  blog_system::BlogTable blog_table(mysql);
  bool ret = false;

  //测试插入
  Json::Value blog;
//  blog["title"] = "我的第一篇博客";
//  blog["content"] = "i will get 30K";
//  blog["tag_id"] = 1;
//  blog["create_time"] = "2019/12/11";
//  bool ret = blog_table.Insert(blog);
//  printf("intert: %d\n",ret);

//测试查找
//  Json::Value blogs;
//   ret = blog_table.SelectALL(&blogs);
//  printf("select all %d\n",ret);
//  printf("blogs: %s\n",writer.write(blogs).c_str());

//测试查找单个博客
//  ret = blog_table.SelectOne(1,&blog);
//  printf("select one %d\n",ret);
//  printf("blog: %s\n",writer.write(blog).c_str());
//

//测试修改博客
//  blog["blog_id"] = 1;
//  blog["title"] = "my first C blog";
//  blog["content"] = "Dream as if you will live \nforever and live as if you die today";
//  ret = blog_table.Update(blog);
//  printf("update %d\n",ret);
//

//测试删除博客
  ret = blog_table.Delete(1);
  printf("delete %d\n",ret);

  blog_system::MySQLRelease(mysql);
}

void TestTagTable(){
  Json::StyledWriter writer;
  MYSQL* mysql = blog_system::MySQLInit();
  blog_system::TagTable tag_table(mysql);
  //测试插入
  //  Json::Value tag;
//  tag["tag_name"] = "C++";
//  bool ret = tag_table.Insert(tag);
//  printf("insert %d\n",ret);

 //测试查找
  //Json::Value tags;
  //bool ret = tag_table.SelectAll(&tags);
  //printf("select all %d\n",ret);
  //printf("tags: %s\n",writer.write(tags).c_str());
 
  //测试删除
  bool ret = tag_table.Delete(1);
  printf("delete %d\n",ret);

  blog_system::MySQLRelease(mysql);
  
}



int main() {  
//  TestBlogTable();
  TestTagTable();
  return 0;
}
