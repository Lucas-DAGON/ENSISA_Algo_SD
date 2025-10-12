# ENSISA_Algo_SD
Repository for all exercises (TDs) used in the course.

## Building with the Makefile

This repository includes a top-level `makefile` that can build each exercise independently and run them. The Makefile was designed to work on both Unix-like systems and Windows (PowerShell).

Build artifacts are put into the `build/` directory. Example executables produced by the Makefile:
- `build/fibonacci.exe`  (from `TD1/exercice_1`)
- `build/prime_number.exe` (from `TD1/exercice_2`)

### Common targets
- `make` or `make all` — build all configured exercises
- `make tdX_exoY` — build TD number X and exercise number Y (`TDX/exercice_Y`)
- `make run TDX_EX=Y` - Build & run TD number X and exercise number Y
- `make clean` — remove generated object files and executables from `build/`
- `make help` — print a short help message

### examples:

- Build td1 exercise 1:
```powershell
make td1_exo1
```
- Build and run td1 exercice 1:
```powershell
make run TD1_EX=1
```