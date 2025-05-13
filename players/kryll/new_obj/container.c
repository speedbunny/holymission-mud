/*-------------------------------------------------------------------------*/
/* FILE : container.c                                                      */
/*                                                                         */
/* Description : This is the inheritable file for containers.              */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments, 
                          added full USERDOCs.

*/

#include "/obj/obj_defs.h"
#include "/obj/lw.h"
#include "/obj/setlight.h"
 
#pragma strict_types

/* USERDOC:
general
This file defines a thing in which you can put thing and get thing from, like
a bag. Generally defined functions:
  query_alias       query_value   set_alais      set_max_weight
  query_alt_name    query_weight  set_alt_name   set_name
  query_container                 set_can_close  set_of_glass
  query_lock                      set_can_get    set_only_for
  query_max_weight                set_can_lock   set_opened
  query_name                      set_closed     set_short
  query_of_glass                  set_lid_name   set_unlocked
  query_only_for                  set_locked     set_value
  query_open                      set_long       set_weight
*/
 
int can_close;
int can_get;
int can_lock;
int is_open;
int is_unlock;
int light_level;
int local_weight;         // weight of everything inside
int of_glass;
int max_weight;           // max weight of all items inside
int my_weight;            // weight of container itself
int value;
string alt_name;
string alias_name;
string cap_name;
string info;
string key_code;
string key_type;
string lid_name;
string long_desc;
string name_of_container;
string only_for;
string short_desc;
 
/* PROTOTYPES */
void recalc_light_level();
int can_put_and_get(int val);
void long();
int add_weight(int val);
int update_weight(int val);
int id(string str);
status prevent_insert();
int get();
string short();
int id(string str);
int close(string str);
int open(string str);
int number_of_keys();
void which_key();
object get_key(string type);
int number_of_containers();
int number_of_this_container();
void which_container();
int this_key(string str);
int this_container(string str);
int lock(string str);
void lock_container(object key);
int unlock(string str);
void unlock_container(object key);
status dump();
void reset(int flag);
 
// sets
void set_of_glass(int val);
void set_only_for(string str);
void set_weight(int val);
void set_max_weight(int val);
void set_value(int val);
void set_name(string str);
void set_alt_name(string str);
void set_alias(string str);
void set_short(string str);
void set_long(string str);
void set_can_close(int val);
void set_closed();
void set_opened();
void set_can_lock(int val, string type, string code);
void set_locked();
void set_unlocked();
void set_lid_name(string str);
void set_can_get(int val);
 
// queries
string query_name();
string query_alt_name();
string query_alias();
int query_open();
int query_lock();
int query_value();
string query_only_for();
int query_container();
int query_weight();
int query_max_weight();
int query_of_glass();
 
int get() {
  return can_get;
}

int can_put_and_get(int val) {
  if(can_close && is_open!=1 && !val)
    TELL(TP, "You have to open it first.\n");
  return is_open;
}
 
status prevent_insert() {
  if(local_weight > 0) {
    write("You can't when there are things in the "+name_of_container+".\n");
    return 1;
  }
  return 0;
}
 
void recalc_light_level() {
  int new_level, i, sz;
  object *all;
 
  if(of_glass) return;
  all = all_inventory(TO);
  new_level = 0;
  for(sz=sizeof(all), i=0; i<sz; i++)
    new_level -= (int)call_other(all[i], "query_arm_light");
  set_light(new_level - light_level);
  light_level = new_level;
}
 
int add_weight(int val) {
  if(local_weight + val > max_weight)
    return 0;
  local_weight += val;
  call_out("recalc_light_level", 1);
  return 1;
}
 
int update_weight(int val) {
  return val;
}

status dump() {
  write("Weight :" + local_weight + "\n");
  write("Can Close :" + can_close + "\n");
  write("Is Open :" + is_open + "\n");
  return 1;
}

void reset(int arg) {
  if(arg)
    return;
  local_weight = 0; 
  my_weight = 0;
  is_open = 1;
  is_unlock = 1;  
  can_get = 1;
  of_glass = 0;
}

