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

		litecoinapi(string user, string password, string host, int port):bitcoinapi(user,password,host,port){};
		int getnetworkhashps();

};
