#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

enum gameResult_e {
    OK = 0,
    NOK = 1,
    END = 10
};

enum gameStatus_e {
    NEW,
    IN_PROGRESS,
    SOLVED,
    ERROR = 10
};

enum level_e {
    EASY,
    MEDIUM,
    HARD,
    UNKNOWN
};

#endif // TYPES_H_INCLUDED
