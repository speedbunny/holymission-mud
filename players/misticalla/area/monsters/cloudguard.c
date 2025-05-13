inherit "/obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;

    set_race("hobbit");
    set_gender(1);
    set_size(2);
    set_level(15);
    set_name("cloud guardian");
    set_alias("guardian");
    set_short("A solemn looking guard");
    set_long(
      "A guard is here, protecting the forest from intruders.\n"+
      "Crossing him might not be such a good idea. You don't\n"+
      "think he wants you here.\n");
    set_whimpy(-1);
    add_money(500);
    set_al(100);
}

void init(){
    ::init();
    add_action("west", "west");
}

status west(){
    if(this_player()->query_wizard() ||
      this_player()->query_level() >=30 &&
      !this_player()->query_npc()){
	write("Cloud Guardian says: Enter immortal one!\n");
	say(capitalize(this_player()->query_real_name())+
	  " is allowed entrance by the guardian.\n");
	return 0;
    }
}
