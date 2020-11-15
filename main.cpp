#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> fil;
    vector<int> position;
    fil.push_back(1);
    fil.push_back(2);
    fil.push_back(3);
    fil.push_back(4);

    fil.push_back(5);
    fil.push_back(6);
    fil.push_back(7);
    fil.push_back(8);


    fil[0] = 3;
    fil[1] = 2;
    fil[2] = 4;
    fil[3] = 1;

    fil[4] = 6;
    fil[5] = 8;
    fil[6] = 7;
    fil[7] = 5;

    position.push_back(0);
    position.push_back(1);
    position.push_back(2);
    position.push_back(3);
    position.push_back(4);
    position.push_back(5);
    position.push_back(6);
    position.push_back(7);

    cout << "Taille du tableau : " << fil.size() << endl;
    for(double n = 0; n < fil.size(); ++n)
    {
        cout << fil[n] << " ";
    }
    cout << "L'ordre actuel des fils" << endl;
    cout << endl;
    for(double p = 0; p < position.size(); ++p)
    {
        cout << position[p] << " ";
    }
    cout << "Et les positions p" << endl;

    cout << endl;
    bool reboucler = true;

    while(reboucler) {
        reboucler = false;
        for(double i = 0; i < fil.size()-1; i ++)
        {
                cout << "Le fil n : " << fil[i] << " et le fil n+1 : " << fil[i+1] << endl;

                if(fil[i] > fil[i+1])

                {
                    reboucler = true;
                    cout << "On inverse " << fil[i] << " et le fil "<< fil[+1] << endl;
                    std::swap(fil[i], fil[i+1]);

                    cout << endl;

                    cout << "Nouvel ordre : ";
                    for(double l = 0; l < fil.size(); l++)
                    {
                        cout << fil[l] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    cout<<"Les elements sont bien tries."<<endl;
                }
        }
    }


    return 0;
}
