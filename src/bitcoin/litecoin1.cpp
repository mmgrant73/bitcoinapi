/**
 * @file litecoin.cpp
 * @date 09.14.2013
 * @author Matthew Grant <mmgrant73@yah00.com>
 * @brief This is a class design to communicate with the litecoin wallet through the JSON-RPC protocol.
 */

#include <jsonrpc/rpc.h>
#include <iostream>
#include <string.h>
#include "bitcoin.cpp"

using namespace jsonrpc;
using namespace std;

class litecoinapi: public bitcoinapi{
	public:
		string connection;
		string user;
		string password;
		string host;
		int port;

		litecoinapi(string username,string password,string address,int port):bitcoinapi(username, password, host, port){
			//this->user=user;
			//this->password=password;
			//this->host=host;
			//this->port=port;
			//string strport = this->NumberToString(this->port);
			//this->connection=this->user+":"+this->password+"@"+this->host+":"+strport;
		}

		int getnetworkhashps(){
			string command="getnetworkhashps()";
			Json::Value params;
			Json::Value result;
			//params.append(account);
			result=this->sendcommand(command,params);
			int hashps=result.asInt();
			return hashps;
		}

};

int main()
{	
	string username="mmgrant73";         //username for the litecoin wallet
	string password="mmgrant3672";       //password for the litecoin wallet
	string address="127.0.0.1";          //address to communicate with the litecoin wallet
	int port=8332;                       //port the the litecoin wallet is listening

//This is the construct to connect to the litecoin wallet//	
	litecoinapi ltc(username,password,address,port); 

///////////////////////getdifficulty()////////////////////////
//To get the difficulty from the litecoincoin wallet,       //
//you just have to call the "getdifficulty function" and    //
//it will return an double value that holds the difficulty  //
//////////////////////////////////////////////////////////////

	cout << "getdifficulty method" << endl;		
	double d1=ltc.getdifficulty();
	cout << "Difficulty = " << d1 << endl;

}
