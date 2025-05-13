inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "shallow moat";
	long_desc= "It is very shallow in this part of the moat. A large oak tree\n"+
	"throws a shadow on the moat. There seems to be something moveing\n" +
	"around in it. You can hear the swaying of the branches on the oak.\n"+
	"No fishes swim in this part of the moat, you wonder why? Very big\n"+
	"footprints surround the waters edge.\n";
	items =
	({
	  "oak","A large oak with colourful leaves stands on the side of the moat casting\n"+
	  "a large shadow on the water",
	  "shadow","Movement comes from the shadow",
	  "footprints","Huge footprints with claw marks, are all along the waters\n"+
	  "edge",
	});
clone_list = ({
1, 1, "silthar", "players/tuppence/fortress/monster/silthar", 0,
});
	dest_dir=
	({
	FROOM+"moat10","east",
	FROOM+"moat12","west",
	  FROOM+"nest","portal",
	});
    }
::reset(arg);
replace_program("/room/room");
}
