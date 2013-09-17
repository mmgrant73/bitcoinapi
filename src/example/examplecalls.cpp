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
	int port=8332;		      //port the the bitcoin wallet is listening

	bitcoinapi btc(username,password,address,port);

////////////getmininginfo//////////////////
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
	cout << "---------------------------------------------------------" << endl;

/////////////////listaccounts/////////////////
	cout << "listaccount method" << endl;
	btc.listaccounts();
	bitcoinapi::accounts al1;
	for (btc.itaccounts= btc.accountlist.begin() ; btc.itaccounts != btc.accountlist.end(); ++btc.itaccounts){
		al1=(*btc.itaccounts);
		cout<< "account=" << al1.account << endl;
		cout<< "amount=" << al1.amount << endl;
		cout << "        " << endl;
	}
	cout << "---------------------------------------------------------" << endl;

////////////////////getpeerinfo///////////////
	cout << "getpeerinfo method" << endl;
	btc.getpeerinfo();
	bitcoinapi::peerinfo b1;
	for (btc.peerinfoiterator = btc.peerinformation.begin() ; btc.peerinfoiterator != btc.peerinformation.end(); ++btc.peerinfoiterator){
		b1=(*btc.peerinfoiterator);
		cout<< "address=" << b1.address << endl;
		cout<< "services=" << b1.services << endl;
		cout<< "lastreceive=" << b1.lastreceive << endl;
		cout<< "lastsend=" << b1.lastsend << endl;
		cout<< "bytessent=" << b1.bytessent << endl;
		cout<< "connectiontime=" << b1.connectiontime << endl;
		cout<< "version=" << b1.version << endl;
		cout<< "subversion=" << b1.subversion << endl;
		cout<< "inbound=" << b1.inbound << endl;
		cout<< "startingheight=" << b1.startingheight << endl;
		cout<< "banscore=" << b1.banscore << endl;
		cout<< "syncnode=" << b1.syncnode << endl;
		cout << "        " << endl;
	}
	cout << "---------------------------------------------------------" << endl;

/////////////////////getconnectioncount///////////////////////
	cout << "getconnectioncount method" << endl;	
	int count1 = btc.getconnectioncount();
	cout << "connection count=" << count1 << endl;
	cout << "---------------------------------------------------------" << endl;

////////////////////getblockcount()//////////////////////////////
	cout << "getblockcount method" << endl;
	count1 = btc.getblockcount();
	cout << "block count=" << count1 << endl;
	cout << "---------------------------------------------------------" << endl;

////////////////////getgenerate////////////////////////////////////
	cout << "getgenerate method" << endl;
	bool generate1 = btc.getgenerate();
	cout << "generate=" << generate1 << endl;
	cout << "---------------------------------------------------------" << endl;

///////////////////////getdifficulty()//////////////////////////////
	cout << "getdifficulty method" << endl;
	double diff1 = btc.getdifficulty();
	cout << "difficulty=" << diff1 << endl;
	cout << "---------------------------------------------------------" << endl;

////////////////////gethashespersec()///////////////////////////////
	cout << "gethashespersec method" << endl;
	double hashpersec = btc.gethashespersec();
	cout << "difficulty=" << hashpersec << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getinfo()/////////////////////////////////
	cout << "getinfo method" << endl;
	btc.getinfo();
	cout << "version=" << btc.generalinfo.version << endl;
	cout << "balance=" << btc.generalinfo.balance << endl;
	cout << "protocolversion=" << btc.generalinfo.protocolversion << endl;
	cout << "walletversion=" << btc.generalinfo.walletversion << endl;
	cout << "blocks=" << btc.generalinfo.blocks << endl;
	cout << "connections=" << btc.generalinfo.connections << endl;
	cout << "difficulty=" << btc.generalinfo.difficulty << endl;
	cout << "errors=" << btc.generalinfo.errors << endl;
	cout << "keypoololdest=" << btc.generalinfo.keypoololdest << endl;
	cout << "keypoolsize=" << btc.generalinfo.keypoolsize << endl;
	cout << "paytxfee=" << btc.generalinfo.paytxfee << endl;
	cout << "proxy=" << btc.generalinfo.proxy << endl;
	cout << "testnet=" << btc.generalinfo.testnet << endl;
	cout << "timeoffset=" << btc.generalinfo.timeoffset << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getversion()///////////////////////////////
	cout << "getversion method" << endl;
	int version1=btc.getversion();
	cout << "version=" << version1 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getprotocolversion()////////////////////////
	cout << "getprotocolversion method" << endl;		
	int protocol1=btc.getprotocolversion();
	cout << "protocolversion=" << protocol1 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getwalletversion()////////////////////////
	cout << "getwalletversion method" << endl;		
	int wallet1=btc.getwalletversion();
	cout << "walletversion=" << wallet1 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getaccountaddress()////////////////////////
	cout << "getaccountaddress method" << endl;		
	string address1=btc.getaccountaddress("user2");
	cout << "address for user2=" << address1 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getaccount()////////////////////////
	cout << "getaccount method" << endl;		
	string account1=btc.getaccount("1BbJ53TByUXYNfz3zgEBcxcQJgGWE9ZkTr");
	cout << "account for this address = " << account1 << endl;
	cout << "---------------------------------------------------------" << endl;		

