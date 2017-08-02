// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The SaruulCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SaruulCoin_SaruulCoinCONSENSUS_H
#define SaruulCoin_SaruulCoinCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_SaruulCoin_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/SaruulCoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBSaruulCoinCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SaruulCoinCONSENSUS_API_VER 1

typedef enum SaruulCoinconsensus_error_t
{
    SaruulCoinconsensus_ERR_OK = 0,
    SaruulCoinconsensus_ERR_TX_INDEX,
    SaruulCoinconsensus_ERR_TX_SIZE_MISMATCH,
    SaruulCoinconsensus_ERR_TX_DESERIALIZE,
    SaruulCoinconsensus_ERR_AMOUNT_REQUIRED,
    SaruulCoinconsensus_ERR_INVALID_FLAGS,
} SaruulCoinconsensus_error;

/** Script verification flags */
enum
{
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | SaruulCoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int SaruulCoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, SaruulCoinconsensus_error* err);

EXPORT_SYMBOL int SaruulCoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, SaruulCoinconsensus_error* err);

EXPORT_SYMBOL unsigned int SaruulCoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // SaruulCoin_SaruulCoinCONSENSUS_H
