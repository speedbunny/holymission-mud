#include "/players/colossus/mearth/mroom.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Path to dwarven city";
    long_desc =
    "You are on a path that leads north and southwest. This room is lighted\n"+
    "however from the light coming from the eyes of the statues of two dwarven\n"+
    "kings. The statues are over 40 feet tall and stand proud to guard their\n"+
    "kin against invaders. Their eyes shine with an almost blinding blue light\n"+
    "that seems to pierce your soul and search it.\n";

    dest_dir = ({
      MORIA+"/city_entrance", "north",
      MORIA+"/hall_entrance", "southwest",
    });

    items = ({
      "light", "A blue light that illuminates enough of the room to see",
      "statues", "The statues of majestic dwarvish kings",
      "path", "A path that leads to the north and southwest",
    });

}

init(){
    ::init();
    add_action("check_go", "north");
}

check_go(){
    if(this_player()->query_alignment()<-20){
	write("The light from the eyes of the statues burns into your soul\n"+
	  "and reveals your evil nature. You cower on the ground and are\n"+
	  "not able to proceed north.\n");
	say(this_player()->query_name()+
	  " cowers on the ground as the blue light from the statue pierces "+
	  this_player()->query_possessive()+" soul.\n");
	return 1;
    }
}
