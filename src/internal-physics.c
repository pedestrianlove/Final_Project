#include "internal-physics.h"

vector vector_sum (vector a, vector b)
{
	vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

vector scalar_multiplication (vector a, double c)
{
	a.x = a.x * c;
	a.y = a.y * c;
	return a;
}

double vector_length_square (vector a)
{
	return a.x*a.x + a.y*a.y;
}

double inner_product (vector a, vector b)
{
	return (a.x*b.x + a.y*b.y);
}

int will_collide (circle* a, circle* b)
{
	double r_y = a->y - b->y;
	double r_x = a->x - b->x;
	double radius = a->radius + b->radius;
	if (r_x*r_x + r_y*r_y <= radius*radius)
		return 1;
	else
		return 0;
}

circle* init_Reddie ()
{
	circle* Reddie = malloc (sizeof(circle));
	Reddie -> x = 50;
	Reddie -> y = 50;
	Reddie -> radius = 20;
	
	Reddie -> velocity.x = 0;
	Reddie -> velocity.y = 0;

	Reddie -> gravitation = 0.05;

	return Reddie;
}

void gravitation_Reddie (circle* Reddie)
{
	if (Reddie != NULL)
		Reddie -> velocity.y += Reddie->gravitation;
	else
		printf("Reddie is gone.\n");
}

void friction_Reddie (circle* Reddie)
{
	if (Reddie != NULL) {
		Reddie -> velocity.x *= 0.995;
		Reddie -> velocity.y *= 0.995;
	}
}


void collision (circle* Reddie, circle* fixed)
{	
	vector initial_velocity = Reddie->velocity;
	vector normal_vector = {Reddie->x-fixed->x, Reddie->y-fixed->y};
	vector directional_vector = {-(normal_vector.y), normal_vector.x};

	double Normal_coef = inner_product (initial_velocity, normal_vector) / vector_length_square (normal_vector);
	double directional_coef = inner_product (initial_velocity, directional_vector) / vector_length_square (directional_vector);

	normal_vector = scalar_multiplication (normal_vector, Normal_coef);
	directional_vector = scalar_multiplication (directional_vector, directional_coef);

	Reddie -> velocity =  vector_sum (normal_vector, directional_vector);
}

