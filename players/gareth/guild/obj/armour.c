/* ARMOUR.C - This is an inherit/clone file. DO NOT COPY! */

#include "setlight.h"

#define SHARE "obj/share"
#pragma strict_types

#include "/obj/properties.h"
#include "/spells/spell.h"

/* USERDOC:
general
This file defines a general purpose armour. Generally defined functions:
query_value, query_name, set_read, query_read, set_id, set_name, set_value,
set_weight, query_weight, set_short, set_long, set_alias, set_long, set_info,
query_info.
*/

string name, alias, short_desc, long_desc, readstr;
mixed type;		// can be (string) or (string *)
int worn,ac,size,NUMBER_OF_SIZES,light_level,weight,value;
object worn_by;		// object that wears the armour
string info;		// should not be used, only for backcompat
string *sizes;		// sizes of armours
status unwearable;	// nobody can wear this armour if 1

private mapping res_mod;        // resistance modifiers
private mapping imm_mod;        // immunity modifiers
private mapping stat_mod;       // stat modifiers

// ----- protoypings
private void _do_modify( int wwi );               // 1 = start, -1 = end


void reset(int arg) {
  if (arg) return;
  type = ({ "armour" });
  size = 0;
  unwearable=0;
  sizes = (string *)SHARE->share_armour_sizes();
  NUMBER_OF_SIZES=sizeof(sizes)-1;
  ac = 0;
}
 
void init() 
{
  add_action("wear", "wear");
  add_action("remove", "remove");
  add_action("read","read");
}

int id(string str) { // An armour identifies to its name, its alias and its type
  return str == name || str == alias || str == type[0];
}
 
int read(string str) 
{
  if(!str || !id(str)) 
  {
    notify_fail("Read what?\n");
    return 0;
  }
  if(!readstr) 
  {
    notify_fail("There's nothing written on it!\n");
    return 0;
  }
  say((string)this_player()->query_name()
	+ " reads " + lower_case(short_desc)+".\n");
  write(readstr);
  return 1;
}

string short() 
{
  if(!short_desc)
    return 0;
  if(worn) 
  {
    if(size)
      return short_desc + " (" + sizes[size] + ") (worn)";
    else
      return short_desc + " (worn)";
  }
  else 
  {
    if(size)
      return short_desc + " (" + sizes[size] + ")";
    else
      return short_desc;
  }
}
 
void long(string str) 
{ 
       write(long_desc); 
}

void fix_weight() 
{ 
  if (weight < (ac+1) )
	  weight = ac+1;
}

/* USERDOC:
query_armour
Format: i=query_armour()
This function returns one, to identify this object as an armour. Of course,
this can also be done by querying the armourclass, though armours with armour
class 0 will then not be noticed.
*/
int query_armour() 
{ 
  return 1; 
}

/* USERDOC:
query_type
Format: s=query_type()
See also: get_type.
This functions returns the first type in the list. This should generally be the
most important type of the armour.
*/ 
string query_type() 
{ 
  return type[0]; 
}

/* USERDOC:
get_type
Format: s=get_type()
See also: query_type.
This function returns an array containing all types this armour represents.
*/
string *get_type() 
{ 
  if (stringp(type)) type=({ type }); 
  return type; 
}
 
int query_value() 
{ 
    return value; 
}

/* USERDOC:
query_worn
Format: i=query_worn()
This function returns 0 if the armour is not worn, and a number unequal to 0
if it's worn. 
*/
int query_worn() 
{ 
  return worn; 
}

/* USERDOC:
query_unwearable
Format: i=query_unwearable()
This function returns 0 if it's possible for a player to wear the armour, and
anything else if only monsters can wear it.
*/
int query_unwearable() 
{ 
  return unwearable; 
}

string query_name() 
{ 
     return name; 
}
 
/* USERDOC:
armour_class
Format: i=armour_class()
This function returns the armour-class of the armour. This number should be in
a certain range, which is different for each type. These ranges are defined in
armour.h. If the armour-class is outside this range, it's not possible to wear
it.
*/
int armour_class() 
{ 
  return ac; 
}

void set_read(string str) 
{
  readstr=str;
}

string query_read() 
{
  return readstr;
}
 