void init() {
  add_action("close", "close");
  add_action("open", "open");
 
  if(can_lock) {
    add_action("lock", "lock");
    add_action("unlock", "unlock");
  }
 
  add_action("dump","dump");
}
 
int id(string str) {
   return (str==name_of_container || str==alt_name || str==alias_name);
}

string short() {
  return short_desc;
}
 
void long() {
  writelw(process_string(long_desc));
  if(is_open < 1) {
    write("It's closed.\n");
    if(!of_glass)
      return;
  }
  if(first_inventory(TO))
    write("There is something in it.\n");
  else
    write("You can put things in it.\n");
}
 
/* improved function, you can close bag 1, close bag 2,...) */
int close(string str) {
  string ln, what;
  int tmp;

  notify_fail("Close what?\n");
  if(!str) return 0;
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(can_close && ((sscanf(str, "%s ", what)==1 && what==ln) || id(str))) { 
    tmp = this_container(str);
    if(tmp != 2)
      return tmp;
    if(is_open == 1) {
      TELL(TP, "You close the " + ln + ".\n");
      say(TP->NAME + " closes the " + ln + ".\n", TP);
      is_open = -1;
    }
    else {
      TELL(TP, "The " + ln + " is already closed.\n");
    }
    return 1;
  }
  return 0;
}


/*  improved function : open bag 1, or open bag 2 */
int open(string str) {
  string ln, what;
  int tmp;

  notify_fail("Open what?\n");
  if(!str) return 0;
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(can_close && ((sscanf(str, "%s ", what)==1 && what==ln) || id(str))) { 
    tmp = this_container(str);
    if(tmp != 2)
      return tmp;
    if(is_unlock == 1){
      if(is_open != 1) {
        TELL(TP, "You open the " + ln + ".\n");
        say(TP->NAME + " opens the " + ln + ".\n", TP);
        is_open = 1;
      }
      else {
        TELL(TP, "The " + ln + " is already open.\n");
      } 
    }
    else{
      TELL(TP, "The " + ln + " is locked.\n");
    }
    return 1;
  }
  return 0;
}

int number_of_keys() {
  object *ob;
  int i, num_key;
  
  num_key = 0;
  ob = all_inventory(TP);
  for (i=0; i<sizeof(ob); i++)
    if(ob[i]->id("key") && ob[i]->query_type())
      num_key++;
  return num_key;
}

void which_key() {
  object *ob, *all;
  int i, j, num_key, sz;
  string str;

  num_key = number_of_keys() - 1;
  write("Which key do you mean");
  all = all_inventory(TP);
  ob = allocate(num_key + 1);
  j = 0;
  for(sz=sizeof(all), i=0; i<sz; i++) {
    if(all[i]->id("key") && all[i]->query_type()) {
      ob[j++] = all[i];
    }
  }
  for(sz=sizeof(ob), i=0; i<sz; i++) {
    if(ob[i]->id("key") && str=(string)call_other(ob[i], "query_type"))
      if(i == num_key)
        write(" or the " + str + " key.\n");
      else
        write(", the " + str + " key");
    if(i == num_key)
      return;
  }
}

object get_key(string type) {
  object ob;
  int num_key, tmp_num;
  string str, k_type;
  
  if(!(sscanf(type, "%s key", k_type) == 1))
    k_type = 0;
  tmp_num = 0;
  num_key = number_of_keys();
  ob = first_inventory(TP);
  while(ob) {
    if(call_other(ob, "id", "key")) {
      tmp_num += 1;
      str = (string)call_other(ob, "query_type", 0);
      if(str==k_type || !k_type)
	return ob;
    }
    if(tmp_num == num_key)
      return 0;
    ob = next_inventory(ob);
  }
}

int number_of_containers() {
  object *ob;
  int i, num_container, sz;
  string ln;
  
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  num_container = 0;
  ob = all_inventory(ENV(TO));
  for(sz=sizeof(ob), i=0; i<sizeof(ob); i++)
    if(ob[i]->id(ln))
      num_container++;
  return num_container;
}

