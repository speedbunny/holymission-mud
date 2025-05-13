/* CONTAINER.C - This is an inherit/clone file. DO NOT COPY! */
/* 260193: Ethereal Cashimor: Fixed visibility of items in containers */
/* 040593: Ethereal Cashimor: attempt to fix the arm_light problem */
/* 030693: Ethereal Cashimor: USERDOC added */
/* 250793: Galadriel: added query_open */
/* 250793: Galadriel: updated USERDOC of set_closed and set_opened */
/* 170994: Goldsun: improved open/close function  */
/* 170994: Goldsun: added lock/unlock possibility ( for chest,shelf... ) */


/* USERDOC:
general
This file defines a thing in which you can put thing and get thing from, like
a bag. Generally defined functions:
query_weight, query_value, set_weight, set_value, set_name, set_alt_name,
set_alias, set_short, set_long, set_read, query_name, query_open,
query_unlock. 
*/
int value,max_weight,local_weight,my_weight,is_open,can_close,can_get,of_glass;
int light_level,is_unlock,can_lock;
string name_of_container ,cap_name ,alt_name ,alias_name;
string short_desc, long_desc,lid_name;
string read_msg,only_for,key_type,key_code; 

recalc_light_level() {
int new_level,i;
object all;

  if(of_glass) return;
  all=all_inventory(this_object());
  for(i=0;i<sizeof(all);i++) new_level-=all[i]->query_arm_light();
  set_light(new_level-light_level);
  light_level=new_level;
}

long() {
    write(process_string(long_desc));
    if(is_open<1) {
      write("It's closed.\n");
      if(!of_glass) return;
    }
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0; 
    my_weight = 0;
    is_open = 1;
    is_unlock = 1;  
    can_get = 1;
    of_glass=0;
}

/* USERDOC:
set_of_glass
Format: set_of_glass(i)
Example: set_of_glass(1)
See also: query_of_glass.
This function makes the container transparant: this means that you can see
what is in it even when it's closed. Also: if a container is of glass then
lighted objects put inside it will shine through it. A container becomes of
glass when i is unequal to 0, preferably 1.
*/
set_of_glass(i) {
  set_light(-light_level);
  light_level=0;
  of_glass=i;
  recalc_light_level();
}

/* USERDOC:
query_of_glass
Format: i=query_of_glass()
See also: set_of_glass.
This function tests if a container is transparant. 0 is returned if it isn't.
*/
query_of_glass() {
  return of_glass;
}

/* USERDOC:
set_only_for
Format: set_only_for(s)
Example: set_only_for("dagger")
See also: query_only_for
This function makes the container only available for objects which id to s.
This is useful for sheaths, scabbards, matchboxes ect.
*/
set_only_for(s) {
  only_for=s;
}

/* USERDOC:
query_only_for
Format: s=query_only_for()
See also: set_only_for.
This function returns the id that items should have if they want to be able
to be entered into this container.
*/
query_only_for() {
  return only_for;
}

/* USERDOC:
query_container
Format: i=query_container()
This function returns 1, to identify this item as a container.
*/
query_container() { 
  return 1; 
}

query_weight() { return my_weight*2; }

/* USERDOC:
query_max_weight
Format: i=query_max_weight()
This function returns the maximum weight that can be put into the container.
*/
query_max_weight() { return max_weight; }

add_weight(w) {
  if (local_weight + w > max_weight) return 0;
  local_weight+=w;
  call_out("recalc_light_level",1);
  return 1;
}

update_weight(w) {
/* int ow,nw;
  this calculates only w/2, now it returns w (Galadriel)
  ow=local_weight/2;
  nw=(local_weight+w)/2;
  return nw-ow;
*/
  return w;
}

short() { return short_desc; }

id(str) {
   return str == name_of_container || str == alt_name || str == alias_name;
}

query_value() { return value; }

can_put_and_get(a) { 
    if(can_close && is_open!=1 && !a) {
        tell_object(this_player(),"You have to open it first.\n");
    }    
    return is_open; 
}

