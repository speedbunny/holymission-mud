/* Uglymouth 931015: added 'else's in the order function */
#include "mroom.h"
object barliman, customer;
int i;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "The Green Dragon Inn";
    long_desc =
    "Welcome to the Green Dragon Inn. The inn is famous for its beers. The\n"+
    "patrons of this bar are very friendly and you feel right at home. People\n"+
    "sit on their chairs at their tables while listening to storytellers or\n"+
    "other entertainers. A menu is lying on an empty table.\n";
    dest_dir = ({
      SHIRE+"/main3", "south",
    });
    items = ({
      "inn", "A really nice and friendly inn",
      "bar", "Great beers served here",
      "chairs", "Chairs that people sit on",
      "patrons", "Mostly hobbits but a few dwarves, elves, and humans",
      "storytellers", "Telling the story of the Silmarillion",
      "entertainers", "Jugglers, magicians, etc",
      "menu", "A menu that would be helpful to read",
    });
    if(!present("barliman")) {
	barliman=clone_object("obj/monster");
	barliman->set_name("barliman");
	barliman->set_alias("butterbur");
	barliman->set_alt_name("innkeeper");
	barliman->set_short("Barliman Butterbur the Innkeep");
	barliman->set_long(
	  "A fat hobbit who carries around a towel and scurries around trying to keep all\n"+
	  "his customers happy and forgetting some in the process. He beams a\n"+
	  "huge smile at you and waits for your order.\n");
	barliman->set_race("hobbit");
	barliman->set_level(5);
	barliman->set_hp(100);
	barliman->set_al(50);
	barliman->add_money(150);
	barliman->set_size(2);
	barliman->set_gender(1);
	move_object(barliman, this_object());
    }
    if(!present("customer"))
	for(i=0;i<6;i++){
	    customer=clone_object("obj/monster");
	    customer->set_name("customer");
	    customer->set_alias("hobbit");
	    customer->set_race("hobbit");
	    customer->set_short("A hobbit");
	    customer->set_long("A hobbit patron of the Green Dragon. He seems to enjoy his food and drink.\n");
	    customer->set_gender(1);
	    customer->set_size(2);
	    customer->set_level(5);
	    customer->set_hp(80);
	    customer->add_money(random(50)+10);
	    move_object(customer, this_object());
	}
}
init(){
    ::init();
    add_action("order", "order");
    add_action("order", "buy");
    add_action("read", "read");
}
read(str){
    if(str=="menu"){
	write(
	  "******************************\n"+
	  "*                            *\n"+
	  "*   Green Dragon Menu        *\n"+
	  "*                            *\n"+
	  "* 1)Beer        45 coins     *\n"+
	  "* 2)Wine        80 coins     *\n"+
	  "* 3)Bread       60 coins     *\n"+
	  "* 4)Venison    175 coins     *\n"+
	  "*                            *\n"+
	  "*                            *\n"+
	  "* You can order by number    *\n"+
	  "* or by name                 *\n"+
	  "*                            *\n"+
	  "******************************\n");
	return 1;
    }
}
order(str){
    string name, short_desc, art, mess;
    int value, cost, strength, heal;
    if(!str){
	write("The innkeeper asks: Would you like to read the menu first?\n");
	return 1;
    }
    if(str=="1" || str=="beer"){
	mess="WOW!!! Really good beer";
	heal=18;
	value=45;
	strength=1;
	art="alko";
    }
    else if(str=="wine" || str=="2") {
	mess="Hmmm.... really smooth wine";
	heal=35;
	value=80;
	strength=4;
	art="alko";
    }
    else if(str=="bread" || str=="3"){
	mess="Nothing like freshly baked bread";
	heal=20;
	value=60;
	strength=3;
	art="food";
    }
    else if(str=="venison" || str=="4"){
	mess="Boy, talk about finely roasted deer.";
	heal=50;
	strength=8;
	value=175;
	art="food";
    }
    else {
	write("There's no such thing being sold here.\n");
	return 1;
    }
    if(call_other(TP, "query_money", 0)<value){
	write("That costs "+value+" gold coins, which you don't have.\n");
	return 1;
    }
    if(art=="alko"){
	if(!call_other(TP, "drink_alcohol", strength)){
	    write("The barkeep says: You've drank enough.\n");
	    return 1;
	}
    }
    else if(art=="food"){
	if(!call_other(TP, "eat_food", strength)){
	    write("You're too full.\n");
	    say(TP->query_name()+" is too full to eat more.\n");
	    return 1;
	}
    }
    write("You pay "+value+" coins.\n");
    call_other(TP, "add_money", -value);
    call_other(TP, "heal_self", heal);
    write(mess+".\n");
    return 1;
}
