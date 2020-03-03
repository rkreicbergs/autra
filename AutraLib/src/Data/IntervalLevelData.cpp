// This is a generated file

#include "Game/Levels/IntervalLevel.h"
#include "Game/Game.h"

namespace AutraLib
{
    static const int ExamIds[] = {14, 34, 59, 74, 99, 119};

    void IntervalLevel::LoadData()
    {
        std::vector<Level*>* allLevels = new std::vector<Level*>();
        allLevels->reserve(120);

        /* 1 */ allLevels->push_back(new IntervalLevel(true, {7}, 23, {5}, 17, 10, 2000, 120, 2000, 'A', 1, 5, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 2 */ allLevels->push_back(new IntervalLevel(false, {7}, 27, {5}, 20, 15, 1500, 141, 2000, 'A', 2, 6, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 3 */ allLevels->push_back(new IntervalLevel(false, {7}, 25, {5}, 18, 20, 1000, 129, 2000, 'L', 0, 75, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 4 */ allLevels->push_back(new IntervalLevel(false, {7}, 29, {5}, 21, 30, 750, 150, 1800, 'L', 4, 187, {0,5,7}, {0,12,19,26,42,57,71}));
        /* 5 */ allLevels->push_back(new IntervalLevel(false, {7}, 35, {5}, 25, 40, 500, 180, 1700, 'P', 5, 19, {1,4,6}, {0,12,19,32,42,57,70}));
        /* 6 */ allLevels->push_back(new IntervalLevel(false, {5}, 23, {7}, 17, 10, 2000, 120, 2000, 'A', 6, 18, {1,4,6}, {0,19,32,42,57,70}));
        /* 7 */ allLevels->push_back(new IntervalLevel(false, {5}, 27, {7}, 20, 15, 1500, 141, 2000, 'A', 3, 26, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 8 */ allLevels->push_back(new IntervalLevel(false, {5}, 33, {7}, 24, 20, 1000, 172, 1800, 'L', 2, 54, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 9 */ allLevels->push_back(new IntervalLevel(false, {5}, 39, {7}, 28, 30, 750, 200, 1700, 'L', 2, 68, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 10 */ allLevels->push_back(new IntervalLevel(false, {5}, 47, {7}, 34, 40, 500, 240, 1500, 'P', 8, 89, {2,6,8}, {0,19}));
        /* 11 */ allLevels->push_back(new IntervalLevel(false, {7,5}, 29, {8,6}, 21, 10, 2000, 150, 2000, 'P', 9, 145, {2,6,8}, {0,19}));
        /* 12 */ allLevels->push_back(new IntervalLevel(false, {7,5}, 34, {8,6}, 25, 15, 2000, 177, 1800, 'P', 3, 194, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 13 */ allLevels->push_back(new IntervalLevel(false, {7,5}, 33, {8,6}, 24, 20, 1500, 172, 1700, 'P', 8, 154, {9,10,11}, {0,19}));
        /* 14 */ allLevels->push_back(new IntervalLevel(false, {7,5}, 39, {8,6}, 28, 30, 1500, 200, 1500, 'P', 2, 156, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 15 */ allLevels->push_back(new IntervalLevel(true, {7,5}, 47, {8,6}, 34, 40, 1000, 240, 1700, 'P', 2, 170, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 16 */ allLevels->push_back(new IntervalLevel(true, {3}, 35, {4}, 25, 10, 2000, 180, 2000, 'A', 1, 5, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 17 */ allLevels->push_back(new IntervalLevel(false, {3}, 41, {4}, 30, 15, 1500, 212, 2000, 'A', 2, 6, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 18 */ allLevels->push_back(new IntervalLevel(false, {3}, 42, {4}, 30, 20, 1000, 215, 1800, 'L', 0, 75, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 19 */ allLevels->push_back(new IntervalLevel(false, {3}, 49, {4}, 35, 30, 750, 250, 1600, 'L', 4, 187, {0,5,7}, {0,12,19,26,42,57,71}));
        /* 20 */ allLevels->push_back(new IntervalLevel(false, {3}, 59, {4}, 42, 40, 500, 300, 1400, 'P', 5, 19, {1,4,6}, {0,12,19,32,42,57,70}));
        /* 21 */ allLevels->push_back(new IntervalLevel(false, {9}, 35, {8}, 25, 10, 2000, 180, 2000, 'A', 6, 18, {1,4,6}, {0,19,32,42,57,70}));
        /* 22 */ allLevels->push_back(new IntervalLevel(false, {9}, 41, {8}, 30, 15, 1500, 212, 2000, 'A', 3, 26, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 23 */ allLevels->push_back(new IntervalLevel(false, {9}, 42, {8}, 30, 20, 1000, 215, 1800, 'L', 4, 33, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 24 */ allLevels->push_back(new IntervalLevel(false, {9}, 49, {8}, 35, 30, 750, 250, 1600, 'L', 4, 40, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 25 */ allLevels->push_back(new IntervalLevel(false, {9}, 59, {8}, 42, 40, 500, 300, 1500, 'P', 8, 9, {2,6,8}, {0,19}));
        /* 26 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 29, {4,8}, 21, 10, 2000, 150, 2000, 'A', 9, 12, {2,6,8}, {0,19}));
        /* 27 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 34, {4,8}, 25, 15, 2000, 177, 2000, 'A', 3, 11, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 28 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 33, {4,8}, 24, 20, 1500, 172, 1900, 'L', 8, 54, {9,10,11}, {0,19}));
        /* 29 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 39, {4,8}, 28, 30, 1500, 200, 1800, 'L', 4, 68, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 30 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 47, {4,8}, 34, 40, 1000, 240, 1600, 'P', 4, 89, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 31 */ allLevels->push_back(new IntervalLevel(false, {3,7}, 41, {4,5}, 29, 10, 1500, 210, 2000, 'P', 1, 145, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 32 */ allLevels->push_back(new IntervalLevel(false, {3,5}, 48, {4,7}, 35, 15, 1500, 247, 1800, 'P', 2, 194, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 33 */ allLevels->push_back(new IntervalLevel(false, {9,5}, 50, {8,7}, 36, 20, 1500, 257, 1600, 'P', 0, 154, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 34 */ allLevels->push_back(new IntervalLevel(false, {9,7}, 59, {8,5}, 42, 30, 1500, 300, 1500, 'P', 4, 156, {9,10,11}, {0,12,19,26,42,57,71}));
        /* 35 */ allLevels->push_back(new IntervalLevel(true, {9,7}, 70, {8,5}, 50, 40, 1500, 360, 1600, 'P', 5, 170, {9,10,11}, {0,12,19,32,42,57,70}));
        /* 36 */ allLevels->push_back(new IntervalLevel(true, {4}, 41, {3}, 29, 10, 2000, 210, 2000, 'A', 6, 6, {0,5,7}, {0,19,32,42,57,70}));
        /* 37 */ allLevels->push_back(new IntervalLevel(false, {4}, 48, {3}, 35, 15, 1500, 247, 2000, 'A', 3, 75, {0,5,7}, {0,11,19,26,40,42,71,9}));
        /* 38 */ allLevels->push_back(new IntervalLevel(false, {4}, 50, {3}, 36, 20, 1000, 257, 1800, 'L', 2, 187, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 39 */ allLevels->push_back(new IntervalLevel(false, {4}, 59, {3}, 42, 30, 750, 300, 1600, 'L', 2, 19, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 40 */ allLevels->push_back(new IntervalLevel(false, {4}, 70, {3}, 50, 40, 500, 360, 1400, 'P', 8, 18, {1,4,6}, {0,19}));
        /* 41 */ allLevels->push_back(new IntervalLevel(false, {8}, 41, {9}, 29, 10, 2000, 210, 2000, 'A', 9, 26, {1,4,6}, {0,19}));
        /* 42 */ allLevels->push_back(new IntervalLevel(false, {8}, 48, {9}, 35, 15, 1500, 247, 1600, 'A', 3, 33, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 43 */ allLevels->push_back(new IntervalLevel(false, {8}, 50, {9}, 36, 20, 1000, 257, 1500, 'L', 8, 40, {1,4,6}, {0,19}));
        /* 44 */ allLevels->push_back(new IntervalLevel(false, {8,9}, 59, {7,5}, 42, 30, 750, 300, 2000, 'L', 4, 5, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 45 */ allLevels->push_back(new IntervalLevel(false, {8,9}, 70, {7,5}, 50, 40, 500, 360, 1600, 'P', 2, 9, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 46 */ allLevels->push_back(new IntervalLevel(false, {8,9}, 41, {3,4}, 29, 10, 2000, 210, 2000, 'A', 3, 12, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 47 */ allLevels->push_back(new IntervalLevel(false, {8,9}, 48, {3,4}, 35, 15, 1500, 247, 1600, 'A', 10, 11, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 48 */ allLevels->push_back(new IntervalLevel(false, {4,3}, 50, {8,9}, 36, 20, 1000, 257, 2000, 'L', 0, 54, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 49 */ allLevels->push_back(new IntervalLevel(false, {3,9}, 59, {4,8}, 42, 30, 750, 300, 1600, 'L', 4, 68, {9,10,11}, {0,12,19,26,42,57,71}));
        /* 50 */ allLevels->push_back(new IntervalLevel(false, {4,8}, 70, {3,9}, 50, 40, 500, 360, 2000, 'P', 5, 89, {9,10,11}, {0,12,19,32,42,57,70}));
        /* 51 */ allLevels->push_back(new IntervalLevel(false, {2,5}, 41, {1,7}, 29, 10, 2000, 210, 1600, 'P', 6, 145, {0,5,7}, {0,19,32,42,57,70}));
        /* 52 */ allLevels->push_back(new IntervalLevel(false, {2,5}, 48, {1,7}, 35, 15, 1500, 247, 1500, 'P', 3, 194, {0,5,7}, {0,11,19,26,40,42,71,9}));
        /* 53 */ allLevels->push_back(new IntervalLevel(false, {2,5}, 50, {1,7}, 36, 20, 1000, 257, 1500, 'P', 2, 154, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 54 */ allLevels->push_back(new IntervalLevel(false, {2,5}, 59, {1,7}, 42, 30, 750, 300, 1500, 'P', 2, 156, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 55 */ allLevels->push_back(new IntervalLevel(false, {2,5}, 70, {1,7}, 50, 40, 500, 360, 1500, 'P', 8, 170, {1,4,6}, {0,19}));
        /* 56 */ allLevels->push_back(new IntervalLevel(false, {7,2}, 35, {5,1}, 25, 10, 2000, 180, 1800, 'A', 9, 5, {1,4,6}, {0,19}));
        /* 57 */ allLevels->push_back(new IntervalLevel(false, {7,2}, 41, {5,1}, 30, 15, 1500, 212, 1600, 'A', 3, 6, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 58 */ allLevels->push_back(new IntervalLevel(false, {7,2}, 59, {5,1}, 42, 20, 1000, 300, 1500, 'L', 8, 75, {1,4,6}, {0,19}));
        /* 59 */ allLevels->push_back(new IntervalLevel(false, {7,2}, 68, {5,1}, 49, 30, 750, 350, 1500, 'L', 2, 187, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 60 */ allLevels->push_back(new IntervalLevel(true, {7,2}, 82, {5,1}, 59, 40, 500, 420, 1500, 'P', 2, 19, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 61 */ allLevels->push_back(new IntervalLevel(true, {6}, 35, {5}, 25, 10, 2000, 180, 2000, 'A', 1, 18, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 62 */ allLevels->push_back(new IntervalLevel(false, {6}, 41, {7}, 30, 15, 1500, 212, 1800, 'A', 2, 26, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 63 */ allLevels->push_back(new IntervalLevel(false, {6}, 59, {10}, 42, 20, 1000, 300, 1700, 'L', 0, 33, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 64 */ allLevels->push_back(new IntervalLevel(false, {6}, 68, {2}, 49, 30, 750, 350, 1500, 'L', 4, 40, {0,5,7}, {0,12,19,26,42,57,71}));
        /* 65 */ allLevels->push_back(new IntervalLevel(false, {5,6}, 82, {7}, 59, 40, 500, 420, 2000, 'P', 5, 9, {1,4,6}, {0,12,19,32,42,57,70}));
        /* 66 */ allLevels->push_back(new IntervalLevel(false, {6,7}, 35, {5}, 25, 10, 2000, 180, 1600, 'A', 6, 12, {1,4,6}, {0,19,32,42,57,70}));
        /* 67 */ allLevels->push_back(new IntervalLevel(false, {8,6}, 41, {9}, 30, 15, 1500, 212, 1500, 'A', 3, 11, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 68 */ allLevels->push_back(new IntervalLevel(false, {6,4}, 59, {3}, 42, 20, 1000, 300, 1500, 'L', 2, 54, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 69 */ allLevels->push_back(new IntervalLevel(false, {6,3}, 68, {4}, 49, 30, 750, 350, 1500, 'L', 2, 68, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 70 */ allLevels->push_back(new IntervalLevel(false, {9,6}, 82, {8}, 59, 40, 500, 420, 1500, 'P', 8, 89, {2,6,8}, {0,19}));
        /* 71 */ allLevels->push_back(new IntervalLevel(false, {2,6}, 35, {1}, 25, 10, 2000, 180, 1500, 'P', 9, 145, {2,6,8}, {0,19}));
        /* 72 */ allLevels->push_back(new IntervalLevel(false, {1,6}, 41, {2}, 30, 15, 1500, 212, 1500, 'P', 3, 194, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 73 */ allLevels->push_back(new IntervalLevel(false, {10,6}, 59, {11}, 42, 20, 1000, 300, 1500, 'P', 8, 154, {9,10,11}, {0,19}));
        /* 74 */ allLevels->push_back(new IntervalLevel(false, {11,6}, 68, {10}, 49, 30, 750, 350, 1500, 'P', 4, 156, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 75 */ allLevels->push_back(new IntervalLevel(true, {12,6}, 82, {0}, 59, 40, 500, 420, 1500, 'P', 10, 170, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 76 */ allLevels->push_back(new IntervalLevel(true, {13}, 29, {14}, 21, 10, 2000, 150, 1500, 'A', 3, 5, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 77 */ allLevels->push_back(new IntervalLevel(false, {14}, 35, {13}, 25, 15, 1500, 180, 1500, 'A', 5, 6, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 78 */ allLevels->push_back(new IntervalLevel(false, {15}, 41, {16}, 29, 20, 1000, 210, 1500, 'L', 10, 194, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 79 */ allLevels->push_back(new IntervalLevel(false, {16}, 29, {15}, 21, 30, 750, 150, 1500, 'L', 4, 187, {0,5,7}, {0,12,19,26,42,57,71}));
        /* 80 */ allLevels->push_back(new IntervalLevel(false, {01}, 35, {02}, 25, 40, 500, 180, 1500, 'P', 5, 19, {1,4,6}, {0,12,19,32,42,57,70}));
        /* 81 */ allLevels->push_back(new IntervalLevel(false, {02}, 41, {01}, 29, 10, 2000, 210, 1500, 'A', 6, 18, {1,4,6}, {0,19,32,42,57,70}));
        /* 82 */ allLevels->push_back(new IntervalLevel(false, {20}, 29, {21}, 21, 15, 1500, 150, 1500, 'A', 3, 26, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 83 */ allLevels->push_back(new IntervalLevel(false, {21}, 35, {20}, 25, 20, 1000, 180, 1500, 'L', 10, 194, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 84 */ allLevels->push_back(new IntervalLevel(false, {13,14}, 34, {15,16}, 25, 30, 750, 177, 1500, 'L', 4, 40, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 85 */ allLevels->push_back(new IntervalLevel(false, {15,16}, 41, {13,14}, 30, 40, 500, 212, 1500, 'P', 8, 9, {2,6,8}, {0,19}));
        /* 86 */ allLevels->push_back(new IntervalLevel(false, {01,02}, 29, {15,16}, 21, 10, 2000, 150, 1500, 'A', 9, 12, {2,6,8}, {0,19}));
        /* 87 */ allLevels->push_back(new IntervalLevel(false, {20,21}, 35, {02,8}, 25, 15, 1500, 180, 1500, 'A', 3, 11, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 88 */ allLevels->push_back(new IntervalLevel(false, {13,11}, 41, {14,10}, 29, 20, 1000, 210, 1500, 'L', 8, 54, {9,10,11}, {0,19}));
        /* 89 */ allLevels->push_back(new IntervalLevel(false, {13,10}, 34, {14,11}, 25, 30, 750, 177, 1500, 'L', 4, 68, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 90 */ allLevels->push_back(new IntervalLevel(false, {20,9}, 41, {21,8}, 30, 40, 500, 212, 1500, 'P', 6, 156, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 91 */ allLevels->push_back(new IntervalLevel(false, {20,8}, 48, {21,9}, 35, 10, 2000, 247, 1500, 'P', 3, 145, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 92 */ allLevels->push_back(new IntervalLevel(false, {21,8}, 33, {20,9}, 24, 15, 1500, 172, 1500, 'P', 10, 194, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 93 */ allLevels->push_back(new IntervalLevel(false, {21,9}, 42, {20,8}, 30, 20, 1000, 215, 1500, 'P', 5, 154, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 94 */ allLevels->push_back(new IntervalLevel(false, {16,3}, 50, {15,4}, 36, 30, 750, 257, 1500, 'P', 4, 156, {0,5,7}, {0,12,19,26,42,57,71}));
        /* 95 */ allLevels->push_back(new IntervalLevel(false, {15,4}, 39, {16,3}, 28, 40, 500, 200, 1500, 'P', 5, 170, {1,4,6}, {0,12,19,32,42,57,70}));
        /* 96 */ allLevels->push_back(new IntervalLevel(false, {6,01}, 34, {02}, 25, 10, 2000, 177, 1500, 'A', 6, 5, {1,4,6}, {0,19,32,42,57,70}));
        /* 97 */ allLevels->push_back(new IntervalLevel(false, {6,02}, 33, {01,11}, 24, 15, 1500, 172, 1500, 'A', 3, 6, {1,4,6}, {0,11,19,26,40,42,71,9}));
        /* 98 */ allLevels->push_back(new IntervalLevel(false, {14,20}, 42, {13,21}, 30, 20, 1000, 215, 1500, 'L', 10, 154, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 99 */ allLevels->push_back(new IntervalLevel(false, {13,21}, 50, {14,20}, 36, 30, 750, 257, 1500, 'L', 6, 187, {2,6,8}, {0,11,12,19,26,32,42,57,70,71}));
        /* 100 */ allLevels->push_back(new IntervalLevel(true, {01,21}, 59, {02,20}, 42, 40, 500, 300, 1500, 'P', 6, 19, {2,6,8}, {0,19}));
        /* 101 */ allLevels->push_back(new IntervalLevel(true, {5,7,12}, 48, {6,9}, 35, 10, 2000, 247, 1500, 'A', 9, 18, {0,5,7}, {0,19}));
        /* 102 */ allLevels->push_back(new IntervalLevel(false, {5,8,12}, 50, {7,9}, 36, 15, 1500, 257, 1500, 'A', 3, 26, {0,5,7}, {0,11,19,26,40,42,71,9}));
        /* 103 */ allLevels->push_back(new IntervalLevel(false, {5,7,10}, 59, {6,11}, 42, 20, 1000, 300, 1500, 'L', 8, 33, {0,5,7}, {0,19}));
        /* 104 */ allLevels->push_back(new IntervalLevel(false, {3,4,11}, 59, {8,9,10}, 42, 30, 750, 300, 1500, 'L', 4, 40, {0,5,7}, {0,11,12,19,26,32,42,57,70,71}));
        /* 105 */ allLevels->push_back(new IntervalLevel(false, {8,9,2}, 59, {3,4,1}, 42, 40, 500, 300, 1500, 'P', 2, 9, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 106 */ allLevels->push_back(new IntervalLevel(false, {10,11,7}, 48, {13,14,5}, 35, 10, 2000, 247, 1500, 'A', 5, 12, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 107 */ allLevels->push_back(new IntervalLevel(false, {1,5,10}, 50, {2,7,11}, 36, 15, 1500, 257, 1500, 'A', 10, 11, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 108 */ allLevels->push_back(new IntervalLevel(false, {1,2,4}, 59, {13,14,3}, 42, 20, 1000, 300, 1500, 'L', 3, 54, {1,4,6}, {0,11,12,19,26,32,42,57,70,71}));
        /* 109 */ allLevels->push_back(new IntervalLevel(false, {1,2,3}, 59, {13,14,4}, 42, 30, 750, 300, 1500, 'L', 4, 68, {2,6,8}, {0,12,19,26,42,57,71}));
        /* 110 */ allLevels->push_back(new IntervalLevel(false, {5,7,8}, 68, {01,9}, 49, 40, 500, 350, 1500, 'P', 5, 89, {2,6,8}, {0,12,19,32,42,57,70}));
        /* 111 */ allLevels->push_back(new IntervalLevel(false, {5,7,9}, 48, {02,8}, 35, 10, 2000, 247, 1500, 'P', 6, 145, {2,6,8}, {0,19,32,42,57,70}));
        /* 112 */ allLevels->push_back(new IntervalLevel(false, {10,11,13}, 50, {1,2,14}, 36, 15, 1500, 257, 1500, 'P', 3, 194, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 113 */ allLevels->push_back(new IntervalLevel(false, {1,8,13}, 59, {2,9,14}, 42, 20, 1000, 300, 1500, 'P', 10, 154, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 114 */ allLevels->push_back(new IntervalLevel(false, {3,4,01}, 59, {16,8,02}, 42, 30, 750, 300, 1500, 'P', 4, 156, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 115 */ allLevels->push_back(new IntervalLevel(false, {6,2,10}, 59, {1,11,13}, 42, 40, 500, 300, 1500, 'P', 8, 170, {9,10,11}, {0,19}));
        /* 116 */ allLevels->push_back(new IntervalLevel(false, {6,5,7}, 48, {01,02}, 35, 10, 2000, 247, 1500, 'A', 9, 5, {2,6,8}, {0,19}));
        /* 117 */ allLevels->push_back(new IntervalLevel(false, {12,6,01}, 59, {02,7}, 42, 15, 1500, 300, 1500, 'A', 3, 6, {2,6,8}, {0,11,19,26,40,42,71,9}));
        /* 118 */ allLevels->push_back(new IntervalLevel(false, {13,14,20}, 68, {1,2,21}, 49, 20, 1000, 350, 1500, 'L', 8, 75, {9,10,11}, {0,19}));
        /* 119 */ allLevels->push_back(new IntervalLevel(false, {14,02,21}, 68, {13,01,20}, 49, 30, 750, 350, 1500, 'L', 6, 187, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));
        /* 120 */ allLevels->push_back(new IntervalLevel(true, {13,01,20}, 68, {14,02,21}, 49, 40, 500, 350, 1500, 'P', 10, 19, {9,10,11}, {0,11,12,19,26,32,42,57,70,71}));

        Game::Register(GameType::Interval, allLevels);
    }
}
