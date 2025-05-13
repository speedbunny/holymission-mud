#ifndef __P_MISC_C__

#define __P_MISC_C__

#include "player_defs.h"
#include "player_misc.h"

nomask int query_balance() {
  return bank_balance;
}

nomask void set_balance(int val) {
  bank_balance = val;
  return;
}

nomask void add_balance(int val) {
  bank_balance += val;
  return;
}

nomask string query_wimpydir() {
  if(stringp(env_var["WIMPYDIR"]))
    return env_var["WIMPYDIR"];
  return "none";
}

/*--------------------------------------------------------------------------*/
/* If the players is wimpying then, lets make him run away.                 */
/*--------------------------------------------------------------------------*/
int check_wimpy(object attacker_ob) {
  object here;

  here = ENV(TO);

/*
 * Blade: Boolean changed to check if players are
 * in the same room as the attacking monster.
 * This caused problems when a player poisons
 * a monster
 */
  if(attacker_ob && (hit_point < max_hp * whimpy / 100)
                 && (here == ENV(attacker_ob))) {
// Moonchild, wimpydir
    if(env_var["WIMPYDIR"]) {
      string *qdd;
      qdd = (string *)here->query_room("dest_dir");
      if((pointerp(qdd) && member_array(env_var["WIMPYDIR"], qdd) != -1)
             || member_array(env_var["WIMPYDIR"], DIRECTIONS) != -1) {
        command(env_var["WIMPYDIR"], TO);
        if(ENV() != here) {
          TELL(TO, "Your legs run away with you!\n");
          TELLR(here, TO->RNAME + " runs away in sheer terror!!!\n");
          return 0;
        }
      }
    }

/* Allow shadowing of run_away(), Ethereal Cashimor */
    TO->run_away();
    if(ENV() != here) {
      return 0;
    }
  }

  return 1;
}

/*
 * Temporary move the player to another destination and execute
 * a command.
 */
static int in_room(string str) {
  object room, old_room;
  string cmd;

  if(!str)
    return 0;
  if(sscanf(str, "%s %s", room, cmd) != 2) {
    write("Usage: in ROOM CMD\n");
    return 1;
  }
  room = valid_read(room, WIZ);
  if(!room) {
    write("Invalid file name.\n");
    return 1;
  }
  old_room = ENV();
  MOVE(TO, room);
  command(cmd);
  if(old_room)
    MOVE(TO, old_room);
  else
    write("Could not go back again.\n");
  return 1; 
}

nomask static void set_wimpydir(string str) {
  if(str == "NULL") {
    env_var["WIMPYDIR"] = 0;
    write("Wimpydir switched off.\n");
  }
  else {
    env_var["WIMPYDIR"] = str;
    write("Wimpydir set to: " + env_var["WIMPYDIR"] + ".\n");
  }
  return;
}

#endif // __P_MISC_C__
