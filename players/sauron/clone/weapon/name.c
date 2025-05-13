/*--------------------------------------------------------------------------*/
/* FILE: /obj/weapon/name.c                                                             */
/*                                                                          */
/* DESC: This file contains functions specific to the name of the weapon.   */
/*--------------------------------------------------------------------------*/

#ifndef __NAME_C__
 
#define __NAME_C__

#include "weapon_action.h"
#include "weapon_defs.h"
#include "weapon_name.h"

/* USERDOC:
set_id
Function: set_id(s)
Examples: set_id("sword")
See also: query_id

This function sets the id of a weapon. This is used in case you do not
wish to use the name as the id. Please use the generic weapon name as
the id of the weapon, eg. sword, axe, club, etc.
*/

void set_id(string str) {
  if(stringp(str)) {
    name_of_weapon=str;
    short_desc=CAP(str);
    long_desc="You see nothing special.\n";
  }
}

int id(string str) {
  if(stringp(str))
    return str==name_of_weapon || str==alt_name || str==alias_name;
}

/* USERDOC:
set_name
Function: set_name(s)
Examples: set_name("short sword")
See also: query_name, set_alias, set_alt_name

This function sets the name of the weapon.
*/

void set_name(string str) {
  if(stringp(str)) {
    name_of_weapon=str;
    short_desc=CAP(str);
    long_desc="You see nothing special.\n";
  }
}

/* USERDOC:
query_name
Function: s=query_name()
Examples:
See also: set_name, query_alias, query_alt_name

This function returns the name of the weapon.
*/

string query_name() {
  return name_of_weapon;
}

/* USERDOC:
set_alt_name
Function: set_alt_name(s)
Examples: set_alt_name("blade")
See also: query_alt_name

This function sets the alternate name for the weapon. It is similar
to the set_alias function and allows for more versatility.
*/

void set_alt_name(string str) {
  if(stringp(str))
    alt_name=str;
}

/* USERDOC:
query_alt_name
Function: s=query_alt_name()
Examples:
See also: query_name, query_alias, set_alt_name

This function returns the alt_name of the weapon.
*/

string query_alt_name() {
  return alt_name;
}

/* USERDOC:
set_alias
Function: set_alias(s)
Examples: set_alias("sword")
See also: query_alias

This function is used to set an alias for the weapon that the player can
use instead of it's name. Aliases should be all lowercase and is for ease
of use.
*/

void set_alias(string str) {
  if(stringp(str))
    alias_name=str;
}

/* USERDOC:
query_alias
Function: s=query_alias()
Examples:
See also: query_name, set_alias, query_alt_name

This function returns the alias of the weapon.
*/

string query_alias() {
  return alias_name;
}

/* USERDOC:
set_short
Function: set_short(s)
Examples: set_short("Short Sword")
See also: set_long
 
This function sets the short description for the weapon. It is what the
player sees when they looks in their inventory. If this is not used, the
short description is just the name.
*/

void set_short(string str) {
  if(stringp(str)) {
    short_desc=str;
    long_desc=short_desc+"\n";
  }
}
 
string short() {
  if(wielded && short_desc) {
    if(ENV(TO)!=wielded_by)
      write("BUG in "+name_of_weapon+". Tell an arch.\n");
    else
      return short_desc+" ("+where_wielded+")";
  }
  return short_desc;
}

/* USERDOC:
set_long
Function: set_long(s)
Examples:
See also: set_short
 
This function sets the long description of the weapon. It is what the
player sees when they look at the weapon. This allows a weapon to not
only be unique but to give it some detail. If this is not used, then
the long description is the same as the short description.
*/

void set_long(string str) {
  if(stringp(str))
    long_desc=str;
}
 
void long() {
  if(!stringp(long_desc))
    writelw(short_desc+"\n");
  else
    writelw(process_string(long_desc));
}

#endif // __NAME_C__
