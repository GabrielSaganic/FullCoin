//time nije privatan
//addWallet u funkciju
//Private sve u Walletu

#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"
#include "Function.h"

using namespace std;

std::unordered_map<string,Wallet> map_wallets;

int main()
{
    int amount, n, odg;

    Blockchain FullCoin=Blockchain();

    do
    {
        switch(odg)
        {
            case 1:
            {
                map_wallets=new_wallet(map_wallets, FullCoin);

                odg=99;
                break;
            }
            case 2:
            {
                n=FullCoin.chain.size()-1;

                FullCoin=paying(map_wallets, FullCoin, n);

                odg=99;
                break;
            }
            case 3:
            {
                 FullCoin.print();

                 odg=99;
                 break;
            }

            case 4:
            {
                for (auto& j: map_wallets)
                {
                    j.second.synx_wallet(FullCoin);
                }

                odg=99;
                break;
            }
            case 5:
            {
                print_all_wallet(map_wallets);

                odg=99;
                break;
            }
            default:
            {
                cout << endl;
                cout <<"NOVI RACUN-------------1\n";
                cout <<"NOVA TRANSAKCIJA-------2\n";
                cout <<"ISPIS BLOKOVA----------3\n";
                cout <<"AZURIRANJE RACUNA------4\n";
                cout <<"ISPIS RACUNA-----------5\n";
                cout <<"IZLAZ------------------0\n";
                cout << endl;
                cin >> odg;
            }
        }
    }while(odg!=0);

    FullCoin.print();
    return 0;
}
