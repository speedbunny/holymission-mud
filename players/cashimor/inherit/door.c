/* DOOR.C, Programmed by Hebol inc. - This is an inherit/clone file - DO NOT
   COPY! */
/* 250593: Ethereal Cashimor: added unlock/open at once */
/* 070693: Ethereal Cashimor: USERDOC added */
/* 181094: Ethereal Cashimor: Clean up prevented properly */

#include "setlight.h"

string direction,key_code,key_type,door_long,door_room;
object partner_door;
int can_lock,is_locked,is_closed,auto_unlock;

no_clean_up() {
  return 1;
}

/* USERDOC:
general
This is a general purpose door. You need to clone two of them, each one in the
rooms that should be connected. Generally you use door.h for this, which can
also make the key. Generally defined functions:
*/

/* USERDOC:
query_dir
Format: s=query_dir()
See also: set_dir.
This function returns the direction the door is in. This is generally 'north',
'south', 'east' or 'west', but can be any other direction as well.
*/
query_dir() { 
  return direction;
}

/* USERDOC:
query_locked
Format: i=query_locked()
This function checks if the door is locked. If it returns 0, the door isn't
locked.
*/
query_locked() { 
  return is_locked; 
}

/* USERDOC:
query_partner_door
Format: o=query_partner_door()
This function returns the door belonging to this one in the other room.
*/
query_partner_door() { 
  return partner_door; 
}

/* USERDOC:
set_dir
Format: set_dir(s)
Example: set_dir("north")
See also: query_dir, set_all.
This function sets the direction the door is in. The other door should be set
to the opposite direction.
*/
set_dir(str) { 
  direction=str;
}

/* USERDOC:
set_auto_unlock
Format: set_auto_unlock(i)
Example: set_auto_unlock(1)
See also: query_auto_unlock.
This function defines this door as the backside of a frontdoor of a house. This
means that even if the door is locked, it will open when someone types 'open
door' from this side, and it will lock if someone types 'close door' on the
other side. Do not use this function on both doors, or the entire concept of
locking will be voided.
*/
set_auto_unlock(i) {
  auto_unlock=i;
}

/* USERDOC:
query_auto_unlock
Format: i=query_auto_unlock()
See also: set_auto_unlock.
This function returns 0 if the door hasn't got the special auto_unlock feature.
This value of auto_unlock is only returned by the door that auto_unlocks. The
door on the other side will always return 0. 
query_auto_unlock() {
  return auto_unlock;
}

/* USERDOC:
set_room
Format: set_room(s)
Example: set_room("players/cashimor/extend/hall")
See also: set_all.
This function sets the destination of the door and moves the door there.
Always use this function (or the set_all()) to move the door to its
destination.
*/
set_room(str) {
  door_room=str;
  move_object(this_object(),door_room);
}

/* USERDOC:
set_code
Format: set_code(s)
Example: set_code("jen")
See also: set_all.
This function sets the code of the lock, which is the code the key has to have
to fit into the lock of this door. Try to make this original, to avoid other
keys opening your door. 'zap' is not an allowed code.
*/
set_code(str) { 
  key_code = str;
}

/* USERDOC:
set_type
Format: set_type(s)
Example: set_type("red")
See also: set_all.
This function sets the type of the lock, which is an adverb displayed if the
door is examined. The key has to have the same type as the door to be able to
fit. This gives an indication to the player to show what key he/she should be
looking for and what door belongs to a certain key.
*/
set_type(str) { 
  key_type = str;
}

/* USERDOC:
set_door
Format: set_door(o)
Example: set_door(door2)
This function explains to this door which door is his partner door. This is
necessary for the correct functioning of doors.
*/
set_door(obj) { 
  partner_door = obj;
}

/* USERDOC:
set_closed
Format: set_closed(i)
Example: set_closed(1)
See also: set_all.
This function closes the door is i is not 0, and opens it if it is. It also
diplays the appropriate sounds.
*/
set_closed(val) { 
  if (is_closed!=val) {
    tell_room(environment(this_object()),"The "+direction+" door ");
    if(val) {
      tell_room(environment( this_object()),"closes.\n");
    }
    else {
      tell_room(environment( this_object()),"opens.\n");
    }
  }
  is_closed=val; 
}

