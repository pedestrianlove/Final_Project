#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
	double x, y;
}vector;

typedef struct circle {
	double x, y;
	double radius;
	vector velocity;
	double gravitation;
}circle;


// initializer
circle* init_Reddie ();


// physics
void collision (circle*, circle*);
int will_collide (circle*, circle*);
void gravitation_Reddie (circle*);
void friction_Reddie (circle*);

// math
vector vector_sum (vector, vector);
vector scalar_multiplication (vector, double);
double vector_length_square (vector);
double inner_product (vector, vector);



