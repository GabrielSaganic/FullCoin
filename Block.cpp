#include "Block.h"
#include "Blockchain.h"
#include "hasha.h"
#include "Wallet.h"
#include "to_string.h"
#include <time.h>
#include <iostream>

Block::Block(int nIndex)
{
    index=nIndex;
    _time=time(0);
    nonce=0;

    _hash=hashing(patch::to_string(index)+prev_hash+patch::to_string(_time)+patch::to_string(nonce));
}

void Block::addTransaction(Transaction tmpTransaction)
{
    _time=time(0);
    _hash=hashing(_hash+patch::to_string(_time)+tmpTransaction.getHash());
    vector_transaction.push_back(tmpTransaction);
}

void Block::MineBlock(int difficulty)
{
    char cstr[difficulty +1];
    for (int i = 0; i < difficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';
    string tmp_hash=_hash;
    string str(cstr);

    while (tmp_hash.substr(0, difficulty) != str)
    {
        nonce++;
        tmp_hash =hashing(_hash+patch::to_string(nonce));
    }

    _hash=tmp_hash;
}
