
   /* fixed by haplo on 3-27-95 */

inherit "room/room";
#include "../island.h"

object *dago;

void reset(int arg) 
{
    /*
      if (!dago)
	   CM("dagobert");
    */

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
      "You are standing in the sea. The sun is glittering "
      + "in the water. To the west you can see a volcano rising "
     + "up into the sky and you can hear a strange drum-roll "
      + "and the noise of the rumbling volcano. "
      + "If you look down you see the water getting deeper.");
    items = ({
      "water","Crystal clear sea water",
      "volcano","A big black volcano",
      "sea","The clear blue sea"
    });
    dest_dir = 
    ({
      PATH+"island15", "west",
//       "/players/beardy/port/pisland","east",
      PATH+"island20","northwest"
    });
}

init() {
    ::init();
    add_action("dive","dive");
    add_action("dive","down");
    add_action("swim","swim");
}

dive(str) {
    write("You are diving down.\n");
    this_player()->move_player("dives#players/whisky/seaworld/room/sw10");
    return 1;
}

swim(arg) {
    call_out("swim1",2);
    return 1;
}

swim1() {
    write("You swim out the wide ozean.\n");
    call_out("swim2",2);
}

swim2() {
    write("You swim and swim and feel your energie getting lower and lower.\n");
    call_out("swim3",2);
}

swim3() {
    write("Suddenly you feel your arms getting so tired that you sink down on the sea-bottom.\n");
    call_out("swim4",2);
}

swim4() {
    string where;
    where="sw"+(1+random(20));
    write("You suddenly find yourself on a different place\n");
    this_player()->move_player("swimming#players/whisky/seaworld/room/"+where+"");
}
