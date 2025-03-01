#!/bin/bash
git aa
./git_datecommit.sh

#!/bin/bash
while true; do
    # Vérifier s'il y a des fichiers modifiés ou en attente d'ajout
    if [[ -n $(git status --porcelain) ]]; then
        echo "Des modifications détectées, commit en cours..."

        # Ajouter les fichiers modifiés
        git aa

        # Commiter avec la date actuelle
        ./git_datecommit.sh

        # (Optionnel) Pousser automatiquement les commits
        # git push origin main  # ou la branche sur laquelle tu travailles

        echo "✅ Commit effectué à $(date '+%Y-%m-%d %H:%M:%S')"
    else
        echo "😴 Aucune modification détectée, en attente..."
    fi

    # Pause de 3 minutes (180 secondes)
    sleep 180
done
