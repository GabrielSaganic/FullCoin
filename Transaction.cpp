#include "Block.h"
#include "to_string.h"
#include "hasha.h"

Transaction::Transaction(string nFrom, string nTo, string nFromID, string nToID, int nAmount)
{
    fromID=nFromID;
    toID=nToID;
    from=nFrom;
    to=nTo;
    amount=nAmount;
    transaction_hash=hashing(from+to+char(amount));
}

Transaction::Transaction()
{
    from="error";
    to="error";
    amount=0000;
    transaction_hash="error";
}

