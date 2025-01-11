#include "ComboLock.h"
ComboLock::ComboLock(int secret1, int secret2, int secret3)
{
    combination[0] = secret1;
    combination[1] = secret2;
    combination[2] = secret3;
    reset();
}

void ComboLock::reset()
{
    turns = 0;
    direction = 1;
    position = 0;
}

void ComboLock::turn_left(int ticks)
{
    if (direction == 1)
    {
        direction = -1;
        if (turns < NTURNS)
        {
            actual[turns] = position;
        }
        turns++;
    }
    position = position - ticks;
    while (position < 0)
    {
        position = position + VALUES;
    }
}

void ComboLock::turn_right(int ticks)
{
    if (direction == -1)
    {
        if (turns < NTURNS)
        {
            actual[turns] = position;
        }
        direction = 1;
        turns++;
    }
    position = (position + ticks) % VALUES;
}

bool ComboLock::open() const
{
    if (turns != NTURNS - 1)
    {
        return false;
    }
    for (int i = 0; i < turns; i++)
    {
        if (combination[i] != actual[i])
        {
            return false;
        }
    }
    if (combination[turns] != position)
    {
        return false;
    }
    return true;
}

