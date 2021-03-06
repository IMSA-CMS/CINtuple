import os,sys
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing('analysis')
#options.register('sampleType',
#                '',
#                VarParsing.multiplicity.singleton,
#                VarParsing.varType.string,
#                "Type of sample.")
#
#options.register('runCrab',
#                '',
#                VarParsing.multiplicity.singleton,
#                VarParsing.varType.bool,
#                "are we running a crab job.")
#options.register('debug',
#                '',
#                VarParsing.multiplicity.singleton,
#                VarParsing.varType.bool,
#                "add debugging.")
#
#options.parseArguments()
#if options.debug:
#    print("sampleType",options.sampleType)
#    print("runCrab",options.runCrab)
# set up process
process = cms.Process("HEEP")
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout.threshold = cms.untracked.string('WARNING')
process.MessageLogger.cerr.FwkReport = cms.untracked.PSet(
    reportEvery = cms.untracked.int32(500),
    limit = cms.untracked.int32(10000),
)
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
#Track isolation correction
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
#setup global tag
# Global tag (MC)
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_mcRun2_asymptotic_2016_TrancheIV_v6', '')


# Global tag (data)
#from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v7', '')

#from ZprimeDiLeptons.Analyzer.wsuciutils.cisamples import cisamples
#massBins = ["M300","M800","M1300","M2000"]
#sample = options.sampleType.split('_')
## bad, self "organized" samples
#if sample[0] == "MiniAod" or sample[0] == "crabConfig":
#    # prakash's samples format:
#    # MiniAod_CIToMuMu_M1300_L100K_LR_Con_Aug15
#    # OR
#    # crabConfig_MiniAod_CIToMuMu_M1300_L100K_LR_Con_Aug15
#    try:
#        sample.remove("crabConfig")
#    except ValueError as e:
#        pass
#    newsample = []
#    newsample.append("CITo2Mu") # 0
#    newsample.append(sample[2]) # 1
#    newsample.append("CUETP8M1") # 2
#    newsample.append("Lam%sTeV%s%s"%(sample[3][1:].lower(),sample[5],sample[4])) # 3
#    sample = newsample
#    pass
#elif sample[0] == "Dielectron":
#    # peter's samples format:
#    # Dielectron_100000000TeV_miniAOD_M300_RR_Des
#    newsample = []
#    newsample.append("CITo2E") # 0
#    newsample.append(sample[3]) # 1
#    newsample.append("CUETP8M1") # 2
#    newsample.append("Lam100kTeV%s%s"%(sample[5],sample[4])) # 3
#    sample = newsample
#    pass
#elif sample[0] == "MuMu":
#    # Shawn's samples format
#    # MuMu_miniAODSIM_LRDesM1300_Use
#    newsample = []
#    newsample.append("CITo2Mu") # 0
#    newsample.append(sample[2][5:]) # 1
#    newsample.append("CUETP8M1") # 2
#    newsample.append("Lam10TeV%s%s"%(sample[2][2:5],sample[2][0:2])) # 3
#    sample = newsample
#    pass
#elif sample[0] == "EE":
#    # Shawn's samples format
#    # EE_miniAODSIM_LRDesM1300_remade
#    newsample = []
#    newsample.append("CITo2E") # 0
#    newsample.append(sample[2][5:]) # 1
#    newsample.append("CUETP8M1") # 2
#    newsample.append("Lam10TeV%s%s"%(sample[2][2:5],sample[2][0:2])) # 3
#    sample = newsample
#    pass
#
## normal good samples format:
## CITo2E_M300_CUETP8M1_Lam34TeVConLL_13TeV_Pythia8_Corrected
#if not "ConLL" in sample[3]:
#    massBins = massBins[:-1]
#lowerCut = sample[1][1:]
#upperCut = 1e10
#try:
#    val = cms.double(lowerCut)
#except:
#    lowerCut = 0
#
#for i,b in enumerate(massBins):
#    if lowerCut == b[1:] and i != (len(massBins)-1):
#        upperCut = massBins[i+1][1:]
#        continue
#
#weight = 1
### for using the pickled sample information
## import cPickle as pickle
## from ZprimeDiLeptons.Analyzer.wsuciutils.xsec-tools.nesteddict import nesteddict
## with open("%s/src/ZprimeDiLeptons/Analyzer/python/ci_xsec_data.pkl"%(os.getenv("CMSSW_BASE")),"rb") as pkl:
##     sdict = pickle.load(pkl)
### for using the json formatted sample information
#
#import json
#with open("%s/src/ZprimeDiLeptons/Analyzer/python/wsuciutils/xsec-tools/data/ci_xsec_data.json"%(os.getenv("CMSSW_BASE")),"rb") as jsn:
#    sdict = json.load(jsn)
#    # pickle dict is:
#    #  DY samples:
#    #     d[sample]["M%d"%(mass)]
#    #  CI samples:
#    #     d[sample]["Lam%s"%(lval)][infm][heli]["M%s"%(mass)]
#    # Data is structured as:
#    #{
#    #  'minCut': minCut,
#    #  'xsec': [xs_val, xs_err, xs_unit],
#    #  'maxCut': maxCut,
#    #  'cutEfficiency': [n_pass, n_fail]
#    #}
#    # sample = options.sampleType.split('_')
#    if "DY" in sample[0]:
#        print(sample)
#        mass   = sample[1][1:]
#        xsdict = sdict[sample[0]]["M%s"%(mass)]
#        if not options.runCrab:
#            infiles = cisamples[sample[0]]["M{}".format(mass)] ## this should be com
#        outfile = '{}_M{}_MC_ntuple.root'.format(sample[0],mass)
#    elif "CI" in sample[0]:
#        special = sample[3].split("TeV")
#        lval   = special[0]
#        infm   = special[1][:-2]
#        heli   = special[1][-2:]
#        mass   = sample[1][1:]
#        if options.debug:
#            print(sdict[sample[0]].keys())
#            print(sdict[sample[0]]["%s"%(lval)].keys())
#        xsdict = sdict[sample[0]]["%s"%(lval)][infm][heli]["M%s"%(mass)]
#        print(sample[0],"%s"%(lval),infm,heli,"M%s"%(mass))
#
#        if not options.runCrab:
#            if options.debug:
#                print(cisamples[sample[0]].keys())
#                print(cisamples[sample[0]]["%s"%(lval)].keys())
#            infiles = cisamples[sample[0]][lval][infm][heli]["M{}".format(mass)]
#        outfile = '{}_M{}_{}{}_MC_ntuple.root'.format(lval,mass,infm,heli)
#    if xsdict:
#        weight = xsdict["xsec"][0]
#    else:
#        weight = 1.
#        infiles = None
#        outfile = '{}_MC_ntuple.root'.format(options.sampleType)
#    pass
#print(outfile)
#print(weight)
#
#if options.runCrab:
#    infiles = []
#
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

