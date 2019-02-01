#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

	
int main(){
  int pix[3];
  char string[20];
  char * header = "P3\n500 500\n255\n ";

  int fd = open("pic.ppm", O_CREAT | O_WRONLY, 0644);
  int written = write(fd, header, strlen(header));
  printf("%d", fd);

  for(int i=0; i<250; i++){
    for(int k=0; k<250; k++){
      for(int j=0; j<4; j++){
	pix[0]=((i+k)*j)%255;
	pix[1]=((i+k)*j)%255;
	pix[2]=j*50;
	snprintf(string, sizeof(string), "%d %d %d ", pix[0], pix[1], pix[2]);
	write(fd, string, strlen(string));
      }

    }
  }
  
}
