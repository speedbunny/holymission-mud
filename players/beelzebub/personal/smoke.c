inherit "obj/monster";

object me;
string chats;

reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("Smoke");
        set_alt_name("smoke");
        set_short("Smoke, Beelzebub's pet scorpion.");
        set_long("This is Smoke, Beelzebub's pet scorpion.\n"+
                 "He is jet black with sharp claws and a deadly stinger.\n");
	set_hp(1000000);
	set_level(100);
	set_wc(1000);
	set_ac(1000);
	set_aggressive(0);
        if(!chats) {
            chats=allocate(4);
            chats[0]= "Smoke sharpens his claws.\n";
            chats[1]= "Smoke kills a bug and eats it.\n";
            chats[2]= "Smoke sharpens his stinger.\n";
            chats[3]= "Smoke prepares to attack.\n";
	}
        load_chat(4,chats);
    }
        
}

heart_beat() {
    ::heart_beat();
    me=find_player("beelzebub");
    if (me && enviornment(me)) {
        if (enviornment(me) != enviornment(this_object())) {
            say("Smoke crawls out following Beelzebub.\n");
            move_object(this_object(),enviornment(me));
            say("Smoke crawls in following Beelzebub.\n");
	}
    }
}
hit_player() {
  heal_self(100000);
  this_object()->stop_fight();
  this_player()->stop_fight();
  return 0;
  }

