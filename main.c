#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <complex.h>
#include "Vector.h"

int main()
{
    Vector* vec1Int = Vectorn();
    Vector* vec2Int = Vectorn();
    Vector* vec1Complex = Vectorn();
    Vector* vec2Complex = Vectorn();
    int Int1[4] = {17, -3, 7, 9};
    int Int2[4] = {4, 18, -8, 10};
    double complex Complex1[2] = {19 + 3 * I, 7 + 9 * I};
    double complex Complex2[2] = {4.5 + 18 * I, 8 + 10.25 * I};
    vec1Int->opers->Assign(vec1Int, Int1, 4, &AssignInt);
    vec2Int->opers->Assign(vec2Int, Int2, 4, &AssignInt);
    vec1Complex->opers->Assign(vec1Complex, Complex1, 2, &AssignComplex);
    vec2Complex->opers->Assign(vec2Complex, Complex2, 2, &AssignComplex);
//векторное сложение
    Vector* vecSumm = Vectorn();
    vecSumm = vecSumm->opers->Summ(vec1Int, vec2Int, &SummInt);
    printf("\nВекторное сложение целых чисел\n");
    for (int i=0; i<4; ++i)
    {
        printf("%d + %d = %d\n", ((int*)vec1Int->coords)[i], ((int*)vec2Int->coords)[i], ((int*)vecSumm->coords)[i] );
    }
    printf("\nВекторное сложение комплексных чисел\n");
    vecSumm = vecSumm->opers->Summ(vec1Complex, vec2Complex, &SummComplex);
    for (int i=0; i<2; ++i)
    {
        printf("%g + ", creal(((double complex*)vecSumm->coords)[i]) );
        printf("%gi\n", cimag(((double complex*)vecSumm->coords)[i]) );

    }
//скалярное произведение
    Vector* vecScalarProduct = Vectorn();
    printf("\nСкалярное произведение целых чисел\n");
    vecScalarProduct = vecScalarProduct->opers->ScalarProduct(vec1Int, vec2Int, &ScalarProductInt);

    for (int i=0; i<4; ++i)
    {
        printf("%d * %d = %d\n", ((int*)vec1Int->coords)[i], ((int*)vec2Int->coords)[i], ((int*)vecScalarProduct->coords)[i]);
    }

    printf("\nСкалярное произведение комплексных чисел\n");
    vecScalarProduct = vecScalarProduct->opers->ScalarProduct(vec1Complex, vec2Complex, &ScalarProductComplex);
    for (int i=0; i<2; ++i)
    {
        printf("%g + ", creal(((double complex*)vecScalarProduct->coords)[i]) );
        printf("%gi\n", cimag(((double complex*)vecScalarProduct->coords)[i]) );
    }
}
