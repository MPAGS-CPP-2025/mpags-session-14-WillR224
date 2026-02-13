//! Unit Tests for MPAGSCipher CaesarCipher Class
#include "gtest/gtest.h"

#include "VigenereCipher.hpp"

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher vc{"KEY"};
    EXPECT_EQ(vc.applyCipher("HELLOWORLD", CipherMode::Encrypt), "RIJVSUYVJN");
}


TEST(VigenereCipher, Decrypt)
{
    VigenereCipher vc{"KEY"};
    EXPECT_EQ(vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt), "HELLOWORLD");
}
