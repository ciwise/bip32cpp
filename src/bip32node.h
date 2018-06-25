/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 David L. Whitehurst
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * bip32node.h
 * BIP-32 HD Wallet Node header.
 *
 * author: David L. Whitehurst
 * date: June 22, 2018
 *
 * Find this code useful? Please donate:
 *  Bitcoin: 1Mxt427mTF3XGf8BiJ8HjkhbiSVvJbkDFY
 *
 */

#ifndef BIP32CPP_BIP32NODE_H
#define BIP32CPP_BIP32NODE_H
#include <iostream>
#include <string>
using namespace std;

class Bip32Node {
    bool public_use;
    bool used;
    char* priv_key, pub_key, chain_code;
    string name;

public:
    Bip32Node (const std::string& str) : name(str) {}
    void print_status();
    void print_name();
    void set_public(bool pstate);
    bool get_public();

    void from_entropy(char* entropy, bool pstate);
    void from_extended_key(char* xkey, bool pstate);
    const string& getname() const {return name;}
};

#endif //BIP32CPP_BIP32NODE_H
