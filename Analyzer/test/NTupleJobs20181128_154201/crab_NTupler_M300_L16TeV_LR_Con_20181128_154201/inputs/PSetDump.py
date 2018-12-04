import FWCore.ParameterSet.Config as cms

process = cms.Process("HEEP")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_1.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_10.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_100.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_11.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_12.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_13.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_14.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_15.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_16.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_17.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_18.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_19.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_2.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_20.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_21.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_22.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_23.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_24.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_25.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_26.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_27.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_28.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_29.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_3.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_30.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_31.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_32.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_33.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_34.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_35.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_36.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_37.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_38.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_39.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_4.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_40.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_41.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_42.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_43.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_44.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_45.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_46.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_47.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_48.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_49.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_5.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_50.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_51.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_52.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_53.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_54.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_55.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_56.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_57.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_58.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_59.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_6.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_60.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_61.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_62.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_63.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_64.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_65.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_66.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_67.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_68.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_69.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_7.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_70.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_71.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_72.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_73.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_74.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_75.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_76.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_77.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_78.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_79.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_8.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_80.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_81.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_82.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_83.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_84.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_85.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_86.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_87.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_88.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_89.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_9.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_90.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_91.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_92.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_93.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_94.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_95.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_96.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_97.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_98.root', 
        'file:/uscms/physics_grp/lpcci2dileptons/nobackup/CI_study/Samples/Lambda_16TeV/CITo2Mu/LLCon/M300/step_MINIAODSIM_bumpHunt_99.root')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1200)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_producer_config = cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.253, 0.081, -0.081, 0.965, 0.917, 
            0.683),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.483, -0.267, -0.323, 0.933, 0.825, 
            0.337),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_Spring15_25ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.988153, 0.96791, 0.841729),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.972153, 0.922126, 0.610764),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.287435, 0.221846, -0.303263, 0.967083, 0.929117, 
            0.726311),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.083313, -0.235222, -0.67099, 0.913286, 0.805013, 
            0.358969),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wpLoose = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.265, -0.556, -0.551, -0.072, -0.286, 
            -0.267),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wpLoose'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_50ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('50nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.981841, 0.946762, 0.79704),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.953843, 0.849994, 0.514118),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring16_GeneralPurpose_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring16GeneralPurpose'),
    mvaTag = cms.string('V1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB1_10.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB2_10.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EE_10.weights.xml')
)

process.mvaEleID_Spring16_GeneralPurpose_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Categories"),
        mvaCuts = cms.vdouble(0.940962684155, 0.899208843708, 0.758484721184),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring16-GeneralPurpose-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring16_GeneralPurpose_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Categories"),
        mvaCuts = cms.vdouble(0.836695742607, 0.715337944031, 0.356799721718),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring16-GeneralPurpose-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring16_HZZ_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring16HZZ'),
    mvaTag = cms.string('V1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_5.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_5.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_5.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_10.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_10.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_10.weights.xml')
)

process.mvaEleID_Spring16_HZZ_V1_wpLoose = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16HZZV1Categories"),
        mvaCuts = cms.vdouble(-0.211, -0.396, -0.215, -0.87, -0.838, 
            -0.763),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring16HZZV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring16-HZZ-V1-wpLoose'),
    isPOGApproved = cms.untracked.bool(True)
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)

process.heep_modifications = cms.VPSet(cms.PSet(
    electron_config = cms.PSet(
        electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
        trkPtIso = cms.InputTag("heepIDVarValueMaps","eleTrkPtIso")
    ),
    modifierName = cms.string('EGExtraInfoModifierFromFloatValueMaps'),
    photon_config = cms.PSet(

    )
), 
    cms.PSet(
        electron_config = cms.PSet(
            electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
            nrSatCrys = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5"),
            photon_config = cms.PSet(

            )
        ),
        modifierName = cms.string('EGExtraInfoModifierFromIntValueMaps')
    ), 
    cms.PSet(
        electron_config = cms.PSet(
            electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
            heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70"),
            photon_config = cms.PSet(

            )
        ),
        modifierName = cms.string('EGExtraInfoModifierFromBoolToIntValueMaps')
    ), 
    cms.PSet(
        electron_config = cms.PSet(
            electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
            heepElectronID_HEEPV70Bitmap = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70Bitmap"),
            photon_config = cms.PSet(

            )
        ),
        modifierName = cms.string('EGExtraInfoModifierFromUIntToIntValueMaps')
    ), 
    cms.PSet(
        electron_config = cms.PSet(
            electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
            heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70")
        ),
        modifierName = cms.string('EGExtraInfoModifierFromVIDCutFlowResultValueMaps'),
        photon_config = cms.PSet(

        )
    ))

