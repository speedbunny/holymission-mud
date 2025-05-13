#define NAME "Jewel"
#if 0
// 210198: Sauron: Moved load location since the area isn't open yet.
#define DEST "/room/sea.c"
#else
#define DEST "/players/jewel/workroom"
#endif
#define WAIT 1
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

inherit "room/room";

reset(arg) {
    if(!arg) {
	set_light(1);
	long_desc="Cavern entrance \n";
	short_desc=
	"    Through the murky waters, you see an enormous coral reef";
	items=({ 
	    "castle","@@short",   /* we need that to get the 'castle' id */
	    "reef","A massive multicolored reef. You can barely make out an small entrance to some caverns at the bottom of the reef",
	      });
    }
    move_object(this_object(), DEST);
}

/*
init() {
    ::init();
    add_action("enter", "enter");
}

enter(str) {
    if ((str=="caverns" || str=="cave" || str=="cavern" || str=="reef"))
    {
	call_out("down_msg",  WAIT,);
	call_out("down_msg", 2*WAIT);
	call_out("down_msg", 3*WAIT);
	call_out("down_msg", 4*WAIT);
	call_out("down_msg", 5*WAIT);
	call_out("up_msg", 6*WAIT);
	call_out("up_msg", 7*WAIT);
	call_out("up_msg", 8*WAIT);
	call_out("up_msg", 9*WAIT);
	call_out("welcome", 10*WAIT);
    }
    return 1;
}
down_msg()
{write("You are diving down...\n");}

up_msg()
{write("You are swimming up...\n");}

welcome()
{
   write("A hollow voice says: Welcome to Jewel's crystal caverns.\n");
   call_other(this_player(),"move_player","enter#players/jewel/room/entrance");
}

*/
