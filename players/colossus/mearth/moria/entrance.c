#include "/players/colossus/mearth/mroom.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Entrance to Moria";
    long_desc = 
    "To the south is the long and winding path you took to come to the\n"+
    "gates of Moria. A huge mountain stands before you. Your surroundings\n"+
    "are uncannily still and silent. There us a wall of carved stone before\n"+
    "you with dwarvish runes before you.\n";

    dest_dir = ({
      MORIA+"/path3", "southeast",
    });

    items = ({
      "path", "A long and winding path that finally brought you to the gates\n"+
      "of moria",
      "gates", "These gates are not really your ordinary gates but a wall of stone",
      "mountain", "A huge, solid, and unconquerable mountain that has weathered\n"+
      "time and all other opponents",
      "wall", "A wall of stone, the gates of Moria, with dwarvish runes written on them",
    });

}

init(){
    ::init();
    add_action("say", "say");
    add_action("say", "'");
    add_action("say"); add_xverb("'");
    add_action("read_wall", "read");
}

read_wall(str){
    if(!str)
	return notify_fail("Read what?\n");

    if(str=="wall" || str=="gate" || str=="gates" || str=="runes"){
	if(this_player()->query_race()=="dwarf"){
	    write("You use your knowledge of the dwarvish tongue to translate the runes.\n");
	    write("The runes say:\n"+
	      "	Speak friend and enter.\n");
	    write("The rest is just lots of talk about dead kings and decoration.\n");
	    say(this_player()->query_name()+" reads the runes on the wall of stone.\n");
	    return 1;
	}
	else {
	    write("As best you try you cannot translate those dwarvish runes.\n");
	    say(this_player()->query_name()+" tries but cannot translate the runes.\n");
	    return 1;
	}
    }
}

say(str){
    if(str=="friend"){
	open_gates();
    }
}

open_gates(){
    write("The gates swing open and you enter the mysterious realm of\n"+
      "Moria.\n");
    say(this_player()->query_name()+" enters the gates of Moria as they\n"+
      "swing open.\n");
    this_player()->move_player("into Moria#/players/colossus/mearth/moria/hall_entrance");
    return 1;
}
