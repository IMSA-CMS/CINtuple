#crabConfigNTupler.py
# Harry Smith & Matthew Hokinson
# November 28, 2018

from CRABClient.UserUtilities import config, getUsernameFromSiteDB
import datetime

currTime=datetime.datetime.now().strftime('%Y%m%d_%H%M%S')

config = config()
config.General.requestName = 'NTupler_M300_L16TeV_LR_Con_' + currTime
workingDir = "NTupleJobs" + currTime
config.General.workArea = workingDir
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
#config.JobType.psetName = '/uscms/home/kgumpula/nobackup/YOURWORKINGAREA/CMSSW_9_4_6/src/HiggsAnalysis/CombinedLimit/ZPrimeCombine/submission/dummyPSet.py'
#config.JobType.scriptExe= 'runMakeZprimeMiniAodTreeMC_cfg.py'
config.JobType.psetName = 'runMakeZprimeMiniAodTreeMC_cfg.py'
config.JobType.outputFiles = ['test.root']

#config.Data.userInputFiles = '/MC17_CITo2Mu_M300to800_CP5_Lam16TeVConLLPythia8_v1/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM'
config.Data.inputDataset = '/MC17_CITo2Mu_M300to800_CP5_Lam16TeVConLLPythia8_v1/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM'
config.Data.publication = True
config.Data.outputDatasetTag = 'CI_M300_L16TeV_LR_Con_NTuple_Nov14'
#config.Data.outputPrimaryDataset = 'test'
config.Data.unitsPerJob = 1
config.Data.totalUnits = 1
#config.Data.splitting = 'EventBased'
config.Data.splitting = 'Automatic'
config.Site.storageSite = 'T3_US_FNALLPC'

