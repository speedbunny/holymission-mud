/* 011092: Torches added (but no long desc - due to std.h) */
/* Ethereal Cashimor. "has_fire" property from torches...  */

#include "tune.h"

#define GUILD	0				/* adventurers guild */
#define GM	"guild/master"
#define TP	this_player()

inherit "guild/room";
inherit "room/room";

reset(arg) {
    object ob;

    "guild/room"::reset(arg);
    "room/room"::reset(arg);
    if (!arg) {
        set_guild(GUILD);
        move_object("obj/book", this_object());
        ob = clone_object("obj/board");
        ob->set_file("obj/bulletin");
        ob->set_name("bulletin");
        move_object(ob,this_object());
        short_desc="The adventurers guild";
        long_desc=
	    "You have to come here when you want to advance your level.\n" +
	    "You can also buy points for a new level.\n" +
	    "ATTENTION: You can't advance above level 19 here.\n"+
	    "Commands: cost, list, list [number], list all,\n"+
	    "          advance.\n" +
	    "YOU ARE NOT ALLOWED TO FIGHT IN THE GUILD !\n"+
	    "There is an opening to the south, and some shimmering\n" +
	    "blue light in the doorway.\n"+
	    "Downwards you see the entrance to the players' flame room.\n"+
            "To the southwest is the players bug room. A reddish looking room.\n"+
            "In the corner you notice a translucent staircase leading\n"+
            "up to the Guild of the Archwizards.\n" +
            "There are a few burning torches attached to the wall,\n" +
            "giving this guild a dark and smoky appearance.\n";
        dest_dir=({
            "room/vill_road1b","north",
            "players/silas/mudadsroom","east",
            "players/kbl/boards/player_bug","southwest",
            "room/arches/general","up",
            "players/calidor/others/board/pla","down",
                 });
        hidden_dir=({
            "room/adv_inner","south",
                   });
        items=({ 
            "stair","It is translucent",
            "torch","They are fixed to the wall",
            "torches","They are fixed to the wall",
              });
        property=({ "no_fight","no_steal","has_fire" });
    }
}

make_quest() {
  object ob;
  ob = clone_object("obj/quest_obj");
  ob->set_name("orc_slayer");
  ob->set_weight(1);
  ob->set_killing(3);
  ob->set_short_hint("Get the Orc slayer");
  ob->set_hint(
"Retrieve the Orc slayer from the evil orc shaman, and give it to Leo.\n");
  ob->add_quest();
}

init() {
    "guild/room"::init();
    "room/room"::init();
    add_action("banish", "banish"); 
    add_action("up","up");
    add_action("south","south");
}

banish(who) {
string banished_by,title;

    if (!this_player()->query_wizard()) return;
    if (!who) {
	write("Banish who ?\n");
	return 1;
    }
    if (!call_other(this_player(), "valid_name", who))
	return 1;
    if (restore_object("players/" + who)) {
	write("That name is already used.\n");
	return 1;
    }
    if (restore_object("banish/" + who)) {
	write("That name is already banished.\n");
	return 1;
    }
    banished_by = call_other(this_player(), "query_name");
    title = call_other(this_player(), "query_title");
    if (banished_by == "Someone") {
	write("You must not be invisible!\n");
	return 1;
    }
    save_object("banish/" + who);
    return 1;
}

up(arg) {
    if (!TP->query_archwiz()) {
	write("You can't go up there - you're not an archwizard!!!!\n");
	return 1;
    }
    return "room/room"::move(arg);
}

south(arg) {
    if (!TP->query_immortal()) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
	    " tries to go through the field, but fails.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    return "room/room"::move(arg);
    return 1;
}

try_attack(ob) { return "room/church"->try_attack(ob); }

light_text(str) {
  write("You light your "+str+" with the torches on the wall.\n");
  say(this_player()->query_name()+" uses the torches on the wall to light a "+str+".\n");
}
