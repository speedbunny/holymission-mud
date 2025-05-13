#include "/players/nylakoorub/guild/defines.h"


do_timepose(string arg) {
    if(arg=="time") {
	shout("Vagabond "+
	  capitalize(TP->QRN)+
	  " whips out his time piece and tells you it is:\n"+
	  ctime(time())+"\n");
	write("You tell the mud the time.\n");
    }
    if(arg=="future") {
	shout("Vagabond "+
	  capitalize(TP->QRN)+
	  " tells you a secret of your future.\n");
	write("You tell the mud about thier futures.\n");
    }
    if(!arg) {
	write("timepose <arg> \n"+
	  "Arguments: future, time \n"+
	  "\n");
	return 1;
    }
    do_vag_log("timepose",
      this_player()->query_real_name()+
      " did timepose "+
      arg+
      " on "+ctime(time())+
      "\n");
    return 1;
}


