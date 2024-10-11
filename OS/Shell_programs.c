#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
void count(char c,char *fn){
	int wc=0,lc=0,cc=0,handle;
	char ch;
	if((handle=open(fn,O_RDONLY))==-1){
		printf("error opening file");
		return;
	}
	while(read(handle,&ch,1)!=0){
		if(ch==' ')
			wc++;
		else if(ch=='\n')
			lc++;
		else
			cc++;
	}
	close(handle);
	switch(c){
		case 'w':
			printf("\ntotal number of words are:%d\n",wc);
			break;
		case 'c':
			printf("\ntotal number of characters are:%d\n",cc);
			break;
		case 'l':
			printf("\ntotal number of lines are:%d\n",lc);
			break;
	}
}
void list(char c,char *dn){
	DIR *dir;
	int cnt=0;
	struct dirent *entry;
	struct stat buff;
	if((dir=opendir(dn))==NULL){
		printf("failed to open directory");
		return;
	}
	switch(c){
		case 'f':
			while((entry=readdir(dir))!=NULL){
				stat(entry->d_name,&buff);
				if(S_IFREG&buff.st_mode){
					printf("%s\n",entry->d_name);
				}
			}
			break;
		case 'n':
			while((entry=readdir(dir))!=NULL){
				cnt++;
			}
			printf("\ntotal number of entries are:%d\n",cnt);
			break;
		case 'i':
			while((entry=readdir(dir))!=NULL){
				stat(entry->d_name,&buff);
				if(S_IFREG&buff.st_mode){
					printf("%s %d\n",entry->d_name,buff.st_ino);
				}
			}
			break;
	}
}
void typeline(char *s,char *fn){
	int handle,i=0,cnt=0,n;
	int ch=0;
	if((handle=open(fn,O_RDONLY))==-1){
		printf("unable to open file");
		return;
	}
	if(strcmp(s,"a")==0){
		while(read(handle,&ch,1)!=0)
			printf("%c",ch);
		close(handle);
		return;
	}
	n=atoi(s);
	if(n>0){
		while(read(handle,&ch,1)!=0){
			if(ch=='\n')
				i++;
			if(i==n)
				break;
			printf("%c",ch);
		}
		printf("\n");
		close(handle);
		return;
	}
}

int main(){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	while(1){
		printf("Myshell$ ");
		fflush(stdin);
		fgets(command,80,stdin);
		n=sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n){
			case 1:
				if(!fork()){
					execlp(t1,t1,NULL);
					perror(t1);
				}
				break;
			case 2:
				if(!fork()){
					execlp(t1,t1,t2,NULL);
					perror(t1);
				}
				break;
			case 3:
				if(strcmp(t1,"list")==0){
					list(t2[0],t3);
				}else{
					execlp(t1,t1,t2,t3,NULL);
					perror(t1);
				}
				break;
			case 4:
				if(!fork()){
					execlp(t1,t1,t2,t3,t4,NULL);
					perror(t1);
				}
				break;
		}
	}
	return 0;
}
