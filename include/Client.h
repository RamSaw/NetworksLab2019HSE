//
// Created by mikhail on 03.02.19.
//

#ifndef NETWORKSLAB2019HSE_CLIENT_H
#define NETWORKSLAB2019HSE_CLIENT_H


#include "Currency.h"

class Client {
public:
    Client(const std::string &hostname, uint16_t portno);

    virtual ~Client();

    const std::vector<Currency> list() const;

    void write_end_of_message(std::vector<int8_t> &buffer) const;

    void write_command(std::vector<int8_t> &buffer, int32_t command_no) const;

private:
    const int sockfd;
    static const size_t BUFFER_INITIAL_LENGTH = 256;
    static const size_t CURRENCY_NAME_SIZE_IN_LIST = 16;

    bool is_message_received(const std::vector<int8_t> &message) const;

    const std::vector<Currency> translate_list_message(std::vector<int8_t> &message) const;

    void remove_ending_symbols(std::vector<int8_t> &message) const;
};


#endif //NETWORKSLAB2019HSE_CLIENT_H
