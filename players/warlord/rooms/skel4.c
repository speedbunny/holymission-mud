#define TP this_player()
inherit"room/room";
object squ,knife;
reset (arg) {
    if (!squ) {
	squ=clone_object("obj/monster");
	squ->set_name("squire");
	squ->set_short("Squire of Skeleton lord");
	squ->set_long("This is the faithful squire to the skeleton lord.\n");
	squ->load_chat(20,({
	    "Squire says: What do you want?\n",
	    "Squire says: Please leave or i'll call my boss!!\n",
	  }));
	squ->load_a_chat(50,({
	    "Squire screams: You Fuckin dick  !! Why are you hitting me?\n",
	  }));
	squ->set_level(10);
	squ->add_money(100);
	move_object(squ,this_object());
	knife=clone_object("obj/weapon");
	knife->set_name("knife");
	knife->set_alias("squire knife");
	knife->set_wc(10);
	knife->set_value(50);
	knife->set_weight(1);
	knife->set_long("This is the squire's knife\n");
	knife->set_short("Squire's knife");
	transfer(knife,squ);
	squ->init_command("wield knife");
    }
    if (arg) return;
    set_light(1);
    short_desc="Skeleton Lord's office\n";
    long_desc="This is the office of the skeleton lord. You see a desk and\n"+
    "a chair. The wall has a huge mural on it.\n";
    items=({
      "chair","The chair is made of human bones",
      "desk","The desk is carved from the bones of a large creature and covered by human skin",
      "mural","This mural depicts a great battle between Warlord and the Skeleton Lord",
    });
    dest_dir=({
      "players/warlord/rooms/skel3","east",
    });
}