get() { return can_get; }

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the " + name_of_container + ".\n");
	return 1;
    }
    return 0;
}

set_weight(w) { my_weight = w; }

/* USERDOC:
set_max_weight
Format: set_max_weight(i)
Example: set_max_weight(5)
See also: query_max_weight.
This function is used to set the maximum weight that can be put into a
container. This function must be called if you want to be able to put something
into the container.
*/
set_max_weight(w) { 
  max_weight = w; 
}

set_value(v) { value = v; }

set_name(n) {
    name_of_container = n;
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = cap_name +"\n";
}

set_alt_name(n) { alt_name = n; }

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n"; }

set_long(lo) { long_desc = lo; }

set_read(str) {
    read_msg = str;
}

/* USERDOC:
set_can_close
Format: set_can_close(i)
Example: set_can_close(1)
See also: set_closed, set_opened.
This function enables the container to be closed and opened if i is not 0.
*/
set_can_close(a) { 
    can_close=a;
    if(can_close && !is_open) is_open=-1;
    else if(!can_close && is_open==-1) is_open=0; 
}

/* USERDOC:
set_closed
Format: set_closed()
See also: set_can_close, set_opened, query_open.
This function closes the container.
*/
set_closed() { 
    is_open = 0;
}

/* USERDOC:
set_opened
Format: set_opened()
See also: set_can_close, set_closed, query_open.
This function opens the container.
*/
set_opened() { 
  is_open=1; 
}

/*         	  added by GOLDSUN      ***************************/
/* USERDOC:
set_can_lock
Format: set_can_lock(i,type,code)
Example: set_can_lock(1,"iron","mx092_goldsun_key")
    or   set_can_lock(0)
See also: set_lock, query_lock.
This function enables the container to be lock and unlock with
 proper key. (if key_type of key ==key_type of lock)
                (and key_code of key ==key_code of lock)
 if i is not 0 
 note: every container can be locked/unlocked by:
    code="zap"; you shouldn't code key of this type !!!
*/


/******************************* aded by GOLDSUN   170994    *************/

set_can_lock(int i,type,code){
 can_lock=i;
 if (can_lock){
    key_type=type;
    key_code=code;
    set_can_close(i);
 }
 if (can_lock && !is_unlock) is_unlock=-1;
 else if (!can_lock && is_unlock==-1) is_unlock = 0;
}


set_locked(){
 is_unlock=0;
}

set_unlocked(){
 is_unlock=1;
}

query_lock(){
 return is_unlock;
}


/***** end of GOLDSUNs functions **********************************/


/* USERDOC:
set_lid_name
Format: set_lid_name(s)
Example: set_lid_name("lid")
This function sets the lidname of the container. This lidname can also be used
in the open and close commands issued by the player.
*/
set_lid_name(ln) { 
    lid_name=ln;
}

/* USERDOC:
set_can_get
Format: set_can_get(i)
Example: set_can_get(0)
This function attaches the container to the ground, making it impossible to
pick it up. This happens if i=0. The default value is 1.
*/
set_can_get(c) { 
  can_get = c; 
}

init() {
    add_action("close", "close");
    add_action("open", "open");

    if (can_lock){                  /* added by GOLDSUN  170994 begin:*/
      add_action("lock","lock");
      add_action("unlock","unlock");
    }                  
                         /*   end   */


    add_action("dump","dump");
    if (read_msg) add_action("read", "read");
}

read(str) {
    if (str != name_of_container &&  str != alt_name && str != alias_name)
        return 0;
    write(read_msg);
    return 1;
}

