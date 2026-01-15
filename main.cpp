#include <dpp/dpp.h>
#include <iostream>

const std::string BOT_TOKEN = "Bot_Token_Here"; // Bot Token
const std::string PREFIX = "!"; // Command Prefix

int main() {
    dpp::cluster bot(BOT_TOKEN, dpp::i_all_intents);
    bot.on_log(dpp::utility::cout_logger());
    bot.on_ready([&bot](const dpp::ready_t& event) {
        std::cout << "Bot is online as " << bot.me.username << std::endl;
    });

    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        const std::string& content = event.msg.content;
        if (content.rfind(PREFIX, 0) == 0) {
            std::string command = content.substr(PREFIX.size());
            if (command == "ping") {
                bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
            }
        }
    });
    bot.start(dpp::st_wait);
}