int number_of_this_container() {
  object *ob, *all;
  int i, sz, num_container, j;
  string ln;
 
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  num_container = number_of_containers();
  if(ENV(TO) == TP)
    all = all_inventory(TP);
  else
    all = all_inventory(ENV(TP));

  ob = allocate(num_container + 1);
  j = 0;
  for(sz=sizeof(all), i=0; i<sz; i++) {
    if(all[i]->id(ln)) {
      ob[j++] = all[i];
    }
  }
  j = 0;
  for(sz=sizeof(ob), i=0; i<sz; i++) {
    j++;
    if(ob[i]->id(ln)) 
    if(ob[i] == TO){
      i++;
      return i;
    }
  }     
  return 0;
}

void which_container() {
  object *ob, *all;
  int i, j, sz, num_container;
  string str, ln;

  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  num_container = number_of_containers() - 1;
  write("Which " + ln + " do you mean");
  if(ENV(TO) == TP)
    all = all_inventory(TP);
  else
    all = all_inventory(ENV(TP));
  ob = allocate(num_container + 1);
  j = 0;
  for(sz=sizeof(all), i=0; i<sz; i++) {
    if(all[i]->id(ln)) {
      ob[j++] = all[i];
    }
  }
  j = 0;
  for(sz=sizeof(ob), i=0; i<sz; i++) {
    j++;
    if(ob[i]->id(ln)) 
      if(i == num_container)
        write(" or the " + ln + " " + j + " .\n");
      else
        write(", the " + ln + " " + j);
    if(i == num_container)
      return;
  }     
}

int this_key(string str) {
  string type;
  
  if(!str) return 0;
  if(sscanf(str, "%s", type)==1 && type=="key") {
    if(number_of_keys() == 1) {
      return 2;
    }
    else {
      if(number_of_keys() == 0) {
	write("You haven't got a key!\n");
	return 1;
      }
      else {
	which_key();
      }
    }
    return 1;
  }
  if(sscanf(str, "%s key", type) == 1) {
    if(present( type + " key", TP))
      return 2;
    write("You haven't got such a key!\n");
  }
  return 0;
}

int this_container(string str) {
  string type, ln;
  int num;

  if(!str) return 0;
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(sscanf(str, "%s", type)==1 && (type==ln || type==alias_name)) {
    if(number_of_containers() == 1)
      return 2;
    else
      which_container();
    return 1;
  }
  if(sscanf(str, "%s %d", type, num)==2 && (type==ln || type==alias_name) &&
      num==number_of_this_container())
    return 2;
  return 0;
}

int lock(string str) {
  object ob;
  int tmp;
  string type, ln, container;
  
  if(!str)
    return 0;
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(str == ln) {
    write("Lock the " + ln + " with what?\n");
    return 1;
  }
  type = 0;
  
  if(sscanf(str, "%s with %s", container, type) == 2) {
    tmp = this_container(container);
    if(tmp != 2)
      return tmp;
    tmp = this_key(type);
    if(tmp != 2)
      return 1;
    ob = get_key(type);
    lock_container(ob);
    return 1;
  }
  return 0;
}    

void lock_container(object key) {
  string str, ln;
  int tmp;

  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(is_unlock != 1) {
    write("The " + ln + " is already locked.\n");
    return;
  }
  if(key) {
    str = (string)call_other(key, "query_code", 0);
    if(str==key_code || str=="zap") {
      TELL(TP, "You lock the " + ln + ".\n");
      say(TP->NAME + " locks the " + ln + ".\n");
      is_open = -1;   /* you close it */
      is_unlock = -1; /* you lock it */
    }
    else
      write("The key doesn't fit!\n");
  }
  return;
}

int unlock(string str) {
  object ob;
  int tmp;
  string type, ln, container;
  
  if(!str) return 0;
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;

  if(str == ln) {
    write("Unlock the " + ln + " with what?\n");
    return 1;
  }
  type = 0;
  
  if(sscanf(str, "%s with %s", container, type) == 2) {
    tmp = this_container(container);
    if(tmp != 2) 
      return tmp;
    tmp = this_key(type);
    if(tmp != 2)
      return 1;
    ob = get_key(type);
    unlock_container(ob);
    return 1;
  }
}    

