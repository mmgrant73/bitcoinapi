/**
 * @file litecoin.cpp
 * @date 09.14.2013
 * @author Matthew Grant <mmgrant73@yah00.com>
 * @brief This is a class design to communicate with the litecoin wallet through the JSON-RPC protocol.
 */

#include "litecoin.h"

		litecoinapi::litecoinapi(string user, string password, string host, int port):bitcoinapi(user, password, host, port){
			
		}

		string litecoinapi::getnetworkhashps(){
			string command="getnetworkhashps()";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			int hashps=result.asInt();
			return hashps;
		}
