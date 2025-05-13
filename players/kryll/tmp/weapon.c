/*--------------------------------------------------------------------------*/
/* FILE: /obj/weapon.c                                                      */
/*                                                                          */
/* DESC: This file contains the generic weapon object that should be        */
/*       inherited when you code a weapon.                                  */
/*       DO NOT COPY THIS FILE!                                             */
/*--------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Nov 7 1997   Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs, and added functionality for
                          easy enchanted and weapon decay.
*/

inherit "/std/object";

#include <material.h>
#include <objects.h>
#include <obj_condition.h>
#include <damage.h>
#include <defs.h>
#include <setlight.h>

#pragma strict_types

// begin PROTOTYPES

void set_wield_func(object ob);
int wield(string str);
int un_wield();
int do_unwield(string str);
int query_wielded();
void init();
nomask void set_type(int val);
nomask int query_weapon_type();
nomask void set_class(int val);
nomask int query_class();
nomask int query_mod_class();
nomask private void update_mwc();
int query_condition();
nomask void init_conditions();
nomask private void check_condition();
string show_condition();
nomask void decay_condition(int val);
varargs void fix_condition(int lvl, int typ);
int drop();
void notify_destruct(object ob);
nomask int query_weapon();
void reset(int arg);
void set_hit_func(object ob);
string query_hit_msg();
void log_weapon(string str);
nomask void set_magic(int val);
nomask int query_magic_level();
nomask void modify_resistance(int kind, int val);
nomask void modify_immunity(int kind, int val);
nomask void modify_stat(int stat, int val);
nomask private void _do_modify(int val);
nomask int enchant(int amt);
nomask int disenchant(int amt);
string short();
nomask void set_two_handed();
nomask int query_two_handed();
void set_weight(int val);
nomask private void update_wt();

// end PROTOTYPES

// begin VARIABLES

object wield_func;
object wielded_by;
object hit_func;
status two_handed;
status wielded;
string hit_msg;
string where_wielded;
int class_level;
private int curr_condition;
private int magic_level;    // magic level of weapon
private int max_condition;
private int modified_wc;
private int weapon_type;
private int weap_condition;
private mapping res_mod;
private mapping imm_mod;
private mapping stat_mod;

// end VARIABLES

/* USERDOC:
set_wield_func
Function: set_wield_func(o)
Examples: set_wield_func(this_object())
See also: set_hit_func

If this function is used, wield() will be called in 'o' when the weapon is
wielded. wield() will have this object as an argument. If wield returns
0, then the weapon will not be wielded.
*/
void set_wield_func(object ob) {
  if(objectp(ob))
    wield_func = ob;
}

int wield(string str) {
  int *where, i, counter;

  if(!str || TO!=present(str, TP))
    return 0;

  if(ENV() != TP) 
    return 0;

  if(TP->query_ghost()) {
    write("You fail.\n");
    say(CAP((string)TP->NAME) + " failed to wield " + short_desc + ".\n");
    return 1;
  }

  if(wielded) {
    write("You already wield the " + str + "\n");
    return 1;
  }

  if(class_level>MAX_WC || magic_level>MAX_WEAP_MC)
    log_weapon("wield");

  if(wield_func)
    if(!wield_func->wield(TO)) 
      return 1;

  if(two_handed || i!=0)
    where = (int *)TP->wield(TO, 2);
  else 
    where = (int *)TP->wield(TO, 1);

  if(!where || !sizeof(where)) {
    write("You fail to wield the " + name + ".\n");
    return 1; 
  }

  wielded_by = TP;
  update_wt();

  str = "You wield the " + name + " in your ";
  str += (string)TP->get_hand_name(where[0]);
  where_wielded = (string)TP->get_hand_name(where[i]);
  counter = sizeof(where);

  for(i=1; i<counter; i++) {
    str += " and " + (string)TP->get_hand_name(where[i]);
    where_wielded += " & " + (string)TP->get_hand_name(where[i]);
  }
  if(counter > 1) {
    str += " hands\n";
    where_wielded += " hands";
  }
  else {
    str += " hand\n";
    where_wielded += " hand";
  }
  wielded = 1;
  _do_modify(1);
  write(str);
  return 1;
}

