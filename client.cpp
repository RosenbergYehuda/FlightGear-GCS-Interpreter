#include "headerFiles/client.h"

// singeltone
Client Client::instance;
Client& Client::getinstance()
{
	return instance;
}

int Client::client(string ip, string port)
{
	struct sockaddr_in serv_addr;

	// converting the string 'port' to a int PORT
	int PORT = stoi(port);

	//converting the string 'ip' to a char* IP
	char *IP = &ip[0];

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	if (inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0)
	{
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr,
				sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	return 1;
}

void Client::send(char* message)
{
	::send(sock, message, strlen(message), 0);
	valread = read(sock, buffer, 1024);
}

/*
int main()
{
	Client::getinstance().client("127.0.0.1", "5402");
	Client::getinstance().send("ls\r\n");
	return 0 ;
}
*/