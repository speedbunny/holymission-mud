#ifndef __CONDITION_C__

#define __CONDITION_C__

#include "weapon_class.h"
#include "weapon_condition.h"
#include "weapon_defs.h"
#include "weapon_log.h"
#include "weapon_magic.h"

/* USERDOC:
query_condition
Function: i=query_condition()
Examples:
See also:
 
This function returns the condition level of the weapon from 
MAGICALLY ENHANCED (7) to abismally poor (0).
*/

int query_condition() {
  return curr_condition;
}

// Functions for weapon condition decay, fixing, and status.
nomask void init_conditions() {
  weap_condition=MAX_CND+(MAGIC_CND*magic_level);
  max_condition=SUPER_CND;
  switch(weap_condition) {
    case 5001..10000: curr_condition=MAGICAL_CND;
    case 901..5000  : curr_condition=SUPER_CND;
    default         : log_weapon("init_conditions");
  }
  update_mwc();
}
 
private void check_condition() {
  int tmp;

  tmp=weap_condition/CND_DIV;
  if(curr_condition!=tmp) {
    curr_condition=tmp;
    if(curr_condition+3<max_condition)
      max_condition=curr_condition+3;
    update_mwc();
  }
}

string show_condition() {
  switch(curr_condition) {
    case MAGICAL_CND  : return MAGICAL_MSG;   break;
    case SUPER_CND    : return SUPER_MSG;     break;
    case EXCELLENT_CND: return EXCELLENT_MSG; break;
    case FINE_CND     : return FINE_MSG;      break;
    case AVERAGE_CND  : return AVERAGE_MSG;   break;
    case POOR_CND     : return POOR_MSG;      break;
    case VERY_POOR_CND: return VERY_POOR_MSG; break;
    case ABISMAL_CND  : return ABISMAL_MSG;   break;
    default :
      log_weapon("show_condition");
      return "An error has occurred. Please contact an arch.\n";
      break;
  }
}

nomask void decay_condition(int amt) {
  if(amt<0)
    log_weapon("decay");
  else {
    weap_condition-=amt;
    check_condition();
  }
}

// lvl should be a number between 1 and 10.
varargs void fix_condition(int lvl,int typ) {
  int tmp,tmp_cond;

  if(lvl<1)
    lvl=1;
  else if(lvl>10)
    lvl=10;
  if(typ==2)
    tmp_cond=max_condition+1;
  else
    tmp_cond=max_condition;
  tmp=lvl*((random(CND_DIV/10)+1)+50);
  if(curr_condition +(tmp/CND_DIV)>tmp_cond) {
    curr_condition=tmp_cond;
    weap_condition=curr_condition*CND_DIV;
  }
  else {
    curr_condition+=tmp/CND_DIV;
    weap_condition+=tmp;
  }
}

#endif // __CONDITION_C__
