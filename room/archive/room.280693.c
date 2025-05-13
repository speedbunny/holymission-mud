#pragma strict_types

#define SHARE "obj/share"
inherit "room/clean_up";
#include "/obj/lw.h"

/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */
/* Changed by Ethereal Cashimor on 020393, for linewrap in long_desc
   Changed by Ethereal Cashimor on 090393, now does a process_string
   when requesting the query_long(), and has query_no_teleport() set
   as a property (can be overridden of course) 
   Changed by Ethereal Cashimor on 100393, query long with parameters 
   Changed by Ethereal Cashimor on 240393, smell of players.
   Changed by Ethereal Cashimor on 310393, start of query_inorout() 
   Changed by James on 280493, rewrote while() loop code to use
   member_array() efun call instead, in these functions: id(), long(), 
   query_property(), query_no_teleport(), move()
   Changed by Patience on 290493: query_no_teleport() with no member_array()
   Added by James on 230593 query_room() which takes a string argument
   and uses a switch statement to allow it to return various room data,
   instead of adding separate functions for each 'query' type. Please add
   all new query's to this function, and consider switching existing code
   away from using the old functions.
   Changed by James on 280593: replaced the do-nothing reset() with
   a new function that uses the clone_list variable to clone monsters
   (and equipment for monsters, or even other objects) each reset.
   Using this method allows most rooms to use replace_program()
   if desired.
   Changed by Moonchild on 140693: declaring types
   Changed by James on 240693: Added logging of some functions
*/
 
/* An array with destinations and directions: "room/church", "north" ... */
string *dest_dir;
 
/* Short description of the room */
string short_desc;
 
/* Long description of the room */
string long_desc;
 
/* Special items in the room. "table", "A nice table", "window", "A window" */
string *items;
 
/* Fact about this room. ex: "no_fight", "no_steal", "no_sneak" */
mixed property;
 
/* No castles are allowed to be dropped here */
int no_castle_flag;

/* Cashimor: smell of the room, search string */
string smell;

/* Llort: This message is displayed when there is no obvious exit */
string no_obvious_msg;

/* Llort: this variable is used similar to dest_dir, but the exits are
          not shown as obvoius exits */
string *hidden_dir;

/* James: This variable used in the new reset() function, to clone
          new monsters and objects each reset (IF the variable
          is defined by the wizard) */
mixed *clone_list;

string *numbers;

static string query_obvious_exits();

void init() {
    int i;
    add_action("smell_it","smell");
    /* see below, Llort */
    add_action("do_ser","search");
    if(dest_dir) for(i=1;i<sizeof(dest_dir);i+=2)
	add_action("move", dest_dir[i]);
    if(hidden_dir) for(i=1;i<sizeof(hidden_dir);i+=2)
	add_action("move", hidden_dir[i]);
}

/* Done by Herp 920718: for REALMS portability.
   Ethereal Cashimor: Could be for REALMS portability, but maybe we could
                      use it too? Though it will involve lots of roomchanging
                      I include ::reset() since this function is here... */
void reset(int arg) { 
int i,j,k,l,n,id,index;
object ob, *all;
mixed *monsters;

if (clone_list) {
  monsters = ({ });
  all = all_inventory(this_object());
  if (!all) all= ({ });
  for(i=0; i<sizeof(clone_list); i += 5) {
    if ((id=clone_list[i]) == 0) continue; 
    if (id > 0) { 
      if(!(index=member_array(id,monsters)+1)) {
        monsters += ({ id, ({ }) });
        index = sizeof(monsters)-1;
      }
      n = clone_list[i+1];
      for(j=0; j<sizeof(all); j++)
        if ((int) call_other(all[j], "id", clone_list[i+2])) n -= 1;
      for(j=0; j<n; j++) {
        ob = clone_object(clone_list[i+3]);
        for(k=0; k<sizeof(clone_list[i+4]); k+=2)
          call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
        monsters[index] += ({ ob });
        move_object(ob, this_object());
        all += ({ ob });
      }
    } else { //Clone items for any monsters we've created
      if(index=member_array(-id,monsters)+1)
        for(l=0; l<sizeof(monsters[index]); l++)
          for(j=0; j<clone_list[i+1]; j++) {
            ob=clone_object(clone_list[i+3]);
            for(k=0; k<sizeof(clone_list[i+4]); k+=2)
              call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
            move_object(ob, monsters[index][l]);
          }
    }
  }
}
}

/* Cashimor: The smell routine */

status smell_it(string str) {
object who;

  if(str) {
    if(!who=present(str,this_object())) {
      notify_fail("Smell what?\n");
      return 0;
    }
    if(!living(who)) {
      notify_fail("Smell what?\n");
      return 0;
    }
    if(!who->query_smell()) {
      notify_fail("You smell nothing special.\n");
      return 0;
    }
    write((string)who->query_smell()+"\n");
    if(who==this_player()) {
      say((string)this_player()->query_name()+
	" smells "+(string)who->query_objective() + "self.\n");
      return 1;
    }
    say((string)this_player()->query_name()+" smells "+
	(string)who->query_name()+".\n",who);
    tell_object(who,(string)this_player()->query_name()+" smells you.\n");
    return 1;
  }
  say((string)this_player()->query_name()+" tastes the air.\n");
  if(!smell) {
    notify_fail("You smell nothing special.\n");
    return 0;
  }
  write(smell+"\n");
  return 1;
}
 
