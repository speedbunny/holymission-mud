inherit "room/room";
 
object pubowner, weapon;
string owner_chat_str;
object top_list, pok;
 
reset(arg) {
     ::reset(arg);
     set_outdoors(1);
/*
    if (!pok || !present(pok,this_object())) {
	pok = clone_object("players/animal/obj/poker");
	move_object(pok,this_object());
	}
*/
    if (!top_list || !present(top_list, this_object())) {
	top_list = clone_object("obj/level_list");
     move_object(top_list, this_object());
    }
    if (arg) return;
    set_light(1);
    extra_reset();
}
 
extra_reset()  {
    if (!pubowner || !present(pubowner)){
      pubowner = clone_object("obj/monster");
        if(!owner_chat_str){
          owner_chat_str=allocate(4);
          owner_chat_str[0]=
		"Owner says: Find the mystic!\n";
       owner_chat_str[1]= "Owner says: Boy, I wish he was easier to find.\n";
       owner_chat_str[2]= "Owner says: Say hi to the king if ya find him.\n";
          owner_chat_str[3]= 
		"Owner says: Boy the mountains are big and steep!\n";
          }
      call_other(pubowner, "load_chat", 10, owner_chat_str);
      call_other(pubowner,"set_name","pub owner");
      call_other(pubowner,"set_level",10);
      call_other(pubowner,"set_alias","owner");
      call_other(pubowner,"set_race","male");
      call_other(pubowner,"set_al",0);
      call_other(pubowner,"set_hp", 250);
      call_other(pubowner,"set_short","The fat owner");
      call_other(pubowner,"set_long",
"He is a fat man, not well built.  He is sitting behind the bar, and\n"+
"he looks like he is bored and tired of waiting on people.\n");
      call_other(pubowner,"set_wc",13);
      call_other(pubowner,"set_ac",8);
      move_object(pubowner,this_object());
      weapon = clone_object("obj/weapon");
      call_other(weapon,"set_name","club");
      call_other(weapon,"set_class",15);
      call_other(weapon,"set_weight",4);
      call_other(weapon,"set_value",850);
      call_other(weapon,"set_alt_name","wooden club");
      call_other(weapon,"set_short","A large wooden club");
      move_object(weapon, pubowner);
      }
}
 
 
short() {
   return "The Mountain Pub";
}
 
init() {
    add_action("north","north");
    add_action("order");   add_verb("order");
    add_action("order");   add_verb("buy");
    add_action("west");    add_verb("west");
}
 
north() {
	this_player()->move_player("north#players/animal/shops/gamble");
	return 1;
}
west(){
    call_other(this_player(),"move_player","west#"+
        "players/animal/shops/shop_street1");
    return 1;
}
 
long() {
    write("Welcome to The Pub of the Mountains!\n");
    write("This is friendliest pub in the mud! Enjoy!\n\n");
    write("     Glass of ale        :  12 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     A special           :  50 coins\n");
    write("     Hot toddy           : 150 coins\n");
    write("     Shot of Jack        : 400 coins\n\n");
    write("There is one exit: west.\n");
}
 
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;
    object drink;
 
    if(!present("owner")) {
           write("No one is here to serve you!\n");
           return 1;
           }
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "ale") {
     mess = "The ale hit the spot";
     heal = 3;
     value = 12;
     strength = 4;
     short_desc = "A bottle of ale";
     name = "ale";
     } else if (str == "special" || str == "special of the house") {
     mess = "This is the best special around";
     heal = 10;
     value = 50;
     strength = 8;
     short_desc = "A special of the Mountain Pub";
     name = "special";
    } else if (str == "hot toddy" || str == "toddy") {
     mess = "The toddy warms your entire body nicely";
     heal = 30;
     value = 150;
     strength = 14;
     short_desc = "A hot toddy";
     name = "toddy";
    } else if (str == "coffee" || str == "cup of coffee") {
     mess = "You feel somewhat invigorated";
     heal = 0;
     value = 20;
     strength = -3;
     short_desc = "A black cup of coffee";
     name = "coffee";
  } else if (str == "shot of jack daniels" || str == "jack" || str == "shot") {
     mess = "Your head explodes and you feel dizzy";
     heal = 60;
     value = 400;
     strength = 20;
     short_desc = "A shot of Jack Daniels";
     name = "shot";
    } else {
       say("The owner says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
          return 1;
    }
    drink = clone_object("obj/drink");
    if (!call_other(this_player(), "add_weight",
     call_other(drink, "query_weight"))) {
     write("You can't carry more.\n");
     destruct(drink);
     return 1;
    }
    if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess +
     "#" + heal + "#" + value + "#" + strength)) {
     write("Error in creating drink.\n");
     destruct(drink);
     return 1;
    }
    call_other(drink, "set_pub");
    move_object(drink, this_player());
    say(call_other(this_player(), "query_name", 0) + " orders a " +
     name + ".\n");
    if(this_player()->query_info("GUILD")=="animal"){
       tell_room(this_object(),"The owner growls: Since you seem to know" +
          " Animal, I will give you a discount.\n");
       write("You get eight percent off.\n");
        value=(value*92)/100;
         }
     this_player()->add_money(-value);
     write("You pay "+value+" for a "+name+".\n");
     return 1;
}
