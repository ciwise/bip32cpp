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
 * hmacsha512.h
 * BIP-32 HD Wallet HMAC-SHA512 header.
 *
 * author: David L. Whitehurst
 * date: June 24, 2018
 *
 * Find this code useful? Please donate:
 *  Bitcoin: 1Mxt427mTF3XGf8BiJ8HjkhbiSVvJbkDFY
 *
 */

#ifndef BIP32CPP_CHMAC_SHA512_H
#define BIP32CPP_CHMAC_SHA512_H

#include <openssl/sha.h>
#include <string>
#include <tuple>

using namespace std;

class CHMAC_SHA512 {

    private:
        string m; // Master Private Key (256 bits, 32 hex bytes)
        string cc; // Master Chain Code (256 bits, 32 hex bytes))

        void getHMAC_SHA512(string root_seed, char outputBuffer[129]);

    public:
        tuple<string, string> getDigestTuple(string seed);
};

#endif //BIP32CPP_CHMAC_SHA512_H