/* USERDOC:
set_locked
Format: set_locked(i)
Example: set_locked(1)
See also: set_can_lock, set_all.
This function unlocks the door if i is 0, and locks it otherwise. The
appropriate sounds is shown in the room. Don't use this function if you
haven't set the door as being can_lock.
*/
set_locked(val) { 
  if(is_locked!=val) door_sound("Klick!");
  is_locked=val; 
}

/* USERDOC:
set_can_lock
Format: set_can_lock(i)
Example: set_can_lock(1)
See also: set_all, set_locked.
This function allows the door to be locked and unlocked if i is unequal to 0.
*/
set_can_lock(val) { 
  can_lock=val; 
}

/* USERDOC:
set_both_status
Format: set_both_status()
This function sets the other door to the same status as this door. It uses the
functions: set_closed, set_locked, set_can_lock, set_type, set_code and
set_door_long.
*/
set_both_status() {
  partner_door->set_closed(is_closed);
  partner_door->set_locked(is_locked);
  partner_door->set_can_lock(can_lock);
  partner_door->set_type(key_type);
  partner_door->set_code(key_code);
  partner_door->set_door_long(door_long);
}

/* USERDOC:
set_door_long
Format: set_door_long(s)
Example: set_door_long("The door is made of wood.\n")
This function sets the long description of the door. It should end with a \n.
set_both_status() will set the longdescription of the other door, so don't make
a different description for each door.
*/
set_door_long(str) {
  door_long = str;
}

/* USERDOC:
set_all
Format: set_all(s)
Example: set_all("players/cashimor/extend/hall south c&h purple 1 1 1")
See also: set_room, set_dir, set_type, set_code, set_closed, set_locked,
          set_can_lock.
This function sets all things that should be set of a door to enable it for
real use. The parameters are in a string, divided by spaces. The first
parameter is the room the door should be in, the second is the direction of
the door, the third is the code needed for the key, the fourth is the type of
the key needed for this door, the fifth is a number, and states if the door is
closed or not (0 means it isn't), the fifth indicates if the door is locked,
and the last indicates if it's possible to lock the door. Using this function
there will be no sounds of closing and locking.
*/
set_all(str) {
  if(!str) return 0;
  if(sscanf(str,"%s %s %s %s %d %d %d",door_room,direction,key_type,key_code, 
            is_closed,is_locked,can_lock)!=7) return 0;
  if(key_type=="0") key_type = 0;
  move_object(this_object(),door_room);
  return 1;
}

/* USERDOC:
query_room
Format: s=query_room()
See also: set_room.
This function returns the room the door is in.
*/
query_room() {
  return door_room;
}

player_enters( str) {
  tell_room(environment(this_object()),str+" enters through the "+direction
	  + " door.\n");
}

/* USERDOC:
door_sound
Format: door_sound(s)
Example: door_sound("Klick")
See also: both_door_sound.
This functions describes the sound s as coming from the door this function is
called in.
*/
door_sound(str) {
  tell_room(environment(this_object()),str+" is heard from the "+direction 
          + " door.\n");
}

/* USERDOC:
both_door_sound
Format: both_door_sound(s)
Example: both_door_sound("Klick")
See also: door_sound.
This function describes the sound s as coming from the door, in both rooms. Can
be very useful.
*/
both_door_sound(str) {
  door_sound(str);
  partner_door->door_sound(str);
}

static open_closed_string() {
  if(is_closed) return "closed";
  return "open";
}

short() {
  return "A door to the "+direction+" ( "+open_closed_string()+" )";
}

query_name()
{
   return short();
}

long() {
  write(door_long);
  if(key_type) write("On the door there is a "+key_type+" lock.\n");
  write("The door is "+open_closed_string()+".\n");
  if(random(20)==7) {
    write("You notice a small sign stating:\n");
    write("A product from Hebol Inc.\n");
    if(this_player()) this_player()->add_exp(10);
  }
}

id(strang) {
  if((strang=="door")||(strang==direction+" door")||(strang=="H_door")) {
    return 1;
  }
  return 0;
}

init() {
  if(direction) add_action( "go_door", direction);
  add_action("go","go");
  add_action("close","close");
  add_action("open","open");
  if(can_lock) {
    add_action("unlock","unlock");
    add_action("lock","lock");
  }
}

