#include "Application.h"

#include <quickfix/FileStore.h>
#include <quickfix/SocketInitiator.h>
#include <quickfix/SessionSettings.h>
#include <quickfix/FileLog.h>

#include <string>
#include <iostream>
#include <fstream>

using std::cerr;
using std::endl;

void main1()
{
	std::string file = "C:/Users/kebin_000/Downloads/L2Demo(1)/L2Demo/config/tt.cfg";

	try
	{
		Application app(file);

		app.Init();

		app.Run();
	}
	catch (std::exception & e)
	{
		cerr << "Exception Caught: " << e.what() << std::endl;
	}
}
