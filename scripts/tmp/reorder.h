#ifndef REORDER_H
#define REORDER_H

#include <petscmat.h>
PetscErrorCode reorder_matrix(Mat A, IS *rowPerm, IS *colPerm);

#endif
