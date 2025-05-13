#define SHARE "obj/share"
inherit "room/clean_up";
/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */
 
/* An array with destinations and directions: "room/church", "north" ... */
string dest_dir;
 
/* Short description of the room */
string short_desc;
 
/* Long description of the room */
string long_desc;
 
/* Special items in the room. "table", "A nice table", "window", "A window" */
string items;
 
/* Fact about this room. ex: "no_fight", "no_steal", "no_sneak" */
string property;
 
/* No castles are allowed to be dropped here */
int no_castle_flag;

/* Cashimor: smell of the room */
string smell;
 
string numbers;

init() {
    int i;
    add_action("smell_it","smell");
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
}

/* Done by Herp 920718: for REALMS portability */
reset(arg) { return; }

/* Cashimor: The smell routine */

smell_it(str) {
  if(str) {
    notify_fail("Smell what?\n");
    return 0;
  }
  say(this_player()->query_name()+" tastes the air.\n");
  if(!smell) {
    notify_fail("You smell nothing special.\n");
    return 0;
  }
  write(smell+"\n");
  return 1;
}
 
id(str) {
    int i;
    if (!items)
	return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}
long(str) {
    int i;
    if (!str) {
      write(process_string(long_desc));
      if (!dest_dir) write("    No obvious exits.\n");
      else {
        i = 1;
        if (!pointerp(numbers)) numbers=SHARE->share_room_numbers();
        if (sizeof(dest_dir) == 2) write("    There is one obvious exit:");
        else if (sizeof(dest_dir) > 18) write("    There are many obvious exits:");
        else write("    There are " + numbers[sizeof(dest_dir)/2] +
                   " obvious exits:");
        while(i < sizeof(dest_dir)) {
          write(" " + dest_dir[i]);
          i += 2;
          if (i == sizeof(dest_dir) - 1) write(" and");
          else if (i < sizeof(dest_dir)) write(",");
        }
      write("\n");
      }
      return;
    }
    if (!items) return;
    i = 0;
    while(i < sizeof(items)) {
      if (items[i] == str) {
         write(process_string(items[i+1]) + ".\n");
         return;
      }
      i += 2;
    }
}
 
/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
query_property(str) {
    int i;
    if (str == 0)
 return property;
    if (!property)
 return 0;
    if (stringp(property))
 return str == property;
    while(i < sizeof(property)) {
 if (property[i] == str)
     return 1;
 i += 1;
    }
    return 0;
}
 
move(str) {
    int i;
 
    i = 1;

    if (!str) str=query_verb();

    while(i < sizeof(dest_dir)) {
    if (str == dest_dir[i]) {
     if (dest_dir[i-1]=="") return 0;
     this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
     return 1;
 }
 i += 2;
    }
}
 
short() {
    if (set_light(0))
 return short_desc;
    return "Dark room";
}
 
query_dest_dir() {
    return dest_dir;
}
 
query_long() {
    return long_desc;
}
 
query_drop_castle() {
    return no_castle_flag;
}
