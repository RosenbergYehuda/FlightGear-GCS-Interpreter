#include "headerFiles/server.h"

void Server::server(string port)
{
	char buffer[1024] = {"0"};
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	int PORT = stoi(port);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port
	if (setsockopt(server_fd, SOL_SOCKET,
				   SO_REUSEADDR | SO_REUSEPORT, &opt,
				   sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		valread = read(new_socket, buffer, 1024);
		Server::updateMap(buffer);
	}
}

void Server::serverThread(string port, string frequancy)
{
	thread t1(&Server::server, this, port);

	// controlling the server to get info 10 times in a second.
	// converting string to int
	int intFrequency = stoi(frequancy);

	chrono::milliseconds timespan(10 * intFrequency);
	this_thread::sleep_for(timespan);

	t1.detach();
}

void Server::updateMap(char (&buffer)[1024])
{
	vector<double> values;

	// separitin the data by the camma and pushing them into a dynamic array
	char *token;
	char *rest = buffer;
	while ((token = strtok_r(rest, ",", &rest)))
	{
		// convert from string to double
		double double_token = stod(token);

		values.push_back({double_token});
	}
	// inserting the values from the drone to there location in the map
	PathValueMap::getinstance().pathValueMap(values);
};

/*
int main()
{
	Server instance;
	//instance.server("5400");
	instance.serverThread("5400","10");


 //this is needed for keep the thread alive until the drone connects.
	cin.ignore();
	return 0;
}
*/