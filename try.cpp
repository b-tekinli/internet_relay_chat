#include <iostream>
#include <string>

// PONG mesajını gönderen IRC botu
class IRCBot {
public:
    void sendPongMessage(const std::string& server, const std::string& server2 = "") {
        if (server2.empty()) {
            std::cout << "PONG " << server << std::endl;
        } else {
            std::cout << "PONG " << server << " " << server2 << std::endl;
        }
    }
};

int main() {
    IRCBot bot;
    std::string server = "csd.bu.edu";
    std::string server2 = "tolsun.oulu.fi";

    // PING mesajına yanıt olarak PONG mesajı gönderme
    bot.sendPongMessage(server);

    return 0;
}
