bitcoinapi
==========

This is a c++ library to help developers communicate with the bitcoin wallet using JSON-RPC

The bitcoin wallet communicates using the JSON-RPC 1.0 protocol.  This is a wrapper library 
the simplifies the communication with the bitcoin wallet using the JSON-RPC protocol.  One
does not need to know this protocol as this library handles all the heavy lifting in the 
background.  A developer just needs to issue some simple function calls and the library
will handle all the communication needed to perform the task that the person desires.

Note this library is still in the alpha stage and thus, there are probably bugs that I 
have yet to address.  I will move this project along as fast as I can.

Requirments needed to use this library
--------------------------------------
* CMake(version 2.6 or higher) - which can be downloaded at http://www.cmake.org
* Libcurl - This is probably already installed on your system

Building and installing this library
--------------------------------------
Open your terminal and enter the following commands:
```
# Go to the build folder of the bitcoin-cpp project
cd bitcoin-cpp/build 

# commands to build and install
cmake ..
make
make install

#if you have linux than the following command needs to be run
ldconfig
```

Example
-------
Note: Make sure you include the bitcoin.h header in your project

1) This example will show you how to connect and get the balance from the bitcoin wallet

Filename getbalance.cpp

```
#include <bitcoin/bitcoin.h>
using namespace std;

int main()
{	
	string username="username";       //username for the bitcoin wallet
	string password="password";       //password for the bitcoin wallet
	string address="127.0.0.1";       //address to communicate with the bitcoin wallet
	int port=8332;                    //port the the bitcoin wallet is listening

//This is the construct to connect to the bitcoin wallet//	
	bitcoinapi btc(username,password,address,port); 

///////////////////////getbalance()////////////////////////
//To get the balance from the bitcoin wallet, you just   //
//have to call the "getbalance function" and it will     //
//return a double value that holds the balance           //
///////////////////////////////////////////////////////////

	cout << "getbalance method" << endl;		
	double b2=btc.getbalance();
	cout << "Total balance = " << b2 << endl;

}
```
To compile this example program run the following command from the commandline
```
g++ getbalance.cpp -lbitcoin -o getbalance
```
Note that this example and a couple more examples are located at bitcoin-cpp/example

Used Libraries:
---------------
* jsoncpp (licensed under MIT) jsoncpp is a very easy to use and powerful json library. It is used for all the JSON parsing and generation inside this library. http://jsoncpp.sourceforge.net/
* curl lib curl is used for the HttpClient connections.
* libjson-rpc-cpp (licensed under MIT) C++ framework for json-rpc (json remote procedure call).  I use a modify version of this library so that it can run 
Json-rpc 1.0.  It is design for Json-rpc 2.0. https://github.com/cinemast/libjson-rpc-cpp
