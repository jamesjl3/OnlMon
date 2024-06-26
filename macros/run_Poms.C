// Phenix Online Monitoring System
//
// Macro loader for starting Online Monitoring GUI Framework
//
// Author:  Cody McCain (mcm99c@acu.edu)
// Date:    January 2, 2003
//
// See run_Poms.C.README

#include <onlmon/Poms.h>

// cppcheck-suppress unknownMacro
R__LOAD_LIBRARY(libpoms.so)

void StartPoms()
{
  PomsMainFrame *pmf;
  pmf = PomsMainFrame::Instance();

  // Register SubSystems
  //  pmf->RegisterSubSystem("EXAMPLE", "example");
  SubSystem *subsys = nullptr;

  subsys = new SubSystem("MBD", "bbc");
  subsys->AddAction("bbcDraw(\"FIRST\")", "MBD Vertex Monitor");
  subsys->AddAction("bbcDraw(\"SECOND\")", "MBD Timing Monitor");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("CEMC", "cemc");
  subsys->AddAction("cemcDraw(\"FIRST\")", "Towers");
  subsys->AddAction("cemcDraw(\"SECOND\")", "Packet Health");
  subsys->AddAction("cemcDraw(\"THIRD\")", "Wave Forms");
  subsys->AddAction("cemcDraw(\"FOURTH\")", "Wave vs Fast Fitting");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("DAQ", "daq");
  subsys->AddAction("daqDraw(\"FIRST\")", "Calo-GL1 Check");
  subsys->AddAction("daqDraw(\"SECOND\")", "Calo-GL1 Snapshot");
  // subsys->AddAction("daqDraw(\"HISTORY\")", "DAQ History Monitor");
   subsys->AddAction(new SubSystemActionSavePlot(subsys));
   pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("Inner HCAL", "ihcal");
  subsys->AddAction("ihcalDraw(\"FIRST\")", "Towers");
  subsys->AddAction("ihcalDraw(\"SECOND\")", "Sector Average [Expert]");
  subsys->AddAction("ihcalDraw(\"THIRD\")", "Wave Form");
  subsys->AddAction("ihcalDraw(\"FOURTH\")", "Packet Health [Expert]");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("Outer HCAL", "ohcal");
  subsys->AddAction("ohcalDraw(\"FIRST\")", "Towers");
  subsys->AddAction("ohcalDraw(\"SECOND\")", "Sector Average [Expert]");
  subsys->AddAction("ohcalDraw(\"THIRD\")", "Wave Form");
  subsys->AddAction("ohcalDraw(\"FOURTH\")", "Packet Health [Expert]");
  subsys->AddAction("ohcalDraw(\"FIFTH\")", "Trigger [Expert]");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("INTT", "intt");
  subsys->AddAction("inttDraw(\"chip_hitmap\")", "Chip Hitmap");
  subsys->AddAction("inttDraw(\"ladder_hitmap\")", "Ladder Hitmap");
  subsys->AddAction("inttDraw(\"chip_nll\")", "Chip NLL");
  subsys->AddAction("inttDraw(\"bco_diff\")", "BCO Diff");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("Local Level 1", "ll1");
  subsys->AddAction("ll1Draw(\"FIRST\")", "Hits");
  subsys->AddAction("ll1Draw(\"SECOND\")", "Hits Correlation");
  subsys->AddAction("ll1Draw(\"THIRD\")", "Hits Lineup");
  subsys->AddAction("ll1Draw(\"FOURTH\")", "EMCAL LL1 - Photon");
  subsys->AddAction("ll1Draw(\"FIFTH\")", "Jet Input - HCAL");
  subsys->AddAction("ll1Draw(\"SIXTH\")", "Jet LL1");
  subsys->AddAction("ll1Draw(\"SEVENTH\")", "EMCAL 2x2 Sums");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("MVTX", "mvtx");
  subsys->AddAction("mvtxDraw(\"GENERAL\")", "General Monitor");
  subsys->AddAction("mvtxDraw(\"FEE\")", "FEE");
  subsys->AddAction("mvtxDraw(\"FHR\")", "FHR");
  subsys->AddAction("mvtxDraw(\"OCC\")", "OCC");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("SEPD", "sepd");
  subsys->AddAction("sepdDraw(\"FIRST\")", "Average ADC vs Tile (Wheel Plot)");
  subsys->AddAction("sepdDraw(\"SECOND\")", "ADC distributions");
  subsys->AddAction("sepdDraw(\"THIRD\")", "North vs South Correlations");
  subsys->AddAction("sepdDraw(\"FOURTH\")", "Wave Forms");
  subsys->AddAction("sepdDraw(\"FIFTH\")", "Packet Status");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("SPIN", "spin");
  subsys->AddAction("spinDraw(\"FIRST\")", "Spin");
  subsys->AddAction("spinDraw(\"SECOND\")", "GL1p");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("TPC", "tpc");
  subsys->AddAction("tpcDraw(\"TPCMODULE\")", "TPC SUM[ADC]");
  subsys->AddAction("tpcDraw(\"TPCSAMPLESIZE\")", "TPC Sample Size");
  subsys->AddAction("tpcDraw(\"TPCCHECKSUMERROR\")", "TPC Checksum Error Prob.");
  subsys->AddAction("tpcDraw(\"TPCADCVSSAMPLE\")", "TPC ADC vs. Sample");
  subsys->AddAction("tpcDraw(\"TPCADCVSSAMPLELARGE\")", "TPC ADC vs. Large Sample");
  subsys->AddAction("tpcDraw(\"TPCMAXADCMODULE\")", "TPC MAX10ADC-Pedestal 1D");
  subsys->AddAction("tpcDraw(\"TPCRAWADC1D\")", "TPC RAW ADC 1D");
  subsys->AddAction("tpcDraw(\"TPCPEDESTSUBADC1D\")", "TPC RAWADC-Pedestal 1D");
  subsys->AddAction("tpcDraw(\"TPCMAXADC1D\")", "TPC (WindowMAX-Pedestal) ADC 1D");
  subsys->AddAction("tpcDraw(\"TPCCLUSTERSXYWEIGTHED\")", "TPC Cluster XY MaxADC-Pedestal,w");
  subsys->AddAction("tpcDraw(\"TPCCLUSTERSXYUNWEIGTHED\")", "TPC Cluster XY MaxADC-Pedestal,u");
  subsys->AddAction("tpcDraw(\"TPCCLUSTERSZYWEIGTHED\")", "TPC Cluster ZY MaxADC-Pedestal,w");
  subsys->AddAction("tpcDraw(\"TPCCLUSTERSZYUNWEIGTHED\")", "TPC Cluster ZY MaxADC-Pedestal,u");
  subsys->AddAction("tpcDraw(\"TPCLASERCLUSTERSXYWEIGTHED\")", "TPC DIFF. LASER Cluster XY MaxADC-Pedestal,w");
  subsys->AddAction("tpcDraw(\"TPCCHANNELPHI_LAYER_WEIGHTED\")", "TPC ChannelPhi vs Layer vs Pedest Sub. ADC,w");
  subsys->AddAction("tpcDraw(\"TPCNEVENTSEBDC\")", "TPC NEvents vs EBDC");
  subsys->AddAction("tpcDraw(\"TPCPEDESTSUBADCVSSAMPLE\")", "TPC Pedest Sub. ADC vs Sample");
  subsys->AddAction("tpcDraw(\"TPCPEDESTSUBADCVSSAMPLE_R1\")", "TPC Pedest Sub. ADC vs Sample R1 ONLY");
  subsys->AddAction("tpcDraw(\"TPCPEDESTSUBADCVSSAMPLE_R2\")", "TPC Pedest Sub. ADC vs Sample R2 ONLY");
  subsys->AddAction("tpcDraw(\"TPCPEDESTSUBADCVSSAMPLE_R3\")", "TPC Pedest Sub. ADC vs Sample R3 ONLY");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("TPOT", "tpot");
  subsys->AddAction("tpotDraw(\"TPOT_counters\")", "Event counters");
  subsys->AddAction("tpotDraw(\"TPOT_detector_occupancy\")", "Detector Occupancy");
  subsys->AddAction("tpotDraw(\"TPOT_resist_occupancy\")", "Resist Occupnacy");
  subsys->AddAction("tpotDraw(\"TPOT_adc_vs_sample\")", "ADC vs Sample");
  subsys->AddAction("tpotDraw(\"TPOT_adc_vs_channel\")", "ADC vs Strip");
  subsys->AddAction("tpotDraw(\"TPOT_counts_vs_sample\")", "Counts vs Sample");
  subsys->AddAction("tpotDraw(\"TPOT_hit_charge\")", "Hit Charge");
  subsys->AddAction("tpotDraw(\"TPOT_hit_multiplicity\")", "Hit Multiplicity");
  subsys->AddAction("tpotDraw(\"TPOT_hit_vs_channel\")", "Hit vs Strip");
  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  subsys = new SubSystem("ZDC/SMD", "zdc");
  subsys->AddAction("zdcDraw(\"FIRST\")", "ZDC 1st Monitor");
  subsys->AddAction("zdcDraw(\"SECOND\")", "ZDC 2nd Monitor");
  subsys->AddAction("zdcDraw(\"ZDC_WAVEFORM\")", "ZDC Wave form");
  subsys->AddAction("zdcDraw(\"SMDVALUES\")", "SMD Values");
  subsys->AddAction("zdcDraw(\"SMDN&S\")", "SMD North South");
  subsys->AddAction("zdcDraw(\"SMD_N_IND\")", "SMD North Individual");
  subsys->AddAction("zdcDraw(\"SMD_S_IND\")", "SMD South Individual");
  subsys->AddAction("zdcDraw(\"SMD_MULTIPLICITIES\")", "SMD Multiplicities");

  subsys->AddAction(new SubSystemActionSavePlot(subsys));
  pmf->RegisterSubSystem(subsys);

  pmf->Draw();
}

void listCanvases()
{
  TSeqCollection* allCanvases = gROOT->GetListOfCanvases();
  for (int i = 0; i<allCanvases->GetEntries(); i++)
    {
      cout << allCanvases->At(i)->GetName() << endl;
    }
}
