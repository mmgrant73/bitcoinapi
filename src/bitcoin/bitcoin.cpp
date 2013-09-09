/**
 * @file bitcoin.cpp
 * @date 09.06.2013
 * @author Matthew Grant <mmgrant73@yah00.com>
 * @brief This is a class design to communicate with the bitcoin wallet through the JSON-RPC protocol.
 */

//Things to do:
//1) Figure out how to list transaction so it is easy for the end-user
//2) Figure out what is raw-transaction and how to implement it
//3) Figure out how to use and implement sign messages
//4) Figure out how to use and implement nodes

#include "bitcoin.h"


		bitcoinapi::bitcoinapi(string user, string password, string host, int port){
			this->user=user;
			this->password=password;
			this->host=host;
			this->port=port;
			string strport = this->NumberToString(this->port);
			this->connection=this->user+":"+this->password+"@"+this->host+":"+strport;
		}

		//template <typename T>
  		string bitcoinapi::NumberToString (int Number){
     			ostringstream ss;
     			ss << Number;
     			return ss.str();
  		}

		//template <typename T>
  		int bitcoinapi::StringToNumber ( const string &Text ){
			//StringToNumber<Type> ( String ); 
     			istringstream ss(Text);
     			int result;
     			return ss >> result ? result : 0;
  		}

		Json::Value bitcoinapi::sendcommand(string command, Json::Value params){
			Json::Value result;
			Client c(new HttpClient("http://mmgrant73:mmgrant3672@127.0.0.1:8332"));
			 try
			 {
				result=c.CallMethod(command, params);
			 }
			 catch (JsonRpcException e)
			 {
				cerr << e.what() << endl;
			 }
			return result;
		}

//////////////////////////// Node functions////////////////////////////////

		int bitcoinapi::addnode(string node, string command){
			//add/remove/onetry
			int res;
			if(command=="add" || command=="remove" || command=="onetry"){
				string command="addnode";
				Json::Value params,result;
				params.append(node);
				params.append(command);
				result=this->sendcommand(command,params);
				res=0;
			}
			else{
				res=1;
			}
			return res;
		}

		void bitcoinapi::getaddednodeinfo(bool dns, string node){
			string command="getaddednodeinfo";
			Json::Value params,result;
			params.append(dns);
			params.append(node);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::getaddednodeinfo(bool dns){
			string command="getaddednodeinfo";
			Json::Value params,result;
			params.append(dns);
			result=this->sendcommand(command,params);
			cout << "nodes=" << result << endl;
			return;
		}

		int bitcoinapi::getconnectioncount(){
			string command="getconnectioncount";
			Json::Value params,result;
			result=this->sendcommand(command,params);
			int res=result.asInt();
			return res;
		}

		void bitcoinapi::getpeerinfo(){
			string command="getpeerinfo";
			Json::Value params,result;
			Json::Value r1,r2;
			string skey,dvalue;
			result=this->sendcommand(command,params);
			for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
				//r1=itr.key();
				Json::Value value = (*itr);
				peerinfo peerinfo1;
				peerinfo1.address=value["addr"].asString();
				peerinfo1.services=value["services"].asString();
				peerinfo1.lastsend=value["lastsend"].asInt();
				peerinfo1.lastreceive=value["lastrecv"].asInt();
				peerinfo1.bytessent=value["bytesent"].asInt();
				peerinfo1.bytesreceive=value["bytesrecv"].asInt();
				peerinfo1.connectiontime=value["conntime"].asInt();
				peerinfo1.version=value["version"].asInt();
				peerinfo1.subversion=value["subver"].asString();
				peerinfo1.inbound=value["inbound"].asBool();
				peerinfo1.startingheight=value["startingheight"].asInt();
				peerinfo1.banscore=value["banscore"].asInt();
				peerinfo1.syncnode=value["syncnode"].asBool();
				this->peerinformation.push_back(peerinfo1);
			}
			return;
		}  

