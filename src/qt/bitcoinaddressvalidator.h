// Copyright (c) 2011-2014 The SaruulCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SaruulCoin_QT_SaruulCoinADDRESSVALIDATOR_H
#define SaruulCoin_QT_SaruulCoinADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SaruulCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SaruulCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** SaruulCoin address widget validator, checks for a valid SaruulCoin address.
 */
class SaruulCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SaruulCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SaruulCoin_QT_SaruulCoinADDRESSVALIDATOR_H