status id(string str) {
    int i;
    if (!items)
	return 0;
    return member_array(str, items) != -1;
}

void long(string str) {
int i;

    if (!str) {
      write(lw(process_string(long_desc)));
      /* HERP: they player might have been teleported away ... */
      if (environment(this_player())!=this_object()) return;
      write(query_obvious_exits());
      return;
    }
    if (!items) return;
    if ((i = member_array(str, items)) != -1)
      write(process_string(items[i+1]) + ".\n");
}

/* New routine, James, I hope it doesn't cost additional memory when I declare
   it static. If it does, the best change is it put it into a #define, I think.
   100393 Ethereal Cashimor */

static string query_obvious_exits() {
string premsg,exits;
int i;
      
  if(!dest_dir) 
    return (no_obvious_msg ? no_obvious_msg : "    No obvious exits.\n");
  i=1;
  if(!pointerp(numbers)) 
    numbers=(string *)SHARE->share_room_numbers();
  if(sizeof(dest_dir)==2) 
    premsg="    There is one obvious exit: ";
  else 
    if(sizeof(dest_dir) > 18) 
      premsg="    There are many obvious exits: ";
    else 
      premsg="    There are "+numbers[sizeof(dest_dir)/2]+" obvious exits: ";
  for(i=1,exits="";i<sizeof(dest_dir);i+=2) {
    if(i!=1) {
      if(i==sizeof(dest_dir)-1) 
        exits+=" and ";
      else 
        exits+=", ";
    }
    exits+=dest_dir[i];
  }
  return sprintf("%s%-=*s\n",premsg,SCREEN_WIDTH-strlen(premsg),exits);
}
  
/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
mixed query_property(string str) {
    int i;
    if (str == 0)
 return property;
    if (!property)
 return 0;
    if (stringp(property))
 return str == property;
    return member_array(str, property) != -1;
}
 
/* The old query_no_teleport routine will have property support, using this
   little routine... *smile* 080393 Ethereal Cashimor. James, I hope you don't
   mind, but it's probably useful... 
   Removed the member_array (what do u do, if it isn't an array !?)  */

status query_no_teleport() {
log_file("ROOM","query_no_teleport:"+file_name(previous_object())+"\n");
  return (status)query_property("no_teleport");
}

status move(string str) {
    int i;
    string *dirs;

    if (!str) str=query_verb();
    dirs=dest_dir;
    if(hidden_dir) { if(dirs) dirs+=hidden_dir; else dirs=hidden_dir; }
    if ((i = member_array(str, dirs)) != -1) {
      if (dirs[i-1]=="") return 0;
      this_player()->move_player(dirs[i] + "#" + dirs[i-1]);
      return 1;
    }
}
 
string short() {
    return set_light(0) ? short_desc : "It's pitch dark";
}
 
/*** 
 removed 11/23/92 -James. These functions dont exist in
 std.h, and probably arent ever used. IF it turns out
 that someone is using them, they can be put back, but
 PLEASE send me some mail explaining why.

Put back by Cashimor. They are continually used by the guild of Bards
for the sing command (sort of local shout). I know, it eats a lot of
processor time, but it's a fun command. Also I'd like to use it
for other things, as creatures walking around. In fact, I was planning
to change every place in the MUD to room.c just to be able to use
this function. Greetings, Ethereal Cashimor. Also Dancer wants to use
this routine, why can't we have it? 081292 */

/* Don't remove this function ever again!! It's used in the wimpy
   and in the monsters-random_move now!!! 020593 Llort */

string *query_dest_dir() {
log_file("ROOM","query_dest_dir:"+file_name(previous_object())+"\n");
    return dest_dir;
}
 
string *query_hidden_dir() {
log_file("ROOM","query_hidden_dir:"+file_name(previous_object())+"\n");
    return hidden_dir;
}
 
/* This command is used to print the local description of a room, when
   using a globe of seeing or something like that. This avoids the
   need to teleport to that location to read the long, and then
   teleport back. It's used in a few places, I don't know where
   exactly, but somewhere in Ted's at least. Cashimor. 090393: Now it has an
   optional argument, if this is 1, also the obvious exits are included. This
   is used by living.c */

string query_long(int arg) {
log_file("ROOM","query_long:"+file_name(previous_object())+"\n");
  if(!arg) return lw(process_string(long_desc)); 
  return lw(process_string(long_desc))+query_obvious_exits();
}
 
/* Put back by Cashimor: this is used by the /room/port_castle.c
   routine. */

status query_drop_castle() {
log_file("ROOM","query_drop_castle:"+file_name(previous_object())+"\n");
    return no_castle_flag;
}

/* 18/12/92 just to look better ! Llort :) */
void do_ser() {
   notify_fail("There is nothing special about it.\n");
}

varargs mixed query_room(string arg, mixed param1) {
  switch (arg) {
    case "items" :          return items;
    case "dest_dir" :       return dest_dir;
    case "short_desc" :     return short_desc;
    case "long_desc" :      if(param1) return lw(process_string(long_desc));
                            return lw(process_string(long_desc))+query_obvious_exits();
    case "property" :       return property;
    case "no_castle_flag" : return no_castle_flag;
    case "smell" :          return smell;
    case "no_obvious_msg" : return no_obvious_msg;
    case "hidden_dir" :     return hidden_dir;
    default :               return "Sorry "+arg+" is not defined";
  }
}