process.mvaConfigsForEleProducer = cms.VPSet(cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('50nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring16HZZ'),
        mvaTag = cms.string('V1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_5.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_5.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_5.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_10.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_10.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_10.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring16GeneralPurpose'),
        mvaTag = cms.string('V1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB1_10.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB2_10.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EE_10.weights.xml')
    ))

process.egmGsfElectronIDs = cms.EDProducer("VersionedGsfElectronIdProducer",
    physicsObjectIDs = cms.VPSet(cms.PSet(
        idDefinition = cms.PSet(
            cutFlow = cms.VPSet(cms.PSet(
                cutName = cms.string('MinPtCut'),
                isIgnored = cms.bool(False),
                minPt = cms.double(35.0),
                needsAdditionalProducts = cms.bool(False)
            ), 
                cms.PSet(
                    allowedEtaRanges = cms.VPSet(cms.PSet(
                        maxEta = cms.double(1.4442),
                        minEta = cms.double(0.0)
                    ), 
                        cms.PSet(
                            maxEta = cms.double(2.5),
                            minEta = cms.double(1.566)
                        )),
                    cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    useAbsEta = cms.bool(True)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDEtaInSeedCut'),
                    dEtaInSeedCutValueEB = cms.double(0.004),
                    dEtaInSeedCutValueEE = cms.double(0.006),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDPhiInCut'),
                    dPhiInCutValueEB = cms.double(0.06),
                    dPhiInCutValueEE = cms.double(0.06),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaWithSatCut'),
                    isIgnored = cms.bool(False),
                    maxNrSatCrysIn5x5EB = cms.int32(0),
                    maxNrSatCrysIn5x5EE = cms.int32(0),
                    maxSigmaIEtaIEtaEB = cms.double(9999),
                    maxSigmaIEtaIEtaEE = cms.double(0.03),
                    needsAdditionalProducts = cms.bool(True),
                    nrSatCrysValueMap = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5")
                ), 
                cms.PSet(
                    cutName = cms.string('GsfEleFull5x5E2x5OverE5x5WithSatCut'),
                    isIgnored = cms.bool(False),
                    maxNrSatCrysIn5x5EB = cms.int32(0),
                    maxNrSatCrysIn5x5EE = cms.int32(0),
                    minE1x5OverE5x5EB = cms.double(0.83),
                    minE1x5OverE5x5EE = cms.double(-1.0),
                    minE2x5OverE5x5EB = cms.double(0.94),
                    minE2x5OverE5x5EE = cms.double(-1.0),
                    needsAdditionalProducts = cms.bool(True),
                    nrSatCrysValueMap = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5")
                ), 
                cms.PSet(
                    constTermEB = cms.double(1.0),
                    constTermEE = cms.double(5),
                    cutName = cms.string('GsfEleHadronicOverEMLinearCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(0.0),
                    slopeTermEB = cms.double(0.05),
                    slopeTermEE = cms.double(0.05)
                ), 
                cms.PSet(
                    constTermEB = cms.double(5.0),
                    constTermEE = cms.double(5.0),
                    cutName = cms.string('GsfEleValueMapIsoRhoCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    rho = cms.InputTag(""),
                    rhoEAEB = cms.double(0.0),
                    rhoEAEE = cms.double(0.0),
                    rhoEtStartEB = cms.double(999999.0),
                    rhoEtStartEE = cms.double(999999.0),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(0.0),
                    slopeTermEB = cms.double(0.0),
                    slopeTermEE = cms.double(0.0),
                    value = cms.InputTag("heepIDVarValueMaps","eleTrkPtIso")
                ), 
                cms.PSet(
                    constTermEB = cms.double(2.0),
                    constTermEE = cms.double(2.5),
                    cutName = cms.string('GsfEleEmHadD1IsoRhoCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    rho = cms.InputTag("fixedGridRhoFastjetAll"),
                    rhoConstant = cms.double(0.28),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(50.0),
                    slopeTermEB = cms.double(0.03),
                    slopeTermEE = cms.double(0.03)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDxyCut'),
                    dxyCutValueEB = cms.double(0.02),
                    dxyCutValueEE = cms.double(0.05),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                    vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleMissingHitsCut'),
                    isIgnored = cms.bool(False),
                    maxMissingHitsEB = cms.uint32(1),
                    maxMissingHitsEE = cms.uint32(1),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleEcalDrivenCut'),
                    ecalDrivenEB = cms.int32(1),
                    ecalDrivenEE = cms.int32(1),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                )),
            idName = cms.string('heepElectronID-HEEPV70')
        ),
        idMD5 = cms.string('45d49ea5f46f3f13f579d208e5e3412b'),
        isPOGApproved = cms.untracked.bool(True)
    )),
    physicsObjectSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.electronMVAValueMapProducer = cms.EDProducer("ElectronMVAValueMapProducer",
    mvaConfigurations = cms.VPSet(cms.PSet(
        mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
    ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('50nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring16HZZ'),
            mvaTag = cms.string('V1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_5.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_5.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_5.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB1_10.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EB2_10.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_HZZ_V1/electronID_mva_Spring16_HZZ_V1_EE_10.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring16GeneralPurpose'),
            mvaTag = cms.string('V1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB1_10.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EB2_10.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring16_GeneralPurpose_V1/electronID_mva_Spring16_GeneralPurpose_V1_EE_10.weights.xml')
        )),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.electronRegressionValueMapProducer = cms.EDProducer("ElectronRegressionValueMapProducer",
    ebReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
    ebReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    eeReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
    eeReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
    esReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsES"),
    esReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedESRecHits"),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
    useFull5x5 = cms.bool(False)
)


process.heepElectrons = cms.EDProducer("ModifiedElectronProducer",
    modifierConfig = cms.PSet(
        modifications = cms.VPSet(cms.PSet(
            electron_config = cms.PSet(
                electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                trkPtIso = cms.InputTag("heepIDVarValueMaps","eleTrkPtIso")
            ),
            modifierName = cms.string('EGExtraInfoModifierFromFloatValueMaps'),
            photon_config = cms.PSet(

            )
        ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    nrSatCrys = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromBoolToIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70Bitmap = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70Bitmap"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromUIntToIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70")
                ),
                modifierName = cms.string('EGExtraInfoModifierFromVIDCutFlowResultValueMaps'),
                photon_config = cms.PSet(

                )
            ))
    ),
    src = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.heepIDVarValueMaps = cms.EDProducer("ElectronHEEPIDValueMapProducer",
    beamSpot = cms.InputTag("offlineBeamSpot"),
    candsAOD = cms.VInputTag("packedCandsForTkIso", "lostTracksForTkIso"),
    candsMiniAOD = cms.VInputTag("packedPFCandidates", "lostTracks"),
    dataFormat = cms.int32(0),
    ebRecHitsAOD = cms.InputTag("reducedEcalRecHitsEB"),
    ebRecHitsMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    eeRecHitsAOD = cms.InputTag("reducedEcalRecHitsEB"),
    eeRecHitsMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
    elesAOD = cms.InputTag("gedGsfElectrons"),
    elesMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
    trkIsoConfig = cms.PSet(
        barrelCuts = cms.PSet(
            algosToReject = cms.vstring(),
            allowedQualities = cms.vstring(),
            maxDPtPt = cms.double(0.1),
            maxDR = cms.double(0.3),
            maxDZ = cms.double(0.1),
            minDEta = cms.double(0.005),
            minDR = cms.double(0.0),
            minHits = cms.int32(8),
            minPixelHits = cms.int32(1),
            minPt = cms.double(1.0)
        ),
        endcapCuts = cms.PSet(
            algosToReject = cms.vstring(),
            allowedQualities = cms.vstring(),
            maxDPtPt = cms.double(0.1),
            maxDR = cms.double(0.3),
            maxDZ = cms.double(0.5),
            minDEta = cms.double(0.005),
            minDR = cms.double(0.0),
            minHits = cms.int32(8),
            minPixelHits = cms.int32(1),
            minPt = cms.double(1.0)
        )
    )
)


process.modifiedElectrons = cms.EDProducer("ModifiedElectronProducer",
    modifierConfig = cms.PSet(
        modifications = cms.VPSet()
    ),
    src = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.slimmedElectrons = cms.EDProducer("ModifiedElectronProducer",
    modifierConfig = cms.PSet(
        modifications = cms.VPSet(cms.PSet(
            electron_config = cms.PSet(
                electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                trkPtIso = cms.InputTag("heepIDVarValueMaps","eleTrkPtIso")
            ),
            modifierName = cms.string('EGExtraInfoModifierFromFloatValueMaps'),
            photon_config = cms.PSet(

            )
        ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    nrSatCrys = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromBoolToIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70Bitmap = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70Bitmap"),
                    photon_config = cms.PSet(

                    )
                ),
                modifierName = cms.string('EGExtraInfoModifierFromUIntToIntValueMaps')
            ), 
            cms.PSet(
                electron_config = cms.PSet(
                    electronSrc = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
                    heepElectronID_HEEPV70 = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV70")
                ),
                modifierName = cms.string('EGExtraInfoModifierFromVIDCutFlowResultValueMaps'),
                photon_config = cms.PSet(

                )
            ))
    ),
    src = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.genweightfilter = cms.EDFilter("GenLevelFilter",
    debug = cms.bool(False),
    filterHS = cms.bool(False),
    filterPreFSR = cms.bool(False),
    filterST1 = cms.bool(False),
    filterST23 = cms.bool(False),
    filterevent = cms.bool(False),
    genParticleSource = cms.InputTag("prunedGenParticles"),
    maxCut = cms.double(5000),
    minCut = cms.double(0.0),
    sampleType = cms.string('CITo2Mu'),
    xsWeight = cms.double(1)
)


process.heepIdExample = cms.EDAnalyzer("MakeZprimeMiniAodTreeMC",
    EBrecHitCollectionLabel = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    EErecHitCollectionLabel = cms.InputTag("reducedEgamma","reducedEERecHits"),
    GenBosonID = cms.int32(1000000),
    JetSource = cms.InputTag("slimmedGenJets"),
    NbGoodPv = cms.int32(1),
    ParticleID1 = cms.int32(13),
    ParticleID2 = cms.int32(11),
    ParticleID3 = cms.int32(15),
    ParticleStatus = cms.int32(25),
    PileupSrc = cms.InputTag("slimmedAddPileupInfo"),
    bDiscriminators = cms.vstring('pfCombinedInclusiveSecondaryVertexV2BJetTags'),
    bits = cms.InputTag("TriggerResults","","HLT"),
    ecalRechitEB = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    ecalRechitEE = cms.InputTag("reducedEgamma","reducedEERecHits"),
    electrons = cms.InputTag("slimmedElectrons"),
    eles = cms.InputTag("slimmedElectrons"),
    isLRHelicity = cms.bool(False),
    jets = cms.InputTag("slimmedJets"),
    lambda_ = cms.int32(16000),
    maxAbsZ = cms.double(24),
    maxd0 = cms.double(2),
    mets = cms.InputTag("slimmedMETs"),
    minndof = cms.int32(4),
    muons = cms.InputTag("slimmedMuons"),
    objects = cms.InputTag("selectedPatTrigger"),
    outputFile = cms.string('test.root'),
    packed = cms.InputTag("packedGenParticles"),
    passHSMInvCutTag = cms.InputTag("genweightfilter","passHSMassCut"),
    passMInvCutTag = cms.InputTag("genweightfilter","passMassCut"),
    passPreFSRMInvCutTag = cms.InputTag("genweightfilter","passPreFSRMassCut"),
    passST1MInvCutTag = cms.InputTag("genweightfilter","passST1MassCut"),
    passST23MInvCutTag = cms.InputTag("genweightfilter","passST23MassCut"),
    pfCands = cms.InputTag("packedPFCandidates"),
    photons = cms.InputTag("slimmedPhotons"),
    prescales = cms.InputTag("patTrigger"),
    pruned = cms.InputTag("prunedGenParticles"),
    rhoIsoInputTag = cms.InputTag("fixedGridRhoFastjetCentralChargedPileUp"),
    scProducer = cms.InputTag("reducedEgamma","reducedSuperClusters"),
    taus = cms.InputTag("slimmedTaus"),
    vertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
    xsWeightTag = cms.InputTag("genweightfilter","xsWeight")
)


process.egmGsfElectronIDSequence = cms.Sequence(process.electronMVAValueMapProducer+process.heepIDVarValueMaps+process.egmGsfElectronIDs+process.electronRegressionValueMapProducer)


process.addHEEPToHEEPElectrons = cms.Sequence(process.heepElectrons)


process.addHEEPToSlimmedElectrons = cms.Sequence(process.slimmedElectrons)


process.heepSequence = cms.Sequence(process.egmGsfElectronIDSequence+process.addHEEPToSlimmedElectrons)


process.p = cms.Path(process.genweightfilter+process.heepSequence+process.heepIdExample)


process.MessageLogger = cms.Service("MessageLogger",
    FrameworkJobReport = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        optionalPSet = cms.untracked.bool(True)
    ),
    categories = cms.untracked.vstring('FwkJob', 
        'FwkReport', 
        'FwkSummary', 
        'Root_NoDictionary'),
    cerr = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        FwkReport = cms.untracked.PSet(
            limit = cms.untracked.int32(10000),
            reportEvery = cms.untracked.int32(500)
        ),
        FwkSummary = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1)
        ),
        INFO = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000)
        ),
        noTimeStamps = cms.untracked.bool(False),
        optionalPSet = cms.untracked.bool(True),
        threshold = cms.untracked.string('INFO')
    ),
    cerr_stats = cms.untracked.PSet(
        optionalPSet = cms.untracked.bool(True),
        output = cms.untracked.string('cerr'),
        threshold = cms.untracked.string('WARNING')
    ),
    cout = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True),
        threshold = cms.untracked.string('WARNING')
    ),
    debugModules = cms.untracked.vstring(),
    debugs = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    default = cms.untracked.PSet(

    ),
    destinations = cms.untracked.vstring('warnings', 
        'errors', 
        'infos', 
        'debugs', 
        'cout', 
        'cerr'),
    errors = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    fwkJobReports = cms.untracked.vstring('FrameworkJobReport'),
    infos = cms.untracked.PSet(
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        optionalPSet = cms.untracked.bool(True),
        placeholder = cms.untracked.bool(True)
    ),
    statistics = cms.untracked.vstring('cerr_stats'),
    suppressDebug = cms.untracked.vstring(),
    suppressInfo = cms.untracked.vstring(),
    suppressWarning = cms.untracked.vstring(),
    warnings = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    )
)


