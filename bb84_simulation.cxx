//
// Created by Filippo Valle on 18/11/2018.
//

#if !defined(__CINT__) || defined(__MAKECINT__)
#include "Simulator.h"
#include "StopWatch.h"
#include "ConfigSimulation.h"
#include "Analyzer.h"
#include <TCanvas.h>
#include <TF1.h>
#endif

void bb84_simulation(){
    StopWatch watch;
    auto cx = new TCanvas();
    std::vector<ConfigSimulation> configs;
    configs.emplace_back(ConfigSimulation(true, 100, 2000, true, 0., nullptr));
    configs.emplace_back(ConfigSimulation(false, 100, 2000, true, 0.2, [&](){return gRandom->Gaus(0, 0.2);}));
    configs.emplace_back(ConfigSimulation(false, 100, 2000, true, 0.4, [&](){return gRandom->Gaus(0, 0.4);}));
    configs.emplace_back(ConfigSimulation(false, 100, 2000, true, 0.6, [&](){return gRandom->Gaus(0, 0.6);}));
    configs.emplace_back(ConfigSimulation(false, 100, 2000, true, 0.8, [&](){return gRandom->Gaus(0, 0.8);}));
    configs.emplace_back(ConfigSimulation(false, 100, 2000, true, 1, [&](){return gRandom->Gaus(0, 1);}));


    auto MyAnalizer = Analyzer::Instance(configs);
    MyAnalizer->RunAnalyzer();
    MyAnalizer->JoinResults(cx);
    Analyzer::Destroy();
}
