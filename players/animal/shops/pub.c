#define MUST_STAY_WITH_DRINKS

inherit "room/room";
 
object owner, weapon;
string owner_chat_str;
object top_list, pok;
 
reset(arg) {
#if 0
     ::reset(arg);
     set_outdoors(1);
#endif
    if (!pok || !present(pok,this_object())) {
	pok = clone_object("players/animal/obj/poker");
	move_object(pok,this_object());
	}
    if (!top_list || !present(top_list, this_object())) {
	top_list = clone_object("obj/level_list");
     move_object(top_list, this_object());
    }
    if (arg) return;
    set_light(1);
    property = "no_teleport";
}
 
 
 
short() {
   return "The Mountain Pub";
}
 
init() {
    add_action("order");   add_verb("order");
    add_action("order");   add_verb("buy");
    add_action("west");    add_verb("west");
}
 
west(){
#ifdef MUST_STAY_WITH_DRINKS
    if(has_drink(this_player())) {
    tell_object(this_player(),
	"You are not allowed to leave with drinks!\n");
	return 1;
    } /* Moonchild - DRINKS SHOULD NOT BE PORTABLE */
#endif
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
    write("     Shot of Jack        : 450 coins\n\n");
    write("There is one exit: west.\n");
}
 
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;
    object drink;
 
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "ale") {
     mess = "The ale hit the spot";
     heal = 0;
     value = 12;
     strength = 2; /* Moonchild - make it same as Beer */
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
     heal = 25;
     value = 150;
     strength = 12; /* Moonchild - make it same as Firebreather */
     short_desc = "A hot toddy";
     name = "toddy";
    } else if (str == "coffee" || str == "cup of coffee") {
     mess = "You feel somewhat invigorated";
     heal = 0;
     value = 20;
     strength = -random(2); /* Moonchild - was FAR TOO GOOD */
     short_desc = "A black cup of coffee";
     name = "coffee";
  } else if (str == "shot of jack daniels" || str == "jack" || str == "shot") {
     mess = "Your head explodes and you feel dizzy";
     heal = 60;
     value = 450;
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
    if(present("assoul",this_player())) {
       tell_room(this_object(),"The owner growls: Since you seem to know" +
          " Animal, I will give you a discount.\n");
       write("You get eight percent off.\n");
        value=(value*92)/100;
         }
     this_player()->add_money(-value);
     write("You pay "+value+" for a "+name+".\n");
     return 1;
}

#ifdef MUST_STAY_WITH_DRINKS
has_drink(obj) {
     status drink;
     object ob;
     ob = first_inventory(obj);
     while(ob) {
        if (call_other(ob, "id", "drk2"))
             drink = 1;
        if (call_other(ob,"can_put_and_get")) {
             if (has_drink(ob))
                  drink = 1;
        }
        ob = next_inventory(ob);
     }
     return drink;
}
#endif
