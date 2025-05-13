/*-------------------------------------------------------------------------*/
/* FILE : base.c                                                           */
/*                                                                         */
/* Description : This is the inheritable file for objects.                 */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Sep 11 1997  Kryll        Created a new base object file containing info that
                          ALL objects, except living creatures and rooms,
                          should have. NAME must be set, everything else
                          defaults to a value.
*/

#include <obj_defs.h>
#include <lw.h>
#include <setlight.h>
#include <material.h>
#include <size.h>

#pragma strict_types

/* GLOBAL VARIABLES */
int    material;      // type of material the object is made of
int    size;          // size of the object
int    value;         // value the object is worth
int    weight;        // weight of the object
status can_get;       // whether a living can take the object
string info;          // special info about the object
string long_desc;     // long description of the object
string name;          // name of the object
string read_message;  // a written message on the object
string short_desc;    // short desc of the object
string *alias_list;   // a list of aliases to use as ids

/* PROTOTYPES */
int id(string str);
int get();
void reset(int arg);
void set_name(string str);
void set_short(string str) ;
void set_long(string str);
void set_read(string str);
void set_weight(int val);
void set_value(int val);
void set_material(int val);
void set_alias(string str);
void set_alt_name(string str);
void set_alias_list(string *str);
void set_can_get(status val);
void set_info(string str);
void set_size(int val);
string short();
void long();
string query_name();
string *query_alias_list();
nomask int query_material();
nomask string query_material_string();
int query_size();
int query_weight();
int query_value();
nomask string query_info();
string query_read();
void init();
status read(string str);


int id(string str) {
  return (member_array(str, alias_list) != -1);
}

int get() {
  return can_get;
}

void reset(int arg) {
  if(arg) return;
  can_get = 1;
  weight = 1;
  value = 0;
  material = UNKNOWN_MAT;
  size = 3;
  alias_list = ({});
}

