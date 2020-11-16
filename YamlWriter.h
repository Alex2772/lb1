#pragma once


#include <fstream>

class YamlWriter {
private:
    std::ofstream& mFos;
    int mIndention = 0;

    void implWriteAttribute(const std::string& name, const std::string& formattedValue);
    void writeIndention();
public:
    YamlWriter(std::ofstream& fos);

    void writeAttribute(const std::string& name, const std::string& value);
    void writeAttribute(const std::string& name, int value);

    void beginObject(const std::string& name);
    void endObject();

    void beginListObject(const std::string& name);
    void endListObject();
};

