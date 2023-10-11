#include "tile.h"
#include "Lair.h"
#include "Hero.h"
#include "HorizontalHero.h"
#include "ReverseHero.h"
#include "StoryTeller.h"
#include "ReclaimTrap.h"
#include "WoundTrap.h"
#include "Facility.h"
#include "ResearchLab.h"
#include "Bank.h"
#include "Menu.h"
#include "Engine.h"
#include <iostream>
using namespace std;

int main()
{
    Lair *l = new Lair();
    for (int i = 0; i < 16; i++)
    {

        l->add(new tile());
        // l->print();
    }

    l->print();

    // cout << endl;
    // HorizontalHero *h1 = new HorizontalHero(l);
    // HorizontalHero *h2 = new HorizontalHero(l);
    // HorizontalHero *h3 = new HorizontalHero(l);
    // HorizontalHero *h4 = new HorizontalHero(l);

    // h1->Search(l, 0);
    // cout << endl;
    // h2->Search(l, 1);
    // cout << endl;
    // h3->Search(l, 2);
    // cout << endl;
    // h4->Search(l, 3);

    // cout << endl;
    // cout << endl;

    // ReverseHero *v1 = new ReverseHero();
    // ReverseHero *v2 = new ReverseHero();
    // ReverseHero *v3 = new ReverseHero();
    // ReverseHero *v4 = new ReverseHero();

    // v1->Search(l, 0);
    // cout << endl;
    // v2->Search(l, 1);
    // cout << endl;
    // v3->Search(l, 2);
    // cout << endl;
    // v4->Search(l, 3);
    // cout << endl;
    // cout << endl;

    // cout << "Testing StoryTeller " << endl;

    StoryTeller *st1 = new StoryTeller();

    Hero *hx = st1->spawn('h');
    Hero *rx = st1->spawn('r');

    // cout << endl;
    // hx->Search(l, 1);
    // cout << endl;

    // cout << endl;
    // vx->Search(l, 2);
    // cout << endl;

    // Trap *trap1 = new ReclaimTrap();
    // tile *x = l->getTile(1, 1);
    // cout << "t: " << x->getX() << "|" << x->getY() << endl;

    // l->placeTrap(1, 1, trap1);
    // l->print();
    // cout << endl;

    ResearchLab *rl = new ResearchLab();
    Bank *bank = new Bank();
    bank->balance = l->calculateTotalBalance();

    Engine *_engine = new Engine(rl, bank);
    // rl->setToEngine();
    // bank->setToEngine();
    rl->e = _engine;
    bank->e = _engine;

    cout << "\033[1;33mThe first wave is approaching\033[0m" << endl;
    _engine->start();
    // cout << "hx health before trap: " << hx->health << endl;
    // cout << "hx balance before : " << hx->balance << endl;
    Menu *menu = new Menu(bank, rl, l);
    int a = 2;
    while (a != 0)
    {
        cout << "\033[1;34mPrepare for the attack:\033[0m" << endl;
        menu->start();
        cout << endl;
        a--;
    }

    l->print();
    cout << endl;
    hx->Search(l, 0);
    cout << endl;
    l->print();
    cout << endl;
    cout << endl;
    l->print();
    cout << "\033[1;33mhx health after trap: " << hx->health << "\033[0m" << std::endl;
    cout << "\033[1;33mhx balance after: " << hx->balance << "\033[0m" << std::endl;
    cout << endl;
    bank->balance = l->calculateTotalBalance();
    _engine->start();
    if (l->calculateTotalBalance() > 0)
    {
        cout << "First wave complete" << endl;
        cout << "\033[1;33mThe second wave is approaching\033[0m" << endl;
        int b = 2;
        while (b != 0)
        {
            cout << "\033[1;34mPrepare for the attack:\033[0m" << endl;
            menu->start();
            cout << endl;
            b--;
        }

        l->print();
        cout << endl;
        Hero *wraith = st1->spawn('h');
        wraith->Search(l, 1);
        cout << endl;
        l->print();
        cout << endl;
        cout << endl;
        l->print();
        cout << "\033[1;33mwraith health after trap: " << wraith->health << "\033[0m" << std::endl;
        cout << "\033[1;33mwraith balance after: " << wraith->balance << "\033[0m" << std::endl;
        cout << endl;
        bank->balance = l->calculateTotalBalance();
        _engine->start();
        if (l->calculateTotalBalance() > 0)
        {
            cout << "Second wave complete" << endl;
            cout << "\033[1;33mThe third wave is approaching\033[0m" << endl;
            int c = 2;
            while (c != 0)
            {
                cout << "\033[1;34mPrepare for the attack:\033[0m" << endl;
                menu->start();
                cout << endl;
                c--;
            }
            cout << endl;
            l->print();
            cout << endl;
            Hero *ghost = st1->spawn('r');
            ghost->Search(l, 2);
            bank->balance = l->calculateTotalBalance();
            cout << endl;
            l->print();
            cout << endl;
            cout << endl;
            l->print();
            cout << "\033[1;33mGhost's health after trap: " << ghost->health << "\033[0m" << std::endl;
            cout << "\033[1;33mGhost's balance after: " << ghost->balance << "\033[0m" << std::endl;
            cout << endl;
            bank->balance = l->calculateTotalBalance();
            _engine->start();
            if (l->calculateTotalBalance() > 0)
            {
                cout << "Second wave complete" << endl;
                cout << "\033[1;33mThe fourth wave is approaching\033[0m" << endl;
                int d = 2;
                while (d != 0)
                {
                    cout << "\033[1;34mPrepare for the attack:\033[0m" << endl;
                    menu->start();
                    cout << endl;
                    d--;
                }
                cout << endl;
                cout << endl;
                l->print();
                cout << endl;
                Hero *Phantom = st1->spawn('r');
                Phantom->Search(l, 3);
                cout << endl;
                l->print();
                cout << endl;
                cout << endl;
                l->print();
                cout << "\033[1;33mPhantom's health after trap: " << Phantom->health << "\033[0m" << std::endl;
                cout << "\033[1;33mPhantom's balance after: " << Phantom->balance << "\033[0m" << std::endl;
                cout << endl;
                bank->balance = l->calculateTotalBalance();
                _engine->start();
                if (l->calculateTotalBalance() > 0)
                {
                    cout << "\033[1;32mSuccess, Game Over\033[0m" << endl
                         << endl;
                }
                else
                {
                    cout << "\033[1;31mGame Over\033[0m" << endl;
                }
            }
            else
            {
                cout << "\033[1;31mGame Over\033[0m" << endl;
            }
        }
        else
        {
            cout << "\033[1;31mGame Over\033[0m" << endl;
        }
    }
    else
    {
        cout << "\033[1;31mGame Over\033[0m" << endl;
    }
}