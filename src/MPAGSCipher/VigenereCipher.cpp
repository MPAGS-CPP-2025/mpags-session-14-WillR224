#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"
#include <algorithm>
#include <iostream>
#include <string>

/**
 * \file VigenereCipher.cpp
 * \brief Contains the implementation of the VigenereCipher class
 */

VigenereCipher::VigenereCipher(const std::string& key)
{
    this -> setKey(key);
}
    
void VigenereCipher::setKey(const std::string& key)
{
    // Store the key
    key_ = key;
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                ::toupper);
    // Make sure the key is uppercase
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    // Remove non-alphabet characters

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        key_ = "KEY";
    }
    // loop over the key
    for (std::size_t i{0}; i < key_.size(); i++) {
        // Find the letter position in the alphabet
        std::size_t position = Alphabet::alphabet.find(key_[i]);
        // Create a CaesarCipher using this position as a key
        CaesarCipher cipher{position};
        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(key_[i], cipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                      const CipherMode cipherMode) const
{
    std::string outputText = "";
    // For each letter in input:
    for(std::size_t i{0}; i<inputText.size(); i++) {
    // Find the corresponding letter in the key,
        char keyletter = key_[i % key_.size()];
        // repeating/truncating as required
        // Find the Caesar cipher from the lookup
        CaesarCipher cipher = charLookup_.at(keyletter);
        // Run the (de)encryption
        outputText += cipher.applyCipher(std::string(1,inputText[i]), cipherMode);
        // Add the result to the output
    }
    return outputText;
}
