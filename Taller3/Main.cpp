#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include "../EstructurasMultienlazadas/Graph.hpp"

using namespace std;

typedef string Persona;

class PersonaEC
{
    private:
        Persona fullname;
        float EC;
    
    public:
        PersonaEC(Persona p, float ec) : fullname(p), EC(ec) {};
        
        // Esto es solamente para 
        bool operator<(const PersonaEC &arg) const { return EC < arg.EC; };
        
        friend ostream& operator<<(ostream& arg, const PersonaEC &p)
        {
            arg << setw(18) << left << p.fullname << fixed << setprecision(3) << fixed << p.EC;
        }
};

int main(int argc, char **argv)
{
	int T, M;
    cin >> T;
    string name1, lastname1, name2, lastname2;
    vector<float> max;
    vector<Persona> vertices;
    vector<float>::iterator maxiter;
    vector<Persona>::iterator veriter;
    
    Persona user1, user2;
    
    for (int i = 1; i <= T; i++)
    {
        cin >> M;
        list<PersonaEC> lista;
        Graph<Persona, int> G;
        for (int j = 0; j < M; j++)
        {
            cin >> name1 >> lastname1 >> name2 >> lastname2;
            lastname1.erase(lastname1.end()-1); // <- Elimina la coma al final del apellido
            user1 = name1 + " " + lastname1;
            user2 = name2 + " " + lastname2;
            G.insertVertex(user1);
            G.insertVertex(user2);
            G.insertArc(user1, user2, 0);
            G.insertArc(user2, user1, 0);
        }
        
        max = G.eccentricityCentrality();
        vertices = G.getVertices();
        
        maxiter = max.begin();
        veriter = vertices.begin();
        while (maxiter < max.end() && veriter < vertices.end())
        {
            PersonaEC in(*veriter, *maxiter);
            lista.push_back(in);
            
            maxiter++;
            veriter++;
        }
        lista.sort();
        cout << "***********" << endl
        << "* Caso #" << i << " *" << endl
        << "***********" << endl;
        
        cout << "-----------------------" << setw(0) << endl;
        cout << setw(18) << left << "Nombre " <<  "EC" << endl
        << "-----------------------" << endl;
        list<PersonaEC>::iterator l_iter;
        for (l_iter = lista.begin(); l_iter != lista.end(); l_iter++)
            cout << *l_iter << endl;
        cout << "-----------------------" << endl << endl;
        
    }
    
    
	return 0;
}

