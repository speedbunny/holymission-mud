inherit "room/room";
 
object mon, weapon;
string owner_chat_str;
object top_list;
 
reset(arg) {
#if 0
     ::reset(arg);
     set_outdoors(1);
#endif
    if (!top_list || !present(top_list, this_object())) {
     top_list = clone_object("obj/level_list");
     move_object(top_list, this_object());
    }
    if (arg) return;
    set_light(1);
    extra_reset();
}
 
extra_reset()  {
    if (!mon || !present(mon)){
      mon = clone_object("obj/monster");
        if(!owner_chat_str){
          owner_chat_str=allocate(4);
          owner_chat_str[0]=
                  "Bob says: I sell only the best booze!\n";
       owner_chat_str[1]= "Bob says: Buy a keg!\n";
       owner_chat_str[2]= "Bob says: My rum is good for your health!\n";
          owner_chat_str[3]= 
                  "Bob says: My kegs are the best!\n";
          }
      mon->load_chat( 10, owner_chat_str);
      mon->set_name("brewer");
      mon->set_level(15);
      mon->set_alias("bob");
      mon->set_race("mrum");
      mon->set_al(0);
      mon->set_hp(350);
      mon->set_short("Bob, the Brewer");
      mon->set_long(
     "Bob is a good looking young entrepreneur, with a taste for\n"+
     "fine booze (not wine).\n");
      mon->set_wc(13);
      mon->set_ac(8);
      move_object(mon,this_object());
      weapon = clone_object("obj/weapon");
      weapon->set_name("drumstick");
      weapon->set_class(15);
      weapon->set_weight(4);
      weapon->set_value(850);
      weapon->set_alt_name("stick");
      weapon->set_short("A drumstick");
      move_object(weapon, mon);
      }
}
 
 
short() {
   return "The Mountain Brewery";
}
 
init() {
    add_action("order");   add_verb("order");
    add_action("order");   add_verb("buy");
    add_action("south");    add_verb("south");
}
 
south(){
    this_player()->move_player("south#players/animal/shops/ss5");
    return 1;
}
 
long() {
    write("Mountain Brewery.\n\n");
    write("This is the famous Mountain Brewery!\n");
    write("We sell kegs here!  The kegs are listed below.\n\n");
    write("  5 gl. Keg of Rum       :   400 coins\n");
    write(" 10 gl. Keg of Rum       :   800 coins\n");
    write("  5 gl. Keg of Jack      :  3500 coins\n");
    write(" 10 gl. Keg of Jack      :  7000 coins\n\n");
    write("Just type in 'buy small jack' or 'buy small rum' for the\n");
    write("5 gl. kegs, or 'buy large jack', or 'rum' for 10gls.\n\n");
    write("There is one exit: south.\n");
}
 
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal, numleft;
    object drink;
 
    if(!present("bob")) {
           write("Bob must be on vacation!\n");
           return 1;
           }
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "5 keg of rum" || str == "5 gl. keg of rum" || str ==
     "small keg of rum" || str == "small rum") {
     mess = "The rum goes down REAL well";
     heal = 10;
     value = 80;
     strength = 10;
     short_desc = "A 5 gl. Keg of Rum";
     name = "rum";
     numleft = 5;
    } else if  (str == "5 keg of jack" || str == "5 gl. keg of jack" || str ==
     "small keg of jack" || str == "small jack") {
     mess = "Nice whiskey, you savor the flavor";
     heal = 35;
     value = 700;
     strength = 30;
     short_desc = "A 5 gl. Keg of Jack";
     name = "jack";
     numleft = 5;
    } else if (str == "10 keg of rum" || str == "10 gl. keg of rum" || str ==
     "large keg of rum" || str == "large rum") {
     mess = "The rum goes down REAL well";
     heal = 10;
     value = 80;
     strength = 10;
     short_desc = "A 10 gl. Keg of Rum";
     name = "rum";
     numleft = 10;
    } else if (str == "10 keg of jack" || str == "10 gl. keg of jack" || str ==
     "large keg of jack" || str == "large jack") {
     mess = "SMMOOOTHH whiskey";
     heal = 35;
     value = 700;
     strength = 30;
     short_desc = "A 10 gl. Keg of Jack";
     name = "jack";
     numleft = 10;
    } else {
       say("Bob says: Whats yer pleasure?\n");
       return 1;
    }
    if (this_player()->query_money() < (value * numleft)) {
    write("That costs " + value*numleft + " gold coins, which you don't have.\n");
          return 1;
    }
    drink = clone_object("players/animal/shops/keg");
    if (!drink->set_value(name + "#" + short_desc + "#" + mess +
     "#" + heal + "#" + value + "#" + strength + "#"+ numleft)) {
     write("Error in creating drink.\n");
     destruct(drink);
     return 1;
    }
    if (!this_player()->add_weight(drink->query_weight())) {
     write("You can't carry more.\n");
     destruct(drink);
     return 1;
    }
    move_object(drink, this_player());
    value = value * numleft;
    say(this_player()->query_name() + " orders a " +
     name + ".\n");
    if(this_player()->query_info("GUILDS")=="/players/animal/closed/t_soul" ||
     this_player()->query_info("GUILDS")=="/players/animal/guild/m_soul"){
       tell_room(this_object(),"Bob says: You know" +
          " Animal! I will give you a discount then.\n");
       write("You get eight percent off.\n");
       value=(value*92)/100;
         }
     this_player()->add_money(-value);
     write("You pay "+value+" for a "+name+".\n");
     return 1;
}
