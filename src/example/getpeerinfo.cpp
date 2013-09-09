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

////////////////////////getpeerinfo//////////////////////////
//To get the information of the peers that is connected    //
//to the bitcoin wallet, you call the method "getpeerinfo" //
//the information for each peer will be stored in a        //
//structure called peerinfo.  In turn each peerinfo will   //
//be stored in a vector called peerinformation.  To cycle  //
//through all the peerinfo in the vector, you use an       //
//iterator that is defined for the peerinformation vector  //
//called peerinfoiterator                                  //
/////////////////////////////////////////////////////////////

	cout << "getpeerinfo method" << endl;
	btc.getpeerinfo();
	bitcoinapi::peerinfo b1;
	for (btc.peerinfoiterator = btc.peerinformation.begin() ; btc.peerinfoiterator != btc.peerinformation.end(); ++btc.peerinfoiterator){
   		//remember you must dereferences the iterator pointer// 
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
		cout << "---------------------------------------" << endl;
	}

}
