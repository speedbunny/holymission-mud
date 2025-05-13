/* 2-SEP-1993 Galadriel: corrected 'try' message from boatman */
inherit "obj/monster";
object boat, weapon;
string dest_file;
int sailing;
void set_dest_file(string dest){ dest_file = dest; }

void set_boat(object obj){
    boat=obj;
    move_object(boat, "/players/colossus/temp");
}

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    weapon=clone_object("obj/weapon");
    weapon->set_name("oar");
    weapon->set_short("A wooden oar");
    weapon->set_long("A wooden oar used for propelling and guiding boats.\n");
    weapon->set_class(12);
    weapon->set_weight(3);
    weapon->set_value(350);
    weapon->set_two_handed();
    weapon->move(this_object());
    set_name("bonn");
    set_alias("master");
    set_alt_name("boat master");
    set_short("Bonn the boat master");
    set_long(
      "Bonn is the owner of this boat. He is willing to take you to your\n"+
      "destination for the small fee of 100 coins, all you need to do is\n"+
      "tell him your destination.\n");
    set_hp(50000);
    set_level(2);
    add_money(200+random(300));
    init_command("wield oar");
}

void init(){
    add_action("tell", "tell");
    add_action("give_man", "give");
    ::init();
}

int give_man(string str){
    string what, whom;
    if(!str){
	notify_fail("Give what to whom?\n");
	return 0;
    }
    if(sscanf(str, "%s to bonn", what) ||
      sscanf(str, "%s to master", what) ||
      sscanf(str, "%s to boat master", what)){
	notify_fail("Give what to whom?\n");
	return 0;
    }
    if(what != "100 coins")
	return 0;
    else
	write("Bonn says: Tell me your destination first.\n");
    return 1;
}

int tell(string str){
    string destination;
    object temp, there;
    if(!str) return 0;
    if((sscanf(str, "bonn %s", destination)==1) ||
      (sscanf(str,"master %s", destination)==1) ||
      (sscanf(str, "boat master %s", destination)==1)){
	if(destination=="island" || destination=="Island"){
	    if(this_player()->query_money()<100){
		write("Bonn says: You haven't got that kind o' gold.\n");
		return 1;
	    }
	    if(sailing) return 0;
	    temp=clone_object("obj/thing");
	    move_object(temp, "/players/colossus/mearth/shire/pier2");
	    there=environment(temp);
	    destruct(temp);
	    boat=present("boat", there);
	    if(!boat){
		write("Bonn exclaims: You're already here!\n");
		return 1;
	    }
	    write("Bonn accepts his payment of 100 coins from you.\n");
	    tell_room(environment(),
	      "Bonn says: Ok, I'll take you to the island.\n");
	    tell_room(there,
	      "A small boat sails out of the pier.\n");
	    move_object(boat, "/players/colossus/temp");
	    dest_file="/players/colossus/mearth/shire/island1";
	    environment()->set_moving(1);
	    this_player()->add_money(-100);
	    sailing=1;
	    call_out("set_sail", 5);
	    return 1;
	}
	else if(destination=="shire" || destination=="Shire"){
	    if(this_player()->query_money()<100){
		write("Bonn says: You don't have that kind o' gold.\n");
		return 1;
	    }
	    if(sailing) return 0;
	    temp=clone_object("obj/thing");
	    move_object(temp, "/players/colossus/mearth/shire/island1");
	    there=environment(temp);
	    destruct(temp);
	    boat=present("boat", there);
	    if(!boat){
		write("Bonn exclaims: But you're already here!\n");
		return 1;
	    }
	    write("Bonn accepts his payment of 100 coins from you.\n");
	    tell_room(environment(),
	      "Bonn says: Ok, I will take you to the main shore.\n");
	    tell_room(there,
	      "A small boat sails away from shore.\n");
	    move_object(boat, "/players/colossus/temp");
	    dest_file = "/players/colossus/mearth/shire/pier2";
	    environment()->set_moving(1);
	    this_player()->add_money(-100);
	    sailing=1;
	    call_out("set_sail",5);
	    return 1;
	}
	else {
	    tell_object(this_player(),
	      /* 2-SEP-1993 Galadriel: The suggestions of the boatman did not work */
	      "Bonn tells you: I can bring you to the Shire or island, make up your mind.\n");
	    return 1;
	}
    }
    else return 0;
}

void set_sail(){
    tell_room(environment(),
      "The boat moves out into the pond.\n");
    call_out("set_sail2", 3);
}

void set_sail2(){
    tell_room(environment(),
      "You are approaching land.\n");
    tell_room(dest_file,
      "A small boat is approaching.\n");
    call_out("set_sail3",3);
}

void set_sail3(){
    tell_room(environment(),
      "You arrive at your destination. Type 'disembark' to exit.\n");
    tell_room(dest_file,
      "A small boat arrives.\n");
    move_object(boat, dest_file);
    environment()->set_moving(0);
    sailing=0;
    return;
}
