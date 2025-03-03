# Trouver le dossier racine du projet, peu importe d'où `make` est lancé
ROOT_DIR := $(patsubst %/, %, $(dir $(abspath $(lastword $(MAKEFILE_LIST)))))

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -lcs50

# Définition des répertoires
SRC_DIR = $(ROOT_DIR)/week4/recursive
BUILD_DIR = $(ROOT_DIR)

# Nom de l'exécutable
EXEC = $(BUILD_DIR)/recursive

# Règle principale : compiler l'exécutable
all: $(EXEC)

# Compilation du programme
$(EXEC): $(SRC_DIR)/recursive.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(EXEC)