/*************** improved by GOLDSUN 170994   begin:
close(arg) {
string ln;
    if(lid_name) ln=lid_name; else ln=name_of_container;
    if(can_close && id(arg)) {
        if(is_open==1) {
            tell_object(this_player(),"You close the "+ln+".\n");
            say(this_player()->query_name()+" closes the "+ln+".\n",
                this_player());
            is_open=-1;
        } else {
            tell_object(this_player(),"The "+ln+" is already closed.\n");
        }
        return 1;
    }
}

open(arg) {
string ln;
    if(lid_name) ln=lid_name; else ln=name_of_container;
    if(can_close && id(arg)) {
        if(is_open!=1) {
            tell_object(this_player(),"You open the "+ln+".\n");
            say(this_player()->query_name()+" opens the "+ln+".\n",
                this_player());
            is_open=1;
        } else {
            tell_object(this_player(),"The "+ln+" is already open.\n");
        }
        return 1;
    }
}

*******************************  end */

close(arg) {   /* improved function, you can close bag 1, close bag 2,...) */
string ln,what;
int tmp;
    notify_fail("Close what ?\n");
    if (!arg) return 0;
    if(lid_name) ln=lid_name; else ln=name_of_container;
    if(can_close &&   ( ((sscanf(arg,"%s ",what)==1) && what==ln)
             || id(arg) )  ) { 

        tmp = this_container( arg );
        if ( tmp != 2 )
           return tmp;
        if(is_open==1) {
            tell_object(this_player(),"You close the "+ln+".\n");
            say(this_player()->query_name()+" closes the "+ln+".\n",
                this_player());
            is_open=-1;
        } else {
            tell_object(this_player(),"The "+ln+" is already closed.\n");
        }
        return 1;
    }
}


open(arg) {                /*   changed by GOLDSUN 170994   */
string ln,what;            /* added lock/unlock condition */
int tmp;	  	   /*  improved function : open bag 1, or open bag 2 */
    notify_fail("Open what ?\n");
    if (!arg) return 0;
    if(lid_name) ln=lid_name; else ln=name_of_container;
    if(can_close &&   ( ((sscanf(arg,"%s ",what)==1) && what==ln)
             || id(arg) )  ) { 

        tmp = this_container( arg );
        if ( tmp != 2 )
           return tmp;


        if(is_unlock==1){
           if(is_open!=1) {
               tell_object(this_player(),"You open the "+ln+".\n");
               say(this_player()->query_name()+" opens the "+ln+".\n",
                   this_player());
               is_open=1;
           } else {
               tell_object(this_player(),"The "+ln+" is already open.\n");
           } 
        } else{
           tell_object(this_player(),"The "+ln+" is lock.\n");
        }
        return 1;
    }
}

/*************************aded by GOLDSUN 170994    ***************/

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


number_of_containers()
{
  object *ob;
  int i,num_container;
  string ln;
  
  if (lid_name) ln=lid_name; else ln=name_of_container;
  num_container = 0;
  ob = all_inventory(environment(this_object()));
  for (i=0;i<sizeof(ob);i++)
      if (ob[i]->id(ln)) num_container++;
  return num_container;
}

number_of_this_container(){
 object ob,all;
 int i,num_container,j;
 string ln;

 if (lid_name) ln=lid_name; else ln=name_of_container;

  num_container = number_of_containers();
  if (environment(this_object())==this_player())
	 all=all_inventory(this_player());
   else all=all_inventory(environment(this_player()));

  ob=allocate(num_container+1);
  j=0;
  for(i=0;i<sizeof(all);i++) {
    if(all[i]->id(ln)) {
      ob[j++]=all[i];
    }
  }
  j=0;
  for (i=0;i<sizeof(ob);i++) {
      j++;
      if (ob[i]->id(ln)) 
      if (ob[i]==this_object()){
         i++;
         return i;
      }
  }     
 
 return 0;
}


