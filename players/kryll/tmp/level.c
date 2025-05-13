#ifndef __P_LEVEL_C__

#define __P_LEVEL_C__

#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "player_level.h"
#include "/sys/levels.h"

/*--------------------------------------------------------------------------*/
/* Set the players level and log it                                         */
/*--------------------------------------------------------------------------*/
nomask int set_level(int val) {
  object scroll;
  int i;

#if 0
  write("set_level [" + val + "] fwz [" + fwz + "] apwz [" + apwz + "]\n");
#endif
  if(!(master_object()->set_wiz_level(name, val)) || val < -1 )
    return illegal_patch("set_level");              /* NOPE ! */
  if(val < apwz)
    is_wizard = 0;

  log_file("LEVEL", ctime() + " " + name + " (" + level + ") " +
           lev + " patched by " + TP->RNAME + "(" + TP->LVL + ")\n");

  set_savings(val, 1);
  return level = val;
}

nomask int add_exp(int val) {
  int max;

// this are the max exp a player can get at once
  max = funcall(call, TO, "query_level") * 1500;

#ifdef LOG_EXP
  if(TP && TP!=TO && query_ip_number(TP) && level<apwz
        && e>=ROOM_EXP_LIMIT)
    log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level +
             ") " + val + " exp by " + TP->RNAME +
             "(" + TP->LVL + ")" +"\n");
#endif
  /* Effect of religion: if inappropriate alignment, no XP! */
  /* Uglymouth: but improvings stats and skills should still cost xp! */
  if(val>0 && !RLM->query_ok(religion, alignment))
    return 1;

  if(val > max)
    val = max;
  experience += val;
  return 1;
}

/* This routine is needed when one wants to circumvent the alignment
   restrictions by religion, this function may only be called by other
   wizards, and never from objects. */
nomask int add_experience(int val) {
#ifdef LOG_EXP
  if(TP && TP!=TO && query_ip_number(TP) && level<apwz
        && val>=ROOM_EXP_LIMIT)
    log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level +
             ") " + val + " exp by " + TP->RNAME +
             "(" + TP->LVL + ")" +"\n");
#endif
  experience += val;
  return 1;
}

/* Ethereal Cashimor, here are the 'secretxp' routines. I hope they work...
   030393 */
nomask int query_has_been_here(string str) {
  string junk1, junk2;

  if(!str)
    return 0;
  if(!explored)
    return 0;
  return(sscanf(explored, "%s#" + str + "#%s", junk1, junk2));
}

void set_has_been_here(string str) {
  string new;
  int i;

  if(!str) return;
  if(!explored) {
    explored = "#" + str + "#";
    return;
  }
  explored += str + "#";
  return;
}

nomask int query_immortal() {
  return level>=L_APPR;
}

nomask int query_newwiz() {
  return level>=L_NEWWIZ;
}

nomask int query_wizard() {
  return level>=L_WIZ;
}

nomask int query_sage() {
  return level>=L_SAGE;
}

nomask int query_lord() {
  return level>=L_ELDER;
}

nomask int query_elder() {
  return level>=L_ELDER;
}

nomask int query_archwiz() {
  return level>=L_ARCH;
}

nomask int query_implementor() {
  return level>=L_ARCH;
}

#endif // __P_LEVEL_C__

