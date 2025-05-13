#include "/players/akira/vag/quest/break_string.h"
#define QINFO "/players/akira/vag/quest/gq_info.c"



int id(string str) {
    return str == "vortex" ||
    str == "portal";
}


string short() {
    return "Vortex";
}

void long() {
    write(
      break_string(
	"As you look into the huge vortex of space, that is ripping "+
	"apart the space & time continuum.  You see scenes swirling "+
	"in the huge vortex.  You see scenes of a world turned inside "+
	"out.  You also see a huge being sitting on throne on top of "+
	"a mountain, looking down at the ruined world.  You wonder how "+
	"can this maddness be stopped.  Then a image appears in the "+
	"vortex, it is "+
	capitalize((QINFO)->query_who_in_area())+
	" and in a distorted voice echoing, through the vortex, "+
	capitalize((QINFO)->query_who_in_area())+
	" says: Save yourself "+
	capitalize(this_player()->query_real_name())+
	", the evil Timelord Thanos, has alternated reality and "+
	"has killed Emit.  Emit before he died, with the last of "+
	"his strength, able to stablized the vortex, for a short "+
	"time, just allowing to enter it.  You see the "+
        "started to fade.  ' My connection with you is fading "+
	"now, So take care, "+
	capitalize(this_player()->query_real_name())+
	"\n",
	75));
}



