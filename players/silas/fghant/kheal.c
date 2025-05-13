inherit "room/room";
object potion;
string name;
int value;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Healing Shop";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a small healing shop in the village of Keidall. Herbs and\n"
        + "various potions sit on shelves and the overpowering smell of incense wafts up\n"
        + "to your nose. An elderly woman stands behind a counter in the center of the\n"
        + "shack, waiting for your order. You can see what she has to offer on the sign\n"
        + "which is hanging on the wall behind her.\n";
    items = ({
         "woman","She looks really old and wrinkled",
         "herbs","I bet the woman uses them for her potions",
         "potions","There sure is a large assortment standing around here",
         "sign","It looks like it's been around for a while, read it",
           });
         
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "north",
        });
}

query_light() {
    return 1;
}

init() {
  ::init();
 add_action("order"); add_verb("order");
 add_action("order"); add_verb("buy");
 add_action("read"); add_verb("read");
}

order(str) {
 if(!str) {
 write("What do you want to buy?\n");
 return 1;
 }
 else if(str == "light" ) {
 potion = clone_object("players/silas/obj/heal1");
 value = 1000;
 name = "potion of light healing";
 }
 else if(str == "medium") {
  potion = clone_object("players/silas/obj/heal2");
  value = 2000;
  name = "potion of medium healing";
 }
 else if(str == "critical") {
  potion = clone_object("players/silas/obj/heal3");
  value = 5000;
  name = "potion of critical healing";
 }
 if(this_player()->query_money() < value) {
  write("That costs "+value+" coins, which you do not have.\n");
 return 1;
 }
 if(!this_player()->add_weight(potion->query_weight())) {
   write("You can't carry anymore.\n");
   destruct(potion);
   return 1;
 }
 move_object(potion, this_player());
 call_other(this_player(),"add_money", -value);
 write("You pay "+value+" for a "+name+".\n");
 say(capitalize(this_player()->query_name())+" purchases a "+name+".\n");
 return 1;
}
read(str) {
 if(str == "sign") {
write("-----------------------------------------\n");
write("Welcome to the Keidall Potion Shop!\n");
write("We currently have these potions in stock:\n");
write("\n");
write("Potion of Light Healing.......1000 coins\n");
write("Potion of Medium Healing......2000 coins\n");
write("Potion of Critical Healing....5000 coins\n");
write("-----------------------------------------\n");
 return 1;
     }
}
