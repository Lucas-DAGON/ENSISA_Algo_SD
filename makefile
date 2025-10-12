# Compiler and flags
CC := gcc
CFLAGS := -Wall -g -MMD
CPPFLAGS := -Iinclude

# Build directory
BUILD_DIR := build

# Create build/binary directory if it doesn't exist
$(shell [ -d $(BUILD_DIR) ] || mkdir $(BUILD_DIR) 2> /dev/null || powershell -NoProfile -Command "if (-not (Test-Path -Path '$(BUILD_DIR)')) { New-Item -ItemType Directory -Path '$(BUILD_DIR)' | Out-Null }")

# --- Exercice 1 ---
SRC_TD1_EX1 := TD1/exercice_1/src
INCLUDE_TD1_EX1 := TD1/exercice_1/include
SRCS_TD1_EX1 := $(wildcard $(SRC_TD1_EX1)/*.c)
OBJS_TD1_EX1 := $(patsubst $(SRC_TD1_EX1)/%.c,$(BUILD_DIR)/ex1_%.o,$(SRCS_TD1_EX1))
DEPS_TD1_EX1 := $(OBJS_TD1_EX1:.o=.d)
TARGET_TD1_EX1 := $(BUILD_DIR)/fibonacci.exe

# --- Exercice 2 ---
SRC_TD1_EX2 := TD1/exercice_2/src
INCLUDE_TD1_EX2 := TD1/exercice_2/include
SRCS_TD1_EX2 := $(wildcard $(SRC_TD1_EX2)/*.c)
OBJS_TD1_EX2 := $(patsubst $(SRC_TD1_EX2)/%.c,$(BUILD_DIR)/ex2_%.o,$(SRCS_TD1_EX2))
DEPS_TD1_EX2 := $(OBJS_TD1_EX2:.o=.d)
TARGET_TD1_EX2 := $(BUILD_DIR)/prime_number.exe

.PHONY: all td1_exo1 td1_exo2 clean help

all: td1_exo1 td1_exo2

# Top-level rules for exercise 1
$(TARGET_TD1_EX1): $(OBJS_TD1_EX1)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/ex1_%.o: $(SRC_TD1_EX1)/%.c
	$(CC) $(CPPFLAGS) -I$(INCLUDE_TD1_EX1) $(CFLAGS) -c $< -o $@

td1_exo1: $(TARGET_TD1_EX1)
	@echo "\nBuilding TD1 Exercice 1..."
	@echo "\nBuild successful (built $(TARGET_TD1_EX1))"

# Top-level rules for exercise 2
$(TARGET_TD1_EX2): $(OBJS_TD1_EX2)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/ex2_%.o: $(SRC_TD1_EX2)/%.c
	$(CC) $(CPPFLAGS) -I$(INCLUDE_TD1_EX2) $(CFLAGS) -c $< -o $@

td1_exo2: $(TARGET_TD1_EX2)
	@echo "\nBuilding TD1 Exercice 2..."
	@echo "\nBuild successful (built $(TARGET_TD1_EX2))"

# Inclusion des fichiers de dépendance (if present)
-include $(DEPS_TD1_EX1) $(DEPS_TD1_EX2)


clean:
	@echo "Cleaning build directory..."
	-@rm -f $(BUILD_DIR)/ex1_*.o $(BUILD_DIR)/ex2_*.o $(BUILD_DIR)/*.d $(BUILD_DIR)/*.exe 2> /dev/null || powershell -NoProfile -Command "Get-ChildItem -Path '$(BUILD_DIR)' -Filter 'ex1_*.o','ex2_*.o','*.d','*.exe' -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue"

help:
	@echo "Makefile to compile each exercise independently"
	@echo "usage:"
	@echo "  make         - Compile all exercises (build-only targets)"
	@echo "  make td1_exo1 - Build TD1 exercise 1 -> $(TARGET_TD1_EX1)"
	@echo "  make td1_exo2 - Build TD1 exercise 2 -> $(TARGET_TD1_EX2)"
	@echo "  make run TD1_EX=1 - Build & run TD1 exercise 1"
	@echo "  make run TD1_EX=2 - Build & run TD1 exercise 2"
	@echo "  make clean   - delete all generated files in $(BUILD_DIR)"


# Run target: use TD1_EX=1 or TD1_EX=2
.PHONY: run
run:
	@if [ "$(TD1_EX)" = "1" ]; then \
		$(MAKE) td1_exo1; \
		echo "Running $(TARGET_TD1_EX1)..."; \
		$(TARGET_TD1_EX1) || true; \
	elif [ "$(TD1_EX)" = "2" ]; then \
		$(MAKE) td1_exo2; \
		echo "Running $(TARGET_TD1_EX2)..."; \
		$(TARGET_TD1_EX2) || true; \
	else \
		echo "Usage: make run TD1_EX=1 or TD1_EX=2"; false; \
	fi