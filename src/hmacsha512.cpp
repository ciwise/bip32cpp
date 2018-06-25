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
 * hmacsha512.cpp
 * BIP-32 HD Wallet HMAC-SHA512 source.
 *
 * author: David L. Whitehurst
 * date: June 24, 2018
 *
 * Find this code useful? Please donate:
 *  Bitcoin: 1Mxt427mTF3XGf8BiJ8HjkhbiSVvJbkDFY
 *
 */

#include "hmacsha512.h"
#include <openssl/sha.h>
#include <tuple>
using namespace std;

/**
 * Private method to perform HMAC-SHA512 one-way hash
 * 
 * @param root_seed
 * @param outputBuffer
 */
void CHMAC_SHA512::getHMAC_SHA512(string root_seed, char outputBuffer[129]) {

    unsigned char digest[SHA512_DIGEST_LENGTH];

    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, root_seed.c_str(), root_seed.length());
    SHA512_Final(digest, &ctx);

    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
        sprintf(&outputBuffer[i*2], "%02x", (unsigned int)digest[i]);
}

/**
 * Public method to return a tuple with the left side of the digest, or
 * Master Public Key and the right side of the digest, or Master Chain
 * Code
 *
 * @param seed
 * @return
 */
tuple<string, string> CHMAC_SHA512::getDigestTuple(string seed) {

    /* get HMAC-SHA512 digest */
    static char digest[129];
    getHMAC_SHA512(seed, digest);

    /* create std::string */
    string tmp = digest;

    /* set private keys */
    m = tmp.substr(0, 64);
    cc = tmp.substr(64, 128);

    /* create tuple and return */
    tuple<string,string> pair (this->m, this->cc);

    return pair;
}