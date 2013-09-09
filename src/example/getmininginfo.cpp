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
	int port=8332       ;         //port the the bitcoin wallet is listening

//This is the construct to connect to the bitcoin wallet//
	bitcoinapi btc(username,password,address,port);

/////////////////////////////getmininginfo///////////////////////////
//To Get the mining information from the bitcoin wallet you have   //
//to call the method "getmininginfo".  The mining information will //
//then be stored in a structure called mining from which you can   //
//call and get the mining information                              //
/////////////////////////////////////////////////////////////////////

	cout << "getmininginfo method" << endl;
	btc.getmininginfo();
	int blocks=btc.mining.blocks;
	int currentblocksize=btc.mining.currentblocksize;
	int currentblocktx=btc.mining.currentblocktx;
	double difficulty=btc.mining.difficulty;
	string errors=btc.mining.errors;
	int genproclimit=btc.mining.genproclimit;
	double hashespersec=btc.mining.hashespersec;
	int pooledtx=btc.mining.pooledtx;
	bool testnet=btc.mining.testnet;
	bool generate=btc.mining.generate;
	cout << "blocks=" << blocks << endl;
	cout << "currentblocksize="<< currentblocksize << endl;
	cout << "currentblocktx="<< currentblocktx << endl;
	cout << "difficulty="<<difficulty << endl;
	cout << "errors="<< errors << endl;
	cout << "genproclimit="<<genproclimit << endl;
	cout << "hashespersec="<<hashespersec << endl;
	cout << "pooledtx="<< pooledtx << endl;
	cout << "testnet="<< testnet << endl;
	cout << "generate="<< generate << endl;

}