void unlock_container(object key) {
  string str, ln;
  
  if(lid_name)
    ln = lid_name;
  else
    ln = name_of_container;
  if(is_unlock == 1) {
    write("The " + ln + " is already unlocked.\n");
    return;
  }
  if(key) {
    str = (string)key->query_code();
    if(str==key_code || str=="zap") {
      TELL(TP, "You unlock the " + ln + ".\n");
      say(TP->NAME + " unlocks the " + ln + ".\n");
      is_unlock = 1;
      return;
    }
    write("The key doesn't fit!\n");
  }
}

/* USERDOC:
set_of_glass
Function  : set_of_glass(i)
Examples  : set_of_glass(1)
See also  : query_of_glass
 
This function makes the container transparant: this means that you can see
what is in it even when it's closed. Also: if a container is of glass then
lighted objects put inside it will shine through it. A container becomes of
glass when i is unequal to 0, preferably 1.
*/
void set_of_glass(int val) {
  set_light(-light_level);
  light_level = 0;
  of_glass = val;
  recalc_light_level();
}
 
/* USERDOC:
set_only_for
Function  : set_only_for(s)
Examples  : set_only_for("dagger")
See also  : query_only_for
 
This function makes the container only available for objects which id to s.
This is useful for sheaths, scabbards, matchboxes ect.
*/
void set_only_for(string str) {
  only_for = str;
}
 
/* USERDOC:
set_weight
Function  : set_weight(i)
Examples  : set_weight(3)
See also  : query_weight
 
This function sets the weight of the container.
*/
void set_weight(int val) {
  my_weight = val;
}
 
/* USERDOC:
set_max_weight
Function  : set_max_weight(i)
Examples  : set_max_weight(5)
See also  : query_max_weight
 
This function is used to set the maximum weight that can be put into a
container. This function must be called if you want to be able to put something
into the container.
*/
void set_max_weight(int val) {
  max_weight = val;
}
 
/* USERDOC:
set_value
Function  : set_value(i)
Examples  : set_value(50)
See also  : query_value
 
This function sets the gold value of the container.
*/
void set_value(int val) {
  value = val;
}
 
/* USERDOC:
set_name
Function  : set_name(s)
Examples  : set_name("bag")
See also  : query_name
 
This function sets the name of the container.
*/
void set_name(string str) {
  name_of_container = str;
  cap_name = capitalize(str);
  short_desc = cap_name;
  long_desc = cap_name +"\n";
}
 
/* USERDOC:
set_alt_name
Function  : set_alt_name(s)
Examples  : set_alt_name("sack")
See also  : query_alt_name
 
This function sets the alt_name of the container.
*/
void set_alt_name(string str) {
  alt_name = str;
}
 
/* USERDOC:
set_alias
Function  : set_alias(s)
Examples  : set_alias("sack")
See also  : query_alias
 
This function sets the alias of the container.
*/
void set_alias(string str) {
  alias_name = str;
}
 
/* USERDOC:
set_short
Function  : set_short(s)
Examples  : set_short("A big bag")
See also  : set_long
 
This function sets the short of the container.
*/
void set_short(string str) {
  short_desc = str;
  long_desc = short_desc + "\n";
}
 
/* USERDOC:
set_long
Function  : set_long(s)
Examples  : set_long("A large sack that looks quite old.\n")
See also  : set_short
 
This function sets the long of the container. The long must end with a \n.
*/
void set_long(string str) {
  long_desc = str;
}
 
/* USERDOC:
set_can_close
Function  : set_can_close(i)
Examples  : set_can_close(1)
See also  : set_closed, set_opened
 
This function enables the container to be closed and opened if i is not 0.
*/
void set_can_close(int val) {
  can_close = val;
  if(can_close && !is_open)
    is_open = -1;
  else if(!can_close && is_open==-1)
    is_open = 0;
}
 
/* USERDOC:
set_closed
Function  : set_closed()
See also  : set_can_close, set_opened, query_open
 
This function closes the container.
*/
void set_closed() {
  is_open = 0;
}
 
