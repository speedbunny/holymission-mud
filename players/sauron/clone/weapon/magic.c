#ifndef __MAGIC_C__

#define __MAGIC_C__

#include "weapon_action.h"
#include "weapon_defs.h"
#include "weapon_magic.h"
#include "weapon_size.h"
 
/* USERDOC:
set_magic
Function: set_magic(i)
Examples: set_magic(5)
See also: query_magic_level, set_hit_func, modify_stat, modify_resistance
 
This function sets the magic level of weapon. Unless set, the weapon is
considered NONMAGICAL. The values that can be set are 0 to MAX_MAGIC_LVL.
Although making the weapon magical this way does very little extra in the
way of damage, it does make it somewhat easier to hit, lighter, and some
creatures may be immune to nonmagical weapons. Always use this function
with set_hit_func if the extra damage is created magically, or with
modify_stat or modify_resistance, or else they become obsolete. The value
for set_magic need not be high to represent that it is magical, but if it
can do a lot, it should be.
*/

nomask void set_magic(int mgc) {
  if(intp(mgc)) {
    if(mgc<=MAX_MAGIC_LVL)
      magic_level=mgc;
    else
      magic_level=MAX_MAGIC_LVL;
  }
  update_wt();
}
 
/* USERDOC:
query_magic_level
Function: i=query_magic_level()
Examples:
See also: set_magic

This function queries the magic level of the weapon. This should
be a value from 0 to MAX_MAGIC_LVL.
*/

int query_magic_level() {
  return magic_level;
}

/* USERDOC:
modify_resistance
Function: modify_resistance(i,i)
Examples: modify_resistance(1,20)
See also: modify_stat
 
This function modifies the resistances the wielder has to certain types
of attacks. 
*/

nomask void modify_resistance(int kind,int value) {
  if(magic_level && kind>0 && kind<MAX_NO_OF_SAVE) {
    if(!res_mod)
      res_mod=([]);
    res_mod[kind]=value;
  }
}
 
/* USERDOC:
modify_stat
Function: modify_stat(i,i)
Examples: modify_stat(0,2)
See also: modify_resistance
 
This function modifies the stat the wielder has.
*/

nomask void modify_stat(int stat,int value) {
  if(magic_level && stat>=0 && stat<=5) {
    if(!stat_mod)
      stat_mod=([]);
    stat_mod[stat]=value;
  }
}

// Modifies resistances, immunities, and stats of players wielding
// the weapon.
// 1 = start, -1 = end
private void _do_modify(int wwi) {
  int i;
  mixed *idx;

  if(!wielded_by || (wwi!=1 && wwi!=-1))
    return;

  if(res_mod) {
    idx=m_indices(res_mod);
    i=m_sizeof(res_mod)-1;
    while (i>=0) {
      wielded_by->modify_resistance(idx[i],res_mod[idx[i]]*wwi);
      i--;
    }
  }

  if(stat_mod) {
    idx=m_indices(stat_mod);
    i=m_sizeof(stat_mod)-1;
    while (i>=0) {
      wielded_by->modify_stat(idx[i],stat_mod[idx[i]]*wwi);
      i--;
    }
  }
}

// Functions to allow easier enchanted and disenchanting of weapons.
// The spellcaster must be holding the weapon and cannot be wielding
// it or will cause weight bug.
int enchant(int amt) {
  if(amt<=0)
    return -1;

  if(magic_level>=amt)
    return -1;
  if(amt>MAX_MAGIC_LVL)
    magic_level=MAX_MAGIC_LVL;
  else
    magic_level=amt;
  update_wt();
  return magic_level;
}

int disenchant(int amt) {
  if(amt<=0)
    return -1;

  if(magic_level>amt)
    return -1;
  if(amt>magic_level*2)
    magic_level=0;
  else
    magic_level-=amt/2;
  update_wt();
  return magic_level;
}

#endif // __MAGIC_C__
