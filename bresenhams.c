#include<stdio.h>
#include<graphics.h>
#include<math.h>

void Bresenham(int x1, int y1, int x2, int y2) {
	int dx = x2-x1;
	int dy = y2-y1;

	int p = 2*dy-dx;
	
	int X=x1, Y=y1;
	int i;
	for(;X<=x2;X++) {
		putpixel(X,Y,RED);
		if(p>=0) {
			Y++;
			p=p+2*dy-2*dx;
		}
		else {
			p=p+2*dy;
		}
		delay(10);
	}
	getch();
}

int main() {
	int gd = DETECT, gm;

	int x1, x2, y1, y2;
	printf("Enter coordinates\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	initgraph(&gd, &gm, NULL);
	setbkcolor(WHITE);

	Bresenham(x1,y1,x2,y2);
}