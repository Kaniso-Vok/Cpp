FLAG=-std=c++11 -L/usr/lib64/mysql -lmysqlclient -ljsoncpp -lpthread

.PHONY:all
all:db_test1 blog_server

db_test1:db_test1.cc db.hpp
	g++ db_test1.cc -o db_test1 $(FLAG)

blog_server:blog_server.cc
	g++ blog_server.cc -o blog_server $(FLAG)


.PHONY: clean
clean:
	rm db_test1 blog_server
