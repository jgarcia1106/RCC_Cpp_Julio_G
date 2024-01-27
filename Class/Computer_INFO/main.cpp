#include <iostream>
#include <array>
#include <cstring>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#endif

std::string GetIPAddress(const std::string& hostname) {
    struct addrinfo hints, *info, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname.c_str(), NULL, &hints, &info)) != 0) {
        std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
        return "Unavailable";
    }

    for(p = info; p != NULL; p = p->ai_next) {
        void *addr;
        std::string ipver;

        // get the pointer to the address itself, different fields in IPv4 and IPv6
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // convert the IP to a string and print it
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        freeaddrinfo(info);
        return std::string(ipstr);
    }

    return "Unavailable";
}

int main() {
    try {
        #ifdef _WIN32
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            throw std::runtime_error("WSAStartup failed");
        }
        #endif

        std::array<char, 256> hostname;
        if (gethostname(hostname.data(), hostname.size()) != 0) {
            throw std::runtime_error("Failed to get host name");
        }

        std::cout << "Hostname: " << hostname.data() << std::endl;

        std::string ipAddress = GetIPAddress(hostname.data());
        std::cout << "IP Address: " << ipAddress << std::endl;

        #ifdef _WIN32
        WSACleanup();
        #endif
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
