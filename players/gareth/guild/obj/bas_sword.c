#define TP this_player()
inherit "/players/gareth/guild/obj/wield";

drop() {
        if(query_verb()=="sell" || query_verb()=="give") {
        write("You decide to keep your trusty guild weapon.\n");
	return 1;
	}
  if(wielded_by) wielded_by->stop_wielding();
        say(this_player()->query_name()+" drops a sword and it melts into oblivion.\n");
        write("You drop your sword and it melts into oblivion.\n");
	destruct(this_object());
	return 1;
}

reset(arg) {
	int maxac;
  ::reset(arg);
	if(arg) return;
	set_name("bastardsword");
	set_alias("sword");
	set_short("Bastardsword");
	set_long("This seems to be a very brutal weapon.\n"+
                        "It must have killed many brave Adventurers.\n"+
                        "It looks very sharp.\n");
        maxac=(TP->query_level()+TP->query_str()*2/3+6);
        if(maxac>25) maxac=25;
	set_class(maxac);
	set_value(0);
	set_weight(3);
}

