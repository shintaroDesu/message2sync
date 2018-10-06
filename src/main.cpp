#include <iostream>
#include <fstream>

#include "Senpai/client/SendRequest.h"
#include "Kouhai/core/Koneku.h"
#include "Kouhai/database/Deta.h"
#include "Kouhai/database/datapath.h"

void controller() {
	int choice;
	std::cout << "1.Run   2.Add class: ";
	std::cin >> choice;

	if(choice == 1) {
		Koneku my_app;
		my_app.launch();
	} else {
		Deta deta;
		deta.createClass("Bash", "../commands/Bash/Bash.h");
		deta.createClass("Send", "../commands/Send/Send.h");
		deta.createClass("Key", "../commands/Key/Key.h");
		deta.createClass("SharePic", "../commands/SharePic/SharePic.h");
		deta.createClass("Shortcut", "../commands/Shortcut/Shortcut.h");
		deta.updateHeader();
	}
}

void commander() {
	SendRequest sendRequest;

	std::string json = R"({"body" : "Hello World"})";
	sendRequest.sendpost(json);
}

void runserver() {
	std::string command = "python3 " + filepath + "src/Kouhai/server/manage.py runserver &";
	system(command.c_str());
}

int main(int argc, char *argv[]) {
	if(argv[1][0] == '1') {
		runserver();
		controller();
	} else if (argv[1][0] == '2') {
		commander();
	}
	return 0;
}
