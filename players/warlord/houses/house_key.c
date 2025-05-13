
 /* house_key.c     Metaprat     6th April 1992  */

 /*  The autoloading component of the player's house.  This checks to see */
 /*  if there is an extant house for that player, and clones one if not.  */
 /*  Also, it provides transport from the starting location to the house. */


#define FILENAME     "/players/silas/houses/house_key"
#include "/players/silas/houses/house_defines.h"

string owner_name;          /* Taken from environment() or this_player()  */
string house_file_name;     /* May not be correct; check when autoloading */
int    args_initialised;    /* Start new house from scratch? (in reset)   */


id(str) {
   return (str == "key")  ||  (str == "house key")  ||  (str == short());
}


short() {
   if (environment() && living(environment())) {
      return environment()->query_name() + "'s house key";
   }
   if (!owner_name) {
      return "WARNING: unclaimed house key";  /* should not happen normally */
   }
   return capitalize(owner_name) + "'s house key";  /* nor this */
}


long() {
   write("A heavy brass Chubb key, which opens up your house.  If you're\n");
   write("in the church, or already in someone's home, type 'house'.\n");
   write("For information about houses, type 'help house' when you are\n");
   write("at home.\n");
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


query_auto_load() {
   return FILENAME + ":" + house_file_name;
}



init_arg(arg) {
   object ob;
   /* NOTE: The house file name is only a short-cut, */
   /* and may not actually be correct.               */

   house_file_name = arg;
   args_initialised = 1;
   owner_name = this_player()->query_real_name();
   if ((!house_file_name)               ||
       (catch(ob=find_object(house_file_name))) || !ob || /* Moonchild 241092 */
       (find_object(house_file_name)->query_owner() !=
        this_player()->query_real_name())) {
      house_file_name = "";
   }
}



reset(arg) {
   if (arg) {
      return;
   }
   if (args_initialised) {
      return;
   }
   if (this_player() &&
       living(this_player()) &&
       (!this_player()->query_npc())) {
      owner_name = this_player()->query_real_name();
   }
   else if (DEBUGLEVEL) {
      log_file(LOGFILE,
         "House_key: Tried to reset(), but this_player() not acceptable.\n");
   }
}



init() {
   if (environment(this_object()) == this_player()) {
      add_action("go_home","house");
   }
   if (this_player()->query_level() > WIZLEVEL) {
      add_action("key_stats","key_stats");
   }
}



go_home() {
   string where;
   string discard;

   if ((!house_file_name) ||
       (house_file_name == "") ||
       (!find_object(house_file_name))) {
      restore_house();
   }
   where = file_name(environment(this_player())) + "junk";
   if (this_player()->query_level() < WIZLEVEL) {
      if ((!sscanf("/" + where, CHURCH + "%s", discard)) &&
          (!sscanf("/" + where, HOUSE  + "%s", discard))) {
         write("You can only go home from the church, or from a house.\n");
         return 1;
      }
   }
   write("You leave, and go to your lovely house.\n");
   this_player()->move_player("to a lovely house#" + house_file_name);
   return 1;
}


key_stats() {
   write("key statistics:\n");
   write("File name:  " + file_name(this_object()) + ".\n");
   write("House file: " + house_file_name          + ".\n");
   write("Owner:      " + owner_name               + ".\n");
   write("Autoloaded: " + args_initialised         + ".\n");
   write("Debug lev:  " + DEBUGLEVEL               + ".\n");
   return 1;
}



restore_house() {
   object house;

 /*  if (DEBUGLEVEL) {
      log_file(LOGFILE,
         "House_key: Restore_house(" + owner_name + "), at time: " +
         ctime(time()) + ".\n");
   } */
   house = clone_object(HOUSE);
   house->set_owner(this_player()->query_real_name());
   house->restore_stats(this_player()->query_real_name());
   house_file_name = file_name(house);
}


