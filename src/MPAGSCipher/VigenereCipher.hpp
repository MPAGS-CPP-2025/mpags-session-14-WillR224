#ifndef MPAGSCIPHER_VigenereCIPHER_HPP
#define MPAGSCIPHER_VigenereCIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include <map>
#include <cstddef>
#include <string>
#include <vector>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher {
  public:
    /**
     * \brief Create a new VigenereCipher, converting the given string into the key
     *
     * \param key The string to convert into the key to be used in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    void setKey(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText The text to encrypt or decrypt
     * \param cipherMode Whether to encrypt or decrypt the input text
     * \return The result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    /// The cipher key, essentially a constant shift to be applied
    std::string key_{""};

    std::map<char,CaesarCipher> charLookup_;
};

#endif
