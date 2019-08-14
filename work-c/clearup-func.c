
int accept (int, struct sockaddr *__peer, socklen_t *);
  
int snprintf(char* dest_str,size_t size,const char* format,...);
//将可变参数 “…” 按照format的格式格式化为字符串，然后再将其拷贝至str中。
  
  
/*
getopt -- 解析命令的可选项
【说明】getopt只是一个简单的解析命令可选项的函数，只能进行简单的格式命令解析，格式如下：
1、形如：cmd [-a][-b] //对短选项的解析；
2、形如：cmd [-a a_argument][-b b_argument] //对短选项及短选项的参数解析；
3、形如：cmd [-a[a_argument]] //选项a的参数也是可选的情况解析
*/

//af_xxx  ARPA Internet地址格式

//process_asp 动态服务器页面

int fseek(FILE *stream, long offset, int fromwhere);
/*函数设置文件指针stream的位置。
如果执行成功，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0。如果执行失败(比如offset取值大于等于2*1024*1024*1024，即long的正数范围2G)，则不改变stream指向的位置，函数返回一个非0值。
第一个参数stream为文件指针
第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
SEEK_SET： 文件开头
SEEK_CUR： 当前位置
SEEK_END： 文件结尾
其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
简言之：
fseek(fp,100L,0);把stream指针移动到离文件开头100字节处；
fseek(fp,100L,1);把stream指针移动到离文件当前位置100字节处；
fseek(fp,-100L,2);把stream指针退回到离文件结尾100字节处。
*/

/*
当返回为-1时，所有描述符集清0。
当返回为0时，表示超时。
当返回为正数时，表示已经准备好的描述符数
*/
int select(int maxfdp, fd_set* readfds, fd_set* writefds, fd_set* errorfds, struct timeval* timeout);
/*
第一：struct fd_set可以理解为一个集合，这个集合中存放的是文件描述符(file descriptor)，即文件句柄，这可以是我们所说的普通意义的文件，
当然Unix下任何设备、管道、FIFO等都是文件形式，全部包括在内，所以，毫无疑问，一个socket就是一个文件，socket句柄就是一个文件描述符。
fd_set集合可以通过一些宏由人为来操作，比如清空集合：FD_ZERO(fd_set*)，
将一个给定的文件描述符加入集合之中FD_SET(int, fd_set*)，将一个给定的文件描述符从集合中删除FD_CLR(int,   fd_set*)，
检查集合中指定的文件描述符是否可以读写FD_ISSET(int, fd_set*)。一会儿举例说明。

第二：struct timeval是一个大家常用的结构，用来代表时间值，有两个成员，一个是秒数，另一个毫秒数。

int maxfdp是一个整数值，是指集合中所有文件描述符的范围，即所有文件描述符的最大值加1，不能错！在Windows中这个参数值无所谓，可以设置不正确。


fd_set* readfds是指向fd_set结构的指针，这个集合中应该包括文件描述符，我们是要监视这些文件描述符的读变化的，即我们关心是否可以从这些文件中读取数据了，如果这个集合中有一个文件可读，select就会返回一个大于0的值，表示有文件可读，如果没有可读的文件，则根据timeout参数再判断是否超时，若超出timeout的时间，select返回0，若发生错误返回负值。可以传入NULL值，表示不关心任何文件的读变化。

fd_set* writefds是指向fd_set结构的指针，这个集合中应该包括文件描述符，我们是要监视这些文件描述符的写变化的，即我们关心是否可以向这些文件中写入数据了，如果这个集合中有一个文件可写，select就会返回一个大于0的值，表示有文件可写，如果没有可写的文件，则根据timeout再判断是否超时，若超出timeout的时间，select返回0，若发生错误返回负值。可以传入NULL值，表示不关心任何文件的写变化。

fe_set* errorfds同上面两个参数的意图，用来监视文件错误异常。
*/

//***一般最大打开文件数会是系统内存的10%（以KB来计算）（称之为系统级限制）
//查看系统级别的最大打开文件数可以使用sysctl -a | grep fs.file-max命令查看
//单个进程最大打开文件数做默认值处理（称之为用户级限制），默认值一般是1024，使用ulimit -n命令可以查看




