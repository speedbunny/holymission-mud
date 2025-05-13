inherit "obj/container";
#include "lw.h"
#include "/players/nylakoorub/guild/defines.h"

void reset(int arg){
    container::reset(arg);
    if(arg) return;
    set_name("pouch");
    set_alias("staffpouch");
    set_short("Rock Pouch");
    set_long(
      "This is the legandary 'Cloak of Time and Space', and seems to be\n"+
      "phasing with in the space/time continium.   The fibers of the\n"+
      "cloak were woven by the Ancient Timelords of the 4th dimension.\n"+
      "\n");
    set_weight(0);
    set_max_weight(this_player()->query_level()+2);
    set_value(0);
}



void init(){
    container::init();
}

int drop(string str){
    if(id(str)){
	write("You do not want to drop your pouch.\n");
	return 1;
    }
}




