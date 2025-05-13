#include "naming.h"
#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define TPRNAME (this_player()->query_real_name())

object camera,spliff,fishtea,tea2;
int is_locked;
query_qnewbie() { return 1; }

extra_reset(arg) {
    if (!spliff) {
    	spliff = clone_object("players/qclxxiv/spliff");
    	move_object(spliff, this_object());
    }
    if (!fishtea) {
    	fishtea = clone_object("players/qclxxiv/fishtea");
    	move_object(fishtea, this_object());
    }
    if (!tea2) {
    	tea2 = clone_object("players/qclxxiv/fishtea");
    	move_object(tea2, this_object());
    }
	is_locked = 1;
	if (arg) return;
    set_nodig(1);
	items = ({	"shelf", "A shelf loaded with books and scrolls", 
				"shelves", "Shelves loaded with books and scrolls",
				"books", "You see Bibles, amongst which a Maccabee version, "
				+"also Qurans, Torah's, \nand many other Great Scriptures",
				"scrolls", "Old Ethiopian scrolls written in a strange letter "
				+"system",
				"wall", "An old dark stone wall",
				"walls", "Old dark stone walls",
				"picture",
"A picture showing Ras Tafari HaileSelassie I sitting on his throne.\n",
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
			});
	property=({ "has_fire" });
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

FOUR_EXIT("room/main_shop","shop",
		  "players/rasta/room/bulletin","board",
          "players/qclxxiv/waitingroom", "north",
		  "players/rasta/room/ital", "ital",
	      TITLE+NAME+"'s library",
	  NAME+"'s library. It's a quite, pretty good place to be.\n"
	+"If properly locked (normally the case) only Rastafarians can be here.\n"
    +"A picture of Ras Tafari sitting on His throne is on the eastern wall.\n"
	+ "There are many shelves packed with books and scrolls. Lanthorns spread\n"
	+ "their yellowish light.\n" ,1) 

init() {
	   ::init();
       add_action("smile","smile");
       add_action("lock","lock");
       add_action("unlock","unlock");
	   add_action("northwest","northwest");
       if (TPRNAME!="qclxxiv" && is_locked && no_dread()) {
         	tell_object(this_player(),
"That's a private room, currently locked. Wanna wait in the waitingroom?\n");
       		move_object(this_player(),"players/qclxxiv/waitingroom");
   	   }
	   else if (!is_locked)
				write("The room is unlocked, anyone can enter it now.\n");
}

lock() {
  if (query_myself()) {
     is_locked=1;
     say("Qclxxiv locked the room.\n"); 
  } 
  return 1;
}

unlock() {
  if (query_myself()) {
      is_locked=0;
      say("Qclxxiv unlocked the room.\n"); 
  } 
  return 1;
}

query_myself() {
  if (TPRNAME!="qclxxiv") {
     write("Only one can do that here.\n");
     return 0;
  }
  return 1;
}

northwest(str) {
	object ob;
	ob = first_inventory(this_player());
	while(ob) {
		if (call_other(ob,"id","dreadlocks")) {
          	tell_object(this_player(),
		 	"You pass through the secret doorway to the workroom.\n");
         	move_object(this_player(),"players/qclxxiv/workroom");
			return 1;
		}
		ob = next_inventory(ob);
	}
	return 0;
}


no_dread() {
	object ob;
	ob = first_inventory(this_player());
	while(ob) {
		if (call_other(ob,"id","dreadlocks")) {
			return 0;
		}
		ob = next_inventory(ob);
	}
	return 1;
}

smile() {
	write( "You smile irier than ever.\n" );
	say( this_player()->query_name()+" smiles irier than ever.\n" );
	return 1;
}