#Load info from the text file 
sourceFiles = FileUtils.loadListFromFile('root_MINIAOD_M300.txt')#JOHN  TURN THIS ONE BACK ON 
#sourceFiles = FileUtils.loadListFromFile('fileQueryTestMuM300L16ConLL.txt') #THIS IS THE ROOT XD 
for line in sourceFiles:
    print(line)

sourceList = ['file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/' + line for line in sourceFiles]#JOHN TURN THIS ONE BACK ON
#sourceList = ['root://cmsxrootd.fnal.gov//' + line for line in sourceFiles]  #THIS IS ALSO ROOT XD 
#for line in sourceList:
#    print(line)

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(*sourceList))

#for running on crab 
#process.source = cms.Source("PoolSource", fileNames = 'file:file.root')

#process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring('root://cmsxrootd.fnal.gov///store/mc/RunIISummer16MiniAODv2/CITo2E_M1300_CUETP8M1_Lam10TeVConLL_13TeV-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/50000/B82FCB94-1ED9-E611-8A29-24BE05CEDC81.root'))#on one file 



#KLUDGE for now
lowerCut = 0.0
upperCut = 5000
sample = ['CITo2Mu']
weight = 1
outfile = "test.root"

#we setup the HEEP ID V7.0 and enable VID via the following function
#and then add it to a new collection of pat::Electrons
#there is the option to call the new collection "slimmedElectrons" (useStdName=True)
#otherwise it calls them "heepElectrons"
#it creates a sequence "process.heepSequence" which we add to our path
from WSUDiLeptons.GenLevelFilter.genLevelFilter_cfi import genLevelFilter
process.genweightfilter = genLevelFilter.clone(
    filterevent   = cms.bool(False),
    filterPreFSR  = cms.bool(False),
    filterST1     = cms.bool(False),
    filterST23    = cms.bool(False),
    filterHS      = cms.bool(False),
    debug         = cms.bool(False),
    minCut        = cms.double(lowerCut),
    sampleType    = cms.string(sample[0]),
    maxCut        = cms.double(upperCut),
    xsWeight      = cms.double(weight),
)

