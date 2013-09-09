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
	string username="user";       //username for the bitcoin wallet
	string password="pass";       //password for the bitcoin wallet
	string address="127.0.0.1";   //address to communicate with the bitcoin wallet
	int port=8332;               //port the the bitcoin wallet is listening
	string account="user1";       //account name of the new bitcoin address that will be created

	bitcoinapi btc(username,password,address,port);

/////////////////////////getnewaddress////////////////////
	cout << "getnewaddress method" << endl;		
	string address3=btc.getnewaddress(account);
	cout << "newaddress =" << address3 << endl;
}
