
#include "../includes/logFile.h"
#include "../includes/errorMsg.h"

int myLog::_loglvl = 3;
ostream *myLog::_out= NULL;

void myLog::printArgv(int loglvl, int argc, char *argv[]) {
  LOG(loglvl,<<"argv =");
  for (int i=0;i<argc;++i)
    LOG(loglvl,<<" \""<<argv[i]<<"\"");
  LOG(loglvl,<<endl);
}
