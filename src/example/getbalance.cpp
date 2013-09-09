/**
 * @file example.cpp
 * @date 09.08.2013
 * @author Matthew Grant <mmgrant73@yahoo.com>
 * @brief Shows example API calls to the bitcoin wallet.
 */

#include <bitcoin/bitcoin.h>
using namespace std;

int main()
{	
	string username="mmgrant73";       //username for the bitcoin wallet
	string password="mmgrant3672";       //password for the bitcoin wallet
	string address="127.0.0.1";   //address to communicate with the bitcoin wallet
	int port=8332       ;         //port the the bitcoin wallet is listening

//This is the construct to connect to the bitcoin wallet//	
	bitcoinapi btc(username,password,address,port); 

///////////////////////getbalance()////////////////////////
//To get the balance from the bitcoin wallet, you just   //
//have to call the "getbalance function" and it will     //
//return an integer value that holds the balance         //
///////////////////////////////////////////////////////////

	cout << "getbalance method" << endl;		
	int b2=btc.getbalance();
	cout << "Total balance = " << b2 << endl;

}
