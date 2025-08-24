#include <petscvec.h>
#include <petscviewer.h>

PetscErrorCode save_results(Vec x, const char *filename) {
    PetscErrorCode ierr;
    PetscViewer viewer;

    ierr = PetscViewerASCIIOpen(PETSC_COMM_WORLD, filename, &viewer); CHKERRQ(ierr);
    ierr = VecView(x, viewer); CHKERRQ(ierr);
    ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

    return 0;
}
