
#include "Blockchain.h"
#include <stack>
#include <time.h>
#include <iostream>

struct tm *ptm;

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0));
    difficulty=2;
}

void Blockchain::addBlock(Block newBlock)
{
    newBlock.prev_hash=chain.back().getHash();
    chain.push_back(newBlock);
}

void Blockchain::print()
{
    for(int j=0; j<chain.size(); j++)
    {
        tm *ptm=localtime(&(chain[j]._time));
        cout<<endl<<"\t\t\tBLOCK " << j<<":"<<endl;
        cout <<"TRANSAKCIJE:"<<endl;
        for(int i=0; i<chain[j].getTransaction().size();i++)
            {
            cout <<"\tFrom "<<chain[j].getTransaction()[i].getFrom();
            cout <<"\tto "<<chain[j].getTransaction()[i].getTo();
            cout <<"\tamount: "<<chain[j].getTransaction()[i].getAmount()<<endl;
            }
        cout <<"BLOCK:"<<endl;
        cout <<"\tRedni broj bloka: " << chain[j].getIndex() << endl;
        cout <<"\tHahh: "<<chain[j].getHash()<<endl;
        cout <<"\tProsli hash: " << chain[j].prev_hash <<endl;
        cout <<"\tNonce: " << chain[j].getNonce() <<endl;
        cout <<"\tVrijeme bloka: " << ptm->tm_hour << ":" << ptm->tm_min<< ":" << ptm->tm_sec << endl;
        cout <<"\tDatum: " << (ptm->tm_year+1900) << "-" << (ptm->tm_mon+1) << "-" << ptm->tm_mday << endl;
    }
}