process.TFileService = cms.Service("TFileService",
    fileName = cms.string('test.root')
)


process.CSCGeometryESModule = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.CaloGeometryBuilder = cms.ESProducer("CaloGeometryBuilder",
    SelectedCalos = cms.vstring('HCAL', 
        'ZDC', 
        'CASTOR', 
        'EcalBarrel', 
        'EcalEndcap', 
        'EcalPreshower', 
        'TOWER')
)


process.CaloTopologyBuilder = cms.ESProducer("CaloTopologyBuilder")


process.CaloTowerGeometryFromDBEP = cms.ESProducer("CaloTowerGeometryFromDBEP",
    applyAlignment = cms.bool(False),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.CaloTowerTopologyEP = cms.ESProducer("CaloTowerTopologyEP")


process.CastorDbProducer = cms.ESProducer("CastorDbProducer")


process.CastorGeometryFromDBEP = cms.ESProducer("CastorGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.DTGeometryESModule = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.EcalBarrelGeometryFromDBEP = cms.ESProducer("EcalBarrelGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalElectronicsMappingBuilder = cms.ESProducer("EcalElectronicsMappingBuilder")


process.EcalEndcapGeometryFromDBEP = cms.ESProducer("EcalEndcapGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalLaserCorrectionService = cms.ESProducer("EcalLaserCorrectionService")


process.EcalPreshowerGeometryFromDBEP = cms.ESProducer("EcalPreshowerGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalTrigTowerConstituentsMapBuilder = cms.ESProducer("EcalTrigTowerConstituentsMapBuilder",
    MapFile = cms.untracked.string('Geometry/EcalMapping/data/EndCap_TTMap.txt')
)


process.GlobalTrackingGeometryESProducer = cms.ESProducer("GlobalTrackingGeometryESProducer")


process.HcalAlignmentEP = cms.ESProducer("HcalAlignmentEP")


process.HcalGeometryFromDBEP = cms.ESProducer("HcalGeometryFromDBEP",
    applyAlignment = cms.bool(True),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.MuonDetLayerGeometryESProducer = cms.ESProducer("MuonDetLayerGeometryESProducer")


process.ParabolicParametrizedMagneticFieldProducer = cms.ESProducer("AutoParametrizedMagneticFieldProducer",
    label = cms.untracked.string('ParabolicMf'),
    valueOverride = cms.int32(-1),
    version = cms.string('Parabolic')
)


process.RPCGeometryESModule = cms.ESProducer("RPCGeometryESModule",
    compatibiltyWith11 = cms.untracked.bool(True),
    useDDD = cms.untracked.bool(False)
)


process.SiStripRecHitMatcherESProducer = cms.ESProducer("SiStripRecHitMatcherESProducer",
    ComponentName = cms.string('StandardMatcher'),
    NSigmaInside = cms.double(3.0),
    PreFilter = cms.bool(False)
)


process.StripCPEfromTrackAngleESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('StripCPEfromTrackAngle'),
    ComponentType = cms.string('StripCPEfromTrackAngle'),
    parameters = cms.PSet(
        mLC_P0 = cms.double(-0.326),
        mLC_P1 = cms.double(0.618),
        mLC_P2 = cms.double(0.3),
        mTEC_P0 = cms.double(-1.885),
        mTEC_P1 = cms.double(0.471),
        mTIB_P0 = cms.double(-0.742),
        mTIB_P1 = cms.double(0.202),
        mTID_P0 = cms.double(-1.427),
        mTID_P1 = cms.double(0.433),
        mTOB_P0 = cms.double(-1.026),
        mTOB_P1 = cms.double(0.253),
        maxChgOneMIP = cms.double(6000.0),
        useLegacyError = cms.bool(False)
    )
)


process.TrackerRecoGeometryESProducer = cms.ESProducer("TrackerRecoGeometryESProducer")


process.TransientTrackBuilderESProducer = cms.ESProducer("TransientTrackBuilderESProducer",
    ComponentName = cms.string('TransientTrackBuilder')
)


process.VolumeBasedMagneticFieldESProducer = cms.ESProducer("VolumeBasedMagneticFieldESProducerFromDB",
    debugBuilder = cms.untracked.bool(False),
    label = cms.untracked.string(''),
    valueOverride = cms.int32(-1)
)


process.ZdcGeometryFromDBEP = cms.ESProducer("ZdcGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.fakeForIdealAlignment = cms.ESProducer("FakeAlignmentProducer",
    appendToDataLabel = cms.string('fakeForIdeal')
)


process.hcalDDDRecConstants = cms.ESProducer("HcalDDDRecConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalDDDSimConstants = cms.ESProducer("HcalDDDSimConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalTopologyIdeal = cms.ESProducer("HcalTopologyIdealEP",
    Exclude = cms.untracked.string(''),
    appendToDataLabel = cms.string('')
)


process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)


process.idealForDigiCSCGeometry = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.idealForDigiDTGeometry = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.idealForDigiTrackerGeometry = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.siPixelQualityESProducer = cms.ESProducer("SiPixelQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiPixelQualityFromDbRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiPixelDetVOffRcd'),
            tag = cms.string('')
        ))
)


process.siStripBackPlaneCorrectionDepESProducer = cms.ESProducer("SiStripBackPlaneCorrectionDepESProducer",
    BackPlaneCorrectionDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    BackPlaneCorrectionPeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    )
)


