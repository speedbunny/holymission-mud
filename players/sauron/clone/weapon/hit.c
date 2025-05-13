#ifndef __HIT_C__

#define __HIT_C__

#include "weapon_hit.h"
#include "weapon_magic.h"

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
    hit_func=ob;
  }
}

/* USERDOC:
query_hit_msg
Function: s=query_hit_msg()
Examples:
See also: set_hit_msg
 
This returns the hit message that weapon gives when it hits something.
*/

string query_hit_msg() {
  return hit_msg;
}

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

#endif // __HIT_C__
