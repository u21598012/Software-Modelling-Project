#include "Menu.h"
#include <string>
#include <vector>
using namespace std;

Menu::Menu()
{
    this->b = NULL;
    this->rl = NULL;
    this->lair = NULL;
}

Menu::Menu(Bank *b, ResearchLab *rl, Lair *l)
{
    this->b = b;
    this->rl = rl;
    this->lair = l;
}

Menu::~Menu()
{
    delete this->b;
    delete this->rl;
    delete this->lair;
}

void Menu::start()
{
    char l1 = 'x';
    cout << "Add or Remove?" << endl;
    cin >> l1;

    if (l1 == 'A')
    {
        int x = -1;
        int y = -1;
        char type = 'x';
        cout << "Enter value for x: " << endl;
        cin >> x;

        cout << "Enter value for y: " << endl;
        cin >> y;

        cout << "Enter value for type: " << endl;
        cin >> type;

        addTrap(x, y, type);
    }
    else
    {
        if (l1 == 'R')
        {
            int x = -1;
            int y = -1;

            cout << "Enter value for x: " << endl;
            cin >> x;

            cout << "Enter value for y: " << endl;
            cin >> y;

            removeTrap(x, y);
        }
    }
}

void Menu::addTrap(int x, int y, char type)
{
    if (rl->bankRequest(100))
    {
        cout << "\033[1;32mProduction of Trap approved\033[0m" << endl;
        Trap *res = rl->produceTrap(type);

        if (res != nullptr)
        {
            //rl->trigger();
            rl->finalize();
            rl->trigger();
            this->lair->placeTrap(x, y, res);
        }
    }
    else
    {
        cout << "\033[1;31mProduction of Trap not approved\033[0m" << endl;
    }
}

void Menu::removeTrap(int x, int y)
{
    int x1 = 0;
    int y1 = 0;
    tile *point = this->lair->zeroZero;
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

    point->trap = NULL;
    cout << "Trap removed" << endl;
}