go( str) {
  if(!str) return 0;
  switch(this_door(str)) {
    case 2:
      go_door();
      return 1;
    case 1:
      return 1;
    default:
      return 0;
  }
}

open(str) {
  if(!str) return 0;
  switch(this_door(str)) {
    case 2:
      open_door();
      return 1;
    case 1:
      return 1;
    default:
      return 0;
  }
}

close( str) {
int tmp;
  
  if(!str) return 0;
  
  tmp = this_door( str);
  if ( tmp == 2 ) {
    close_door();
    return 1;
  }
  else 
    if ( tmp == 1 )
      return 1;
    else
      return 0;
}

unlock( str)
{
  object ob;
  int tmp;
  string type, door;
  
  if ( !str)
    return 0;
  
  if ( str == "door" ) {
    write( "Unlock the door with what?\n");
    return 1;
  }
  type = 0;
  
  if (sscanf(str, "%s with %s", door, type) == 2) {
    tmp = this_door( door);
    if ( tmp != 2 ) 
      return tmp;
    
    tmp = this_key( type);
    if ( tmp != 2 )
      return 1;
    ob = get_key( type);
    
    unlock_door( ob);
    return 1;
  }
}    

lock( str)
{
  object ob;
  int tmp;
  string type, door;
  
  if ( !str)
    return 0;
  
  if ( str == "door" ) {
    write( "Lock the door with what?\n");
    return 1;
  }
  type = 0;
  
  if (sscanf(str, "%s with %s", door, type) == 2) {
    tmp = this_door( door);
    if ( tmp != 2 ) 
      return tmp;
    
    tmp = this_key( type);
    if ( tmp != 2 )
      return 1;
    ob = get_key( type);
    
    lock_door( ob);
    return 1;
  }
}    

/* USERDOC:
this_door
Format: i=this_door(s)
See also: this_key.
this_door(str) tests if the argument arg refers to this door. Return values: 
0 => str not refering to a door, 1 => str refering to a door but there are 
several alternatives tells the player that this has occurred. 2 => str refers 
to this door.
*/
this_door(str) {
string type;

  if(!str) return 0;
  if((sscanf(str,"%s",type)==1)&&(type=="door")) {
    if(number_of_doors()==1) {
      return 2;
    }
    else {
      which_door();
    }
    return 1;
  }
  if((sscanf(str,"%s door",type)==1)&&(type==direction)) return 2;
  return 0;
}

/* USERDOC:
this_key
Format: i=this_key(s)
See also: this_door.
this_key(str) tests if the argument arg refers to the key belonging to this 
door. Return values: 0 => str not refering to the key, 1 => str refering to 
the key but there are several alternatives tells the player that this has 
occurred. 2 => str refers to the key belonging to this door.
*/
this_key(str) {
string type;
  
  if(!str) return 0;
  if((sscanf(str,"%s",type)==1)&&(type=="key")) {
    if(number_of_keys()==1) {
      return 2;
    }
    else {
      if(number_of_keys()==0) {
	write("You haven't got a key!\n");
	return 1;
      }
      else {
	which_key();
      }
    }
    return 1;
  }
  if(sscanf(str,"%s key",type)==1) {
    if(present( type + " key", this_player())) return 2;
    write("You haven't got such a key!\n");
  }
  return 0;
}

open_door() {
string str;
int tmp;
  
  if(!is_closed) {
    write("But why? It's already open!\n");
    return;
  }
  if(is_locked) {
    if(!auto_unlock) {
      write("You can't open the "+direction+" door, it's locked!\n");
      return;
    }
    set_locked(0);
    partner_door->set_locked(is_locked);
  }
  write("You open the "+direction+" door.\n");
  set_closed(0);
  partner_door->set_closed(is_closed);
  return;
}

close_door() {
  if(is_closed) {
    write("But why? It's already closed!\n");
    return;
  }
  if(is_locked) {
    write("You can't close the "+direction+" door, it's locked!\n");
    return;
  }
  write("You close the "+direction+" door.\n");
  set_closed(1);
  partner_door->set_closed(is_closed);
  if(partner_door->query_auto_unlock()) {
    set_locked(1);
    partner_door->set_locked(is_locked);
  }
}


