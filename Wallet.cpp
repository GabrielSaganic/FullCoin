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
    own_balance=n_balance;
}

void Wallet::synx_wallet(Blockchain FullCoin)
{
    balance=own_balance;
    for(int j=0; j<FullCoin.chain.size(); j++)
    {
        for(int i=0; i<FullCoin.chain[j].getTransaction().size(); i++)
        {
            if(FullCoin.chain[j].getTransaction()[i].getFromID()==id)
            {
                balance=balance-FullCoin.chain[j].getTransaction()[i].getAmount();
            }

            if(FullCoin.chain[j].getTransaction()[i].getToID()==id)
            {
                balance=balance+FullCoin.chain[j].getTransaction()[i].getAmount();
            }

        }
    }
}
