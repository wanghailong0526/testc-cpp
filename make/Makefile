#makefile语法 1.目标 2.依赖(源文件) 3.命令(tab开头)
#$^表示所有依赖 $@表示所有目标
#没有依赖的目标为 伪目标 声明方式 .PHONY:目标名称 作用:若目录下有文件与伪目标重名当执行 make clean 执行的是伪目标的命令而不是目录下的clean文件
#通配符 %.o:%.c
#= 递归展开式 引用未定义的变量
#str=$(str1)
#str1=hello
#:= 直接展开式 引用定义好的变量或字面量
#str2:=1
#str4:=$(str3)
#str3:=hi
#+= 变量值追回 str3+=whl
#当在目录下执行 make 默认执行目录下的Makefile 或 makefile 文件中的内容
#生成的终极目标执行 ./myMath 会输出结果
#指定所有 .c 源文件
SOURCES=$(wildcard *.c)
#把.c 后缀 替换成 .o 后缀
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
myMathr:$(OBJECTS)
#$^表示所有依赖 $@表示所有目标
	gcc  $^ -o $@
#没有依赖的目标为伪目标使用 .PHONY:目标名字
#执行 make clean
.PHONY:clean
clean:
	rm -f *.o
	rm -f myMathr
#执行 make test
.PHONY:test
test:
	@echo $(SOURCES)
	@echo $(OBJECTS)

#递归展开式
str=$(str1) world!
str1=hello
#直接展开式
str2:=1
str4:=$(str3)
str3:=hi
str3+= whl
.PHONY:print
print:
	@echo "str=$(str)"
	@echo "str2=$(str2)"
	@echo "str3=$(str3)"
	@echo "str4=$(str4)"

