/*fcfs
#include<stdio.h>
#include<unistd.h>
int main(){
    int n;
    float swt=0.0,stat=0.0;
    float awt,atat;
    scanf("%d",&n);
    int bt[n],wt[n],tat[n];
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    tat[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        swt+=wt[i];
        stat+=tat[i];
    }
    awt=swt/n;
    atat=stat/n;
    printf("%f %f",awt,atat);
}*/
//sjf
/*
#include<stdio.h>
#include<unistd.h>
int main(){
    int n,t;
    float swt=0.0,stat=0.0;
    float awt,atat;
    scanf("%d",&n);
    int bt[n],wt[n],tat[n];
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
            }
        }
    }
    wt[0]=0;
    tat[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        swt+=wt[i];
        stat+=tat[i];
    }
    awt=swt/n;
    atat=stat/n;
    printf("%f %f",awt,atat);
}*/
//fcfs page replacement
/*
#include<stdio.h>
int main(){
    int pages,m,n,s,pagefault=0,frame=3;
    scanf("%d",&pages);
    int pagestream[pages],temp[frame];
    for(m=0;m<pages;m++){
        scanf("%d",&pagestream[m]);
    }
    printf("incoming\tframe 1\tframe 2\frame 3");
    for(m=0;m<frame;m++){
        temp[m]=-1;
    }
    for(m=0;m<pages;m++){
        s=0;
        for(n=0;n<frame;n++){
            if(pagestream[m]==temp[n]){
                s++;
                pagefault--;
            }
        }
        pagefault++;
        if((pagefault<=frame) &&(s==0)){
            temp[m]=pagestream[m];
        }
        else if(s==0){
            temp[(pagefault-1)%frame]=pagestream[m];
        }
        printf("\n");
        printf("%d\t\t\t",pagestream[m]);
        for(n=0;n<frame;n++){
            if(temp[n]!=-1){
                printf("%d\t\t\t",temp[n]);
            }
            else{
                printf("-\t\t\t");
            }
        }
    }
printf("\ntotal page faulys are%d",pagefault);
}*/
//LRU page replacement
/*
#include<stdio.h>
int lru(int t[],int n){
    int i,mini=t[0],pos=0;
    for(i=1;i<n;i++){
        if(t[i]<mini){
            mini=t[i];
            pos=i;
        }
    }
    return pos;
}
int main(){
    int i,j,page,pos,frame,f1,f2,c=0,pf=0,time[10];
    scanf("%d%d",&page,&frame);
    int ps[page],f[frame];
    for(i=0;i<page;i++){
        scanf("%d",&ps[i]);
    }
    for(i=0;i<frame;i++){
        f[i]=-1;
    }
    for(i=0;i<page;i++){
        f1=f2=0;
        for(j=0;j<frame;j++){
            if(ps[i]==f[j]){
                c++;
                time[j]=c;
                f1=f2=1;
                break;
            }
        }
        if(f1==0){
            for(j=0;j<frame;j++){
                if(f[j]==-1){
                    c++;
                    pf++;
                    f[j]=ps[i];
                    time[j]=c;
                    f2=1;
                    break;
                }
            }
        }
        if(f2==0){
            pos=lru(time,frame);
            c++;
            pf++;
            f[pos]=ps[i];
            time[pos]=c;

        }
        printf("\n");
        for(j=0;j<frame;j++){
            printf("%d\t",f[j]);
        }
    }
    printf("\npage faults are%d",pf);
}
*/
//PIPe
/*
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int fd[2],n;
    char bufferr[100];
    pid_t p=fork();
    pipe(fd);
    if(p>0){
        printf("parent passing\n");
        write(fd[1],"hello",5);
        wait(NULL);
    }
    else{
        printf("chil receivd is:");
        n=read(fd[0],buffer,100);
        write(1,buffer,n);
    }
}*/
//fifo
/*// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;

	// FIFO file path
	char * myfifo = "/tmp/myfifo";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>, <permission>)
	mkfifo(myfifo, 0666);

	char arr1[80], arr2[80];
	while (1)
	{
		// Open FIFO for write only
		fd = open(myfifo, O_WRONLY);

		// Take an input arr2ing from user.
		// 80 is maximum length
		fgets(arr2, 80, stdin);

		// Write the input arr2ing on FIFO
		// and close it
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		// Open FIFO for Read only
		fd = open(myfifo, O_RDONLY);

		// Read from FIFO
		read(fd, arr1, sizeof(arr1));

		// Print the read message
		printf("User2: %s\n", arr1);
		close(fd);
	}
	return 0;
}
// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd1;

	// FIFO file path
	char * myfifo = "/tmp/myfifo";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>,<permission>)
	mkfifo(myfifo, 0666);

	char str1[80], str2[80];
	while (1)
	{
		// First open in read only and read
		fd1 = open(myfifo,O_RDONLY);
		read(fd1, str1, 80);

		// Print the read string and close
		printf("User1: %s\n", str1);
		close(fd1);

		// Now open in write mode and write
		// string taken from user.
		fd1 = open(myfifo,O_WRONLY);
		fgets(str2, 80, stdin);
		write(fd1, str2, strlen(str2)+1);
		close(fd1);
	}
	return 0;
}

*/