#define NAME "qclxxiv"
#define CNAME	capitalize(NAME)
#include "/players/qclxxiv/myroom.h"
/* #include "/room/room.h" */

#define SIX_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6  }); }\
    EXTRA_RESET }\

#define SEVEN_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7  }); }\
    EXTRA_RESET }\


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

#define TPRNAME (this_player()->query_real_name())

object spliff,fishtea;
int is_locked;
object window;

int connected_to_center() { return 1; }

extra_reset(arg) {
	if (!window) {
		window = clone_object("/players/qclxxiv/window");
		move_object(window,this_object());
		window->set_name("A magic window");
		window->set_alias("magic window");
		window->set_long("Just an ordinary magic window.\n");
		window->set_toroom("players/qclxxiv/waitingroom");
		window->set_clean(1);
	}
    if (!spliff) {
    	spliff = clone_object("players/qclxxiv/spliff");
    	move_object(spliff, this_object());
    }
	is_locked = 1;
	if (arg) return;
	items = ({ "shelf", "A shelf full of books",
				"shelves", "Shelves full of books",
				"walls", "Old dark stone walls",
				"wall", "An old dark stone wall",
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

query_light() { return 1; }

SEVEN_EXIT("obj/tick","tick",
	      "room/church", "church",
          "room/adv_guild", "guild", 
			"players/qclxxiv/testroom", "testing",
			"players/nokey/centralroom", "central",
            "players/qclxxiv/waitingroom", "east",
            "players/qclxxiv/guestroom", "north",
	      CNAME +"'s workroom",
 "The residence of "+CNAME+".\n"
+"Some shelves are in it. Lanthorns are spreading their light. To the east\n"
+"there is a waiting room.\n", 1)

/* extra_init() { */
init() {
		::init();
       add_action("lock","lock");
       add_action("unlock","unlock");
	   add_action("southeast","southeast");
       if (TPRNAME!="qclxxiv" && is_locked) {
			if (this_player()->query_level()>=30 
/* Nokey could be wiz   (done all quest)  but prefers to be player */
/* should be one of the 'honoray' civilians whisky pondered about */
			|| this_player()->query_real_name()=="nokey" ) {
         		tell_object(this_player(),
"That's a private room, currently locked. Because of your high status\n"
+"you can wait in the extra comfortable guest room though.\n");
       			move_object(this_player(),"players/qclxxiv/guestroom");
			}
			else {
         		tell_object(this_player(),
"That's a private room, currently locked. Wanna wait in the waitingroom?\n");
       			move_object(this_player(),"players/qclxxiv/waitingroom");
			}
   }
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

southeast(str) {
	if (!no_dread())
	{
       	tell_object(this_player(),
		 	"You pass through the secret doorway to the library.\n");
       	move_object(this_player(),"players/qclxxiv/library");
		return 1;
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