process.siStripGainESProducer = cms.ESProducer("SiStripGainESProducer",
    APVGain = cms.VPSet(cms.PSet(
        Label = cms.untracked.string(''),
        NormalizationFactor = cms.untracked.double(1.0),
        Record = cms.string('SiStripApvGainRcd')
    ), 
        cms.PSet(
            Label = cms.untracked.string(''),
            NormalizationFactor = cms.untracked.double(1.0),
            Record = cms.string('SiStripApvGain2Rcd')
        )),
    AutomaticNormalization = cms.bool(False),
    appendToDataLabel = cms.string(''),
    printDebug = cms.untracked.bool(False)
)


process.siStripLorentzAngleDepESProducer = cms.ESProducer("SiStripLorentzAngleDepESProducer",
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    ),
    LorentzAngleDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripLorentzAngleRcd')
    ),
    LorentzAnglePeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripLorentzAngleRcd')
    )
)


process.siStripQualityESProducer = cms.ESProducer("SiStripQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiStripDetVOffRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiStripDetCablingRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('RunInfoRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadChannelRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadFiberRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadModuleRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadStripRcd'),
            tag = cms.string('')
        )),
    PrintDebugOutput = cms.bool(False),
    ReduceGranularity = cms.bool(False),
    ThresholdForReducedGranularity = cms.double(0.3),
    UseEmptyRunInfo = cms.bool(False),
    appendToDataLabel = cms.string('')
)


