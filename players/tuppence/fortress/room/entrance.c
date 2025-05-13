inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc="You have come to the entrance of the fortress";
	long_desc="You have come to the lowered draw bridge of the fortress Haden.\n" +
	"The draw bridge lays before you, you think it is safe to cross.\n"+
	"The fortress Haden looks dangerous and big. Guards stand by the\n"+
	"gates. There is a moat that goes around the fortress, you think\n"+
	"that you can enter it from here.\n";
	dest_dir=
	({
	  FROOM+"bridge","north",
        "/room/crop4","east",
	});

	items=
	({
	  "draw bridge","It looks slimy, better watch out",
	  "moat","It has dark and thick water in it, you wonder what maybe down there",
	  "fortress","It looks ancient and evil",
	});
    }
}
void init () {
    ::init ();
    add_action("enter", "enter");
}
int enter(string str) {
    if (!str || str != "moat") {
        notify_fail("Enter what?\n");
        return 0;
    }
    write("You have entered the moat.\n");
    TP->move_player("into the moat#"+FROOM+"moat1");
    return 1;
}
