#include "Wallet.h"
#include <iostream>
#include "to_string.h"
#include "hasha.h"

Wallet::Wallet()
{
    id="0000";
    balance=0000;
}

Wallet::Wallet(double n_balance)
{
    id=hashing(patch::to_string(rand() % 100000 + 1));
    balance=n_balance;
}

void Wallet::synx_wallet(Blockchain FullCoin)
{
    cout << balance << endl;
    for(int j=0; j<FullCoin.chain.size(); j++)
    {
        for(int i=0; i<FullCoin.chain[j].getTransaction().size(); i++)
        {
            if(FullCoin.chain[j].getTransaction()[i].getFromID()==id)
            {
                cout << FullCoin.chain[j].getTransaction()[i].getFrom() << " - " << FullCoin.chain[j].getTransaction()[i].getAmount() <<endl;
                balance-=FullCoin.chain[j].getTransaction()[i].getAmount();
                cout << balance << endl;
            }

            if(FullCoin.chain[j].getTransaction()[i].getToID()==id)
            {
                cout << FullCoin.chain[j].getTransaction()[i].getTo() << " + " << FullCoin.chain[j].getTransaction()[i].getAmount() <<endl;
                balance+=FullCoin.chain[j].getTransaction()[i].getAmount();
                cout << balance <<endl;
            }

        }
    }
}

/*void Wallet::addWallet(Wallet newWallet)
{
    string username;
    cout << "Unesite username"<<endl;
    cin >> username;
    map_wallets[username]=newWallet;
}

void Wallet::print_wallet(std::unordered_map<string,Wallet> map_wallets)
{
    for (auto& x: map_wallets)
    {
        cout << x.first<<":" << endl <<"\tbalance: " << x.second.balance <<endl<< "\tID: " << x.second.id << endl;
    }
}*/
