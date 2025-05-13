#include "/players/sargon/define.h"
inherit "/room/room"; 

reset(arg) {
    if(!arg) {
    set_light(1);
    short_desc= "Hallway in the Fighter's guild";
    long_desc = 
        "This is a hall in the guild of the Fighters.\n" +
        "Fighters of all levels pass through here to heal at the\n" +
        "pub to the west, buy and sell goods at the shop to the\n" +
        "north. There's a new armoury south of here. And other\n"+
        "special rooms are located to the west.\n" ;
    dest_dir = ({
        "/players/sargon/guild/rooms/restroom","east",
        "/players/sargon/guild/rooms/hall2", "west",
        "/players/sargon/guild/rooms/shop", "north",
        "/players/sargon/guild/rooms/armoury", "south",
        });
    property=({"no_fight","no_steal"});
    smell="It stinks like sweat!! whew!";
	
	}
}

