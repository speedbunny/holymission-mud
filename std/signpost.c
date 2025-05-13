// Generic wooden sign object.
// Can be either cloned then patched or inherited.

// Useful functions :

// ----------------------------------------------------------------------------
//     add_sign(string direction, string description)
// direction = direction you want the sign to point. This is also the direction
// the user uses when accessing the sign (ie - read west sign)
// description = information that is displayed when the user reads the sign
// ----------------------------------------------------------------------------
//     delete_sign(string direction)
// direction = direction of sign you want to remove.
// ----------------------------------------------------------------------------


inherit "/std/object.c";
#include <lw.h>
#include <obj_defs.h>
#include <setlight.h>
#include <material.h>
#include <size.h>

mapping sign=([]); // Stores the actual sign stuff. Each entry in here is a
              // direction

int add_sign(string dir, string text);
int delete_sign(string dir);

void reset(int arg) {
  if (arg) return;
  
  ::reset();
  set_name("signpost");
  set_alias_list(({"sign"}));
  set_long("A tall post with signs nailed to it.\n");
  set_short("signpost");
  set_value(0);
  set_weight(100);
  set_can_get(0);

  add_sign("west","There be dragons.\n");
}

void init() {
  add_action("_look","look");
  add_action("_exa","exa");
  add_action("_exa","examine");
  add_action("_exa","read");
}

int _look(string arg) {
  string *args;
  if (!arg) return 0; // Not for us - so quit function

  if (sizeof(args=explode(arg," "))!=3) return 0;

  if ((args[0]=="at") && (args[2]=="sign")) {
    if (member(sign,args[1]))
      write(sign[args[1]]);
    else
      write("No such sign!\n");
    return 1;
  }
  return 0;
}

int _exa(string arg) {
  string *args;
  if (!arg) return 0; // Not for us - so quit function

  if (sizeof(args=explode(arg," "))!=2) return 0;

  if (args[1]=="sign") {
    if (member(sign,args[0]))
      write(sign[args[0]]);
    else
      write("No such sign!\n");
    return 1;
  }
  return 0;
}

void add_sign(string dir, string text) {
  int size;
  string *signs;

  if (member(sign,dir))
    sign[dir]=text;
  else
    sign+=([dir : text]);
  
  size=m_sizeof(sign);
  signs=m_indices(sign);

  long_desc="A wooden signpost. It has "+size+" sign"+ (size!=1 ? "s " : " ")+
    "nailed to it:\n";
  while (size--) 
    long_desc+=signs[size]+ (size ? ", " : ".");
}

int delete_sign(string dir) {
  if (member(sign,dir)) 
    m_delete(sign,dir);
  else
    return 0;
  return 1;
}
