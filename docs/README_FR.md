# Documentation (Français)

Ce projet constitue une base pour une application ESP32 permettant la gestion complète d'un élevage de reptiles, conforme aux règlementations françaises et européennes. Les modules sont organisés de manière à pouvoir être complétés selon les besoins.

## Arborescence

- `main/` : point d'entrée de l'application.
- `components/database/` : gestion de la base SQLite ou du système de fichiers.
- `components/ui/` : interface tactile LVGL.
- `components/legal/` : génération des documents légaux (CERFA, I-FAP, CITES).
- `docs/` : cette documentation.

## Configuration rapide

1. Installer ESP-IDF et configurer l'environnement.
2. Se placer à la racine du projet puis exécuter `idf.py menuconfig` pour ajuster la configuration.
3. Compiler et flasher avec `idf.py flash monitor`.

Les modules présents sont à l'état minimal et doivent être complétés pour une utilisation en production.
