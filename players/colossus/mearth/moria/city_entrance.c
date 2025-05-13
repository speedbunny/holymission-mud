#include "/players/colossus/mearth/mroom.h"

reset(arg){
    if(arg) return;
    set_light(1);
    short_desc = "Dwarvish city";
    long_desc =
    "You are at the dwarvish city of Rama, this city was built\n"+
    "recently by the dwarves that abandoned Moria but wished to\n"+
    "stay in the mountains. Though the town is small it is slowly\n"+
    "growing. Some believe that Rama is the city where dwarves\n"+
    "whose souls burn for revenge will arise and take back what\n"+
    "is rightfully theirs. A signpost is here and there is a\n"+
    "small booth to the east that has the sign: Visitors information\n"+
    "hanging over its door.\n";

    dest_dir = ({
      MORIA+"/road", "south",
      MORIA+"/mithril1", "north",
      MORIA+"/info_booth", "east",
    });

    items = ({
      "booth", "A small booth with the sign: Visitors information",
    });

    clone_list = ({1,1, "sign", "/obj/treasure",
    ({"set_name", "sign", "set_alias", "signpost", "set_short", "signpost",
      "set_long", "A sign that reads:\n"+
      "East		Visitor information\n"+
      "South		Entrance of Rama\n"+
      "North		Intersection of Silver/Main Street\n",
      "set_weight", 99999999, "set_value", 0}),
    });
    ::reset();
    replace_program("/room/room");
}
