
 /* House_help.c        Metaprat       16th April 1992   */


#define  FILENAME     "/players/silas/houses/house_help"
#include "/players/silas/houses/house_defines.h"


id(str) {
   return (str == "house help");
}


short() {
   return "house help";
}


long() {
   write("House Help object.\n");
}


get() {
   return 0;     /* may not be picked up */
}


drop() {
   return 1;     /* may not be dropped */
}


query_weight() {
   return 0;     /* weightless  */
}


query_value() {
   return 0;     /* may not be sold */
}


query_drop_castle() {
   return 1;              /* do not permit portable castles here!!! */
}



help(str) {
   if (!str) {
      return 0;
   }
   if (str == "house") {
      write("Welcome to your new Metaprat Industries house.  These houses\n");
      write("have been specially designed for the comfort and convenience\n");
      write("of you, the consumer.  The owner may decorate as he or she\n");
      write("wishes, and the new design will remain perfect even if the\n");
      write("mud itself crashes or shuts down.  Furthermore, he or she has\n");
      write("an unprecidented degree of access control; friends may be\n");
      write("invited, and even banished if they don't behave themselves.\n");
      write("For summaries of each of these points, please enter:\n");
      write("        help map              help decorate\n");
      write("        help build            help furnish\n");
      write("        help doors            help rooms\n");
      write("        help invite           help expel\n");
      write("        help destroy\n");
      if (this_player()->query_level() > WIZLEVEL) {
         write("Wizards also may read 'help wizards'.\n");
      }
      return 1;
   }
   if (str == "map") {
      write("Is this house so large that you need a map to explore it?\n");
      write("Well, worry not!  ACME DIY provides cheap, biodegradable maps\n");
      write("to anyone who requests one with the 'map' command.  The paper\n");
      write("is designed to have a minimum impact on the environment, by\n");
      write("degrading into harmless dust after a few minutes.\n");
      write("Cost: " + MAPCOST + ".\n");
      write("See also: house.\n");
      return 1;
   }
   if (str == "decorate") {
      write("With the aid of ACME DIY, the appearence and even role of any\n");
      write("room may be totally changed, with a minimum of effort.\n");
      write("Simply by using the 'decorate' command, the lucky customer\n");
      write("may permanently modify the description of a room.  Using\n");
      write("the elegant and simple interface made famous by the bulletin\n");
      write("boards, the customer can specify the new design, see what it\n");
      write("would look like, and is then given the option to go ahead\n");
      write("with the redecoration, or not.\n");
      write("Cost: " + DECORCOST + " coins.\n");
      write("See also: house, build, destroy, furnish, doors, rooms.\n");
      return 1;
   }
   if (str == "build") {
      write("Extensions for you wonderful new house allow you to expand\n");
      write("to your heart's desire*.  You can build new rooms, and new\n");
      write("doors, simply by saying   'build room east'.  If you have\n");
      write("built a room you don't want anymore, then it may be\n");
      write("destroyed if you wish.\n");
      write("*- if you desire 10 rooms or less, that is :-)\n");
      write("Cost: " + ROOMCOST + " gp for a new room, and " + DOORCOST);
      write(" gp for a door.\n");
      write("See also: house, decorate, destroy, furnish, doors, rooms.\n");
      return 1;
   }
   if (str == "destroy") {
      write("If you want to get rid of an exit, or a room that is surplus\n");
      write("to your requirements, you may 'destroy room'.  To get rid of\n");
      write("a room, you must be in it at the time, and also must have\n");
      write("already destroyed all the exits to the room.\n");
      write("Destroying an exit is equally easy, simply 'destroy exit'\n");
      write("or 'destroy door north', and it will be removed rapidly.\n");
      write("However; a word of warning.  If you isolate rooms, it may\n");
      write("be expensive to build rooms and exits to reach them again.\n");
      write("Cost: Free for a room, and " + DOORCOST + " coins to destroy\n");
      write("each exit.\n");
      write("See also: house, decorate, build, furnish, doors, rooms.\n");
      return 1;
   }
   if (str == "furnish") {
      write("As the owner of a beautiful house you will want to be sure\n");
      write("to describe the things in your room. This can be done by\n");
      write("typing 'furnish'. By using this option you will be able to\n");
      write("describe everything in your room to your heart's content.\n");
      write("Cost: Free.\n");
      write("See also: house, decorate, build, destroy, doors, rooms.\n");
      return 1;
   }
   if ((str == "doors") || (str == "exits")) {
      write("ACME DIY supply the following types of doors:\n");
      write("   Simple exits,\n");
      write("   Doors that may open and close,\n");
      write("   Doors that may be locked, by the owner of the house,\n");
      write("   Magic Portals, that only the owner of the house may use,\n");
      write("   Exits to the church, adventurer's guild, and shop.\n");
      write("To get a new door, simply:   'build door north'.\n");
      write("Cost: " + DOORCOST + " coins to get a new exit.\n");
      write("See also: house, decorate, build, furnish, rooms.\n");
      return 1;
   }
   if (str == "rooms") {
      write("ACME DIY has connections with many reputable builders, who\n");
      write("will be glad to add an extension to your house.  Not only\n");
      write("are you supplied with a wonderful new room in your house,\n");
      write("you are sold a wonderful door to it!\n");
      write("To have the room build, simply:   'build room north', and\n");
      write("the new room and the connecting door will be put into place\n");
      write("immediately, by the 24-hour speedy-builder (Ltd) firm.\n");
      write("Due to the local housing regulations, you can have up to 10\n");
      write("rooms, but no more.  Rooms may be demolished if you wish, by\n");
      write("using the 'destroy' command.\n");
      write("Cost: " + ROOMCOST + " gp to build a new room, with another\n");
      write(DOORCOST + " gp for the exit leading to it.\n");
      write("See also: house, decorate, build, furnish, doors.\n");
      return 1;
   }
   if (str == "room_stats") {
      write("For the technically minded, you can examine the most\n");
      write("intimate details of the room's construction, with this\n");
      write("command.  However, little information will be useful,\n");
      write("unless you are a wizard.\n");
      write("Cost: Free.\n");
      write("See also: house, decorate, build, furnish.\n");
      return 1;
   }
   if (str == "invite") {
      write("Let your friends admire your new house; invite them in for a\n");
      write("house warming party!  Decorate the place with balloons and\n");
      write("tinsel, then get down and _rock_!  Yes, thats right, invite\n");
      write("will send your friends a rapid mail invitation, all they\n");
      write("to do is go the the church, or to a house, and accept it!\n");
      write("In no time at all, they'll be crowding around in your house\n");
      write("gasping at the amazing decor!\n");
      write("Cost: " + INVITECOST + " coins.\n");
      write("See also: house, expel, housekeeper.\n");
      return 1;
   }
   if ((str == "banish") || (str == "expel")) {
      write("When things get too rough, as they always do, the customer\n");
      write("can always rely on the ability to expel the trouble makers\n");
      write("from the new house.  Simply 'expel <person>'!  Yes, thats\n");
      write("right, they'll get booted into the church with the proles\n");
      write("where they belong, leaving the house nice and peaceful.\n");
      write("Naturally, if an invitation has been issued to someone, the\n");
      write("expulsion will also cancel their invitation.\n");
      write("Cost: Free.\n");
      write("See also: house, invite, housekeeper.\n");
      return 1;
   }
   if (str == "housekeeper") {
      write("This feature is not yet available.\n");
      write("See also: house, invite, expel.\n");
      return 1;
   }

   /* Below this point are all wizard help files. */
   if (this_player()->query_level() < WIZLEVEL) {
      return 0;
   }

   if (str == "wizards") {
      write("Wizards can use the following commands:                    \n");
      write("  room_stats    -- displays info about current room.       \n");
      write("  generate_lpc  -- writes LPC code into /open for the room.\n");
      write("Functions that may be useful:                              \n");
      write("  in \"/players/metaprat/houses/master_house\",            \n");
      write("     query_house(person's name); returns ptr -> house.     \n");
      write("  in house object,                                         \n");
      write("     query_room(0 to 9); returns ptr to room objects.      \n");
      write("     self_destruct(); destructs every room.                \n");
      write("See also:  room_stats, generate_lpc, query_house,          \n");
      write("  query_room, self_destruct, restore_stats, set_owner,     \n");
      write("  query_owner, find_room, get_room_index,                  \n");
      write("  query_room_position.                                     \n");
      return 1;
   }
   if (str == "generate_lpc") {
      write("Defined in: every house room.\n");
      write("Parameters: none.\n");
      write("This is currently an empty function, but at some point it may\n");
      write("be changed so that an LPC version of the room is written into\n");
      write("the /open directory.  Naturally, its not available to\n");
      write("mortals.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "query_house") {
      write("Defined in: master house object.\n");
      write("Parameters: string owner_name.\n");
      write("This function returns a pointer to the house object.  Note\n");
      write("that houses are only registered with the master house object\n");
      write("once the player has logged in.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "query_room") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: int room_number (0 to 9).\n");
      write("This function will return the object number of the room\n");
      write("specified by the index.  The room index is the same as shown\n");
      write("on the map.  Note that the object number will only be\n");
      write("returned if the room actually has been initialised by someone\n");
      write("entering it.  Room number 0 is the entrance hall.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "self_destruct") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: none.\n");
      write("This function will destruct each room in turn, moving out all\n");
      write("objects inside them to the church.  The data structures in\n");
      write("the save file will be intact, so it is used mainly for\n");
      write("updating the house version, or saving memory.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "restore_stats") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: string owner_name.\n");
      write("This function restores the house data structures from the\n");
      write("owner_name save file.  Note that the rooms will NOT be\n");
      write("updated, so it should be followed by a call to self_destruct.\n");
      write("If you want to record the data structures into the real\n");
      write("owner's file, some activity that does this must be performed.\n");
      write("(eg, changing a door type, or redecorating).\n");
      write("This effectively allows us to copy one save file onto\n");
      write("another.  The only time when this is useful is when we want\n");
      write("to change a player's name, or give a copy of his house to\n");
      write("someone.  A special owner_name is NEW_OWNER.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "set_owner") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: string owner_name.\n");
      write("Allows us to change the owner name in the house itself.  This\n");
      write("means that any changes the original owner makes will be\n");
      write("recorded under the new name.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "query_owner") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: none.\n");
      write("Guess! .. the owner name is the player's query_real_name.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "find_room") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: int loc_x, int loc_y.\n");
      write("Do not all this unless you are sure that a room exists at\n");
      write("that location (eg, get_room_index() returns >= 0).\n");
      write("It will return the object number of the room.  If the room\n");
      write("has not been initialised, it will initialise it first.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "get_room_index") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: int loc_x, int loc_y.\n");
      write("This will return the rooms index number, which is from 0 to\n");
      write("9.  If no room at that location is found, then returns -1.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "query_room_position") {
      write("Defined in: main house (room 0).\n");
      write("Parameters: int indx  (0 to 9).\n");
      write("It will return an array of int loc_x, int loc_y.\n");
      write("The X positions are: west is -1, east is + 1.\n");
      write("The Y positions are: north is -1, south is + 1.\n");
      write("This is relative to the main room, so that a room which\n");
      write("is S, W, W of the main room is ({ -2, 1 )}.\n");
      write("If there is no room at that index number, then it returns\n");
      write("a null string, and can therefore be used to locate unused\n");
      write("spaces in the data arrays.\n");
      write("See also: wizards\n");
      return 1;
   }
   if (str == "change_exit_status") {
      write("Defined in: every house room.\n");
      write("Parameters: string direction, int new_status.\n");
      write("Forces a particular exit, IN A SINGLE ROOM, to change its\n");
      write("status.  Note, since all exits are paired with the next\n");
      write("room, the operation MUST BE REPEATED in that next room,\n");
      write("otherwise the exits will get confused.  This problem\n");
      write("will not affect the data files, since only north and east\n");
      write("exits are recorded for each room.  The south and west exit\n");
      write("is inferred from the north/east exit of the room to the\n");
      write("south/west.  Thus, if the exits get totally screwed up,\n");
      write("the best thing to do is call self_destruct.\n");
      write("See also: wizards\n");
      return 1;
   }
   return 0;   /* probably just a normal help command */
}
