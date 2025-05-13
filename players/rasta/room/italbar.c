/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */

#define	TP	this_player()
 
/* An array with destinations and directions: "room/church", "north" ... */
string dest_dir;
 
/* Short description of the room */
string short_desc;
 
/* Long description of the room */
string long_desc;

/* Menu description of the bar */
/* format: ({ ({ <name>,<short desc>,strength,cost,type,<drink message> }),
              ({ like the above .... }), .....}) 
   types: 0..food, 1..alcohol, 2..soft drink                               */
string menu_desc;

/* Menu title */
string menu_title;

/* are the things in the bar already sold out? */
string stock;
 
/* Special items in the room. "table", "A nice table", "window", "A window" */
string items;
 
/* Fact about this room. ex: "no_fight", "no_steal", "no_sneak" */
string property;
 
/* No castles are allowed to be dropped here */
int no_castle_flag;

reset(arg) {
int i;
  if(!arg) {
    menu_title="The card:\n---------\n";
    menu_desc=0;
  }
  if(stock)
    for(i=0;i<sizeof(stock);i++) 
      if(stock[i]<1) stock[i]=100;
}

init() {
    int i;
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
    add_action("do_consume","buy");
 
    if(!stock) {
      stock=allocate(sizeof(menu_desc)+1);
      for(i=0;i<sizeof(menu_desc);i++) stock[i]=100;
    }
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
      write(long_desc);
      if (!dest_dir) write("    No obvious exits.\n");
      else {
        i = 1;
        if (sizeof(dest_dir) == 2) write("    There is one obvious exit:");
        else write("    There are " + convert_number(sizeof(dest_dir)/2) +
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
     write(items[i+1] + ".\n");
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

menu() {
string entry;
int i;
  if(!menu_desc) {
    write("Nothing to sell jet!\n");
    return 1;
  }
  write(menu_title);
  for(i=0;i<sizeof(menu_desc);i++) {
    entry=capitalize(menu_desc[i][1]);
    entry+=extract("                                        ",0,   
	           40-strlen(entry));
    if(stock[i]<0)
      entry+="sold out";
    else
      entry+=menu_desc[i][3]+" coins";
    write(entry+"\n");
  }
  return 1;
}

do_consume(arg) {
int i;
  if(!arg) return 0;
  if(!menu_desc) {
    write("Nothing to sell jet!\n");
    return 1;
  }
  arg=lower_case(arg);
  while(i<sizeof(menu_desc) && (arg!=lower_case(menu_desc[i][0]))) i++;
  if(i==sizeof(menu_desc)) {
    write("Sorry, we don't sell "+arg+" here.\n");
    return 1;
  }
  if(stock[i]<0) {
    write("We're sold out of that.\n");
    return 1;
  }
  if(TP->query_money()<menu_desc[i][3]) {
    write("You don't have enough money for that.\n");
    return 1;
  }
  switch(menu_desc[i][4]) {
    case 0:	/* food */
      TP->add_money(-menu_desc[i][3]);
      write("You pay "+menu_desc[i][3]+" coins to the bartender.\n");
      if(TP->eat_food(menu_desc[i][2])) {
        write(menu_desc[i][5]);
        TP->heal_self(menu_desc[i][2]);
      }
      stock[i]--;
      break;
    case 1:	/* alcohol */
      if(TP->drink_alcohol(menu_desc[i][2])) {
        write(menu_desc[i][5]);
        TP->heal_self(menu_desc[i][2]);
        TP->add_money(-menu_desc[i][3]);
        write("You pay "+menu_desc[i][3]+" coins to the bartender.\n");
        stock[i]--;
      }
      break;
    case 2:	/* soft drink */
      TP->add_money(-menu_desc[i][3]);
      write("You pay "+menu_desc[i][3]+" coins to the bartender.\n");
      if(TP->drink_soft(menu_desc[i][2])) {
        write(menu_desc[i][5]);
        TP->heal_self(menu_desc[i][2]);
      }
      stock[i]--;
      break;
    default:
      write("This should not happen! Please report this bug.\n");
      return 1;
  }
  return 1;
}

set_stock(st) {
  stock=st; 
}

query_stock() {
  return stock;
}
 
query_dest_dir() {
    return dest_dir;
}
 
query_long() {
    return long_desc;
}
 
/*
 * Convert a number to a word. The array is being created by the
 * standard room/room, and shared by all rooms.
 */
string numbers;
 
convert_number(n) {
    if (!pointerp(numbers))
 numbers = query_numbers();
    if (n > 9)
 return "lot of";
    return numbers[n];
}
 
query_numbers() {
    if (!numbers) {
 if (file_name(this_object()) == "room/room")
     numbers = ({"no", "one", "two", "three", "four", "five",
       "six", "seven", "eight", "nine" });
 else
     numbers = call_other("room/room", "query_numbers");
    }
    return numbers;
}
 
query_drop_castle() {
    return no_castle_flag;
}
