//
// Created by Filippo Valle on 15/11/2018.
//

#ifndef BB84_SIMULATION_SIMULATOR_H
#define BB84_SIMULATION_SIMULATOR_H

#if !defined(__CINT__) || defined(__MAKECINT__)
#include "Buddy.h"
#include "Channel.h"
#include "Phone.h"
#include "ConfigSimulation.h"
#include <TFile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TH1D.h>
#include <TGraphErrors.h>
#include <stdio.h>
#include <TLine.h>
#endif

class Simulator {
public:
    static Simulator *Instance();
    static Simulator *Instance(ConfigSimulation config);

    Simulator* RunSimulation();
    Simulator* GeneratePlots();
    Simulator* ShowResults(TCanvas *cx);

private:
    Simulator();                  // costruttore privato --> non si può usare! Il Simulatpr verrà creato (una volta sola) solo con Instance()
    Simulator(ConfigSimulation config);                  // costruttore privato --> non si può usare! Il Simulatpr verrà creato (una volta sola) solo con Instance()
    ~Simulator();
    Simulator(const Simulator& source);             // impedisco a compilatore di creare copy constructor


    void PlotPdfPerLenght(TTree *);
    void PlotNinterceptedVsN(TTree *);
    void HistNintercepted(TTree*);

    Channel** fChannels;
    int fNqbits;
    int fNSimulations;
    bool fUseLogicQbits;
    std::string fInfos;

    static constexpr const char* fFilename = "bb84_simulation.root";
    static constexpr const char* fTreename = "bb84";
    static constexpr const char* fBranchName = "dataBranch";
    static constexpr const char* fProbabilityPlotName = "probability_vs_N";
    static constexpr const char* fProbabilityTeoPlotName = "probability_vs_N_teo";
    static constexpr const char* fNPlotName = "Naltered_vs_Nsent";
    static constexpr const char* fNDistrName = "N_distr";
    static constexpr const char* fUsefulPlotName = "useful_distr";
    static constexpr const char* fPdfperLenghtCom = "PdfperLenghtCom";
    static constexpr const char* fUsefulHistName = "NSameBase_vs_Nsent";


    void SetStylesAndDraw(TObject *hist, const char *xLabel, const char *ylabel, Color_t color, Width_t linewidth) const;

    static Simulator* fgSimulator;                  // global pointer
};


#endif //BB84_SIMULATION_SIMULATOR_H
