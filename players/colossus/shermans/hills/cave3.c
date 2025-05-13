/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (!present("dracolich")) {
	move_object(clone_object("/players/sherman/hills/dracolich"),this_object());
    }
    if (arg) return;
    set_light(0);
    short_desc = "Cave full of bones";
    long_desc=
    "The cave is full of bones littered everywhere. Apparently\n\
someone or something is guarding this area. On the walls\n\
hang the bodies of two elves and a dwarf, the more recent\n\
trophies.\n";
    items=({
      "cave", "The cave is littered full of bones",
      "walls", "The walls are bleak and rocky and piled high with bones",
      "bodies", "The bodies of two elves and a dwarf hang grotesquely "+
      "on the wall",
      "elves", "The two elves have had their ears sliced off and their\n"+
      "eyes gouged out",
      "dwarf", "The dwarf is dismembered limb from limb, only the torso\n"+
      "and head remain intact",
    });
    dest_dir=({
      "/players/sherman/hills/cave2","north",
      "/players/sherman/hills/cave4","east"
    });
}

void init(){
    ::init();
    if(present("dracolich")) {
	add_action("east","east",1);
    }
}

status east(){
    if(!present("dracolich")) {
	this_player()->move_player("east#players/sherman/hills/cave4");
    } else { 
	write("The dracolich blocks your way.\n");
    }
    return 1;
}

