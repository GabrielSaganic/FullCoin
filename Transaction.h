#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <iostream>

using namespace std;

class Transaction
{
private:
    string from;
    string to;
    string fromID;
    string toID;
    int amount;
    string transaction_hash;
public:
    Transaction();
    Transaction(string nFrom, string nTo, string nFromID, string nToID, int nAmount);

    int getAmount(){return amount;}
    string getFrom(){return from;}
    string getTo(){return to;}
    string getFromID(){return fromID;}
    string getToID(){return toID;}
    string getHash(){return transaction_hash;}
};

#endif // TRANSACTION_H_INCLUDED
