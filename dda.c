#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDA(int x1, int y1, int x2, int y2) {
	int dx = x2-x1;
	int dy = y2-y1;

	int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

	float x_inc = dx/(float)steps;
	float y_inc = dy/(float)steps;

	float X=x1, Y=y1;
	int i;
	for(i=0;i<=steps;i++) {
		putpixel(X,Y,RED);
		X+=x_inc;
		Y+=y_inc;
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

	DDA(x1,y1,x2,y2);
}