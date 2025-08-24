#include <petscsys.h>
#include <petsc.h>

int init_environment(int argc, char **argv) {
    PetscErrorCode ierr;

    ierr = PetscInitialize(&argc, &argv, NULL, NULL); CHKERRQ(ierr);

    // You can load any config options here (e.g., from options file)

    return 0;
}

int finalize_environment() {
    PetscErrorCode ierr = PetscFinalize(); CHKERRQ(ierr);
    return 0;
}
