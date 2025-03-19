#!/bin/bash

# Initialisation de la variable booléenne
no_changes=false

while true; do
    # Vérifier s'il y a des fichiers modifiés ou en attente d'ajout
    if [[ -n $(git status --porcelain) ]]; then
        echo "🚀 Des modifications détectées, commit en cours..."

        # Ajouter les fichiers modifiés
        git aa

        # Commiter avec la date actuelle
        ./git_datecommit.sh

        # Réinitialiser la variable car un commit a été fait
        no_changes=false

        echo "✅ Commit effectué à $(date '+%Y-%m-%d %H:%M:%S')"
    else
        echo "😴 Aucune modification détectée, en attente..."
        
        # Si aucun changement n'a été détecté, on active le mode rapide (30s)
        if [ "$no_changes" = false ]; then
            no_changes=true
            echo "⏳ Passage au mode d'attente rapide (30 secondes)"
        fi
    fi

    # Définition du temps de pause en fonction de la variable `no_changes`
    if [ "$no_changes" = true ]; then
        sleep 30  # Mode rapide
    else
        sleep 180  # Mode normal
    fi
done
