#include <stdio.h>

typedef struct {
	float length;
	float width;
} Rectangle;

int check(Rectangle rect){
	if(rect.length>0.0 && rect.length<20.0){
		if(rect.width>0.0 && rect.width<20.0)
			return 1;
		return 2;
	}
	return 0;
}

float perimeter(Rectangle rect){
	float result;
	result = 2*rect.length + 2*rect.width;
	return result;
}

float area(Rectangle rect){
	float result;
	result = rect.length*rect.width;
	return result;
}

int main(){
	Rectangle rect;
	printf("Enter Length: ");
	scanf("%f", &rect.length);
	printf("Enter Width: ");
	scanf("%f", &rect.width);
	
	if(check(rect) == 0)
		printf("Length is not in desired range.\n");
	if(check(rect) == 2)
		printf("Width is not in desired range.\n");
	if(check(rect) == 1){
		printf("Valid\n");
		printf("Area: %.3f\n", area(rect));
		printf("Perimeter: %.3f", perimeter(rect));
	}
	return 0;
}
