PETSC_DIR = ../../petsc
PETSC_ARCH = arch-linux-32-opt

CC = ${PETSC_DIR}/${PETSC_ARCH}/bin/mpicc
CFLAGS = -O2 -Wall -Wextra -I${PETSC_DIR}/include -I${PETSC_DIR}/${PETSC_ARCH}/include
LDFLAGS = -L${PETSC_DIR}/${PETSC_ARCH}/lib -lpetsc -Wl,-rpath,${PETSC_DIR}/${PETSC_ARCH}/lib

SRC = mtx_to_bin_converter.c
EXE = mtx_to_bin_converter

.PHONY: all clean

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXE)
