#include<stdio.h>
int main()
{
	int data[8], c, c0, c1, c2, recv[8], i;
	
	printf("Enter four bit data: ");
	scanf("%d", &data[3]);
	scanf("%d", &data[5]);
	scanf("%d", &data[6]);
	scanf("%d", &data[7]);
	
	data[1] = (data[3] + data[5] + data[7]) % 2;
	data[2] = (data[3] + data[6] + data[7]) % 2;
	data[4] = (data[5] + data[6] + data[7]) % 2;
	
	printf("The Data encoded is: ");
	for (i = 1; i < 8; i++) {
		printf("%d", data[i]);
	}
	printf("\n");
	
	printf("Enter Data received: ");
	for (i = 1; i < 8; i++) {
		scanf("%d", &recv[i]);
	}
	
	c0 = (recv[1] + recv[3] + recv[5] + recv[7]) % 2;
	c1 = (recv[2] + recv[3] + recv[6] + recv[7]) % 2;
	c2 = (recv[4] + recv[5] + recv[6] + recv[7]) % 2;
	c = c2 * 4 + c1 * 2 + c0 * 1;
	
	if (c == 0)
		printf("No error detected.\n");
	else {
		printf("The error is at position %d\n", c);
		if (recv[c] == 0)
			recv[c] = 1;
		else
			recv[c] = 0;
	}
	
	printf("The Data corrected is: ");
	for (i = 1; i < 8; i++) {
		printf("%d", recv[i]);
	}
	printf("\n");
	
	return 0;
}