/* USERDOC:
set_opened
Function  : set_opened()
See also  : set_can_close, set_closed, query_open
 
This function opens the container.
*/
void set_opened() {
  is_open = 1; 
}
 
/* USERDOC:
set_can_lock
Function  : set_can_lock(i, type, code)
Examples  : set_can_lock(1, "iron", "mx092_goldsun_key")
            set_can_lock(0)
See also  : set_lock, query_lock
 
This function enables the container to be locked and unlocked with a
proper key (if key_type of key == key_type of lock and key_code of key
== key_code of lock) if i is not 0.
NOTE: every container can be locked/unlocked by: code = "zap".
      You should not code a key of this type!!!
*/
void set_can_lock(int val, string type, string code) {
  can_lock = val;
  if(can_lock) {
    key_type = type;
    key_code = code;
    set_can_close(val);
  }
  if(can_lock && !is_unlock)
    is_unlock = -1;
  else if(!can_lock && is_unlock==-1)
    is_unlock = 0;
}
 
/* USERDOC:
set_locked
Function  : set_locked()
See alos  : set_unlocked
 
This function sets the container as locked.
*/
void set_locked() {
  is_unlock = 0;
}
 
/* USERDOC:
set_unlocked
Function  : set_unlocked()
See also  : set_locked
 
This function sets the container as being unlocked.
*/
void set_unlocked() {
  is_unlock = 1;
}
 
/* USERDOC:
set_lid_name
Function  : set_lid_name(s)
Examples  : set_lid_name("lid")
 
This function sets the lidname of the container. This lidname can also be used
in the open and close commands issued by the player.
*/
void set_lid_name(string str) {
  lid_name = str;
}
 
/* USERDOC:
set_can_get
Function  : set_can_get(i)
Examples  : set_can_get(0)
 
This function attaches the container to the ground, making it impossible to
pick it up. This happens if i=0. The default value is 1.
*/
void set_can_get(int val) {
  can_get = val;
}
 

/* USERDOC:
query_name
Function  : s = query_name()
See also  : set_name
 
This function returns the name of the container.
*/
string query_name() {
  return name_of_container;
}
 
/* USERDOC:
query_alt_name
Function  : s = query_alt_name()
See also  : set_alt_name
 
This function returns the alt_name of the container.
*/
string query_alt_name() {
  return alt_name;
}
 
/* USERDOC:
query_alias
Function  : s = query_alias()
See also  : set_alias
 
This function returns the alias of the container.
*/
string query_alias() {
  return alias_name;
}

/* USERDOC:
query_open
Function  : i = query_open()
See also  : set_opened, set_closed
 
This function returns 1 if the container is open, 0 otherwise.
*/
int query_open() {
  return is_open;
}

/* USERDOC:
query_lock
Function  : i = query_lock()
See also  : set_locked, set_unlocked
 
This function returns whether the container is locked or not. A 0 is returned
if locked, and 1 if unlocked.
*/
int query_lock() {
  return is_unlock;
}
 
/* USERDOC:
query_value
Function  : i = query_value()
See also  : set_value
 
This function returns the gold value of the container.
*/
int query_value() {
  return value;
}
 
/* USERDOC:
query_only_for
Function  : s = query_only_for()
See also  : set_only_for.
 
This function returns the id that items should have if they want to be able
to be entered into this container.
*/
string query_only_for() {
  return only_for;
}
 
/* USERDOC:
query_container
Function  : i = query_container()
 
This function returns 1, to identify this item as a container.
*/
int query_container() {
  return 1;
}
 
/* USERDOC:
query_weight
Function  : i = query_weight()
See also  : set_weight
 
This function returns the weight of the container.
*/
int query_weight() {
  return my_weight*2;
}
 
/* USERDOC:
query_max_weight
Function  : i = query_max_weight()
 
This function returns the maximum weight that can be put into the container.
*/
int query_max_weight() {
  return max_weight;
}
 
/* USERDOC:
query_of_glass
Function  : i = query_of_glass()
See also  : set_of_glass
 
This function tests if a container is transparant. 0 is returned if it isn't.
*/
int query_of_glass() {
  return of_glass;
}
 

