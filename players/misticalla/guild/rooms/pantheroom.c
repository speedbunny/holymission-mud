
inherit "room/room";
#include "../guild.h"

object cat,board,barrel;
object *cats;
string extra;
int i;

reset(arg) {
    /*** mod by James. limit # of cats to 8, or whatever the size
	 of the 'cats' array is. once a cat dies, the spot in the
	 array will open up, so another cat can be born. 
    ***/

    if(!sizeof(cats)) cats = allocate(20);

    if (!present("cat",this_object())) {
	for(i=0; i<sizeof(cats); i++) {
	    if(!objectp(cats[i])) {
		cats[i]=clone_object("players/whisky/hole/monster/cat");
		move_object(cats[i],this_object());
		break;
	    }
	}
    }
    i=0;

    if(!present("barrel",this_object())) {
	barrel=clone_object("obj/container");
	barrel->set_name("barrel");
	barrel->set_short("A wooden barrel");
	barrel->set_long(extra+"  wooden barrel, normally\n"+
	  "used to be filled with fresh mountainwater\n"+
	  "for thirsty adventurers.\n");
	barrel->set_weight(60); /* can be taken but woudn't be too clever */
	barrel->set_max_weight(90);
	barrel->set_value(100); 
	transfer(barrel,this_object());
    }

    if (arg) return;
    set_light(1);
    short_desc = "Panther room in an abbey";
     long_desc = 
     "This is a northern room in the abbey. It is a place "+
      "where you can get a panther to travel with you on your "+
      "adventures. You see a sign on the wall. The marbled "+
      "floors have panthers etched into them. The archway to the "+
      "south leads back into the courtyard, and the exit to the "+
      "east leads to the stairwell.\n";
    items = ({ 
     "walls","They are made of marble and are shiny",
      "sign","There is something written on it",
     "floor","You see your reflection in the marble"
    });

    dest_dir = 
    ({
      "players/misticalla/guild/rooms/courtyard4","south",
      "players/misticalla/guild/rooms/stairs","east"
    });
}
init() {
    add_action("drink","drink");
    if (i<200) { extra="A full"; } 
    else { extra="An emty"; }
    add_action("fcn_read","read");
    add_action("fix_me","prepare");
    ::init();
}

public int
fcn_read(string arg)
{
    if (arg!="sign") return 0;

    write( 
      "How to use a follower (panther):\n\n"+
      "Monks are permitted to have a follower. The followers "+
      "of the blue Order are panthers. To handle them there are several "+
      "commands:\n"+
      "get panther           to show your pet that you want it.\n"+
      "name panther <name>   to give your pat a nickname.\n"+
      "drop panther          and it will follow you (if it likes you)\n"+
      "crawl <direction>     so the panther will spy for you\n"+
      "C <command>           to let your panther fulfill easy commands as purr\n"+
      "D <item>              to let the panther drop items you gave it D without\n"+
      "                      argument lets your panther drop everything.\n"+
      "D coins               to let the panther drop the money it has got\n"+
      "remember <place>      as 'remember shop', so that the panther will store\n"+
      "                      the place where you are standing with shop\n"+
      "forget <place>        lets your panther forget the places.\n"+
      "places                shows all the places the panther remembers max = 10\n"+
      "command <place> <arg> the panther will do the command <arg> on the stored\n"+
      "                      place as 'command shop buy torch'\n"+
      "S                     your panther will sit down and wait or S to stand\n"+
      "                      up and follow you.\n"+
      "E                     lets your panther eat a corpse (healing)\n"+
      "K <victim>            lets your panther attack your victim\n"+
      "R                     and your panther will rescue you :*) \n\n"+
      "                               **  Whisky the gnome ** \n");
    return 1;
}
drink(arg) {
    if (arg!="from barrel") return;
    if (i<200) {
	write("You drink from the barrel.\n");
	TP->drink_soft(20); /* hmm nothing special */
	i++;
	return 1;
    }
    write("You try to drink from the barrel,\n"+
      "but its emty.\n");
    return 1;
}

int fix_me()
{
   object obj;
   if(!present("monks_chk",this_player()) && this_player()->query_guild()==7)
   {
      obj = clone_object("/players/whisky/guild/obj/monks_chk");
      if(obj) transfer(obj,this_player());
      write("OK, you might fight now.\n");
   }
   else write("Everything is ok, or you don't belong to this guild.\n");
   return 1;
}

   
