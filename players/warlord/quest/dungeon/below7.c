#define TP this_player()
inherit"players/warlord/NEWSTUFF/room";
object earth,baby;
int i;
reset (arg) {
    i=0;
    property=( "no sneak" );
    if (!earth) {
	earth=clone_object("obj/monster");
	earth->set_name("earthworm");
	earth->set_short("Giant Earthworm");
	earth->set_long("You see a giant earthworm here and by the looks of it\n"+
	  " she is very hungry!\n");
	earth->set_level(15);
	earth->set_ac(10);
	earth->add_money(400);
	earth->set_gender(2);
	earth->set_dead_ob(this_object());
	move_object(earth,this_object());
    }
    if (!arg) {
	set_light(0);
	short_desc="Under the forest";
	long_desc=  
	"You entered a burrowed out cavern.\n";
	dest_dir=({
	  "/players/warlord/quest/dungeon/below6","west",
	  "/players/warlord/quest/dungeon/below8","east",
	  "/players/warlord/quest/dungeon/below10","down",
	});
    }
}
monster_died(earth) {
    if (!present("baby")) {
	for(i=0;i<5;i++) {
	    baby=clone_object("obj/monster");
	    baby->set_name("baby");
	    baby->set_short("Baby Earthworm");
                    baby->set_long("This is a baby earthworm.\n");
	    baby->set_level(7);
	    move_object(baby,this_object());
	}
    }
    return;
}
init () {
    ::init();
    add_action("down","down");
    add_action ("sneak","sneak");
}
down () {
    if ((present("earthworm"))||(present("baby"))) {
	write("That way is blocked by an earthworm.\n");
	return 1;
    }
    if (!(present("orchid",TP)) || (!present("black sword",TP)) || (!present("rock",TP))) {
	write("You do not possess the proper items.\n");
	return 1;
    }
    else {
	return !this_player()->move_player("down#players/warlord/quest/dungeon/below10");
    }
}
sneak() {
    write("You can't sneak anywhere around here.\n");
    return 1;
}
