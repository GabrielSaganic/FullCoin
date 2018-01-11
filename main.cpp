//time nije privatan
//transakcije u poseban cpp i header

#include <iostream>
#include "blockchain.h"

using namespace std;

int main()
{
    char odg='1';
    string from, to;
    int amount, n;
    Blockchain FullCoin=Blockchain();

    while(odg=='1')
    {
        n=FullCoin.chain.size()-1;
        cout <<"unesit od koga, kome i koliko: "<<endl;
        cin >> from >> to >> amount;
        FullCoin.chain[n].addTransaction(Transaction(from,to,amount));

        if(FullCoin.chain[n].getTransaction().size()==2)
        {
            FullCoin.chain[n].MineBlock(FullCoin.getDifficulty());
            cout <<"Mining..."<<endl;
            FullCoin.addBlock(Block(n+1));
        }

        cout <<"Ako zelis jos unesi 1: " <<endl;
        cin >> odg;
    }

    FullCoin.print();
    return 0;
}
