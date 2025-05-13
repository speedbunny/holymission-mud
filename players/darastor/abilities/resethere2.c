/******

RESETHERE:

Calls reset in the environment of the newwiz, with arg either
1 or 0 depending on what the wiz specified

********/
#include "/sys/defs.h"

int main(string str) {

  int      resetArg;
  object   env;
  string   creatorname;
// Using creator and makeing code a little shorter and more efficient
// I think. If not then please tell me. :) -Mangla
//  string   envFileName;
//  int      envPathSize;
//  string   *envFilePath;

  if(!str)
    return 0;

  if((sscanf(str, "%d", resetArg) != 1 )
           || ((resetArg != 0) && (resetArg != 1))) {
// Mangla: Added in the extra stuff for resethere.
    notify_fail("Invalid argument to reset.\n" +
                "    'resethere [0|1]'\n");
    return 0;
  }

//  envFileName = file_name(env = ENV(TP));
  creatorname = creator(env = ENV(TP));

  if(env) {
//    envFilePath = explode(envFileName, "/");
//    envPathSize = sizeof(envFilePath);
//    if((envPathSize > 1)
//          && (envFilePath[1] == (string)(TP->RNAME))) {
    if(creatorname == TP->RNAME || TP->query_wizard()) {
      env->reset(resetArg);
      TELL(TP, "Called reset " + to_string(resetArg) + "\n");
      say(CAP(TP->NAME) + "called " +
          "reset with arg " + resetArg + ".\n", TP);
      return 1;
    }
    else {
      notify_fail("You can only reset your own rooms.\n");
      return 0;
    }
  }
  else {
    notify_fail("Could not get environment file name.\n");
    return 0;
  }
}