/////////////////////getaccountbalance()////////////////////////
	cout << "getaccountbalance method" << endl;		
	int b3=btc.getaccountbalance("user2");
	cout << "balance for user2 = " << b3 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getbalance()////////////////////////
	cout << "getbalance method" << endl;		
	int b2=btc.getbalance();
	cout << "Total balance = " << b2 << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////validateaddress()////////////////////////
	cout << "validateaddress method" << endl;		
	btc.validateaddress("1BbJ53TByUXYNfz3zgEBcxcQJgGWE9ZkTr");
	cout << "account=" << btc.addressinfo.account << endl;
	cout << "address=" << btc.addressinfo.address << endl;
	cout << "iscompressed=" << btc.addressinfo.iscompressed << endl;
	cout << "ismine=" << btc.addressinfo.ismine << endl;
	cout << "isscript=" << btc.addressinfo.isscript << endl;
	cout << "isvalid=" << btc.addressinfo.isvalid << endl;
	cout << "pubkey=" << btc.addressinfo.pubkey << endl;
	cout << "---------------------------------------------------------" << endl;

/////////////////////getrawmempool()////////////////////////
/////  need to verify this function
	cout << "getrawmempool method" << endl;		
	btc.getrawmempool();
	cout << "---------------------------------------------------------" << endl;

/////////////////////setaccount()////////////////////////
	cout << "setaccount method" << endl;		
	//btc.setaccount("1rakH3UWYfoZqpN3Rtmh25zipebcy6HV1","user1");
	cout << "---------------------------------------------------------" << endl;

/////////////////////getblock()////////////////////////
//need to verify this function
	cout << "getblock method" << endl;		
	//btc.getblock("0000000000000797a7aeb9d883e6b23b25cf0516c7c27f5b175afcc3927dc3d1");
	cout << "---------------------------------------------------------" << endl;

///////////////////////////addnode//////////////////
//add/remove/onetry
//need to verify this function
	cout << "addnode method" << endl;		
	//int r1=btc.addnode("http://127.0.0.1", "add");
	cout << "----------------------------------------------------------" << endl;

///////////////////////////getaddednodeinfo//////////////////
//need to verify this function
	cout << "getaddednodeinfo method" << endl;		
	//btc.getaddednodeinfo(true);
	cout << "----------------------------------------------------------" << endl;

///////////////////////////backupwallet//////////////////
	cout << "backupwallet method" << endl;		
	//btc.backupwallet("/root/");
	cout << "----------------------------------------------------------" << endl;

///////////////////////////encryptwallet//////////////////
	cout << "encryptwallet method" << endl;		
	btc.encryptwallet("mmgrant3672");
	cout << "----------------------------------------------------------" << endl;

///////////////////////////walletpassphrasechange//////////////////
	cout << "walletpassphrasechange method" << endl;		
	btc.walletpassphrasechange("mmgrant3672","gena3672");
	cout << "----------------------------------------------------------" << endl;

/////////////////////////getnewaddress////////////////////
	cout << "getnewaddress method" << endl;		
	string address3=btc.getnewaddress("user3");
	cout << "newaddress =" << address3 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////getreceivedbyaccount/////////////////////////////
	cout << "getreceivedbyaccount method" << endl;		
	double amount3=btc.getreceivedbyaccount("user2");
	cout << "user2 amount =" << amount3 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////getreceivedbyaddress/////////////////////////////
	cout << "getreceivedbyaddress method" << endl;		
	double amount2=btc.getreceivedbyaddress("1rakH3UWYfoZqpN3Rtmh25zipebcy6HV1");
	cout << "address amount =" << amount2 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////signmessage/////////////////////////////
	cout << "signmessage method" << endl;		
	//btc.signmessage("1rakH3UWYfoZqpN3Rtmh25zipebcy6HV1","matthew");
	//cout << "address amount =" << amount2 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////getblocktemplate/////////////////////////////
	cout << "getblocktemplate method" << endl;		
	//btc.getblocktemplate("matthew");
	//cout << "address amount =" << amount2 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////getblockhash/////////////////////////////
	cout << "getblockhash method" << endl;		
	//btc.getblockhash("matthew");
	//cout << "address amount =" << amount2 << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////dumpprivkey/////////////////////////////
	cout << "dumpprivkey method" << endl;		
	//string privkey=btc.dumpprivkey("matthew");
	//cout << "private key =" << privkey << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////importprivkey/////////////////////////////
	cout << "importprivkey method" << endl;		
	//btc.importprivkey("matthew","matthew",false);
	cout << "----------------------------------------------------------" << endl;

/////////////////////////gettransaction/////////////////////////////
	cout << "gettransaction method" << endl;		
	//btc.gettransaction("tx");
	cout << "txid=" << btc.transaction.txid << endl;
	cout << "confirmation=" << btc.transaction.confirmation << endl;
	cout << "amount=" << btc.transaction.amount << endl;
	cout << "fee=" << btc.transaction.fee << endl;
	cout << "account=" << btc.transaction.account << endl;
	cout << "address=" << btc.transaction.address << endl;
	cout << "category=" << btc.transaction.category << endl;
	cout << "----------------------------------------------------------" << endl;

/////////////////////////sendfrom/////////////////////////////
	cout << "sendfrom method" << endl;		
	//btc.sendfrom("account","bitcoinaddress",0,"comment","comment1");
	cout << "----------------------------------------------------------" << endl;

/////////////////////////sendtoaddress/////////////////////////////
	cout << "sendtoaddress method" << endl;		
	//btc.sendtoaddress("address",0,"comment","comment1");
	cout << "----------------------------------------------------------" << endl;


}
