# Lyzard Board

Ce projet fournit une structure de base pour le développement d'une application ESP32 (ESP-IDF) destinée à la gestion d'un élevage de reptiles. Il s'appuie sur LVGL pour l'interface tactile, une base de données locale et des modules spécifiques permettant la génération automatique des documents légaux français (CERFA, I-FAP, CITES, etc.).

**Fonctionnalités prévues** :

- Gestion des animaux, terrariums, cycles de vie et événements sanitaires.
- Stocks et transactions avec création des documents légaux correspondants.
- Interface graphique LVGL (800x480, thème clair/sombre, multi-langues).
- Authentification locale et chiffrement des données sensibles.
- Export/Import CSV ou JSON et sauvegarde sur carte SD ou via Wi-Fi.

Ce dépôt propose uniquement une implémentation minimale servant de point de départ.
Reportez-vous à `docs/README_FR.md` pour plus d'informations.

## Pré-requis supplémentaires

Le composant graphique [LVGL](https://lvgl.io) n'est pas inclus directement.
Installez-le via le gestionnaire de composants ESP‑IDF :

```bash
idf.py add-dependency lvgl/lvgl
```
