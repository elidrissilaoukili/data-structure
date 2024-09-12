#include <iostream>
using namespace std;

class Base
{
public:
    virtual void afficher()
    {
        cout << "Je suis la classe de base" << endl;
    }
};

// Classe dérivée
class Derivee : public Base
{
public:
    void afficher() override
    {
        cout << "Je suis la classe derivee" << endl;
    }
};

int main()
{
    Base *basePtr;      // Pointeur de type classe de base
    Derivee objDerivee; // Objet de la classe dérivée

    basePtr = &objDerivee; // Le pointeur de la classe de base pointe vers l'objet de la classe dérivée

    basePtr->afficher(); // Appelle la méthode de la classe dérivée grâce au polymorphisme

    return 0;
}
