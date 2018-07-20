#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "Block.h"
#include "Blockchain.h"
#include "Transaction.h"
#include <iostream>

Blockchain paying (std::unordered_map<string,Wallet> map_wallets, Blockchain FullCoin, int n);
std::unordered_map<string,Wallet> new_wallet (std::unordered_map<string,Wallet> map_wallets, Blockchain FullCoin);
void print_all_wallet(std::unordered_map<string,Wallet> map_wallets);

Blockchain paying (std::unordered_map<string,Wallet> map_wallets, Blockchain FullCoin, int n)
{
    bool provjera=false;
    string from, to, username, input, IDf, IDt;
    double amount;

    do
    {
        provjera=false;
        cout << "\nUnesite svoj username: " << endl;
        cin >> input;

        std::unordered_map<string,Wallet>::const_iterator x = map_wallets.find (input);

        if ( x == map_wallets.end() )
            cout << "\nKrivi username! Pokusajte ponovno.\n"<<endl;
        else
        {
            cout << "\nDOBRODOSLI " << x->first<<endl;
            from=x->first;
            IDf=x->second.getID();
            provjera=true;
        }
    }while(provjera!=true);

    map_wallets[from].synx_wallet(FullCoin);
    cout << "Vase stanje racuna: " << map_wallets[from].getBalance() <<endl;
    do
    {
        provjera=false;

        cout <<"\nUnesite s kim zelite obaviti transakciju: " <<endl;
        cin >> input;

        std::unordered_map<string,Wallet>::const_iterator y = map_wallets.find (input);

        if ( y == map_wallets.end() )
            cout << "\nKrivi username! Pokusajte ponovno.\n"<<endl;
        else if(y->first==from)
            cout << "\nUnesi tudi username ne svoji! \n"<<endl;
        else
        {
            to=y->first;
            IDt=y->second.getID();
            provjera=true;
        }
    }while(provjera!=true);

    do
    {
        provjera=false;

        cout <<"\nUnesite svotu: " <<endl;
        cin >> amount;

        if(amount<0)
            cout << "\nSvota mora biti pozitivna! Unesi opet.\n"<<endl;
        else if(map_wallets[from].getBalance()<amount)
            cout << "\nNemas dovoljno na racunu! Unesi opet.\n"<<endl;
        else
            provjera=true;

    }while(provjera!=true);

    FullCoin.chain[n].addTransaction(Transaction(from,to, IDf, IDt, amount));

    cout << "\nTRANSAKCIJA USPIJESNO OBAVLJENA!" <<endl;
    cout << "\t" <<from << " ---" << amount << "---> " << to << endl;
    cout <<endl;

    from.clear();
    to.clear();
    amount=0;

    if(FullCoin.chain[n].getTransaction().size()==2)
    {
        FullCoin.chain[n].MineBlock(FullCoin.getDifficulty());
        cout <<"Mining..."<<endl<<endl;
        FullCoin.addBlock(Block(n+1));
    }

    return FullCoin;
}

std::unordered_map<string,Wallet> new_wallet (std::unordered_map<string,Wallet> map_wallets, Blockchain FullCoin)
{
    string username;

    cout << "\nUnesi username novog walleta: "<<endl;
    cin >> username;

    Wallet newWallet(100);

    map_wallets[username]=newWallet;
    map_wallets[username].synx_wallet(FullCoin);

    return map_wallets;
}

void print_all_wallet(std::unordered_map<string,Wallet> map_wallets)
{
    for (auto& i: map_wallets)
    {
        cout << i.first<<":" << endl <<"\tbalance: " << i.second.getBalance() <<endl<< "\tID: " << i.second.getID() << endl;
    }
}
#endif // FUNCTION_H_INCLUDED

