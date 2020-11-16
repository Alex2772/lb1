//
// Created by alex2772 on 11/16/20.
//

#include "YamlWriter.h"

YamlWriter::YamlWriter(std::ofstream& fos) : mFos(fos) {}

void YamlWriter::writeAttribute(const std::string& name, const std::string& value) {
    implWriteAttribute(name, "\"" + value + "\"");
}

void YamlWriter::writeAttribute(const std::string& name, int value) {
    implWriteAttribute(name, std::to_string(value));
}

void YamlWriter::implWriteAttribute(const std::string& name, const std::string& formattedValue) {
    writeIndention();
    mFos << name << ": " << formattedValue << std::endl;
}

void YamlWriter::writeIndention() {
    for (int i = 0; i < mIndention; ++i) {
        mFos << "  ";
    }
}

void YamlWriter::beginObject(const std::string& name) {
    writeIndention();
    mFos << name << ":" << std::endl;
    mIndention += 1;
}

void YamlWriter::endObject() {
    mIndention -= 1;
    mFos << std::endl;
}

void YamlWriter::beginListObject(const std::string& name) {
    writeIndention();
    mFos << "- " << name << ":" << std::endl;
    mIndention += 2;
}

void YamlWriter::endListObject() {
    mIndention -= 2;
    mFos << std::endl;
}