//accept()是在一个套接口接受的一个连接。accept（）是c语言中网络编程的重要的函数，本函数从s的等待连接队列中抽取第一个连接，创建一个与s同类的新的套接口并返回句柄。
SOCKET accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
/*参数
sockfd：套接字描述符，该套接口在listen()后监听连接。
addr：（可选）指针，指向一缓冲区，其中接收为通讯层所知的连接实体的地址。Addr参数的实际格式由套接口创建时所产生的地址族确定。
addrlen：（可选）指针，输入参数，配合addr一起使用，指向存有addr地址长度的整型数。
*/

//setsockopt()函数，用于任意类型、任意状态套接口的设置选项值。尽管在不同协议层上存在选项，但本函数仅定义了最高的“套接口”层次上的选项。
/*int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);
sockfd：标识一个套接口的描述字。
level：选项定义的层次；支持SOL_SOCKET、IPPROTO_TCP、IPPROTO_IP和IPPROTO_IPV6。
optname：需设置的选项。
optval：指针，指向存放选项待设置的新值的缓冲区。
optlen：optval缓冲区长度。
*/

//内核（kernel）利用文件描述符（file descriptor）来访问文件。文件描述符是非负整数。
//打开现存文件或新建文件时，内核会返回一个文件描述符。读写文件也需要使用文件描述符来指定待读写的文件。

//reenter： n. 重进入，再加入 | vt. 重新加入


//MIME, 全称为“Multipurpose Internet Mail Extensions”, 比较确切的中文名称为“多用途互联网邮件扩展”。

strsep函数用于分解字符串为一组字符串
//char *strtok(char *s, const char *delim);
char *strsep(char **s, const char *delim);
//s为要分解的字符串，delim为分隔符字符串，返回值：从s开头开始的一个个子串，当没有分割的子串时返回NULL0

long unsigned int strspn(const char *s,const char *accept)
/*strspn（返回字符串中第一个不在指定字符串中出现的字符下标）
函数说明 strspn()从参数s 字符串的开头计算连续的字符，而这些字符都完全是accept 所指字符串中的字符。简单的说，若strspn()返回的数值为n，则代表字符串s 开头连续有n 个字符都是属于字符串accept内的字符。
返回值 返回字符串s开头连续包含字符串accept内的字符数目
*/


int strncasecmp(const char *s1, const char *s2, size_t n)
//函数说明：strncasecmp()用来比较参数s1和s2字符串前n个字符，比较时会自动忽略大小写的差异。
//返回值 ：若参数s1和s2字符串相同，则返回0；若s1大于s2，则返回大于0的值；若s1小于s2，则返回小于0的值。


/*
IKE Keepalive 密钥检测协议存活
Dead Peer Detection 失效对端检测*/


//strlen()计算给定字符串的长度
//sizeof 操作用来用字节计算右边表达式并返回字节数.

/*
strpbrk()函数检索两个字符串中首个相同字符的位置，其原型为：
char *strpbrk( char *s1, char *s2);
*/

/*
函数原型
void *memcpy(void *destin, void *source, unsigned n);
参数
destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
source-- 指向要复制的数据源，类型强制转换为 void* 指针。
n-- 要被复制的字节数。
返回值
该函数返回一个指向目标存储区destin的指针。
*/

extern int strcmp(const char *s1,const char *s2);
//当s1<s2时，返回为负数；当s1=s2时，返回值= 0；当s1>s2时，返回正数。




char *strchr(const char *str, int c)
/*
参数
str-- 要被检索的 C 字符串。
c-- 在 str 中要搜索的字符。
功能
在参数str所指向的字符串中搜索第一次出现字符c（一个无符号字符）的位置。
返回值
该函数返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符则返回 NULL
*/


定义函数：int strcasecmp (const char *s1, const char *s2);
函数说明：strcasecmp()用来比较参数s1 和s2 字符串，比较时会自动忽略大小写的差异。
返回值：若参数s1 和s2 字符串相同则返回0。s1 长度大于s2 长度则返回大于0 的值，s1 长度若小于s2 长度则返回小于0 的值。


函数原型
char *fgets(char *str, int n, FILE *stream);
参数
str-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
n-- 这是要读取的最大字符数（包括最后的空字符）。通常是使用以 str 传递的数组长度。
stream-- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。
功能
从指定的流 stream 读取一行，并把它存储在str所指向的字符串内。当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定















//#==============================================
fopen函数是打开一个文件，其调用的一般形式为：
文件指针名=fopen（文件名,使用文件方式）;


