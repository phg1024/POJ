#include "stdio.h"

__int16 mine[12];
unsigned char field[12][12];
__int16 touch[12];

int main(){
	char n;
	char i, j;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		mine[i] = 0;
		scanf("%s", field[0]);
		for(j=1;j<=n;j++){
			if( field[0][j-1] == '*' )
				mine[i] |= (1<<j);
		}
	}

	char explode = 0;
	for(i=1;i<=n;i++){
		touch[i] = 0;
		scanf("%s", field[0]);
		for(j=1;j<=n;j++){
			if( field[0][j-1] == 'x' )
			{
				touch[i] |= (1<<j);
				if( mine[i] & (1<<j) )
					explode = 1;
			}
		}
	}

	// compute the field
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if( mine[i] & (1<<j) ){
				field[i-1][j-1]++;
				field[i-1][j]++;
				field[i-1][j+1]++;

				field[i][j-1]++;
				field[i][j+1]++;

				field[i+1][j-1]++;
				field[i+1][j]++;
				field[i+1][j+1]++;
			}
		}
	}

	if( explode == 0 ){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(touch[i] & (1<<j)){
					if( mine[i] & (1<<j) ) putchar('*');
					else putchar(field[i][j] + '0');
				}
				else putchar('.');
			}
			putchar('\n');
		}
	}
	else
	{
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
			{
				if( mine[i] & (1<<j) )
					putchar('*');
				else if( touch[i] & (1<<j) )
					putchar(field[i][j] + '0');
				else
					putchar('.');
			}
			putchar('\n');
		}
	}
	return 0;
}