// called from living, do not change !!!
int un_wield() {
  if(wielded) {
    wielded = 0;
  }
  return 1;
}

int do_unwield(string str) {
  if(!str || TO!=present(str, TP))
    return 0;

  else if(wielded) {
    if(!wielded_by->stop_wielding(TO))
      wielded = 1;          // could be removed by living, so set it again
    else {
      wielded = 0;
      TELL(wielded_by, "You unwield the " + name + ".\n");
      say(CAP((string)TP->NAME) + " unwields " + name + ".\n");
      _do_modify(-1);
      wielded_by = 0;
    }
    return 1;
  }
  else
    return 0;
}

/* USERDOC:
query_wielded
Function: i=query_wielded()

This function returns whether the weapon is wielded or not. 0 = not
wielded, and 2 returns something else.
*/
int query_wielded() {
  return wielded;
}

void init() {
  ::init();
  add_action("wield", "wield");
  add_action("do_unwield", "unwield");
}

/* USERDOC:
set_type
Function: set_type(i)
Examples: set_type(2)
See also: query_weapon_type, query_kind, set_kind
 
This function sets what type of weapon this is. The possible values
are found in objects.h.
The various types are not only there to determine how to hit various
monsters, but also damage, and how useful it may be against various
armours and monsters.
*/
nomask void set_type(int val) {
  if(!intp(val))
    return;
  if(val>NO_OF_WEAPON_TYPES || val<1)
    weapon_type = 0;
  else
    weapon_type = val;
}

/* USERDOC:
query_weapon_type
Function: i=query_weapon_type()
Examples:
See also: set_type

This function returns what type of weapon this is. Possible options
can be found in objects.h. This function is not shadowable.
*/
nomask int query_weapon_type() {
  return weapon_type;
}

/* USERDOC:
set_class
Function: set_class(i)
Examples: set_class(10)
See also: weapon_class
 
This function sets the weapon class of the weapon. This is a value between
1 and MAX_WEAP_CLASS indicating how strong the weapon is.
*/
nomask void set_class(int val) {
  if(!intp(val))
    return;
  if(val > MAX_WC)
    val = MAX_WC;
  else if(val < 0)
    val = 0;
  class_level = val;
  TO->update_wt();
}

/* USERDOC:
query_class
Function: i=query_class()
See also: set_class

This function queries the weapon class of the weapon. This should
be a value from 0 to MAX_WEAP_CLASS.
*/
nomask int query_class() {
  return class_level;
}

/* USERDOC:
query_mod_class
Function: i=query_mod_class()
See also: set_class, query_class
 
This function queries the modified weapon class of the weapon. This
value is computed from the weapon class, magic level, and the
condition of the weapon.
*/
nomask int query_mod_class() {
  return modified_wc;
}

nomask private void update_mwc() {
  modified_wc = class_level + magic_level + (curr_condition - FINE_CND);
}

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
  weap_condition = MAX_CND + (MAGIC_CND * magic_level);
  max_condition = SUPER_CND;
  switch(weap_condition) {
    case 5001..10000: curr_condition = MAGICAL_CND;
    case 901..5000  : curr_condition = SUPER_CND;
    default         : log_weapon("init_conditions");
  }
  update_mwc();
}
 
nomask private void check_condition() {
  int tmp;

  tmp = weap_condition / CND_DIV;
  if(curr_condition != tmp) {
    curr_condition = tmp;
    if(curr_condition+3 < max_condition)
      max_condition = curr_condition + 3;
    update_mwc();
  }
}

string show_condition() {
  switch(curr_condition) {
    case MAGICAL_CND  : return MAGICAL_MSG; break;
    case SUPER_CND    : return SUPER_MSG; break;
    case EXCELLENT_CND: return EXCELLENT_MSG; break;
    case FINE_CND     : return FINE_MSG; break;
    case AVERAGE_CND  : return AVERAGE_MSG; break;
    case POOR_CND     : return POOR_MSG; break;
    case VERY_POOR_CND: return VERY_POOR_MSG; break;
    case ABISMAL_CND  : return ABISMAL_MSG; break;
    default :
      log_weapon("show_condition");
      return "An error has occurred. Please contact an arch.\n";
      break;
  }
}

