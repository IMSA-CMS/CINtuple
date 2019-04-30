#crabConfigNTupler.py
# Harry Smith & Matthew Hokinson
# January 28, 2018

from CRABClient.UserUtilities import config, getUsernameFromSiteDB
import datetime
from HEEP.VID.tools import *
import sys

currTime=datetime.datetime.now().strftime('%Y%m%d_%H%M%S')

#Some functions to do the parsing of the dataset name 
#This is going to return a string which has a boolean saying if the set is LR Helicity 
def findHelicityInName(name):
    helicityReturnString = 'isHelicityLR='
    
    i = 0
    while i < len(name) - 5:
        if name[i] == 'C' and name[i+1] == 'o' and name[i+2] == 'n':
            if name[i+3] == 'L' and name[i+4] == 'R':
                helicityReturnString += "True"
                return helicityReturnString;
                #return "True";
        i += 1
    #return helicityReturnString + '1';
    return "False";

#This is going to return just the regular helicity 
def findRealHelicityInName(name):
    i = 0
    while i < len(name) - 5:
        if name[i] == 'C' and name[i+1] == 'o' and name[i+2] == 'n':
            return name[i+3] + name[i+4];
        i += 1
    return 'LL';#this is our default value if for some reason the loop does not work 

#This is gong to return a string with the Lambda value in eV 
def findLambdaInName(name):
    lambdaReturnString = 'Lambda='
    
    i = 0
    while i < len(name) - 5:
        if name[i] == 'L' and name[i+1] == 'a' and name[i+2] == 'm':
            return lambdaReturnString + name[i+3] + name[i+4] + '000';#putting it in units of eV 
        i += 1
    return lambdaReturnString + '16000';#This is going to be our default if we have an issue with parsing 

config = config()
config.General.requestName = 'NTupler_M300_L16TeV_LR_Con_' + currTime
workingDir = "NtupleJobs/NTupleJobs" + currTime
config.General.workArea = workingDir
config.General.transferOutputs = True
config.General.transferLogs = True

print("Finish Setup")

config.JobType.pluginName = 'Analysis'
#config.JobType.psetName = '/uscms/home/kgumpula/nobackup/YOURWORKINGAREA/CMSSW_9_4_6/src/HiggsAnalysis/CombinedLimit/ZPrimeCombine/submission/dummyPSet.py'
config.JobType.psetName = 'runMakeZprimeMiniAodTreeMC_cfg.py'
config.JobType.outputFiles = ['test.root']

inputDataset = sys.argv[4][18:]

print("Set the input name: " + inputDataset)

helicityString = findHelicityInName(inputDataset)

print("Helicity String: " + helicityString)

print("We got to here")

lambdaString = findLambdaInName(inputDataset)

print("We got to here2")

config.JobType.pyCfgParams = [lambdaString,helicityString]

print("We got to here3")

#We should be inputting /MC17_CITo2Mu_M300to800_CP5_Lam16TeVConLRPythia8_v1/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM to test 
#config.Data.inputDataset should be set automatically if we add the argument in command line Data.inputDataset='Dataset'
#config.Data.inputDataset = '/MC17_CITo2E_M800to1300_CP5_Lam16TeVConLRPythia8_v1/RunIIFall17MiniAOD-PU2017_94X_mc2017_realistic_v11-v1/MINIAODSIM'
print("We got to here4")

#config.Data.inputDBS = 'global'
config.Data.publication = True
#Get rid of the 000 at the end of the lambda string 

print("We got to here5")
config.Data.outputDatasetTag = 'CI_M300_Lam' + lambdaString[7] + lambdaString[8] + 'TeV_' + findRealHelicityInName(inputDataset) + '_Con_NTuple_' + currTime
#config.Data.outputDatasetTag = 'CITo2E_M800_L16TeV_LR_Con_NTuple_' + currTime
#config.Data.outputPrimaryDataset = 'test'
config.Data.unitsPerJob = 1
#config.Data.totalUnits = 1
#config.Data.splitting = 'EventBased'
#config.Data.splitting = 'Automatic'
config.Data.splitting = 'FileBased'
config.Site.storageSite = 'T3_US_FNALLPC'

print("End")

