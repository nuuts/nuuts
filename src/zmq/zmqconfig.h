// Copyright (c) 2014 The SaruulCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SaruulCoin_ZMQ_ZMQCONFIG_H
#define SaruulCoin_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/SaruulCoin-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char *str);

#endif // SaruulCoin_ZMQ_ZMQCONFIG_H