/* USERDOC:
set_name
Function  : set_name(s)
Examples  : set_name("letter")
See also  : query_name

This function sets the name of the thing.
*/
void set_name(string str) {
  if(!stringp(str))
    return;
  name = str;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_short
Function  : set_short(s)
Examples  : set_short("A letter")
See also  : set_long

This function sets the short of the thing. It is what is seen in
inventory.
*/
void set_short(string str) {
  if(!stringp(str))
    return;
  short_desc = str;
}

/* USERDOC:
set_long
Function  : set_long(s)
Examples  : set_long("It is a letter of some importance.\n");
See also  : set_short

This function sets the long description of the thing.
*/
void set_long(string str) {
  if(!stringp(str))
    return;
  long_desc = str;
}

/* USERDOC:
set_read
Function  : set_read(s)
Examples  : set_read("My dear friends, come visit sometime.\n");
See also  : query_read

This function sets the message that the object has that the player
can read.
*/
void set_read(string str) {
  if(!stringp(str))
    return;
  read_message = str;
}

/* USERDOC:
set_weight
Function  : set_weight(i)
Examples  : set_weight(3);
See also  : query_weight

This function sets the weight of the object. Look in /doc/standards
for a list of example weights.
*/
void set_weight(int val) {
  if(!intp(val) || val<1)
    return;
  weight = val;
}

/* USERDOC:
set_value
Function  : set_value(i)
Examples  : set_value(100);
See also  : query_value

This function sets the value of the object. This value is the average value
a player gets for selling the object.
*/
void set_value(int val) {
  if(!intp(val) || val<0)
    return;
  value = val;
}

/* USERDOC:
set_material
Function  : set_material(i)
Examples  : set_material(WOOD);
See also  : query_material, query_material_string

This function sets the material type of the object. Materials are an
integer value that represents the material. A complete list is in
material.h. If you include that file, you can use the define word
instead, like the example above. The material that the majority of the
object is made of is used if it is multiple.
*/
void set_material(int val) {
  if(!intp(val) || val<1 || val>NO_OF_MATERIALS)
    return;
  material = val;
}

/* USERDOC:
set_alias
Function  : set_alias(s)
Examples  : set_alias("paper");
See also  : set_alias_list, query_alias_list, query_alias

This function sets an alias for the object. This function is OBSOLETE!
Use set_alias_list instead.
*/
void set_alias(string str) {
  if(!stringp(str))
    return;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alt_name
Function  : set_alt_name(s)
Examples  : set_alt_name("writ");
See also  : set_alias_list, query_alias_list, query_alt_name

This function sets an alternate name for the object. This function is
OBSOLETE! Use set_alias_list instead.
*/
void set_alt_name(string str) {
  if(!stringp(str))
    return;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alias_list
Function  : set_alias_list(*s)
Examples  : set_alias_list(({"writ", "paper"}));
See also  : query_alias_list

This function sets optional aliases that identifies the object besides
the name of the object.
*/
void set_alias_list(string *str) {
  int i, sz;

  if((sz = sizeof(str)) < 1)
    return;
  for(i=0; i<sz; i++) {
    if(member_array(str[i], alias_list) == -1)
      alias_list += ({ str[i] });
  }
}

/* USERDOC:
set_can_get
Function  : set_can_get(i)
Examples  : set_can_get(0)

This function sets whether the object can be picked up or not. Only two
values are valid. 1 = can get (default), 0 = can't get.
*/
void set_can_get(status val) {
  if(!intp(val))
    return;
  can_get = val;
}

/* USERDOC:
set_info
Function  : set_info(s)
Examples  : set_info("The letter was witten by Lord Aragos himself. It "+
                     "even has his seal upon it.\n");
See also  : query_info

This function sets special info about the object that could be gotten
by an ability or NPC.
*/
void set_info(string str) {
  if(!stringp(str))
    return;
  info = str;
}

/* USERDOC:
set_size
Function  : set_size(i)
See also  : query_size

This function sets the size of the object.
*/
void set_size(int val) {
  if(!intp(val) || val<0 || val>NO_OF_SIZES)
    return;
  size = val;
}

/* USERDOC:
short
Function  : s=short()
See also  : long

This function returns the short description of the object.
*/
string short() {
  if(!short_desc)
    return CAP(name);
  return short_desc;
}

/* USERDOC:
long
Function  : long()
See also  : short

This function writes the long description of the object for the player
to see.
*/
void long() {
  if(long_desc)
    writelw(long_desc);
  else
    write("You see a " + name + ".\n");
}

/* USERDOC:
query_name
Function  : s=query_name()
See also  : set_name

This function returns the name of the object.
*/
string query_name() {
  return name;
}

/* USERDOC:
query_alias_list
Function  : *s=query_alias_list()
See also  : set_alias_list

This function returns the list of ids that the living has.
*/
string *query_alias_list() {
  return alias_list;
}

/* USERDOC:
query_material
Function  : i=query_material()
See also  : set_material

This function returns the material integer value that the object is made
of predominantly. This function is not shadowable.
*/
nomask int query_material() {
  return material;
}

/* USERDOC:
query_material_string
Function  : s=query_material_string()
See also  : query_material

This function returns the string describing the type of material the
object is made of. See material.h for a list of these. This function
is not shadowable.
*/
nomask string query_material_string() {
  return MATERIAL_TYPE[material];
}

/* USERDOC:
query_size
Function  : i=query_size()
See also  : set_size

This function returns the size of the object.
*/
int query_size() {
  return size;
}

/* USERDOC:
query_weight
Function  : i=query_weight()
See also  : set_weight

This function returns the weight of the object.
*/
int query_weight() {
  return weight;
}

/* USERDOC:
query_value
Function  : i=query_value()
See also  : set_value

This function returns the value of the object.
*/
int query_value() {
  return value;
}

/* USERDOC:
query_info
Function  : s=query_info()
See also  : set_info

This function returns the info string for special info about the object.
*/
nomask string query_info() {
  return info;
}

/* USERDOC:
query_read
Function  : s=query_read()
See also  : set_read

This function returns the message string that players can read that the
object has.
*/
string query_read() {
  return read_message;
}

void init() {
  if(read_message)
    add_action("read", "read");
}

status read(string str) {
  if(!str || !id(str) || !read_message) {
    notify_fail("Read what?\n");
    return 0;
  }
  say((string)CAP((string)TP->NAME) + " reads the " + name + ".\n");
  writelw(read_message);
  return 1;
}

