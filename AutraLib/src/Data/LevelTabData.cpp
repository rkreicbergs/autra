﻿// This is a generated file

#include "Game/Game.h"

namespace AutraLib
{
    std::map<GameType, std::vector<Game::LevelTab>> Game::LevelTabs;

    void Game::LoadLevelTabs()
    {
        LevelTabs[GameType::Pitch] = std::vector<LevelTab>({
            { 0, 20, "Skaņaugstuma uzmanība I" },
            { 20, 20, "Skaņaugstuma uzmanība II" },
            { 40, 20, "Skaņaugstuma uzmanība III" },
        });

        LevelTabs[GameType::Rhythm] = std::vector<LevelTab>({
            { 0, 20, "Ritma uzmanība I" },
            { 20, 20, "Ritma uzmanība II" },
            { 40, 20, "Ritma uzmanība III" },
        });

        LevelTabs[GameType::Interval] = std::vector<LevelTab>({
            { 0, 15, "t4,t5" },
            { 15, 20, "m3,l6" },
            { 35, 25, "l2,l3,m6" },
            { 60, 15, "Tritons,m2,m7,l7" },
            { 75, 25, "Saliktie intervāli" },
            { 100, 20, "Vienkāršie un saliktie intervāli" },
        });

        LevelTabs[GameType::Scale] = std::vector<LevelTab>({
            { 0, 20, "Tetrahordi, dabiskais mažors un minors" },
            { 20, 20, "Mažora un minora veidi" },
            { 40, 20, "Senās skaņkārtas (modi)" },
            { 60, 20, "Pentatonika" },
            { 80, 20, "pl un pm skaņkārtas" },
            { 100, 20, "Minora veidu modi" },
            { 120, 20, "Mažora veidu modi" },
            { 140, 20, "Alterētie modi" },
            { 160, 20, "Enigmātiskā un kompozītā skaņkārta" },
            { 180, 20, "Bībopa modi" },
            { 200, 20, "Dominantes un astoņtoņu skaņkārtas" },
            { 220, 20, "Austrumu skaņkārtas" },
            { 240, 20, "Dažādi skaņkārtu paterni" },
        });

        LevelTabs[GameType::Chord] = std::vector<LevelTab>({
            { 0, 21, "Mažora un minora trijskaņi" },
            { 21, 21, "Mazais mažora un minora septakords" },
            { 42, 21, "Mazais ievadseptakords" },
            { 63, 21, "Pamazinātais kvintakords un septakords" },
            { 84, 21, "Nonakordi, septakordi ar sekstu" },
            { 105, 21, "Lielais mažora un minora septakords" },
            { 126, 21, "Palielinātais kvintakords un septakords" },
        });
    }
}
