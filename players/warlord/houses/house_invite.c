 /* house_invite.c  */
 /* An object that is given to another player, to invite them to the first */
 /* player's house.  It has a short time-out period, and only works from   */
 /* the church, or a house.                                                */
#include "/players/silas/houses/house_defines.h"

string invited_house;  /* house flag */
string inviter;        /* owner's flag */
string invitee;        /* who invited flag */

id(str) {
   return (str == "invitation")  ||  (str == short())  ||
          (lower_case(str) == inviter + "'s invitation")   ||
          (lower_case(str) == inviter + "s invitation")  ;
}

short() {
   if (!inviter) {
      return "A blank invitation";
   }
   return "invitation to visit " + capitalize(inviter) + "'s house";
}

long() {
   write("This is an invitation to visit " + capitalize(inviter) + "'s\n");
   write("house.  It will only last for a short time, so quickly go to\n");
   write("the church (or your own house), if you want to accept it.  The\n");
   write("command is 'accept invitation' or 'accept " +
         capitalize(inviter) + "'s invitation'.\n");
   write("'refuse invitation' gets rid of it.\n");
}


get() { return 0; }
drop() {return 1; }
query_weight() { return 0; }
query_value() { return 0; }


init() {
   if (environment(this_object()) == this_player()) {
      add_action("accept","accept");
      add_action("refuse","refuse");
   }
   if (this_player()->query_level() > WIZLEVEL) {
      add_action("invite_stats","invite_stats");
   }
}


accept(str) {
   string discard;
   string here;

   if ((str) && (!id(str))) {
      return 0;
   }
   if (this_player()->query_level() < WIZLEVEL) {
      here = file_name(environment(this_player())) + "junk" ;
      if ((!sscanf("/" + here, CHURCH + "%s", discard)) &&
          (!sscanf("/" + here, HOUSE  + "%s", discard))) {
         write("You can only accept the invitation if you are in the\n");
         write("church, or in a house.\n");
         return 1;
      }
   }
   if (!find_object(invited_house)) {
      write("Sorry, the invitation is invalid, and the house is empty!\n");
      destruct(this_object());
      return 1;
   }
   write("You visit " + capitalize(invitee) + ".\n");
   if (find_player(inviter)) {
      tell_object(find_player(inviter),
         this_player()->query_name() + " accepts your kind invitation.\n");
   }
   this_player()->move_player("to " + capitalize(inviter) + "'s house#" +
                              invited_house);
   remove_call_out("timeout");
   destruct(this_object());
   return 1;
}


refuse(str) {
   if ((str) && (!id(str))) {
      return 0;
   }
   if (DEBUGLEVEL > 1) {
      log_file(LOGFILE,
         "house_invite: " + capitalize(invitee) + " refuses " +
         capitalize(inviter) + "'s invitation.\n");
   }
   write("You rip " + capitalize(inviter) + "'s invitation to shreds.\n");
   if (find_player(inviter)) {
      tell_object(find_player(inviter),
         capitalize(invitee) + " refuses your kind invitation.\n");
   }
   say( capitalize(invitee) +
       " rips " + capitalize(inviter) + "'s invitation to shreds.\n",
       this_player());
   remove_call_out("timeout");
   destruct(this_object());
   return 1;
}



timeout() {
   if (DEBUGLEVEL > 1) {
      log_file(LOGFILE,
         "house_invite: " + capitalize(invitee) + " fails to decide " +
         " about " + capitalize(inviter) + "'s invitation in time.\n");
   }
   if (find_player(inviter)) {
      tell_object(find_player(inviter),
         capitalize(invitee) +
         " fails to respond to your invitation within the time limit.\n");
   }
   tell_object(find_player(invitee),
   "You fail to respond quickly enough to the invitation, and it\n" +
       "turns to dust with old age.\n");
   destruct(this_object());
}


invite_stats() {
   write("invitation statistics:\n");
   write("File name:  " + file_name(this_object()) + ".\n");
   write("House file: " + invited_house            + ".\n");
   write("Inviter:    " + inviter                  + ".\n");
   write("Invitee:    " + invitee                  + ".\n");
   write("Debug lev:  " + DEBUGLEVEL               + ".\n");
   return 1;
}

/* this sets the player who is sending */
set_inviter(str) {
   inviter = str;
   call_out("timeout",TIMEOUT);
}

/* this sets the player who is recieving the invite */
set_invitee(str) {
   invitee = str;
}


set_invited_house(str) {
   invited_house = str;
}
