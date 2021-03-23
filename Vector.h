#ifndef LAB_1_VECTOR_H
#define LAB_1_VECTOR_H

#include <stdio.h>
#include <complex.h>

struct VectorN
{
    size_t size;
    void* coords;
    struct Operations* opers;
};

typedef struct VectorN Vector;

Vector* Vectorn();

struct Operations
{
    void (*Assign)(Vector* v, void* coords, size_t size, void (*AssignType)(Vector* v, void* coords, size_t size) );
    Vector* (*Summ)(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) ); //векторное сложение
    Vector* (*ScalarProduct)(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) ); //скалярное произведение
};
void Assign(Vector* v, void* coords, size_t size, void (*AssignType)(Vector* v, void* coords, size_t size));
Vector* Summ(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) );
Vector* ScalarProduct(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) );
void AssignInt(Vector* v, int* coords, size_t size);
void AssignComplex(Vector* v, double complex* coords, size_t size);
Vector* SummInt(Vector* v1, Vector* v2);
Vector* SummComplex(Vector* v1, Vector* v2);
Vector* ScalarProductInt(Vector* v1, Vector* v2);
Vector* ScalarProductComplex(Vector* v1, Vector* v2);

#endif //LAB_1_VECTOR_H