int wear(string str) 
{
  object wea;
  mixed ob;

  if (!id(str) || environment()!=this_player())
      return 0;
  else if (this_player()->query_ghost()) 
  {
     write("You fail.\n");
     return 1;
  }
/*  REMOVED (pat) senseless
  else if (this_player()->no_wear())
  {
      write("You are not allowed to wear this armour.\n");
      return 1;
  }
*/
  else if (worn) 
  {
    write("You already wear it!\n");
    return 1;
  }
  else if(unwearable) 
  {
    write(short_desc+" cannot be worn by players.\n");
    return 1;
  }
  else if(size!=0 && size!=(int)this_player()->query_size()) 
  {
    write(short_desc+" doesn't fit.\n");
    return 1;
  }
  wea = (object)this_player()->query_wielded();
  if(type[0]=="shield" && wea && wea->query_two_handed()) 
  {
    write("You cannot wear a shield while wielding a twohanded weapon.\n");   
    return 1;
  }
  if (ac>0) 
  {
     int i,j,k,ta;
     string *types;
     int *max_ac;

     types  = (string *)SHARE->share_armour_types();
     max_ac = (int *)SHARE->share_armour_max_ac();

     k=0;
     for (i=0;i<sizeof(type);i++) {
         j=member_array(type[i],types);
         if (j!=-1) k+=max_ac[j];
     }	
  } 
  if (objectp(ob=(object)this_player()->wear(this_object())))
      return 1; 
  if(!ob) 
  {
    worn_by = this_player();
    worn = 1;
    this_object()->wear_fun(worn_by);
    _do_modify(1);
    return 2; /* sucess */
  }
  if(ob==-1) return 1;
  if(type[0]=="ring") 
  {
    write("You find no place to put the ring on your finger.\n");
  } else {
    write("You already have an armour of class " + type[0] + ".\n");
    write("Worn armour " + (string)ob->short() + ".\n");
  }
  return 1;
}
 
int get() { return 1; }
 
int drop(int silently) 
{
  if (worn) 
  {
    worn_by->stop_wearing(this_object());
    this_object()->remove_fun(worn_by);
    _do_modify(-1);
    worn = 0;
    worn_by = 0;
    if (!silently)
      tell_object(environment(this_object()),"You drop your worn armour.\n");
  }
  return 0;
}
 
int remove(string str) {
  if (!id(str)) return 0;
  if (!worn) return 0;
  worn_by->stop_wearing(this_object());
  this_object()->remove_fun(worn_by); 
  _do_modify(-1);
  worn_by = 0;
  worn = 0;
  return 2;
}
  
void set_id(string n)     { name = n; }
void set_name(string n)   { name = n; }
void set_short(string s)  { short_desc = s; long_desc = s + ".\n"; }
void set_value(int v)     { value = v; }
void set_weight(int w)    { weight = w; fix_weight(); }

/* USERDOC:
set_ac
Format: set_ac(i)
Example: set_ac(2)
See also: armour_class.
This function sets the ac of the armour. This number should be according to the
ranges of types mentioned in armour.h.
*/
void set_ac(int a)        { ac = a; fix_weight(); } 
void set_alias(string a)  { alias = a; }
void set_long(string l)   { long_desc = l; }

/* USERDOC:
set_unwearable
Format: set_unwearable()
See also: query_unwearable.
This function makes the armour unwearable for anything other than a monster.
This can be useful if the armour-class of the armour is too high to give to a
player, but you want a monster to use the armour, or if the armour is totally
out of shape for the player.
*/
void set_unwearable()     { unwearable=1; }

/* herp: no confusion about armour vs. armor anymore ! */

/* USERDOC:
set_type
Format: set_type(s)
Example: set_type("armour/arm")
See also: query_type, get_type.
This function sets the type(s) of the armour. type 'armor' is converted to
'armour'. Multiple types (thus increasing the maximum ac) can be set by 
seperating them by a '/'. The different types that can be set are mentioned
in armour.h.
*/
void set_type(string t)
{
   int idx;

   type = explode( t, "/" );

   idx = member_array( "armor", type );
   if ( idx >= 0 ) type[idx] = "armour";
   idx = member_array( "boots", type );
   if ( idx >= 0 ) type[idx] = "boot";
}

