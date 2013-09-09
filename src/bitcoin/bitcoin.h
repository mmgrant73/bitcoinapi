#include <jsonrpc/rpc.h>
#include <iostream>
#include <string.h>
//#include "version.h"

using namespace jsonrpc;
using namespace std;

class bitcoinapi{
	public:
		string connection;
		string user;
		string password;
		string host;
		int port;
		
		struct accounts{
			string account;
			double amount; 
		};

		struct generalinfo{
			double balance;
			int blocks;
			int connections;
			double difficulty;
			string errors;
			int keypoololdest;
			int keypoolsize;
			double paytxfee;
			int protocolversion;
			string proxy;
			bool testnet;
			int timeoffset;
			int version; 
			int walletversion;
		} generalinfo;

		struct transaction{
  			string txid;
  			int confirmation;
			string account;
			string address;
			string category;
			double amount;
			double fee;
		} transaction;

		struct mining{
			int blocks;
			int currentblocksize;
			int currentblocktx;
			double difficulty;
			string errors;
			int genproclimit;
			double hashespersec;
			int pooledtx;
			bool testnet;
			bool generate;	
		} mining;

		struct addressinfo{
			string account;
			string address;
			bool iscompressed;
			bool ismine;
			bool isscript;
			bool isvalid;
			string pubkey;
		} addressinfo;

		struct listtransaction{
  			string txid;
  			int confirmations;
			string account;
			string address;
			string category;
			double amount;
			double fee;
		};

		struct receivedbyaccount{
			string account;
			double amount;
			int confirmations;
		};

		struct receivedbyaddress{
			string address;
			string account;
			double amount;
			int confirmations;
		};

		struct peerinfo{
			string address;
			string services;
			int lastsend;
			int lastreceive;
			int bytessent;
			int bytesreceive;
			int connectiontime;
			int version;
			string subversion;
			bool inbound;
			int startingheight;
			int banscore;
			bool syncnode;
		};

		struct unspent{
			string txid;
			string output;
			string scriptPubKey;
			double amount;
			int confirmations;
		};
		
		vector<receivedbyaccount> receivedaccountlist;
		vector<receivedbyaddress> receivedaddresslist;
		vector<listtransaction> transactionlist;
		vector<peerinfo> peerinformation;
		vector<accounts> accountlist;
		vector<unspent> unspentlist;

		vector<receivedbyaddress>::iterator itreceivedbyaddress;		
		vector<receivedbyaccount>::iterator itreceivedbyaccount;
		vector<listtransaction>::iterator itlisttransaction;
		vector<peerinfo>::iterator peerinfoiterator;
		vector<accounts>::iterator itaccounts;
		vector<unspent>::iterator itunspent;

		bitcoinapi(string user, string password, string host, int port);
		string NumberToString (int Number);
  		int StringToNumber (const string &Text);
		Json::Value sendcommand(string command, Json::Value params);
		int addnode(string node, string command);
		void getaddednodeinfo(bool dns, string node);
		void getaddednodeinfo(bool dns);
		int getconnectioncount();
		void getpeerinfo();
		void getblock(string hash);
		int getblockcount();
		void getblocktemplate(string param);
		void getblockhash(string index);
		bool getgenerate();
		double getdifficulty();
		double gethashespersec();
		void getmininginfo();
		void getwork(string data);
		void setgenerate(bool generate);
		void backupwallet(string destination);
		void encryptwallet(string paraphase);
		void getinfo();
		int getversion();
		int getprotocolversion();
		int getwalletversion();
		void stop();
		void addmultisigaddress(string required, string key, string account);
		void createmultisig(string required, string key);
		string dumpprivkey(string bitcoinaddress);
		void importprivkey(string privatekey, string label, bool rescan);
		void keypoolrefill();
		void verifymessage(string bitcoinaddress, string signature, string message);
		void signmessage(string bitcoinaddress, string message);
		void walletlock();
		void walletpassphrase(string passphase, int timeout);
		void walletpassphrasechange(string oldpassphase, string newpassphase);
		string getaccount(string bitcoinaddress);
		string getaccountaddress(string account);
		void getaddressesbyaccount(string account);
		float getaccountbalance(string account);
		float getbalance();
		string getnewaddress(string account);
		double getreceivedbyaccount(string account);
		double getreceivedbyaddress(string bitcoinaddress);
		void gettransaction(string tx);
		void listaccounts();
		void listreceivedbyaccount();
		void listreceivedbyaddress();
		void listtransactions(string account, int count, int start);
		void listsinceblock(string hash);
		void move(string toaccount, string fromaccount, float amount, string comment);
		void sendfrom(string account, string bitcoinaddress, float amount, string comment, string to_comment);
		void sendtoaddress(string bitcoinaddress, float amount, string comment, string to_comment);
		void setaccount(string bitcoinaddress, string account);
		void settxfee(double amount);
		void validateaddress(string bitcoinaddress);
		bool isvalidateaddress(string bitcoinaddress);
		bool isitmyaddress(string bitcoinaddress);
		void listunspent(int confirmationmin, int confirmationmax);
		void lockunspent(string txid, bool lock);
		void listlockunspent();
		void createrawtransaction(string txid, bool lock1, string address, double amount);
		void decoderawtransaction(string hexstring);
		void getrawtransaction(string txid);
		void signrawtransaction(string hexstring, string txid, bool lock, string pubkey, string privatekey, string sighash);
		void sendrawtransaction(string hexstring);
		void getrawmempool();
		void gettxout(string txid, int n, bool includemempool);
		void gettxoutsetinfo();	

};
