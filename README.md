# Apexe - Projet de Démonstration C++

## Introduction

Bonjour,

Tout d'abord, je vous remercie de prendre le temps d'examiner mon projet ainsi que ma candidature.

Ce projet comporte trois pages distinctes :
1. **Pierre-Feuille-Ciseaux** : Une implémentation du jeu classique pour réaliser l'architecture et la base du projet et vérifier son bon fonctionnement.
2. **Visualisation de différents tris** : Une démonstration visuelle de divers algorithmes de tri.
3. **Simulation de transaction bancaire** : Une simulation mettant en avant l'utilisation du multitâche. Cette simulation de banque crée une tâche spécifique pour chaque transaction et l'exécute en parallèle des autres. 

Ce projet a été réalisé pour postuler au poste de développeur C++ que vous proposez. Mon objectif est de vous démontrer mon savoir-faire en C++ et ma capacité à concevoir des applications structurées et fonctionnelles.

## Structure du Projet

Le projet est structuré de manière à séparer la gestion graphique et les fonctionnalités logiques. Chaque page possède sa propre gestion graphique dans le dossier `PageNomDeLaPage`, tandis que les classes non graphiques se trouvent dans des dossiers dédiés `sources`.

Pour l'interface graphique, j'ai choisi d'utiliser **Qt**, une bibliothèque puissante et flexible pour le développement d'interfaces graphiques en C++.

### Détails des Pages

1. **Pierre-Feuille-Ciseaux** :
    - Une interface utilisateur simple permettant de jouer au jeu.
    - La logique du jeu est implémentée dans des classes distinctes pour garantir une séparation claire entre l'interface graphique et la logique.

2. **Visualisation de différents tris** :
    - Une interface visuelle permettant de voir les étapes de différents algorithmes de tri en temps réel.
    - Les algorithmes de tri sont implémentés dans des classes distinctes, assurant ainsi une modularité et une facilité de maintenance.
    - Chaque algorithme est codé dans un dossier spécifique.

3. **Simulation de transaction bancaire** :
    - Une simulation de transactions bancaires mettant en avant l'utilisation du multitâche.
    - Chaque transaction est une tâche distincte, ainsi que le générateur de transaction qui s'exécute sur une tâche particulière.

## Compilation et Exécution

Ce projet utilise CMake pour la configuration et Visual Studio pour la compilation. Pour l'interface graphique, Qt est nécessaire.

### Prérequis

- [Qt](https://www.qt.io/download)
- [CMake](https://cmake.org/download/)
- [Visual Studio](https://visualstudio.microsoft.com/)

### Instructions de Compilation

1. **Cloner le dépôt :** 
    ```sh
    git clone git@github.com:amelie-ort/Apexe.git
    cd Apexe
    ```

2. **Configurer Qt :** 
    - Assurez-vous que Qt est correctement installé et configuré sur votre système.
    - Ajoutez Qt au PATH ou configurez les variables d'environnement nécessaires.

3. **Compiler le projet avec Visual Studio :**
    - Dans l'onglet Générer : "Générer Apexe.exe"

4. **Exécution :**
    - Apexe.exe est dans le répertoire `out/build`

## Auto-évaluation

En raison de l'incertitude du temps qu'il restait pour réaliser ce projet avant que l'offre ne soit pourvue, j'ai réalisé ce projet rapidement. Par conséquent, je suis consciente que mon code présente plusieurs axes d'amélioration :

- Refactorisation du code en respectant davantage la théorie des principes SOLID
- Amélioration de la documentation et des commentaires pour améliorer la clarté et faciliter la compréhension du code
- Identification et résolution des avertissements (warnings) générés par le compilateur
- Mise en place d'un environnement de développement plus fonctionnel, incluant l'intégration d'outils de développement tels que des linters et des outils d'aide à la détection et à la correction des bugs.
- Ajout de la fonction rejoué dans les tris, ainsi que la correction du bug de lancement anticipé de l'animation si on change de tri alors qu'un tri est déjà en cours.
- Optimiser l'interface graphique de la banque afin de ne pas tout redessiner à chaque fois tous les éléments

## Conclusion

J'espère que ce projet vous montrera ma motivation et mes compétences pour le poste que vous proposez. 

Je suis impatiente de discuter plus en détail de ce projet et de mes qualifications pour le poste.

Je vous remercie pour votre temps.

Cordialement,

Amélie Ortuno
