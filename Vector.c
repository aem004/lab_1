#include "Vector.h"
#include <malloc.h>
#include <stdlib.h>

Vector* Vectorn()
{
    Vector* v = malloc(sizeof(Vector));
    v->opers = malloc(sizeof(struct Operations));
    v->opers->Summ = &Summ;
    v->opers->ScalarProduct = &ScalarProduct;
    v->opers->Assign = &Assign;
    v->coords = NULL;
    v->size = 0;
    return v;
}
void Assign(Vector* v, void* coords, size_t size, void (*AssignType)(Vector* v, void* coords, size_t size))
{
    AssignType(v, coords, size);
}
Vector* Summ(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) )
{
    return SummType(v1, v2);
}
Vector* ScalarProduct(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) )
{
    return ScalarProductType(v1, v2);
}
void AssignInt(Vector* v, int* coords, size_t size)
{
    v->coords = malloc(sizeof(int)*size);
    v->size = size;
    for (size_t i=0; i<size; ++i)
    {
        ((int*)v->coords)[i] = coords[i];
    }
}
void AssignComplex(Vector* v, double complex* coords, size_t size)
{
    v->coords = malloc(sizeof(double complex)*size);
    v->size = size;
    for (size_t i=0; i<size; ++i)
    {
        ((double complex*)v->coords)[i] = coords[i];
    }
}
Vector* SummInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coords = malloc(sizeof(int)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            int coord1 = ((int*)v1->coords)[i];
            int coord2 = ((int*)v2->coords)[i];
            ((int*)v->coords)[i] = coord1 + coord2;
        }
    }
    return v;
}
Vector* SummComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coords = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coords)[i];
            double complex coord2 = ((double complex*)v2->coords)[i];
            ((double complex*)v->coords)[i] = coord1 + coord2;
        }
    }
    return v;
}
Vector* ScalarProductInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coords = malloc(sizeof(int)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            int coord1 = ((int*)v1->coords)[i];
            int coord2 = ((int*)v2->coords)[i];
            ((int*)v->coords)[i] = coord1 * coord2;
        }
    }
    return v;
}

Vector* ScalarProductComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coords = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coords)[i];
            double complex coord2 = ((double complex*)v2->coords)[i];
            ((double complex*)v->coords)[i] = coord1 * coord2;
        }
    }
    return v;
}
