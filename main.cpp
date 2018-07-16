//time nije privatan
//addWallet u funkciju
//Private sve u Walletu

#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"

using namespace std;

std::unordered_map<string,Wallet> map_wallets;

int main()
{
    char odg='1';
    string from, to, username, input, IDf, IDt;
    int amount, n, odg2;
    bool provjera=false;

    Blockchain FullCoin=Blockchain();

    do
    {
        cout << "Unesite username"<<endl;
        cin >> username;

        Wallet newWallet(100);

        map_wallets[username]=newWallet;

        cout <<"Unesi 0 za kraj: "<<endl;
        cin >>odg2;
    }while(odg2!=0);

    while(odg=='1')
    {

        n=FullCoin.chain.size()-1;

        do
        {
            provjera=false;
            cout << "Unesite svoj username: " << endl;
            cin >> input;

            std::unordered_map<string,Wallet>::const_iterator x = map_wallets.find (input);

            if ( x == map_wallets.end() )
                cout << "Krivi username! Pokusajte ponovno.\n"<<endl;
            else
            {
                cout << "Uspjesno :)\n";
                from=x->first;
                IDf=x->second.getID();
                provjera=true;
            }
        }while(provjera!=true);

        do
        {
            provjera=false;

            cout <<"Unesite s kim zelite obaviti trensakciju: " <<endl;
            cin >> input;

            std::unordered_map<string,Wallet>::const_iterator y = map_wallets.find (input);

            if ( y == map_wallets.end() )
                cout << "Krivi username! Pokusajte ponovno.\n"<<endl;
            else if(y->first==from)
                cout << "Unesi tudi username ne svoji! \n"<<endl;
            else
            {
                cout << "Uspjesno :)\n";
                to=y->first;
                IDt=y->second.getID();
                provjera=true;
            }
        }while(provjera!=true);

        do
        {
            provjera=false;

            cout <<"unesite svotu: " <<endl;
            cin >> amount;

            if(amount<0)
                cout << "Svota mora biti pozitivna! Unesi opet.\n"<<endl;
            else
                provjera=true;

        }while(provjera!=true);

        FullCoin.chain[n].addTransaction(Transaction(from,to, IDf, IDt, amount));

        from.clear();
        to.clear();
        amount=0;

        if(FullCoin.chain[n].getTransaction().size()==2)
        {
            FullCoin.chain[n].MineBlock(FullCoin.getDifficulty());
            cout <<"Mining..."<<endl;
            FullCoin.addBlock(Block(n+1));
        }

        cout <<"Ako zelis jos unesi 1: " <<endl;
        cin >> odg;
    }
    /*
    cout << "Unesite svoj username za azurirati: " << endl;
    cin >> input;

    std::unordered_map<string,Wallet>::const_iterator x = map_wallets.find (input);

    if ( x == map_wallets.end() )
        cout << "Krivi username! Pokusajte ponovno.\n"<<endl;
    else
    {
        cout << "Uspjesno :)\n";
       // x->second.synx_wallet(FullCoin);
    }
   print_wallet(map_wallets);
*/
    for (auto& j: map_wallets)
    {
        j.second.synx_wallet(FullCoin);
    }

    for (auto& i: map_wallets)
    {
        cout << i.first<<":" << endl <<"\tbalance: " << i.second.getBalance() <<endl<< "\tID: " << i.second.getID() << endl;
    }

    FullCoin.print();
    return 0;
}
