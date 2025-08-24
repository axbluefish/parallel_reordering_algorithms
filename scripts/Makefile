# Modify these paths to match your actual PETSc setup
PETSC_DIR = /home/alexandr/Plocha/bsc_thesis/numerical_experiments/petsc
PETSC_ARCH = arch-linux-32-opt

CC = ${PETSC_DIR}/${PETSC_ARCH}/bin/mpicc
CFLAGS = -O2 -Wall -Wextra -I${PETSC_DIR}/include -I${PETSC_DIR}/${PETSC_ARCH}/include
LDFLAGS = -L${PETSC_DIR}/${PETSC_ARCH}/lib -lpetsc -Wl,-rpath,${PETSC_DIR}/${PETSC_ARCH}/lib

SRC = experiments.c
OBJ = $(SRC:.c=.o)

EXE = experiment

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(EXE) *.o
