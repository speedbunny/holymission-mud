#ifndef __GENERAL_C__

#define __GENERAL_C__

#include "weapon_action.h"
#include "weapon_condition.h"
#include "weapon_class.h"
#include "weapon_defs.h"
#include "weapon_general.h"
#include "weapon_magic.h"
#include "weapon_size.h"
 
/* USERDOC:
set_info
Function: set_info(s)
Examples:
See also: query_info
 
This function is used to assign some information to the weapon, that
the player may obtain through some other means, eg. an npc. If this
is not set, then the weapon is obviously ordinary and has nothing
special attached to it. You should assign this to special weapons,
so that the player might get some information about it.
*/

void set_info(string str) {
  if(stringp(str))
    info=str;
}

/* USERDOC:
query_info
Function: s=query_info()
Examples:
See also: set_info

This returns any hidden info about the weapon that can only be obtained
through special functions or from npcs.
*/

string query_info() {
  return info;
}
 
/* USERDOC:
set_value
Function: set_value(i)
Examples: set_value(1000)
See also: query_value
 
This function sets the value of the weapon in gold. On average, 
a weapon should be worth approximately 200 times its weapon class,
for normal weapons. If it is magical, or has some special ability,
then it should be worth more.
*/

void set_value(int v) {
  if(intp(v))
    value=v;
}

/* USERDOC:
query_value
Function: i=query_value()
Examples:
See also: set_value

This function returns the value of the weapon in gold.
*/

int query_value() {
  return value;
}

int get() {
  return 1;
}
 
int drop() {
  if(wielded) {
    if(!wielded_by->stop_wielding(TO))
      return 1;
    else {
      _do_modify(-1);
      wielded = 0;
      tell_object(wielded_by,"You drop your wielded weapon.\n");
      wielded_by=0;
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
Examples:
See also:

This function returns 1, to identify this object as a weapon.
*/

int query_weapon() {
  return 1;
}

void reset(int flag) {
  if(flag)
    return;

  wielded=0; 
  wielded_by=0;
  value=0;
  two_handed=0; 
  weapon_kind=0;
  weapon_type=0;
  weap_size=3;
  class_level=0;
  magic_level=0;
  if(!weap_condition)
    init_conditions();
}

#endif // __GENERAL_C__
