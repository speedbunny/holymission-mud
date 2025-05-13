inherit "/obj/monster";
object staff;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    staff=clone_object("obj/weapon");
    staff->set_name("staff");
    staff->set_short("A hefty staff");
    staff->set_long("A staff used by the gatekeeper of the shire.\n");
    staff->set_class(16);
    move_object(staff, this_object());
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    set_level(20);
    set_name("keeper");
    set_alias("gatekeeper");
    set_short("A hobbit gatekeeper");
    set_long(
      "He is one of the larger hobbits and he's armed with a staff.\n"+
      "Crossing him might not be such a good idea. He's here to keep\n"+
      "out any trouble makers.\n");
    set_whimpy(-1);
    add_money(1500);
    set_al(100);
    command("wield staff", this_object());
}

void init(){
    ::init();
    add_action("north", "north");
}

status north(){
    if(this_player()->query_wizard() ||
      this_player()->query_level() >=30 &&
      !this_player()->query_npc()){
	write("Gatekeeper says: Enter immortal one!\n");
	say(capitalize(this_player()->query_real_name())+
	  " is allowed entrance by the gatekeeper.\n");
	return 0;
    }
    if(this_player()->query_level()>10) {
	write("The gatekeeper shoves you back saying: "+
	  "You're too big to enter.\n");
	return 1;
    }
}
