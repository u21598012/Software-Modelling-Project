#include "Lair.h"
#include <string>
#include <vector>
using namespace std;

Lair::Lair()
{
    this->zeroZero = new tile();
    this->xp = 0;
    this->yp = 0;
    this->zeroZero->setX(0);
    this->zeroZero->setY(0);
}

Lair::~Lair()
{
    delete zeroZero;
}

void Lair::add(tile *t)
{
    int xm = 0;
    int ym = 0;
    tile *point = this->zeroZero;
    if (xp % 3 == 0 && xp != 0)
    {
        // cout << "New row case" << endl;
        //  xm = 0;
        while (ym != yp)
        {
            point = point->down;
            ym++;
        }
        if (ym > 3)
        {
            cout << "Capacity Reached" << endl;
            return;
        }
        else
        {
            point->down = t;
            t->up = point;
            t->setX(xm);
            t->setY(ym + 1);
            yp++;
            xp = xm;
        }
    }
    else
    {
        while (ym != yp)
        {
            point = point->down;
            ym++;
        }
        if (ym > 3)
        {
            cout << "Capacity Reached" << endl;
            return;
        }
        // cout << xp % 3 << endl;
        while (xm != xp % 3)
        {
            while (point->right != NULL)
            {
                point = point->right;
                xm++;
            }
        }

        // point->right = new tile();
        point->right = t;
        t->left = point;
        xp++;
        t->setX(xm + 1);
        t->setY(ym);
    }
}

// void Lair::remove(int x, int y)
// {
//     tile *start = zeroZero;
//     int xc, int yc = 0;
//     while (start->x != x)
//     {
//         start = start->right;
//     }
//     while (start->y != y)
//     {
//         start = start->down;
//     }

//     tile *upc = start->up;
//     tile *dc = start->down;
//     tile *lc = start->left;
//     tile *rc = start->right;

// }

void Lair::print()
{
    tile *currentRow = zeroZero;

    for (int y = 0; y < 4; ++y)
    {
        tile *currentTile = currentRow;
        for (int x = 0; x < 4; ++x)
        {
            if (currentTile != nullptr)
            {
                if (currentTile->trap != NULL)
                {
                    cout << "[(" << currentTile->getX() << " | " << currentTile->getY() << ")"
                         << "<<T>>"
                         << "(" << currentTile->getTB() << ")]";
                }
                else
                {
                    cout << "[(" << currentTile->getX() << " | " << currentTile->getY() << ")"

                         << "(" << currentTile->getTB() << ")]";
                }
                if (currentTile->right != nullptr)
                {
                    cout << " -->> ";
                }
            }
            else
            {
                cout << " N/A";
            }

            if (currentTile != nullptr)
            {
                currentTile = currentTile->right;
            }
        }
        cout << endl;
        if (currentRow != nullptr)
        {
            currentRow = currentRow->down;
        }
    }
}

tile *Lair::getTile(int x, int y)
{
    int x1 = 0;
    int y1 = 0;
    tile *point = this->zeroZero;
    // while (y1 != y)
    // {
    while (y1 != y)
    {
        point = point->down;
        y1++;
    }

    // cout << xp % 3 << endl;
    while (x1 != x)
    {
        // while (point->right != NULL)
        // {
        point = point->right;
        x1++;
        // }
    }
    return point;
}

void Lair::placeTrap(int x, int y, Trap *t)
{
    int x1 = 0;
    int y1 = 0;
    tile *point = this->zeroZero;
    // while (y1 != y)
    // {
    while (y1 != y)
    {
        point = point->down;
        y1++;
    }

    // cout << xp % 3 << endl;
    while (x1 != x)
    {
        // while (point->right != NULL)
        // {
        point = point->right;
        x1++;
        // }
    }

    point->addTrap(t);
}

int Lair::calculateTotalBalance()
{
    int totalBalance = 0;
    tile *currentRow = zeroZero;

    for (int y = 0; y < 4; ++y)
    {
        tile *currentTile = currentRow;
        for (int x = 0; x < 4; ++x)
        {
            if (currentTile != nullptr)
            {
                totalBalance += currentTile->getTB();
            }

            if (currentTile != nullptr)
            {
                currentTile = currentTile->right;
            }
        }

        if (currentRow != nullptr)
        {
            currentRow = currentRow->down;
        }
    }

    return totalBalance;
}
