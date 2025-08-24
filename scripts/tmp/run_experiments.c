#include <petscksp.h>
#include "init_experiments.h"
#include "reorder.h"
#include "save_results.h"

int main(int argc, char **argv) {
    PetscErrorCode ierr;

    ierr = init_environment(argc, argv); CHKERRQ(ierr);

    // Load matrix
    Mat A;
    PetscViewer viewer;
    ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, "matrices/matrix1.bin", FILE_MODE_READ, &viewer); CHKERRQ(ierr);
    ierr = MatCreate(PETSC_COMM_WORLD, &A); CHKERRQ(ierr);
    ierr = MatLoad(A, viewer); CHKERRQ(ierr);
    ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

    // Reorder matrix
    IS rowPerm, colPerm;
    ierr = reorder_matrix(A, &rowPerm, &colPerm); CHKERRQ(ierr);

    // Solve system (example: KSP)
    Vec x, b;
    ierr = MatCreateVecs(A, &x, &b); CHKERRQ(ierr);
    ierr = VecSet(b, 1.0); CHKERRQ(ierr); // simple RHS for demo

    KSP ksp;
    ierr = KSPCreate(PETSC_COMM_WORLD, &ksp); CHKERRQ(ierr);
    ierr = KSPSetOperators(ksp, A, A); CHKERRQ(ierr);
    ierr = KSPSetFromOptions(ksp); CHKERRQ(ierr);
    ierr = KSPSolve(ksp, b, x); CHKERRQ(ierr);

    // Save results
    ierr = save_results(x, "results/result1.txt"); CHKERRQ(ierr);

    // Cleanup
    ISDestroy(&rowPerm); ISDestroy(&colPerm);
    VecDestroy(&x); VecDestroy(&b);
    MatDestroy(&A); KSPDestroy(&ksp);

    ierr = finalize_environment(); CHKERRQ(ierr);
    return 0;
}