from HEEP.VID.tools import addHEEPV70ElesMiniAOD
addHEEPV70ElesMiniAOD(process,useStdName=True)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string(outfile)
)

#this is our example analysis module reading the results, you will have your own module
process.heepIdExample = cms.EDAnalyzer("MakeZprimeMiniAodTreeMC",
    eles=cms.InputTag("slimmedElectrons"),
    passMInvCutTag       = cms.InputTag("genweightfilter","passMassCut"),
    passPreFSRMInvCutTag = cms.InputTag("genweightfilter","passPreFSRMassCut"),
    passST1MInvCutTag    = cms.InputTag("genweightfilter","passST1MassCut"),
    passST23MInvCutTag   = cms.InputTag("genweightfilter","passST23MassCut"),
    passHSMInvCutTag =    cms.InputTag("genweightfilter","passHSMassCut"),
    xsWeightTag          = cms.InputTag("genweightfilter","xsWeight"),
    scProducer = cms.InputTag("reducedEgamma:reducedSuperClusters"),
    vertices   = cms.InputTag("offlineSlimmedPrimaryVertices"),
    muons      = cms.InputTag("slimmedMuons"),
    electrons  = cms.InputTag("slimmedElectrons"),
    taus       = cms.InputTag("slimmedTaus"),
    photons    = cms.InputTag("slimmedPhotons"),
    #jets       = cms.InputTag("slimmedJetsCMSTopTagCHSPacked:SubJets"),
    jets       = cms.InputTag("slimmedJets"),
    #jets        = cms.InputTag("slimmedJetsPuppi"),
    mets       = cms.InputTag("slimmedMETs"),
    #mets       = cms.InputTag("slimmedMETsNoHF"),
    packed     = cms.InputTag("packedGenParticles"),
    pruned     = cms.InputTag("prunedGenParticles"),
    pfCands    = cms.InputTag("packedPFCandidates"),
    rhoIsoInputTag          = cms.InputTag("fixedGridRhoFastjetCentralChargedPileUp"),
    EBrecHitCollectionLabel = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    EErecHitCollectionLabel = cms.InputTag("reducedEgamma","reducedEERecHits"),
    ecalRechitEB            = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    ecalRechitEE            = cms.InputTag("reducedEgamma","reducedEERecHits"),
    JetSource               = cms.InputTag('slimmedGenJets'),
    PileupSrc               = cms.InputTag("slimmedAddPileupInfo"),
    #METSignificance        = cms.InputTag("METSignificance","METSignificance"),
    #generalTracksLabel      = cms.InputTag("generalTracks"),
    bits           = cms.InputTag("TriggerResults","","HLT"),
    prescales      = cms.InputTag("patTrigger"),
    objects        = cms.InputTag("selectedPatTrigger"),
    GenBosonID     = cms.int32(1000000),
    ParticleID1    = cms.int32(13),
    ParticleID2    = cms.int32(11),
    ParticleID3    = cms.int32(15),
    ParticleStatus = cms.int32(25),
    maxAbsZ  = cms.double(24),
    maxd0    = cms.double(2),
    minndof  = cms.int32(4),
    NbGoodPv = cms.int32(1),
    bDiscriminators = cms.vstring(      # list of b-tag discriminators to access
        #'pfTrackCountingHighEffBJetTags',
        #'pfTtrackCountingHighPurBJetTags',
        #'pfJetProbabilityBJetTags',
        #'pfJetBProbabilityBJetTags',
        #'pfSimpleSecondaryVertexHighEffBJetTags',
        #'pfSimpleSecondaryVertexHighPurBJetTags',
        #'pfCombinedSecondaryVertexV2BJetTags',
        'pfCombinedInclusiveSecondaryVertexV2BJetTags'
        #'pfCombinedMVABJetTags'
    ),

    outputFile = cms.string(outfile),

    isLRHelicity = cms.bool(False), 
    lambda_ = cms.int32(16000)                                   
        
    )

process.p = cms.Path(
    process.genweightfilter+
    (process.heepSequence*
    process.heepIdExample)) #our analysing example module, replace with your module