nomask void decay_condition(int val) {
  if(val < 0)
    log_weapon("decay");
  else {
    weap_condition -= val;
    check_condition();
  }
}

// lvl should be a number between 1 and 10.
varargs void fix_condition(int lvl, int typ) {
  int tmp, tmp_cond;

  if(lvl < 1)
    lvl = 1;
  else if(lvl > 10)
    lvl = 10;
  if(typ == 2)
    tmp_cond = max_condition+1;
  else
    tmp_cond = max_condition;
  tmp = lvl * ((random(CND_DIV / 10) + 1) + 50);
  if(curr_condition + (tmp/CND_DIV) > tmp_cond) {
    curr_condition = tmp_cond;
    weap_condition = curr_condition * CND_DIV;
  }
  else {
    curr_condition += tmp / CND_DIV;
    weap_condition += tmp;
  }
}

int drop() {
  if(wielded) {
    if(!wielded_by->stop_wielding(TO))
      return 1;
    else {
      _do_modify(-1);
      wielded = 0;
      TELL(wielded_by, "You drop your wielded weapon.\n");
      wielded_by = 0;
      return 0;
    }
  }
  else
    return 0;
}

void notify_destruct(object ob) {
  if(wielded_by)
    _do_modify(-1);
}

/* USERDOC:
query_weapon
Function: i=query_weapon()

This function returns 1, to identify this object as a weapon.
*/
nomask int query_weapon() {
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  wielded = 0; 
  wielded_by = 0;
  two_handed = 0; 
  weapon_type = 0;
  class_level = 0;
  magic_level = 0;
  set_material(METAL);
  if(!weap_condition)
    init_conditions();
}

/* USERDOC:
set_hit_func
Function: set_hit_func(o)
Examples: set_hit_func(this_object())
See also: set_wield_func

When an object is set in this function, the functions weapon_hit() and
magic_hit() will be called in o. The value returned by these is the
value of additional damage done with the hits. Armour still applies,
and specific types of damage should be specified, since they are
special.
*/
void set_hit_func(object ob) {
  if(objectp(ob) && magic_level) {
    hit_func = ob;
  }
}

/* USERDOC:
query_hit_msg
Function: s=query_hit_msg()
See also: set_hit_msg
 
This returns the hit message the weapon gives when it hits something.
*/
string query_hit_msg() {
  return hit_msg;
}

#if 0
// This is a waste of speed :( ... Same below.
int hit(object ob) {
  if(objectp(ob) && hit_func)
    return hit_func->weapon_hit(ob); 
  return 0;
}

int hit2(object ob) {
  if(objectp(ob) && hit_func)
    return hit_func->magic_hit(ob);
  return 0;
}
#endif

void log_weapon(string str) {
  if(!stringp(str))
    return;
  if(TP) {
    log_file("ILLEGAL", ctime() + " : " + TP->RNAME +
             " had an illegal weapon " +
             short_desc + "(" + name + ") with WC=" + 
             class_level + " creator=" + creator(TO) + " (" +
             file_name(TO) + ") problem=" + str + "\n");
  }
  else 
    log_file("ILLEGAL", ctime() + " : name=" + short_desc + "(" +
             name + ") WC=" + class_level + " problem=" +
             str + "\n");
}

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
nomask void set_magic(int val) {
  if(!intp(val))
    return;
  if(val <= MAX_WEAP_MC)
    magic_level = val;
  else
    magic_level = MAX_WEAP_MC;
  update_wt();
}
 
