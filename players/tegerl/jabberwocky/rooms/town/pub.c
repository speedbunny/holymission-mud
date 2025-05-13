/*  */
inherit "room/room";
#define TP this_player()
int i;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    if (!present("woman")){
    move_object(clone_object("/players/tegerl/jabberwocky/monsters/wom"),this_object());
     }
    set_light(1);
    short_desc = "A dark pub in town";
    long_desc =
    "This is the best pub in town. But it is very dark and normally evil \n"+
    "people can be found here. Today you are the only customer. \n"+
    "The woman who serves the meals is the keeper's wife, take care. \n"+
    "A menu is lying on an empty table.\n"+
    "To the east is the bedroom of the keeper, don't enter it.\n";
    dest_dir = ({
      "/players/tegerl/jabberwocky/rooms/town/street9", "south",
      "/players/tegerl/jabberwocky/rooms/town/dt", "east",
    });
    items = ({
      "pub", "A really dim pub",
      "bar", "Great beers served here",
      "chairs", "Chairs that people sit on",
      "menu", "A menu that would be helpful to read",
    });
  
	
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
	  "*          Menu              *\n"+
	  "*                            *\n"+
	  "* 1)Beer        50 coins     *\n"+
	  "* 2)Wine       120 coins     *\n"+
	  "* 3)Rat         90 coins     *\n"+
	  "* 4)Potatoe    400 coins     *\n"+
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
	write("The innkeeper asks: Pardon ?\n");
	return 1;
    }
    if(str=="1" || str=="beer"){
	mess="You gulp down the beer";
	heal=12;
	value=50;
	strength=1;
	art="alko";
    }
    else if(str=="wine" || str=="2") {
	mess="Hmmm...you think about drinking another";
	heal=20;
	value=120;
	strength=4;
	art="alko";
    }
    else if(str=="rat" || str=="3"){
	mess="You close your eyes as you eat the rat. GRMPF....";
	heal=20;
	value=90;
	strength=3;
	art="food";
    }
    else if(str=="potatoe" || str=="4"){
	mess="OH NO, the potatoe was half rotten.";
	heal=50;
	strength=8;
	value=400;
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