fwrite() 是 C 语言标准库中的一个文件处理函数，功能是向指定的文件中写入若干数据块，如成功执行则返回实际写入的数据块数目。
该函数以二进制形式对文件进行操作，不局限于文本文件
函数原型
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
参数
ptr-- 这是指向要被写入的元素数组的指针。
size-- 这是要被写入的每个元素的大小，以字节为单位。
nmemb-- 这是元素的个数 （==每个元素的大小为 size 字节。===）
stream-- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。
功能
把ptr所指向的数组中的数据写入到给定流stream中。
返回值
如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误


函数原型
size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
参 数
buffer
用于接收数据的内存地址
size
要读的每个数据项的字节数，单位是字节
count
要读count个数据项，每个数据项size个字节.
stream
输入流
返回值
返回真实读取的项数，若大于count则意味着产生了错误。另外，产生错误后，文件位置指示器是无法确定的。若其他stream或buffer为空指针，或在unicode模式中写入的字节数为奇数，此函数设置errno为EINVAL以及返回0


fclose是一个函数名，功能是关闭一个流。注意：使用fclose()函数就可以把缓冲区内最后剩余的数据输出到内核缓冲区，并释放文件指针和有关的缓冲区。
函数原型：int fclose( FILE *fp );
返回值：如果流成功关闭，fclose 返回 0，否则返回EOF（-1）。（如果流为NULL，而且程序可以继续执行，fclose设定error number给EINVAL，并返回EOF。）


1. fgetc是一种计算机语言中的函数。意为从文件指针stream指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节。格式：int fgetc(FILE *stream);

2. fputc()函数名称：写字符文件函数fputc()
函数格式：int fputc (int c, File *fp)
参数解释：fp为文件指针，它的值是执行fopen()打开文件时获得的。
c为输出的字符量。
虽然函数被定义为整型数，但仅用其低八位。
返回值：在正常调用情况下，函数返回写入文件的字符的ASCII码值，出错时，返回EOF（-1）。
当正确写入一个字符或一个字节的数据后，文件内部写指针会自动后移一个字节的位置。EOF是在头文件 stdio.h中定义的宏


int fseek(FILE *stream, long offset, int fromwhere);函数设置文件指针stream的位置。
如果执行成功，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0。如果执行失败(比如offset取值大于等于2*1024*1024*1024，即long的正数范围2G)，则不改变stream指向的位置，函数返回一个非0值。
fseek函数和lseek函数类似，但lseek返回的是一个off_t数值，而fseek返回的是一个整型

int fseek( FILE *stream, long offset, int origin );
第一个参数stream为文件指针
第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
SEEK_SET： 文件开头
SEEK_CUR： 当前位置
SEEK_END： 文件结尾
其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
简言之：
fseek(fp,100L,0);把stream指针移动到离文件开头100字节处；
fseek(fp,100L,1);把stream指针移动到离文件当前位置100字节处；
fseek(fp,-100L,2);把stream指针退回到离文件结尾100字节处。



void *memset(void *s, int ch, size_t n);
函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法 [1]  。
memset()函数原型是extern void *memset(void *buffer, int c, int count) 
buffer：为指针或是数组,c：是赋给buffer的值,count：是buffer的长度.


write有两种用法。一种是：ssize_t write(int fd, const void *buf, size_t nbyte);
fd：文件描述符；
buf：指定的缓冲区，即指针，指向一段内存单元；
nbyte：要写入文件指定的字节数；
返回值：写入文档的字节数（成功）；-1（出错）
write函数把buf中nbyte写入文件描述符handle所指的文档，成功时返回写的字节数，错误时返回-1.
另一种是： write（const char* str,int n)
str是字符指针或字符数组，用来存放一个字符串。n是int型数，它用来表示输出显示字符串中字符的个数。
write（"string",strlen("string");表示输出字符串常量

用于得到文件位置指针当前位置相对于文件首的偏移字节数。
函数名
ftell
函数原型
long ftell(FILE *stream);
函数功能
使用fseek函数后再调用函数ftell()就能非常容易地确定文件的当前位置。
约束条件
因为ftell返回long型，根据long型的取值范围-231~231-1（-2147483648～2147483647），故对大于2.1G的文件进行操作时出错。


函数原型
void *memcpy(void *destin, void *source, unsigned n);
参数
destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
source-- 指向要复制的数据源，类型强制转换为 void* 指针。
n-- 要被复制的字节数。
返回值
该函数返回一个指向目标存储区destin的指针。
功能
从源source所指的内存地址的起始位置开始拷贝n个字节到目标destin所指的内存地址的起始位置中。 [2] 
所需头文件
C语言：#include<string.h>
















