// 02-17-93: This room changed by Cashimor
// 03-09-93: Cashimor: Changed once again
// 11-27-94: Mangla: Changed to make hacks by several people more reasonable.
// 11-27-94: Cannot go up in the room at all. Could not see where the
//               complain on the code change board came from. If you
//               wish for the up to go back in so that the dragon can
//               clone then please let me know and I will change.

inherit "room/room";

#include "/obj/door.h"

object the_dragon;
int no_dragon;
object obj_1, obj_2;	         // Used by the MAKE_DOORS macro
string *function, *type, *match;

/* For the NEW, IMPROVED monster class: */
mixed setup_arrays() {

    function=({"ticket_check"});
    type=({"arrives"});
    match=({""});
} 

void make_dragon() {

    object key;

    the_dragon = clone_object("/players/whisky/obj/std_dragon");
    the_dragon->set_colour("steel");
    the_dragon->set_age(5);
    the_dragon->set_silent(1);
    the_dragon->set_no_follow();
    the_dragon->set_no_steal();
    MAKE_KEY(key,"moderate-security","treasurydoor")
    transfer(key,the_dragon);
    /* The NEW, IMPROVED monster calls: */
    if(!function) setup_arrays();
    the_dragon->set_match(this_object(), function, type, match);
    move_object(the_dragon, this_object());
} 

int id_note(string str) 
{
    return str == "note" || str == "small note" || str == "door note";
}

status move(string arg)
{
  string n;

  if (!stringp(arg))
      arg = query_verb();

// Mangla: Moved qery_name up here since it was used in the first if
//      but not defined until INTO the else.
  n=this_player()->query_name();
  if (arg == "up" && no_dragon==1 && !present("dragon",this_object()))
  {
     printf("As you try to climb the ladder, an alarm sounds!\n");
     say("As " + n + " tries to climb the ladder, an alarm sounds!\n");
     printf("A giant steel dragon shows up to investigate!\n");
     say("A giant steel dragon shows up to investigate!\n");
     make_dragon();
     no_dragon = 0;
     return 1;
  }
  else if (arg=="up" && present("dragon",this_object()))
  {
     printf("You cannot pass the dragon.\n");
     say(capitalize(n) + " tries to climb the ladder, but the dragon bars the way.\n");
     return 1;
  }
  return ::move(arg);
}

int do_read(string str) 
{
    if (id_note(str)) {
	write("The small note on the north door says:\n" +
	      "    'Don't go in here. The guards have gone crazy again.'\n");
	return 1;
    }
  notify_fail("Read what?\n");
  return 0;
}


void ticket_check(string str) {

    string who, rest;
    object suspect;

    if (sscanf(str, "%s arrives%s", who, rest) != 2)
	return;		/* Some strange error! */

    suspect = present(lower_case(who), this_object());

    if (!suspect)
	return;		/* Already gone! */

    if (!present("castle ticket", suspect)) {

//  The dragon was to attack any player without a picket at this point.
//      This was changed to not happen. The say was also redone to reflect
//      what would actually happen in a circumstance like this. As it was
//      before the player was not told anything.

        tell_room(this_object(),"The dragon notices that " + who +
                  "does not have a ticket.\n" +
                  "From deep in his stomach he rumbles:\n" +
                  "\t\tYou would be wise to get a ticket.\n");
	/* the_dragon->attacked_by(suspect); */
    }
} /* ticket_check */


void reset(int flag) 
{
  if (!the_dragon)
      no_dragon = 1;
  ::reset(flag);
  if(flag == 0) 
  {
    set_light(1);
    MAKE_DOORS("players/padrone/tower/hall","north",
	       "players/padrone/tower/rambo_room","south",
	       "moderate-security",
	       "treasurydoor",
	       "This is a stout wooden door, several inches thick.\n" +
	       "There is a small note nailed to it:\n" +
	       "    'Don't go in here. The guards have gone crazy again.'\n",
	       1,1,1)
    short_desc="The Tower Hall";
    dest_dir=({"players/padrone/tower/bedroom","south",
               "players/padrone/tower/lab","east",
               "players/padrone/tower/poolroom","west",
               "players/padrone/tower/tower4","down",
               "players/padrone/tower/tower_top","up",
               });
    long_desc="You are in the hall of Padrone's private tower. This is a big "
            + "and spacious hall, so the interior of the tower must have been "
            + "expanded using magic. Several doors lead to other rooms. A "
            + "small ladder in one corner leads up, and a stone stairway "
            + "leads down into the tower. There is a small note on the door "
            + "leading north.\n";
    items=({"tower","It looks vast and magnificent",
            "hall","It has a very magical look",
            "doors","They are exquisitely carved",
            "ladder","A small rickety ladder in one corner of the room. It"
                    +" doesn't look that strong now, but it should be safe",
            "stairway","It looks very solid",
            "note","It has only recently been put up"});
  }
  if(flag) {
    obj_1->set_closed(1);
    obj_1->set_locked(1);
    obj_1->set_both_status();
  }
}

void init() {
  ::init();
  add_action("do_read","read");
}

