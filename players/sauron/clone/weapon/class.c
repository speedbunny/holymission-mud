#ifndef __CLASS_C__

#define __CLASS_C__

#include "weapon_class.h"
#include "weapon_defs.h"
#include "weapon_condition.h"
#include "weapon_magic.h"

/* USERDOC:
set_kind
Function: set_kind(i)
Examples: set_kind(2)
See also: query_weapon_kind

This function sets the weapon's kind of material. Possible choices
include: 1 = iron, 2 = wood, 3 = bone.
The material makes a difference in how sturdy the weapon is and how
much damage is possible, plus what type of monster or armour it 
could affect.
*/

void set_kind(int i) {
  if(intp(i)) {
    if(i>NO_OF_KINDS || i<1)
      weapon_kind=0;
    else
      weapon_kind=i;
  }
}

/* USERDOC:
query_weapon_kind
Function: i=query_weapon_kind()
Examples:
See also: set_kind

This function returns what the weapon is made of. Possible options
include: 0 = iron, 1 = wood, 2 = bone.
*/

int query_weapon_kind() {
  return weapon_kind;
}

/* USERDOC:
set_type
Function: set_type(i)
Examples: set_type(2)
See also: query_weapon_type, query_kind, set_kind
 
This function sets what type of weapon this is. There are seven possible
values: 1 = slashing, 2 = bludgeoning, 3 = piercing, 4 = slash & bludgeon,
5 = slash & pierce, 6 = bludgeon & pierce, 7 = all three.
The various types are not only there to determine how to hit various
monsters, but also damage, and how useful it may be against various
armours and monsters.
*/

void set_type(int i) {
  if(intp(i)) {
    if(i>NO_OF_TYPES || i<1)
      weapon_type=0;
    else
      weapon_type=i;
  }
}

/* USERDOC:
query_weapon_type
Function: i=query_weapon_type()
Examples:
See also: set_type

This function returns what type of weapon this is. Possible options
include: 0 = slashing, 2 = bludgeoning, 3 = piercing, 4 = slashing
& bludgeoning, 5 = slashing & piercing, 6 = bludgeoning &
piercing, 7 = all three.
*/

int query_weapon_type() {
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

void set_class(int class) {
  if(intp(class)) {
    if(class<=MAX_WEAP_CLASS)
      class_level=class;
    else
      class_level=MAX_WEAP_CLASS;
  }
  TO->update_wt();
}

/* USERDOC:
query_class
Function: i=query_class()
Examples:
See also: set_class

This function queries the weapon class of the weapon. This should
be a value from 0 to MAX_WEAP_CLASS.
*/

int query_class() {
  return class_level;
}

/* USERDOC:
query_mod_class
Function: i=query_mod_class()
Examples:
See also: set_class, query_class
 
This function queries the modified weapon class of the weapon. This
value is computed from the weapon class, magic level, and the
condition of the weapon.
*/

int query_mod_class() {
  return modified_wc;
}

private void update_mwc() {
  modified_wc=class_level+magic_level+(curr_condition-FINE_CND);
}

#endif // __CLASS_C__