lock_door( key)
{
  string str;
  int tmp;

  if ( is_locked ) {
    write("But why? It's already locked!\n");
    return;
  }
  if ( key)
    str = call_other( key, "query_code", 0);
  
  if ( ( str == key_code ) || ( str == "zap" ) ) {
    write("\nYou lock the " + direction + " door.\n");
    set_locked( 1);
    call_other( partner_door, "set_locked", is_locked);
  }
  else
    write("The key doesn't fit!\n");
  
  return;
}


unlock_door(key) {
string str;
  
  if(!is_locked) {
    write("But why? It's already unlocked!\n");
    return;
  }
  if(key) str=key->query_code();
  if((str==key_code)||(str=="zap")) {
    write("You unlock the "+direction+" door.\n");
    set_locked(0);
     if(partner_door)
    partner_door->set_locked(is_locked);
    return;
  }
  write("The key doesn't fit!\n");
}

go_door()
{
  string str;
  object localroom;

  if ( is_closed ) {
    write("You can't do that, the door is closed.\n");
    return 1;
  }

  if ( partner_door) {
    str = call_other( this_player(), "query_name", 0);
    call_other( partner_door, "player_enters", str);
    write( "You go through the " + direction + " door.\n");
    /*
    move_object( this_player(), environment(partner_door));
    */
    call_other(this_player(), "move_player", 
	direction + "#" + call_other(partner_door, "query_room"));
  }
/* Mangla: added so that if partner door was dested in the other room
           then it would only delay you for one round and not add
           to the growing list of errors in lpmud.log
*/
  else {
    printf("Something strange happens, and you remain where you were.\n");
    localroom = environment(this_object());
    localroom->reset(0);
    destruct(this_object());
    this_player()->look();
  }
  return 1;
	       
}

number_of_doors()
{
  object *ob;
  int i,num_door;
  
  num_door = 0;
  ob = all_inventory(environment(this_object()));
  for (i=0;i<sizeof(ob);i++)
      if (ob[i]->id("door")) num_door++;
  return num_door;
}

which_door()
{
  object *ob;
  int i,num_door;
  string str;
  
  num_door = number_of_doors()-1;
  write("Which door do you mean? The " + direction + " door");
  ob = all_inventory(environment(this_object()));
  for (i=0;i<sizeof(ob);i++) { 
      if (ob[i]->id("door") && (str=ob[i]->query_dir()))
	 if (i==num_door) write(" or the "+str+" door.\n");
	 else write(", the "+str+" door");
      if (i==num_door) return;
  }
}

number_of_keys()
{
  object *ob;
  int i,num_key;
  
  num_key = 0;
  ob = all_inventory(this_player());
  for (i=0;i<sizeof(ob);i++)
    if((ob[i]->id("key"))&&(ob[i]->query_type())) num_key++;
  return num_key;
}

which_key()
{
object ob,all;
int i,j,num_key;
  string str;

  num_key = number_of_keys()-1;
  write("Which key do you mean");
  all=all_inventory(this_player());
  ob=allocate(num_key+1);
  j=0;
  for(i=0;i<sizeof(all);i++) {
    if((all[i]->id("key"))&&(all[i]->query_type())) {
      ob[j++]=all[i];
    }
  }
  for (i=0;i<sizeof(ob);i++) {
      if (ob[i]->id("key") && (str=ob[i]->query_type()))
	 if (i==num_key) write(" or the "+str+" key.\n");
	 else write(", the "+str+" key");
      if (i==num_key) return;
  }
}

get_key(type)
{
  object ob;
  int num_key;
  int tmp_num;
  string str;
  string k_type;
  
  if ( ! (sscanf( type, "%s key", k_type) == 1) )
    k_type = 0;

  tmp_num = 0;
  num_key = number_of_keys();
  
  ob = first_inventory(this_player());
  while(ob) {
    if (call_other(ob, "id", "key")) {
      tmp_num += 1;
      str = call_other(ob, "query_type", 0);
      
      if  ( ( str == k_type ) || ( ! k_type ) )
	return ob;
    }
    if ( tmp_num == num_key ) return 0;
    
    ob = next_inventory(ob);
  }
}

