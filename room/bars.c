/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */

#define        TP        this_player()
inherit "/room/room";
 
/* Menu description of the bar */
/* format: ({ ({ <name>,<short desc>,strength,cost,type,<drink message> }),
              ({ like the above .... }), .....}) 
   types: 0..food, 1..alcohol, 2..soft drink                               */
mixed *menu_desc;

/* Menu title */
string menu_title;

/* Are the things in the bar already sold out? */
mixed *stock;
 
string *numbers;

void reset(int arg) {

    int i;

    ::reset(arg);

    if(!arg) {
        menu_title="The card:\n---------\n";
        menu_desc=0;
    }
    if(stock)
        for(i=0;i<sizeof(stock);i++) 
            if(stock[i]<1) stock[i]=100;
}

init() {

    ::init();

    add_action("do_consume","buy");
}
 
int menu() {

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

int do_consume(string arg) {

    int i;

    if(!arg) return 0;

    if(!menu_desc) {
        write("Nothing to sell yet!\n");
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
    say(this_player()->query_name()+" buys "+menu_desc[i][1]+".\n");

    switch(menu_desc[i][4]) {
        case 0:        /* food */
            TP->add_money(-menu_desc[i][3]);
            write("You flip "+menu_desc[i][3]+" coins on the counter.\n");
            if(TP->eat_food(menu_desc[i][2])) {
                write(menu_desc[i][5]);
                TP->heal_self(menu_desc[i][2]);
            }
            stock[i]--;
            break;
      case 1:        /* alcohol */
          if(TP->drink_alcohol(menu_desc[i][2])) {
              write(menu_desc[i][5]);
              TP->heal_self(menu_desc[i][2]);
              TP->add_money(-menu_desc[i][3]);
              write("You flip "+menu_desc[i][3]+" coins on the counter.\n");
              stock[i]--;
          }
          break;
      case 2:        /* soft drink */
          TP->add_money(-menu_desc[i][3]);
          write("You flip "+menu_desc[i][3]+" coins on the counter.\n");
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

void set_stock(mixed *st) {
  stock=st; 
}

mixed *query_stock() {
  return stock;
}
 
string *query_numbers();

/*
 * Convert a number to a word. The array is being created by the
 * standard room/room, and shared by all rooms.
 */
string convert_number(int n) {

    if (!numbers) numbers = query_numbers();
    if (n > 9) return "lot of";
    return numbers[n];
}
 
string *query_numbers() {
    return ({"no", "one", "two", "three", "four", "five",
       "six", "seven", "eight", "nine" });
}