which_container()  
{
object ob,all;
int i,j,num_container;
string str,ln;

  if (lid_name) ln=lid_name; else ln=name_of_container;
  num_container = number_of_containers()-1;
  write("Which "+ln+" do you mean");
  if (environment(this_object())==this_player())
	 all=all_inventory(this_player());
   else all=all_inventory(environment(this_player()));
  ob=allocate(num_container+1);
  j=0;
  for(i=0;i<sizeof(all);i++) {
    if(all[i]->id(ln)) {
      ob[j++]=all[i];
    }
  }
  j=0;
  for (i=0;i<sizeof(ob);i++) {
      j++;
      if (ob[i]->id(ln)) 
	 if (i==num_container) write(" or the "+ln+" "+j+" .\n");
	 else write(", the "+ln+" "+j);
      if (i==num_container) return;
  }     
}

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


this_container(str) {
string type,ln;
int num;

  if (lid_name) ln=lid_name; else ln=name_of_container;
  if(!str) return 0;
  if((sscanf(str,"%s",type)==1)&&(type==ln)) {
    if(number_of_containers()==1) {
      return 2;
    }
    else {
      which_container();
    }
    return 1;
  }
  if ((sscanf(str,"%s %d",type,num)==2)&&(type==ln)&&
       (num==number_of_this_container())){
    return 2;
  }
  return 0;
}


lock( str)
{
  object ob;
  int tmp;
  string type, ln, container;
  
  if ( !str)
    return 0;
  if (lid_name) ln=lid_name; else ln=name_of_container;
  if ( str == ln ) {
    write( "Lock the "+ln+" with what?\n");
    return 1;
  }
  type = 0;
  
  if (sscanf(str, "%s with %s",container, type) == 2) {
    tmp = this_container( container);
    if ( tmp != 2 )
      return tmp;

    tmp = this_key( type);
    if ( tmp != 2 )
      return 1;
    ob = get_key( type);
    
    lock_container( ob);
    return 1;
  }
}    

lock_container( key)
{
  string str,ln;
  int tmp;

  if (lid_name) ln=lid_name; else ln=name_of_container;
  if ( is_unlock!=1 ) {
    write("The "+ln+" is already locked.\n");
    return;
  }
  if ( key)
    str = call_other( key, "query_code", 0);
  
  if ( ( str == key_code ) || ( str == "zap" ) ) {
    tell_object(this_player(),"You lock the " +ln + ".\n");
    say(this_player()->query_name()+" locks the "+ln+".\n");
    is_open=-1;   /* you close it */
    is_unlock=-1; /* you lock it */
  }
  else
    write("The key doesn't fit!\n");
  
  return;
}

unlock( str)
{
  object ob;
  int tmp;
  string type, ln, container;
  
  if ( !str)
    return 0;

  if(lid_name) ln=lid_name; else ln=name_of_container;

  if ( str == ln ) {
    write( "Unlock the "+ln+" with what?\n");
    return 1;
  }
  type = 0;
  
  if (sscanf(str, "%s with %s",container, type) == 2) {
    tmp = this_container( container);
    if ( tmp != 2 ) 
      return tmp;
                 
    tmp = this_key( type);
    if ( tmp != 2 )
      return 1;
    ob = get_key( type);
    
    unlock_container( ob);
    return 1;
  }
}    

unlock_container(key) {
string str,ln;
  
  if (lid_name) ln=lid_name; else ln=name_of_container;
  if(is_unlock==1) {
    write("The "+ln+" is already unlocked.\n");
    return;
  }
  if(key) str=key->query_code();
  if((str==key_code)||(str=="zap")) {
    tell_object(this_player(),"You unlock the "+ln+".\n");
    say(this_player()->query_name()+" unlocks the "+ln+".\n");
    is_unlock=1;
    return;
  }
  write("The key doesn't fit!\n");
}

/*		end of GOLDSUNs functions 		             */
/*********************************************************************/


dump() {
  write("W:"+local_weight+"\n");
  write("CC:"+can_close+"\n");
  write("IO:"+is_open+"\n");
  return 1;
}

query_name() { return name_of_container; }

/* USERDOC:
query_open
Format: i=query_open()
See also: set_opened, set_closed.
This function returns 1 if the container is open, 0 otherwise.
*/
query_open() {
  return is_open;
}
