/* ROOM.C - This is an inherit file. DO NOT COPY! */
/* 180792: Herp: reset() added for REALMS portability */
/* 231192: James: Removed query_dest_dir */
/* 081292: Ethereal Cashimor: query_dest_dir put back */
/* 181292: Llort: Search routine added */
/* 020393: Ethereal Cashimor: Linewrap in long_desc */
/* 080393: Ethereal Cashimor: query_no_teleport added */
/* 090393: Ethereal Cashimor: process_string on query_long */
/* 100393: Ethereal Cashimor: query_long parameters added */
/* 240393: Ethereal Cashimor: Smell of players added */
/* 310393: Ethereal Cashimor: Start of query_inorout */
/* 280493: James: member_array used instead of loops */
/* 290493: Patience: member_array removed from query_no_teleport */
/* 029593: Llort: query_dest_dir put back */
/* 230593: James: query_room instead of various query functions USE THIS! */
/* 280593: James: clone_list added for use with replace_program() */
/* 140693: Moonchild: Declaring types */
/* 280693: James: move() no longer performs an array addition */
/* 020793: Ethereal Cashimor: USERDOC added */
/* 140793: Moonchild: smell removed */
/* 140793: Moonchild: Search routine removed */

#pragma strict_types
#define SHARE "obj/share"
#include "/obj/lw.h"

#if 0
inherit "room/clean_up";
#endif

/* USERDOC:
general
This is a room, and unlike normal options it can only be initialized by
inheriting it. Still, after inheriting it you might want to use
replace_program() to make it another clone... Setting isn't done by calling
set-functions, but by addressing the variables directly. Possible variables
are:
dest_dir, short_desc, long_desc, items, property, no_castle_flag, smell,
no_obvious_msg, hidden_dir, clone_list.
Don't forget to use set_light(1) if you want to room to be lit!
Usage of these variables is best learned from looking at examples:
/room/church.c: short_desc, long_desc, dest_dir, items, property, smell.
/room/vill_green.c: no_castle_flag.
/players/cashimor/rooms/elevator.c: no_obvious_msg.
/room/wiz_hall.c: hidden_dir.
Of clone list there is only a docfile at the moment: 
/players/james/clone_list_doc.
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

    string fn;
    if(dest_dir) for(i=1;i<sizeof(dest_dir);i+=2)
	add_action("move", dest_dir[i]);
    if(hidden_dir) for(i=1;i<sizeof(hidden_dir);i+=2)
	add_action("move", hidden_dir[i]);
}

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
            if (ob->query_weapon()) command("wield "+clone_list[i+2],monsters[index][l]);
            if (ob->query_armour()) command("wear "+clone_list[i+2],monsters[index][l]);
          }
    }
  }
}
}

status id(string str) {
    int i;
    if (!items)
	return 0;
    return items && member_array(str, items) != -1;
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
      write(lw(process_string(items[i+1]) + ".\n"));
}

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
  
/* USERDOC:
query_property
Format: m=query_property([s])
Does this room has a special property? The 'property' variable can be both a 
string and array of strings. If no argument is given, return the 'property' 
variable. Possible properties are: no_fight, has_fire...
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

/* USERDOC:
query_no_teleport
Format: i=query_no_teleport()
This function returns 0 if you can teleport to this room, and something else
otherwise.
*/
status query_no_teleport() {
  return (status)query_property("no_teleport");
}

status move(string str) {
    int i;

    if (!str) str=query_verb();
    if ((i = member_array(str, dest_dir)) != -1) {
      if (dest_dir[--i]=="") return 0;
      (void)this_player()->move_player(str,dest_dir[i]);
      return 1;
    }
    if ((i = member_array(str, hidden_dir)) != -1) {
      if (hidden_dir[--i]=="") return 0;
      (void)this_player()->move_player(str,hidden_dir[i]);
      return 1;
    }
}
 
string short() {
    return set_light(0) ? short_desc : "It's pitch dark";
}

/* USERDOC:
query_dest_dir
Format: s=query_dest_dir()
See also: query_room, query_hidden_dir.
This function returns a string with all possible directions in it. These
directions are pairs of strings, the first being the filename, the second
being the direction of this filename. Please use query_room("dest_dir")
instead of this function.
*/
string *query_dest_dir() {
    return dest_dir;
}

/* USERDOC:
query_hidden_dir
Format: s=query_hidden_dir()
See also: query_room, query_dest_dir.
This function returns a string similar to that of query_dest_dir, but only the
hidden exits are mentioned. Please use query_room("hidden_dir") instead of
this function.
*/
string *query_hidden_dir() {
    return hidden_dir;
}

/* USERDOC:
query_long
Format: s=query_long([i])
See also: query_room.
If i is not supplied, then this function returns the long description of the
room, after being processed by process_string() and lw(). If i is supplied and
unequal to zero, the obvious exits are added to the string as well. Please use
query_room("long_desc") and query_room("long_desc",1) instead of this function.
*/
string query_long(int arg) {
  if(!arg) return lw(process_string(long_desc)); 
  return lw(process_string(long_desc))+query_obvious_exits();
}

/* USERDOC:
query_drop_castle
Format: i=query_drop_castle()
See also: query_room.
This function returns 0 if it's possible to drop a castle at this location.
This function is probably obsolete due to the new system of wizards. If you
have to use it, use query_room("no_castle_flag") instead.
*/
status query_drop_castle() {
    return no_castle_flag;
}

/* USERDOC:
query_room
Format: m=query_room(s[,i]);
See also: query_drop_castle, query_long, query_hidden_dir, query_dest_dir,
          query_property.
This function returns variables defined in room.c, depending on s. Possible
values of s:
items         : The string containing the items, in pairs of itemname,
                description.
dest_dir      : See query_dest_dir.
short_desc    : The short description of the room.
long_desc     : See query_long. The optional argument is i.
property      : A call to query_property without an argument.
no_castle_flag: See query_drop_castle.
smell         : The smell of the room.
no_obvious_msg: The message displayed if there are no obvious exists.
*/
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


