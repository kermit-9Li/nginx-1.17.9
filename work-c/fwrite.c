#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

//限制指定日志文件大小（1024*10字节）,shell 脚本限制指定日志文件行数(100行)
typedef struct data {
	char *str;
	long time;
	int symbal;
} DATA;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
   struct timeval tv;
   gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int write_log(char *c){
	FILE *fp;
	long curTime = getCurrentTime();
	int line_count;

	DATA *pt;
	pt = (DATA *)malloc(sizeof(DATA));
	// memcpy(pt->str, c, strlen(c));
	pt->str = c;
	pt->time = curTime;
	pt->symbal = ;
	printf("%s\n", pt->str);
	fp=fopen("system.log", "r+");
	if(NULL == fp) {
		fprintf(stderr,"open file system.log error! %s\n",strerror(errno));
		//printf("The profile doesn't exist, create logFile.\n");
		//doSystem("touch xxxfile.log");
		return 0;
	}
	if(fp) {
		//文件大于1M 处理待定
		if (ftell(fp) > 1024*1024) {

		}
		while((line_count = fgetc(fp)) != EOF)
		{
			 if(line_count == '\n')
			 {
				 line_count++;
			 }
		}
		if (line_count < 100) {
			//fseek(fp, sizeof(*fp), SEEK_END);
			fwrite(pt,sizeof(DATA),1,fp);
		} else {
			//doSystem(" sed -i '0,49d' system.log ");
			fwrite(pt,sizeof(DATA),1,fp);
		}
	}
	free(pt);
	fclose(fp);
	return 0;
}


int main(int argc, char **argv)
{
	char *p = "As food is to the body";
	int ret = write_log(p);
	printf("%d\n", ret);
	return ret;
}


