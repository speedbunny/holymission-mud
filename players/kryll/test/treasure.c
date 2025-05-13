/*-------------------------------------------------------------------------*/
/* FILE : treasure.c                                                       */
/*                                                                         */
/* Description : This is the inheritable file for treasure.                */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
Jun 25 1997  Kryll        Removed alt_name and alias and added alias_list.
                          Made query_name and query_treasure nomask. 
*/

#include "/obj/obj_defs.h"
#include "/obj/lw.h"
#include "/obj/setlight.h"

#pragma strict_types

int    local_weight;
int    value;
string treas_id;
string info;
string long;
string name;
string short;
string *alias_list;

/* PROTOTYPES */
void reset(int arg);
int id(string str);
int get();
void set_id(string str);
void set_name(string str);
void set_alias(string str);
void set_alt_name(string str);
void set_long(string str);
void set_value(int v);
void set_weight(int w);
void set_info(string str);
void set_short(string str);
void set_alias_list(string *str);
string short();
void long();
nomask string query_name();
int query_value();
int query_weight();
string query_info();
string *query_alias_list();
nomask string query_treasure_id();
nomask int query_treasure();
void init();

void reset(int arg) {
  if(arg) return;
  local_weight = 1;
  value = 0;
  alias_list = ({});
}

int id(string str) {
  return (member_array(str, alias_list) + 1);
}

int get(){
  return 1;
}

/* USERDOC:
set_id
Function  : set_id(s)
Examples  : set_id("sapphire")

This function sets the id of the treasure.
*/
void set_id(string str) {
  treas_id = str;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_name
Function  : set_name(s)
Examples  : set_name("large sapphire");
See also  : query_name
 
This function sets the name of the treasure.
*/
void set_name(string str) {
  name = str;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alias
Function  : set_alias(s)
Examples  : set_alias("sapphire")
See also  : query_alias_list
 
This function sets the alias of the treasure. With the addition
of set_alias_list, this function becomes obsolete. Do not use.
*/
void set_alias(string str) {
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alt_name
Function  : set_alt_name(s)
Examples  : set_alt_name("gem")
See also  : query_alias_list
 
This function sets the alt_name of the treasure. With the addition
of set_alias_list, this function becomes obsolete. Do not use.
*/
void set_alt_name(string str) {
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alias_list
Function  : set_alias_list(*s)
Examples  : set_alias_list(({"white diamond","gem"}))
See also  : query_alias_list

This function sets an alternative choice of ids besides what
was set with set_name and set_id.
*/
void set_alias_list(string *str) {
  alias_list += str;
}

/* USERDOC:
set_long
Function  : set_long(s)
Examples  : set_long("A beautifully cut sapphire about the size of "+
                     "a normal human's fist.\n");
See also  : set_short
 
This function sets the long of the treasure.
*/
void set_long(string str) {
  long = str;
}

/* USERDOC:
set_value
Function  : set_value(i)
Examples  : set_value(3500)
See also  : query_value
 
This function sets the value of the treasure in gold.
*/
void set_value(int v) {
  value = v;
}

/* USERDOC:
set_weight
Function  : set_weight(i)
Examples  : set_weight(2)
See also  : query_weight
 
This function sets the weight of the treasure.
*/
void set_weight(int w) {
  local_weight = w;
}

/* USERDOC:
set_info
Function  : set_info(s)
Examples  : set_info("This sapphire looks to be the same one that "+
                     "the great king Linea had about 200 years ago.\n")

This function sets some extra information about the treasure.
*/
void set_info(string str) {
  info = str;
}

/* USERDOC:
set_short
Function  : set_short(s)
Examples  : set_short("A large sapphire")
See also  : set_long
 
This function sets the short of the treasure.
*/
void set_short(string str) {
  short = str;
  long = str + ".\n";
}

string short() {
  return short;
}

void long() {
  writelw(long);
}

/* USERDOC:
query_name
Function  : s=query_name()
See also  : set_name
 
This function returns the name of the treasure. This function 
has been nomasked.
*/
nomask string query_name() {
  return name;
}

/* USERDOC:
query_value
Function  : i=query_value()
See also  : set_value
 
This function returns the gold value of the treasure.
*/
int query_value() {
  return value;
}

/* USERDOC:
query_weight
Function  : i=query_weight()
See also  : set_weight
 
This function returns the weight of the treasure.
*/
int query_weight() {
  return local_weight;
}

/* USERDOC:
query_info
Function  : s=query_info()
See also  : set_info

This function returns the info associated with the treasure.
*/
string query_info() {
  return info;
}

/* USERDOC:
query_alias_list
Function  : *s=query_alias_list()
See also  : set_alias_list
 
This function returns all the possible ids of the treasure, or
0 if there are none.
*/
string *query_alias_list() {
  if(sizeof(alias_list))
    return alias_list;
  return 0;
}

/* USERDOC:
query_treasure
Function  : i=query_treasure()
 
This function always returns 1 and identifies this object as treasure.
This function is nomasked.
*/
nomask int query_treasure() {
  return 1;
}

void init() {
}