//////////////////////////Mining Functions///////////////////////////

		void bitcoinapi::getblock(string hash){
			string command="getblock";
			Json::Value params;
			Json::Value result;
			params.append(hash);
			result=this->sendcommand(command,params);
			cout << "blockinfo=" << result << endl;
			return;
		}

		int bitcoinapi::getblockcount(){
			string command="getblockcount";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			int res=result.asInt();
			return res;
		}

		void bitcoinapi::getblocktemplate(string param){
			string command="getblocktemplate";
			Json::Value params;
			Json::Value result;
			params.append(param);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::getblockhash(string index){
			string command="getblockhash";
			Json::Value params;
			Json::Value result;
			params.append(index);
			result=this->sendcommand(command,params);
			return;
		}

		bool bitcoinapi::getgenerate(){
			string command="getgenerate";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			bool res=result.asBool();
			return res;
		}

		double bitcoinapi::getdifficulty(){
			string command="getdifficulty";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return result.asDouble();
		}

		double bitcoinapi::gethashespersec(){
			string command="gethashespersec";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return result.asDouble();
		}

		void bitcoinapi::getmininginfo(){
			string command="getmininginfo";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			Json::Value b=result["blocks"];
			Json::Value cbs=result["currentblocksize"];
			Json::Value cbt=result["currentblocktx"];
			Json::Value d=result["difficulty"];
			Json::Value e=result["errors"];
			Json::Value g=result["genproclimit"];
			Json::Value h=result["hashespersec"];
			Json::Value p=result["polledtx"];
			Json::Value t=result["testnet"];
			Json::Value g1=result["generate"];
			receivedbyaccount listaccount;
			this->mining.blocks= b.asInt();
			this->mining.currentblocksize= cbs.asInt();
			this->mining.currentblocktx=cbt.asInt();
			this->mining.difficulty=d.asDouble();
			this->mining.errors=e.asString();
			this->mining.generate=g1.asBool();
			this->mining.genproclimit=g.asInt();
			this->mining.hashespersec=h.asDouble();
			this->mining.pooledtx=p.asInt();
			this->mining.testnet=t.asBool();
			return;
		}

		void bitcoinapi::getwork(string data){
			string command="getwork";
			Json::Value params;
			Json::Value result;
			params.append(data);
			result=this->sendcommand(command,params);			
			return;
		}

		void bitcoinapi::setgenerate(bool generate){
			string command="setgenerate";
			Json::Value params;
			Json::Value result;
			params.append(generate);
			result=this->sendcommand(command,params);
			return;
		}

//////////////////////Wallet functions////////////////////////////////

		void bitcoinapi::backupwallet(string destination){
			string command="backupwallet";
			Json::Value params;
			Json::Value result;
			params.append(destination);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::encryptwallet(string paraphase){
			string command="encryptwallet";
			Json::Value params;
			Json::Value result;
			params.append(paraphase);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::getinfo(){
			string command="getinfo";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			this->generalinfo.balance=result["balance"].asDouble();
			this->generalinfo.blocks=result["blocks"].asInt();
			this->generalinfo.connections=result["connections"].asInt();
			this->generalinfo.difficulty=result["difficulty"].asDouble();
			this->generalinfo.errors=result["errors"].asString();
			this->generalinfo.keypoololdest=result["keypoololdest"].asInt();
			this->generalinfo.keypoolsize=result["keypoolsize"].asInt();
			this->generalinfo.paytxfee=result["paytxfee"].asDouble();
			this->generalinfo.protocolversion=result["protocolversion"].asInt();
			this->generalinfo.proxy=result["proxy"].asString();
			this->generalinfo.testnet=result["testnet"].asBool();
			this->generalinfo.timeoffset=result["timeoffset"].asInt();
			this->generalinfo.version=result["version"].asInt();
			this->generalinfo.walletversion=result["walletversion"].asInt();
			return;
		}

		int bitcoinapi::getversion(){
			this->getinfo();
			return this->generalinfo.version;
		}

		int bitcoinapi::getprotocolversion(){
			this->getinfo();
			return this->generalinfo.protocolversion;
		}

		int bitcoinapi::getwalletversion(){
			this->getinfo();
			return this->generalinfo.walletversion;
		}

		void bitcoinapi::stop(){
			string command="stop";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::addmultisigaddress(string required, string key, string account){
			string command="addmultisigaddress";
			Json::Value params;
			Json::Value result;
			params.append(required);
			params.append(key);
			params.append(account);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::createmultisig(string required, string key){
			string command="createmultisig";
			Json::Value params;
			Json::Value result;
			params.append(required);
			params.append(key);
			result=this->sendcommand(command,params);
			return;
		}

		string bitcoinapi::dumpprivkey(string bitcoinaddress){
			string command="dumpprivkey";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			result=this->sendcommand(command,params);
			return result["privkey"].asString();
		}

		void bitcoinapi::importprivkey(string privatekey, string label, bool rescan){
			string command="importprivkey";
			Json::Value params;
			Json::Value result;
			params.append(privatekey);
			params.append(label);
			params.append(rescan);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::keypoolrefill(){
			string command="keypoolrefill";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::verifymessage(string bitcoinaddress, string signature, string message){
			string command="verifymessage";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			params.append(signature);
			params.append(message);
			result=this->sendcommand(command,params);
			return;
		} 

		void bitcoinapi::signmessage(string bitcoinaddress, string message){
			string command="signmessage";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			params.append(message);
			result=this->sendcommand(command,params);
			return;
		} 

		void bitcoinapi::walletlock(){
			string command="walletlock";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::walletpassphrase(string passphase, int timeout){
			string command="walletpassphase";
			Json::Value params;
			Json::Value result;
			params.append(passphase);
			params.append(timeout);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::walletpassphrasechange(string oldpassphase, string newpassphase){
			string command="walletpassphasechange";
			Json::Value params;
			Json::Value result;
			params.append(oldpassphase);
			params.append(newpassphase);
			result=this->sendcommand(command,params);
			return;
		} 

/////////////////////Accounts and transaction functions////////////////////////

		string bitcoinapi::getaccount(string bitcoinaddress){
			string command="getaccount";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			result=this->sendcommand(command,params);
			string account=result.asString();
			return account;
		}	

		string bitcoinapi::getaccountaddress(string account){
			string command="getaccountaddress";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			string bitcoinaddress=result.asString();
			return bitcoinaddress;
		}

		void bitcoinapi::getaddressesbyaccount(string account){
			//need to fix this function returns all address associated to this address
			string command="getaddressesbyaccount";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			return;
		}

		float bitcoinapi::getaccountbalance(string account){
			string command="getbalance";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			//float balance=json2float(result);
			double balance=result.asDouble();
			return balance;
		}

		float bitcoinapi::getbalance(){
			this->getinfo();
			return this->generalinfo.balance;
		}

		string bitcoinapi::getnewaddress(string account){
			string command="getaccount";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			//Json::Value b=result["bitcoinaddress"];
			//string bitcoinaddress=json2string(result);
			string bitcoinaddress=result.asString();
			return bitcoinaddress;
		}

		double bitcoinapi::getreceivedbyaccount(string account){
			string command="getreceivedbyaccount";
			Json::Value params;
			Json::Value result;
			params.append(account);
			result=this->sendcommand(command,params);
			//float balance=json2float(result);
			double balance=result.asDouble();
			return balance;
		}

		double bitcoinapi::getreceivedbyaddress(string bitcoinaddress){
			string command="getreceivedbyaddress";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			result=this->sendcommand(command,params);
			//float balance=json2float(result);
			double balance=result.asDouble();
			return balance;
		}

		void bitcoinapi::gettransaction(string tx){
			string command="gettransaction";
			Json::Value params;
			Json::Value result;
			params.append(tx);
			result=this->sendcommand(command,params);
			Json::Value txid1=result["txid"];
			Json::Value confirmation1=result["confirmation"];
			Json::Value amount1=result["amount"];
			Json::Value fee1=result["fee"];
			Json::Value account1=result["account"];
			Json::Value address1=result["address"];
			Json::Value category1=result["category"];
			this->transaction.txid=txid1.asString();
			this->transaction.confirmation=confirmation1.asInt();
			this->transaction.amount=amount1.asDouble();
			this->transaction.fee=fee1.asDouble();
			this->transaction.account=account1.asString();
			this->transaction.address=address1.asString();
			this->transaction.category=category1.asString();
			return;
		}

		void bitcoinapi::listaccounts(){
			string command="listaccounts";
			Json::Value params;
			Json::Value result;
			Json::Value r1,r2;
			string skey;
			double dvalue;
			result=this->sendcommand(command,params);
			for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
				Json::Value value = (*itr);
				accounts accounts1;
				r1=itr.key();
				skey=r1.asString();
				r2=result[skey];
				dvalue=r2.asDouble();
				accounts1.account=skey;
				accounts1.amount=dvalue;
				this->accountlist.push_back(accounts1);
			}
		}

		void bitcoinapi::listreceivedbyaccount(){
			//probaby will not need
			string command="listreceivedbyaccount";
			Json::Value params,result;
			for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
				Json::Value value = (*itr);
				receivedbyaccount listaccount;
				listaccount.account=value["account"].asString();
				listaccount.amount=value["amount"].asDouble();
				listaccount.confirmations=value["confirmations"].asInt();
				this->receivedaccountlist.push_back(listaccount);
				//delete listaccount;
			}
			return;
		}

		void bitcoinapi::listreceivedbyaddress(){
			//probably will not need
			string command="listreceivedbyaddress";
			Json::Value params,result;
			for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
				receivedbyaddress listaccount;
				listaccount.address=result["address"].asString();
				listaccount.account=result["account"].asString();
				listaccount.amount=result["amount"].asDouble();
				listaccount.confirmations=result["confirmations"].asInt();
				this->receivedaddresslist.push_back(listaccount);
				//delete listaccount;
			}
			return;
		}

		void bitcoinapi::listtransactions(string account, int count, int start){
			string command="listtransactions";
			Json::Value params,result;
			for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
				listtransaction listtrans;
				listtrans.txid=result["txid"].asString();
				listtrans.address=result["address"].asString();
				listtrans.account=result["account"].asString();
				listtrans.amount=result["amount"].asDouble();
				listtrans.confirmations=result["confirmations"].asInt();
				listtrans.fee=result["fee"].asDouble();
				this->transactionlist.push_back(listtrans);
			}
			return;
		}

		void bitcoinapi::listsinceblock(string hash){
			string command="listsinceblock";
			Json::Value params,result;
			params.append(hash);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::move(string toaccount, string fromaccount, float amount, string comment){
			string command="move";
			Json::Value params,result;
			params.append(toaccount);
			params.append(fromaccount);
			params.append(amount);
			params.append(comment);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::sendfrom(string account, string bitcoinaddress, float amount, string comment, string to_comment){
			string command="sendfrom";
			Json::Value params,result;
			params.append(account);
			params.append(bitcoinaddress);
			params.append(amount);
			params.append(comment);
			params.append(to_comment);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::sendtoaddress(string bitcoinaddress, float amount, string comment, string to_comment){
			string command="sendtoaddress";
			Json::Value params,result;
			params.append(bitcoinaddress);
			params.append(amount);
			params.append(comment);
			params.append(to_comment);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::setaccount(string bitcoinaddress, string account){
			string command="setaccount";
			Json::Value params, result;
			params.append(bitcoinaddress);
			params.append(account);
			result=this->sendcommand(command,params);
			return;
		} 

		void bitcoinapi::settxfee(double amount){
			string command="settxfee";
			Json::Value params,result;
			params.append(amount);;
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::validateaddress(string bitcoinaddress){
			string command="validateaddress";
			Json::Value params;
			Json::Value result;
			params.append(bitcoinaddress);
			result=this->sendcommand(command,params);
			this->addressinfo.account=result["account"].asString();
			this->addressinfo.address=result["address"].asString();
			this->addressinfo.iscompressed=result["iscompressed"].asBool();
			this->addressinfo.ismine=result["ismine"].asBool();
			this->addressinfo.isscript=result["isscript"].asBool();
			this->addressinfo.isvalid=result["isvalid"].asBool();
			this->addressinfo.pubkey=result["pubkey"].asString();
			return;
		}

		bool bitcoinapi::isvalidateaddress(string bitcoinaddress){
			this->validateaddress(bitcoinaddress);
			return this->addressinfo.isvalid;
		}

		bool bitcoinapi::isitmyaddress(string bitcoinaddress){
			this->validateaddress(bitcoinaddress);
			return this->addressinfo.ismine;
		}

/////////Low level calls that will not be needed by most but added for completeness////////////// 

		void bitcoinapi::listunspent(int confirmationmin, int confirmationmax){
			string command="listunspent";
			Json::Value params;
			Json::Value result;
			params.append(confirmationmin);
			params.append(confirmationmax);
			result=this->sendcommand(command,params);
				for( Json::ValueIterator itr = result.begin() ; itr != result.end() ; itr++ ) {
					unspent unspent1;
					unspent1.txid=result["txid"].asString();
					unspent1.output=result["output"].asString();
					unspent1.scriptPubKey=result["scriptPubKey"].asString();
					unspent1.amount=result["amount"].asDouble();
					unspent1.confirmations=result["confirmations"].asInt();
					this->unspentlist.push_back(unspent1);
				}
			return;
		}

		void bitcoinapi::lockunspent(string txid, bool lock){
			string command="lockunspent";
			Json::Value params;
			Json::Value result;
			params.append(txid);
			params.append(lock);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::listlockunspent(){
			string command="listlockunspent";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::createrawtransaction(string txid, bool lock1, string address, double amount){
			string command="createrawtransaction";
			Json::Value params;
			Json::Value result;
			params.append(txid);
			params.append(lock1);
			params.append(address);
			params.append(amount);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::decoderawtransaction(string hexstring){
			string command="decoderawtransaction";
			Json::Value params;
			Json::Value result;
			params.append(hexstring);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::getrawtransaction(string txid){
			string command="getrawtransaction";
			Json::Value params;
			Json::Value result;
			params.append(txid);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::signrawtransaction(string hexstring, string txid, bool lock, string pubkey, string privatekey, string sighash){
			string command="signrawtransaction";
			Json::Value params;
			Json::Value result;
			params.append(hexstring);
			params.append(txid);
			params.append(lock);
			params.append(pubkey);
			params.append(privatekey);
			params.append(sighash);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::sendrawtransaction(string hexstring){
			string command="signrawtransaction";
			Json::Value params;
			Json::Value result;
			params.append(hexstring);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::getrawmempool(){
			string command="getrawmempool";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			cout << "rawmempool=" << result << endl;
			return;
		}

		void bitcoinapi::gettxout(string txid, int n, bool includemempool){
			string command="gettxout";
			Json::Value params;
			Json::Value result;
			params.append(txid);
			params.append(n);
			params.append(includemempool);
			result=this->sendcommand(command,params);
			return;
		}

		void bitcoinapi::gettxoutsetinfo(){
			string command="gettxoutsetinfo";
			Json::Value params;
			Json::Value result;
			result=this->sendcommand(command,params);
			return;
		} 