process.sistripconn = cms.ESProducer("SiStripConnectivity")


process.stripCPEESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('stripCPE'),
    ComponentType = cms.string('SimpleStripCPE'),
    parameters = cms.PSet(

    )
)


process.trackerGeometryDB = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.trackerNumberingGeometryDB = cms.ESProducer("TrackerGeometricDetESModule",
    appendToDataLabel = cms.string(''),
    fromDDD = cms.bool(False)
)


process.trackerTopology = cms.ESProducer("TrackerTopologyEP",
    appendToDataLabel = cms.string('')
)


process.GlobalTag = cms.ESSource("PoolDBESSource",
    DBParameters = cms.PSet(
        authenticationPath = cms.untracked.string(''),
        authenticationSystem = cms.untracked.int32(0),
        messageLevel = cms.untracked.int32(0),
        security = cms.untracked.string('')
    ),
    DumpStat = cms.untracked.bool(False),
    ReconnectEachRun = cms.untracked.bool(False),
    RefreshAlways = cms.untracked.bool(False),
    RefreshEachRun = cms.untracked.bool(False),
    RefreshOpenIOVs = cms.untracked.bool(False),
    connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS'),
    globaltag = cms.string('80X_mcRun2_asymptotic_2016_TrancheIV_v6'),
    pfnPostfix = cms.untracked.string(''),
    pfnPrefix = cms.untracked.string(''),
    snapshotTime = cms.string(''),
    toGet = cms.VPSet()
)


process.eegeom = cms.ESSource("EmptyESSource",
    firstValid = cms.vuint32(1),
    iovIsRunNotTime = cms.bool(True),
    recordName = cms.string('EcalMappingRcd')
)


process.es_hardcode = cms.ESSource("HcalHardcodeCalibrations",
    GainWidthsForTrigPrims = cms.bool(False),
    HERecalibration = cms.bool(False),
    HEreCalibCutoff = cms.double(20.0),
    HFRecalibration = cms.bool(False),
    iLumi = cms.double(-1.0),
    testHFQIE10 = cms.bool(False),
    toGet = cms.untracked.vstring('GainWidths')
)


process.prefer("es_hardcode")

