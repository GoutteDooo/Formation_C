# MODIFIER LE NOM DU COMP_FILE POUR LA COMPILATION
COMP_FILE = pointers


# Définition des dossiers
ROOT_DIR := $(patsubst %/, %, $(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
SRC_DIR = $(ROOT_DIR)/week4/$(COMP_FILE)
BUILD_DIR = $(ROOT_DIR)

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -lcs50

# Nom de l'exécutable
EXEC = $(BUILD_DIR)/week4/$(COMP_FILE)/$(COMP_FILE)

# Règle principale
all: $(EXEC)

# Ajout de la cible "COMP_FILE" pour que make -C ../.. COMP_FILE fonctionne
$(COMP_FILE): $(EXEC)

# Compilation du programme
$(EXEC): $(SRC_DIR)/$(COMP_FILE).c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(EXEC)