/* USERDOC:
set_arm_light
Format: set_arm_light(i)
Example: set_arm_light(1)
See also: query_arm_light.
This function makes the armour give light. The amount of light is i, it can 
also be a negative value, making the armour give less light. Beware: the amount
of light is ADDED to the light the armour already gave. So to stop it giving
light do: set_arm_light(-query_arm_light()).
*/
void set_arm_light(int l) { set_light(l); light_level+=l; }

/* USERDOC:
query_arm_light
Format: i=query_arm_light()
See also: set_arm_light.
This function returns the amount of light the armour currently gives.
*/
int query_arm_light() { return light_level; }

/* USERDOC:
set_size
Format: set_size(s|i)
Example: set_size(3)
See also: query_size, query_size_name.
This function sets the size of the armour. If the size is 'any' then everyone
can wear it (default), but if it's anything else then you can only wear it if
you have that size. It's preferred a size is set for any armour you make. The
different sizes are mentioned in armour.h. With set_size(s) you can set the
string of the size, with set_size(i) you can set the size as integer: 0 being
any, 1 being tiny, 2 small ect. It's preferable to use the 's' parameter.

Utter rubbish. Set size using i. This is much more sensible. -Moonchild
*/
void set_size(mixed v) { 
int i;
  if (stringp(v)) {
    for(i=0;i<sizeof(sizes);i++)
	if (v==sizes[i]) break;
  } else i=v; 
  if(i<0 & i>NUMBER_OF_SIZES) i=0;
  size = i;
}

void set_info(string i) { info = i; }
 
int query_weight()      { return weight; }
string query_info()     { return info; }

/* USERDOC:
query_size
Format: i=query_size()
See also: set_size, query_size_name.
This returns the number belonging to the size of the armour. It's better to use
query_size_name(). I don't see why it's better to use query_size_name().
I think query_size() is much more sensible and is also faster. Moonchild 120893
*/
int query_size()     { return size; }
 
/* USERDOC:
query_size_name
Format: s=query_size_name()
See also: set_size, query_size.
This returns the size of the armour, in writing.
But only if you call it with arg -1. What a stupid function. --Moonchild
Otherwise it returns stuff that shouldn't even be in here.
*/
string query_size_name(int i) {
  if(i==-1) return sizes[size];
  return sizes[i];
}

nomask void modify_resistance( int kind, int value )
{
   if ( kind > 0 && kind < MAX_NO_OF_SAVE ) {
      if ( !res_mod ) res_mod = ([]);
      res_mod[kind] = value;
   }
}

nomask void modify_immunity( int kind, int value )
{
   if ( kind > 0 && kind < MAX_NO_OF_SAVE ) {
      if ( !imm_mod ) imm_mod = ([]);
      imm_mod[kind] = value;
   }
}

nomask void modify_stat( int which, int value )
{
   if ( which >= 0 && which <= 5 ) {
      if ( !stat_mod ) stat_mod = ([]);
      stat_mod[which] = value;
   }
}

private void _do_modify( int wwi )                // 1 = start, -1 = end
{
   int   i;
   mixed *idx;

   if ( !(worn_by && (wwi==1 || wwi==-1)) ) return;

   if ( res_mod ) {
      idx = m_indices( res_mod );
      i = m_sizeof( res_mod ) - 1;
      while ( i >= 0 ) {
         worn_by->modify_resistance( idx[i], res_mod[idx[i]]*wwi );
         i--;
      }
   }

   if ( imm_mod ) {
      idx = m_indices( imm_mod );
      i = m_sizeof( imm_mod ) - 1;
      while ( i >= 0 ) {
         worn_by->modify_immunity( idx[i], imm_mod[idx[i]]*wwi );
         i--;
      }
   }

   if ( stat_mod ) {
      idx = m_indices( stat_mod );
      i = m_sizeof( stat_mod ) - 1;
      while ( i >= 0 ) {
         worn_by->modify_stat( idx[i], stat_mod[idx[i]]*wwi );
         i--;
      }
   }
}

void notify_destruct( object ob )
{
   if ( worn_by ) _do_modify(-1);
}
