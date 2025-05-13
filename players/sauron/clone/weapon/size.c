#ifndef __SIZE_C__

#define __SIZE_C__

#include "weapon_class.h"
#include "weapon_defs.h"
#include "weapon_magic.h"
#include "weapon_size.h"
 
/* USERDOC:
set_size
Function: set_size(i)
Examples: set_size(4)
See also: query_size, set_two_handed, query_two_handed
 
This function sets the size of the weapon. If it is not set, it defaults
to 3 (medium). The size may not be less than 1, nor greater than MAX_SIZE.
The sizes are as follows: 1 = tiny, 2 = small, 3 = medium, 4 = large, 
5 = x-large, 6 = giant.
The purpose of this is to determine what size creature can wield what
type of weapon what way. (eg. a dwarf which is small should be able to
wield a small weapon one-handed or a medium weapon two-handed so long
as they are not designated a two handed weapon. A creature cannot wield
something that is greater than 1 size difference from themself.
*/

void set_size(int sz) {
  if(intp(sz)) {
    if(sz<1)
      weap_size=1;
    else if(sz>MAX_SIZE)
      weap_size=MAX_SIZE;
    else
      weap_size=sz;
  }
}

/* USERDOC:
query_size
Function: i=query_size()
Examples:
See also: set_size

This function returns the size of the weapon. The only options
include: 1 = tiny, 2 = small, 3 = medium, 4 = large, 5 = x-large,
6 = giant.
*/

int query_size() {
  return weap_size;
}

/* USERDOC:
set_two_handed
Function: set_two_handed()
Examples:
See also: query_two_handed

This function makes the weapon a two-handed weapon for anyone of equal
size or one size greater. This means that no shield or second weapon may
be used in conjunction with it. Either 1 for yes, or 0 for no.
*/

void set_two_handed() {
  two_handed=1;
}
 
/* USERDOC:
query_two_handed
Function: i=query_two_handed()
Examples:
See also: set_two_handed

This functions returns the value of whether the weapon is a two-handed
weapon or not. 0 = no, 1 = yes.
*/

int query_two_handed() {
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

void set_weight(int w) {
  if(intp(w)) {
    local_weight=w;
    update_wt();
  }
}

/* USERDOC:
query_weight
Function: i=query_weight()
Examples:
See also: set_weight

This function returns the weight of the weapon.
*/

int query_weight() {
  return local_weight;
}

private void update_wt() {
  int tmp;

  tmp=(class_level+5)/5+(weap_size-3)+2*two_handed-magic_level/2;
  if(tmp<=0)
    tmp=1;
  if(tmp>local_weight)
    local_weight=tmp;
}

#endif // _SIZE_C__
