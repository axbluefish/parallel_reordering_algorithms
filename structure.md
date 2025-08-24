# Libraries and solvers

1. **PETSc**
    - a general-purpose library for scientific computations
    -  frameworks and bunch of solvers

2. **MUMPS**
    - a parallel sparse direct solver (LU/Cholesky)
    - should work from within PETSc

3. **SuperLU\_DIST**
    - a parallel version of SuperLU for sparse matrices

4. **PaStiX**
    - a parallel sparse direct solver (LU/Cholesky)

5. **Trilinos** (? maybe)
    - a suite of scientific computing libraries with parallel solvers

6. **METIS** & **ParMETIS**
    - graph partitioning and reordering
    - used e.g. in nested dissection

7. **Pardiso** (? maybe)
    - a high-performance parallel direct solver (available in Intel MKL or as PARDISO Project)

8. **UMFPACK**
    - a sparse LU solver from SuiteSparse

9. **HYPRE** 
    - parallel preconditioners and solvers
    - often used in large-scale simulations

---

# Reordering algorithms

1. **Approximate Minimum Degree (AMD)**
    - reduces fill-in for factorization

2. **Minimum Degree (MD)** 
    - classic version of AMD

3.  **Nested Dissection (ND)** 
    - recursive graph partitioning to reduce fill-in

4. **Nested Dissection with Metis**
    - implementation of nested dissection using Metis library

5. **Reverse Cuthill-McKee (RCM)**
    - reduces matrix bandwidth

6. **Spectral sequencing**
    - uses eigenvalue info to order matrices

7. **Sloan Algorithm** (? maybe)
    - minimizes profile and wavefront

8. **Gibbs-Poole-Stockmeyer (GPS)**
    - reduces bandwidth

9. **PT-SCOTCH**
    - scalable distributed reordering