#include "HuffmanEncoder.h"
#include "gtest/gtest.h"

void testEncode(const std::string &text, int expectedEncodeLength) {
    auto encoder = HuffmanEncoder(text);
    std::string encodedText = encoder.encode();
    ASSERT_EQ(encodedText.length(), expectedEncodeLength);
}

void testDecode(const std::string &text) {
    auto encoder = HuffmanEncoder(text);
    std::string encodedText = encoder.encode();
    std::string decodedText = encoder.decode(encodedText);
    ASSERT_EQ(text, decodedText);
}

TEST(HuffmanTest, EncodeShortText1) { testEncode("Hello World", 32); }

TEST(HuffmanTest, EncodeShortText2) {
    testEncode("Magnificent collisions of ethereal weight, Colossal magnitude "
               "rests upon thee",
               317);
}

TEST(HuffmanTest, DecodeShortText1) { testDecode("Hello World"); }

TEST(HuffmanTest, DecodeShortText2) {
    testDecode("Magnificent collisions of ethereal weight, "
               "Colossal magnitude rests upon thee");
}
