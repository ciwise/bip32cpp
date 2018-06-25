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
 * bip32.cpp
 * A BIP-32 Implementation using C++.
 *
 * Utilities for Hierarchical Deterministic (HD) Wallet needs.
 * Using a random 512-bit seed, one can create a Master key for an always
 * reproducible HD wallet. See https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki
 * Deterministic (HD) wallet (BIP-32).
 *
 * author: David L. Whitehurst
 * date: June 22, 2018
 *
 * Algorithm:
 *
 * Find this code useful? Please donate:
 *  Bitcoin: 1Mxt427mTF3XGf8BiJ8HjkhbiSVvJbkDFY
 *
 */
#include <iostream>
#include <string>
#include <tuple>
#include "bip32node.h"
#include "hmacsha512.h"

using namespace std;

int main()
{
  Bip32Node bip32node("Master");
  bip32node.set_public(true);
  bip32node.print_status();
  cout << "Name(" << bip32node.getname() << ")" << endl;

  CHMAC_SHA512 hash;
  tuple<string,string> foo = hash.getDigestTuple("511f53ae13a256519b674951c3c957ed951acf648052f022252142fb812ea974895b2aab3608c340f41222f4778da459ababf6da812678bc0487affadd4f46d1");

  cout << "Left:  " << get<0>(foo) << endl;
  cout << "Right: " << get<1>(foo) << endl;

  return 0;
}

