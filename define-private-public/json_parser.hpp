#pragma once
#include <nlohmann/json.hpp>
#include <string>

class JsonParser
{
public:
    explicit JsonParser(const std::string &text)
        : data_(nlohmann::json::parse(text)) {}

    std::string get_string(const std::string &key) const
    {
        return data_.at(key);
    }

private:
    nlohmann::json data_;
};