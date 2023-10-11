#include "ReverseHero.h"
#include <string>
#include <vector>
using namespace std;

ReverseHero::ReverseHero() : Hero()
{
}

ReverseHero::~ReverseHero()
{
}

void ReverseHero::Search(Lair *l, int index)
{
    if (this->health > 0)
    {
        int yp = 0;
        int res = -1;
        tile *curr = l->zeroZero;
        while (yp != index)
        {
            curr = curr->down;
            yp++;
        }

        tile *lastTile = nullptr; // To keep track of the previous tile
        while (curr->right != NULL)
        {
            curr = curr->right;
        }

        while (curr != NULL)
        {
            if (curr->trap != NULL)
            {
                curr->trap->intruder = true;
                if (curr->trap->Trt == 'r')
                {
                    res = React(curr);
                    cout << "The hero has encountered a Reclaim Trap" << endl;
                }
                else
                {
                    if (curr->trap->Trt == 'w')
                    {
                        this->health = React(curr);
                        cout << "The hero has encountered a Wound Trap" << endl;
                        if (this->health == 0)
                        {
                            cout << "\033[1;32mHero Defeated\033[0m" << endl;
                            return;
                        }
                    }
                }
            }
            cout << curr->getX() << "|" << curr->getY() << " ";
            if (res != -1)
            {
                this->balance -= res;
                curr->Balance += res;
                curr = curr->left;
                res = -1;
            }
            else
            {
                int update = curr->getTB();
                balance += update;
                curr->setTB(curr->getTB() - update);
                curr = curr->left;
            }
        }
    }
    else
    {
        cout << "\033[1;32mHero Defeated\033[0m" << endl;
    }
}
