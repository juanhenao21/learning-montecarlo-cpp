#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "types.h"
#include "utilities.h"

using namespace std;


int main(int argc, char* argv[])
{
    std::vector<Atom> atoms;
    std::vector<Link> links;
    std::vector<int> limits;
    std::vector<int> neighboors;
    std::vector<int> interactions;
    std::vector<Spin> spinUp;

    AtomsLinks al = AtomsLinks::read_from_file(argv[1]);
    atoms = al.atoms;
    links = al.links;

    // Link and Atom ordering
    std::sort(links.begin(), links.end(), CompLink());
    std::sort(atoms.begin(), atoms.end(), CompAtom());

    // for (int i = 0; i < atoms.size(); ++i)
    // {
    // 	cout << atoms[i].id << endl;
    // }

    int a = 0;
    int n = 0;

    limits.push_back(n);
    for (int i = 0; i < al.links.size();)
    {
        do
        {
            n++;
            i++;
            neighboors.push_back(links[i].target);
            interactions.push_back(links[i].exchange);
        } while (links[i].source == a);

        a += 1;
        limits.push_back(n);
    }

    for (int i = 0; i < limits.size(); ++i)
    {
        cout << limits[i] << endl;
    }

    // for (int i = 0; i < neighboors.size(); ++i)
    // {
    // 	cout << neighboors[i] << endl;
    // 	cout << interactions[i] << endl;
    // }

    //std::cout << neighboors.size() << "\n" << interactions.size() << std::endl;

    Spin sup = Spin::up();
    Spin sdown = Spin::down();
    //std::cout << sup << std::endl;
    //std::cout << sup * sup << std::endl;
    //std::cout << sup * sdown << std::endl;

    for (int i = 0; i < al.links.size(); ++i)
    {
        Spin Up = Spin::up();
        spinUp.push_back(Up);
    }
    //cout << spinUp << endl;

    for (int i = 0; i < al.links.size(); i++)
        for (int j = 0; j < limits.size(); j++)
        {
            /* code */
        }

}
