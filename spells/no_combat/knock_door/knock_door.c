/* ################################################################
   #                                                              #
   #                    Mage knock door                           #
   #                                                              #
   ###############################################(C) Llort########
 * 121297: Uglymouth: Adapted code to allow using /room/doorroom.c
 *                    At the same time updated code efficiency a bit.
 */

#include <doorroom.h>
#include <sys_defs.h>
#include "/spells/spell.h"

inherit "/spells/spell";

static void knock_old_door(string str, object door, int act_skill,
                           int max_skill) {
  if(!door->query_locked()) {
    write("Your spell fizzles on the unlocked door.\n");
    say(TP->TNAME+" tries to cast a spell on the "+str+" but fails.\n",
        TP, TP,
        "Someone tries to cast a spell on the "+str+" but fails.\n");
  }
  else if(check_success(act_skill, max_skill)) {
    write("The lock glows bright for a moment.\n");
    say("The lock on the "+str+" glows bright for a moment.\n");
    door->set_locked(0);
    if((door = door->query_partner_door()))
      door->set_locked(0);
  }
}

static void knock_inheritable_door(string str, int act_skill,
                                   int max_skill) {
  object where;

  where = ENV(TP);
  if(where->query_lock_status(str) == DOOR_UNLOCKED) {
    write("Your spell fizzles on the unlocked door.\n");
    say(TP->TNAME+" tries to cast a spell on the "+str+" but fails.\n",
        TP, TP,
        "Someone tries to cast a spell on the "+str+" but fails.\n");
  }
  else if(check_success(act_skill, max_skill)) {
    write("The lock glows bright for a moment.\n");
    say("The lock on the "+str+" glows bright for a moment.\n");
    where->set_lock_status(str, DOOR_UNLOCKED);
    call_other(where->query_other_door(str), "set_lock_status", str,
               DOOR_UNLOCKED);
  }
}

int speed(int lev) {
  if(lev > 20)
    return -1;
  else if(lev > 10)
    return 0;
  else
    return 1;
}

void release_spell(string str, int act_skill, int max_skill) {
  string dest, *all_doors;
  object door;

  if(!str || str == "")
    write("Knocking on heaven's door?\n");

  else if(!(door = present(str, ENV(TP)))) {
    all_doors = ENV(TP)->query_doors();
    if(!all_doors)
      write("Your spell fizzles as it cannot find its target.\n");
    else if(member_array(str, all_doors) == -1)
      write("Your spell fizzles as it cannot find its target.\n");
    else
      knock_inheritable_door(str, act_skill, max_skill);
  }
  else if(str != "door" && sscanf(str, "%s door", dest) !=1)
    write("Your spell fizzles as it cannot find its target.\n");
  else if(str == "door" && door->number_of_doors() != 1)
    door->which_door();
  else
    knock_old_door(str, door, act_skill, max_skill);
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("knock door");
  set_kind(NO_COMBAT);
  set_syntax("cast 'knock door' [door]");
  set_guild_allowed(5, 8);
  set_save_vs(NO_SAVE);
  set_cost(40);
  set_player_help("This spell will magically cause locked doors to unlock. \
However, this spell will not work on all doors, since some have been \
magically protected from this spell.");
}
