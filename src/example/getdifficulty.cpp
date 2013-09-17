/**
 * @file example.cpp
 * @date 09.08.2013
 * @author Matthew Grant <mmgrant73@yahoo.com>
 * @brief Shows example API calls to the litecoin wallet.
 */

//#include "bitcoin.h"
//#include "bitcoin.cpp"
//#include <bitcoin/bitcoin.h>
#include <bitcoin/litecoin.h>
using namespace std;

int main()
{	
	string username="mmgrant73";         //username for the litecoin wallet
	string password="mmgrant3672";       //password for the litecoin wallet
	string address="127.0.0.1";          //address to communicate with the litecoin wallet
	int port=8332;                       //port the the litecoin wallet is listening

//This is the construct to connect to the litecoin wallet//	
	litecoinapi ltc(username,password,address,port); 

///////////////////////getbalance()////////////////////////
//To get the difficulty from the litecoincoin wallet,    //
//you just have to call the "getbalance function" and    //
//it will return an double value that holds the balance  //
///////////////////////////////////////////////////////////

	cout << "getdifficulty method" << endl;		
	double d1=ltc.getdifficulty();
	cout << "Difficulty = " << d1 << endl;

}
