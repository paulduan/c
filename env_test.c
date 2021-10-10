#include <stdio.h>
#include <string.h>

extern char **environ;
int main(int argc, char **argv) {
    for(int i=0;i<argc;i++){
	printf("addr:%p,value:%s\n",argv[i],argv[i]);
    }
    for(int i=0;environ[i]!=NULL;i++){
	printf("addr:%p,value:%s\n",environ[i],environ[i]);
    }
char *base, *end, *nul;
	base = argv[0];

	/* We start with end pointing at the end of argv[0] */
	nul = &base[strlen(base)];
	printf("null addr:%p,value:%s\n",nul,nul);
	end = nul + 1;
	printf("end addr:%p,value:%s\n",end,end);
    //argv[0][0]='f';
    getchar();
    return 0;
}
