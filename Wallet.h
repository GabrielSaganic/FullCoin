#ifndef WALLET_H_INCLUDED
#define WALLET_H_INCLUDED

#include <unordered_map>
#include "Blockchain.h"
#include "Block.h"

using namespace std;

class Wallet
{
private:
    string id;
    double balance;
public:
    string getID () const
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
    Wallet();
    Wallet(double n_balance);

    void synx_wallet (Blockchain FullCoin) ;
    void print_wallet(std::unordered_map<string,Wallet> map_wallets);
};

#endif // WALLET_H_INCLUDED