/* USERDOC:
query_magic_level
Function: i=query_magic_level()
See also: set_magic

This function queries the magic level of the weapon. This should
be a value from 0 to MAX_MAGIC_LVL.
*/
nomask int query_magic_level() {
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
nomask void modify_resistance(int kind, int val) {
  if(magic_level && kind>=0 && kind<NO_OF_DAMAGE_TYPES) {
    if(!res_mod)
      res_mod = ([]);
    res_mod[kind] = val;
  }
}
 
/* USERDOC:
modify_immunity
Function: modify_immunity(i,i)
Examples: modify_immunity(1,20)
See also: modify_resistance, modify_stat
 
This function modifies the immunities the wielder has to certain types
of attacks. 
*/
nomask void modify_immunity(int kind, int val) {
  if(magic_level && kind>=0 && kind<NO_OF_DAMAGE_TYPES) {
    if(!imm_mod)
      imm_mod = ([]);
    imm_mod[kind] = val;
  }
}
 
/* USERDOC:
modify_stat
Function: modify_stat(i,i)
Examples: modify_stat(0,2)
See also: modify_resistance
 
This function modifies the stat the wielder has.
*/
nomask void modify_stat(int stat, int val) {
  if(magic_level && stat>=0 && stat<=5) {
    if(!stat_mod)
      stat_mod = ([]);
    stat_mod[stat] = val;
  }
}

// Modifies resistances, immunities, and stats of players wielding
// the weapon.
// 1 = start, -1 = end
nomask private void _do_modify(int val) {
  int   i;
  mixed *idx;

  if(!wielded_by || (val!=1 && val!=-1))
    return;

  if(res_mod) {
    idx = m_indices(res_mod);
    i = m_sizeof(res_mod) - 1;
    while(i >= 0) {
      wielded_by->modify_resistance(idx[i], res_mod[idx[i]]*val);
      i--;
    }
  }

  if(imm_mod) {
    idx = m_indices(imm_mod);
    i = m_sizeof(imm_mod) - 1;
    while(i >= 0) {
      wielded_by->modify_immunity(idx[i], imm_mod[idx[i]]*val);
      i--;
    }
  }

  if(stat_mod) {
    idx = m_indices(stat_mod);
    i = m_sizeof(stat_mod) - 1;
    while(i >= 0) {
      wielded_by->modify_stat(idx[i], stat_mod[idx[i]]*val);
      i--;
    }
  }
}

// Functions to allow easier enchanted and disenchanting of weapons.
// The spellcaster must be holding the weapon and cannot be wielding
// it or will cause weight bug.
nomask int enchant(int amt) {
  if(amt <= 0)
    return -1;

  if(magic_level >= amt)
    return -1;
  if(amt > MAX_WEAP_MC)
    magic_level = MAX_WEAP_MC;
  else
    magic_level = amt;
  update_wt();
  return magic_level;
}

nomask int disenchant(int amt) {
  if(amt <= 0)
    return -1;

  if(magic_level > amt)
    return -1;
  if(amt > magic_level*2)
    magic_level = 0;
  else
    magic_level -= amt/2;
  update_wt();
  return magic_level;
}

string short() {
  if(wielded && short_desc) {
    if(ENV(TO) != wielded_by)
      write("BUG in " + name + ". Tell an arch.\n");
    else
      return short_desc + " (" + where_wielded + ")";
  }
  return short_desc;
}

/* USERDOC:
set_two_handed
Function: set_two_handed()
See also: query_two_handed

This function makes the weapon a two-handed weapon for anyone of equal
size or one size greater. This means that no shield or second weapon may
be used in conjunction with it. Either 1 for yes, or 0 for no.
*/
nomask void set_two_handed() {
  two_handed = 1;
}
 
/* USERDOC:
query_two_handed
Function: i=query_two_handed()
See also: set_two_handed

This functions returns the value of whether the weapon is a two-handed
weapon or not. 0 = no, 1 = yes.
*/
nomask int query_two_handed() {
  return two_handed;
}

/* USERDOC:
set_weight
Function: set_weight(i)
Examples: set_weight(5)
See also: query_weight
 
This function sets the weight of the weapon. The weapon may not 
weigh less than 1, nor may it weigh less than the following formula:

*/
void set_weight(int val) {
  ::set_weight(val);
  update_wt();
}

nomask private void update_wt() {
  int tmp;

  tmp = (class_level + 5)/5 + (size - 3) +
        (2 * two_handed) - (magic_level / 2);
  if(tmp <= 0)
    tmp = 1;
  if(tmp > weight)
    weight = tmp;
}

