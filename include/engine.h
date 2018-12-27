#pragma once

#include "instrument.h"
#include "config.h"
#include "wallet.h"
#include "calculate.h"
#include "position.h"
#include <iostream>
#include <vector>

const std::string currentDateTime();
void logPosition(std::string && str);

class Api
{

public:
  Api(Config & config) : v2(config.accessKey, config.secretKey), v1(config.accessKey, config.secretKey)
  {
  }
  BfxAPI::bitfinexAPIv2 v2;
  BfxAPI::BitfinexAPI v1;
};

class Engine
{
public:
  Engine(Config & config);
  Config &_config;
  Api _api;
  Calculate _calc;
  Position  _position;
  CandleInterface _candleInterface;
  std::vector<Instrument> vInstr;
  Wallet _wallet;
  void run();

};
