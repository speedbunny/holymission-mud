inherit "room/room";
#include "/players/helmut/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }

    if ( !present( "skeleton", this_object() ) )
       transfer( clone_object("/players/helmut/obj/skeleton"), this_object() );
    short_desc="Skeleton";
    long_desc="This small clearing in the jungle is dominated by the large,\n"+
    "well-chewed upon skeleton in the center. The ribs of this\n"+
    "dead thing are at least 20 feet long, and the thigh bones\n"+
    "measure at least 9 feet. You notice that five or six of the\n"+
    "vertebrae have been shattered with great force. There are a\n"+
    "myriad of track on the ground, tracks of all types, but all\n"+
    "are small. The jungle around the clearing is less dense than\n"+
    "the other parts you have seen, as if large animals had \n"+
    "trampled paths through it.\n";
    set_light(1);
    dest_dir=({"players/helmut/rooms/lair1","east",
      "players/helmut/rooms/oneway","west"});
    replace_program("room/room");
}
