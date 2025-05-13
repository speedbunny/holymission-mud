/*-------------------------------------------------------------------------*/
/* FILE : std_pub.c                                                        */
/*                                                                         */
/* Description : This is the inheritable file for pubs. It also inherits   */
/*               /room/room.                                               */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 28 1997  Kryll        Cleaned up the file, debugged it, and now usable
                          with USERDOCs.
*/
 
inherit "/room/room";

#include "/sys/defs.h"

// LINES AND SPACES contain 80 characters each
#define LINES  "----------------------------------------"\
               "----------------------------------------"
#define SPACES "                                        "\
               "                                        "

mapping   item_list, check;
string    waiter, header;
int       count;

void reset(int flag) {
  ::reset(flag);
  if(flag) return;

  count = 0;
  if(!stringp(waiter))
    waiter = "Mack";
  if(!stringp(header))
    header ="            Mack's Place           ";
  if(!mappingp(item_list))
    item_list = ([ ]);
  if(!mappingp(check))
    check = ([ ]);
}

/* USERDOC:
add_item
Function  : add_item(s1, i1, i2, s2, i3, s3)
Examples  :

This function adds an item into the menu. It can either be a
food, alcoholic beverage or soft drink. Note that the order 
with which you add items is the order which will be shown
in the menu.
*/
void add_item(string item_name, int cost, int strength,
              string type, int heal_amt, string menu_listing) {
  string al;

  if(!mappingp(item_list))
    item_list = ([ ]);
  if(!mappingp(check))
    check = ([ ]);

  if(!stringp(item_name) || !intp(cost)
                         || !intp(strength)
                         || !stringp(type)
                         || !intp(heal_amt)
                         || !stringp(menu_listing)
                         || member(item_list, item_name)==1)
    return;

  al = to_string(count + 1);
  count++;
  item_list += ([ item_name :
               ({ al, cost, strength, type, heal_amt, menu_listing }) ]);
  check += ([ al : item_name]); 
}

/* USERDOC:
set_waiter
Function  : set_waiter(s)
Examples  : set_waiter("Mack")
See also  : set_header

This function sets the name of the waiter or barkeep of the pub.
*/
void set_waiter(string str) {
  if(stringp(str))
    waiter = str;
}

/* USERDOC:
set_header
Function  : set_header(s)
Examples  : set_header("Mack's Place")
See also  : set_waiter

This function sets the name of the pub.
*/
void set_header(string str) {
  if(stringp(str))
    header = str;
}


void init() {
  ::init();
  add_action("_buy","order");
  add_action("_buy","buy");
  add_action("_read","read");
}

status _read(string str) {
  int    i, sz, x, len;
  string *arr, choice;

  if(str!="sign" && str!="menu") {
    notify_fail("Read what?\n");
    return 0;
  }

  if((len = strlen(header)) > 1) {
    printf(extract(LINES, 1, 55) + "\n");
    printf(extract(SPACES, 1, (55-len)/2) + header + "\n");
    printf(extract(LINES, 1, 55) + "\n");
  }
  else
    printf(extract(LINES, 1, 55) + "\n");

  printf("%-6s %-35s %-10s\n", "Number", "Menu Item", "Price");
  printf("%s %s %s\n\n", "------", extract(LINES, 1, 35),
         extract(LINES, 1, 12));

  arr = m_indices(item_list);
  for(i=0, sz=sizeof(arr); i<sz; i++) {
    choice = to_string(i+1);
    printf("%4s   %-35s %-10s\n",
           choice, item_list[check[choice]][5],
           to_string(item_list[check[choice]][1]));
  }

  write("\nYou can order by item name or number.\n");
  printf(extract(LINES, 1, 55) + "\n");
  return 1;
}
    
status _buy(string str) {
  string what;
  status which; // a flag for food (1) or drink (0)

  if(!str) {
    notify_fail("Buy what ?\n");
    return 0;
  }
  else if(member(check, str))
    what = check[str];
  else 
    what = str;

  which = 0;
  if(!member(item_list, what)) {
      notify_fail(lw(CAP(waiter) + " tells you: Sorry, but we "+
                     "dont have this kind of drink or food.\n"));
      return 0;
  }

  if(TP->query_money() <  item_list[what][1]) {
    writelw(CAP(waiter) + " tells you: You don't have enough money.\n");
    return 1;
  }

  switch(item_list[what][3]) {
    case "alco":
      if(!TP->drink_alcohol(item_list[what][2]))
        return 1;
    case "soft":
      if(!TP->drink_soft(item_list[what][2]))
        return 1;
    case "food":
      if(!TP->eat_food(item_list[what][2]))
        return 1;
  }

  tell_room(TO, CAP(waiter) + " says: Here we are.\n");
  if(item_list[what][3] != "food") {
    writelw("You drink " + lower_case(item_list[what][5]) + ".\n");
    say(TP->NAME + " drinks a glass of " + what + ".\n", TP);
  }
  else {
    writelw("You eat " + lower_case(item_list[what][5]) + ".\n");
    say(TP->NAME + " eats some " + what + ".\n", TP);
  }

  TP->heal_self(item_list[what][4]);
  TP->add_money(-item_list[what][1]);
  return 1;
}

