inherit "/obj/thing";

reset(arg) {
    if (arg) return 1;
    set_name("A Hara-Kiri knife");
    set_alias("knife");
    set_short("A Hara-Kiri knife");
    set_long("A razorsharp knife.\n"+
      "Ninja's use this knife to commit suicide.\n"+
      "You better think it over before you use this knife,\n"+
      "because the result is really DEADLY !\n");
    set_value(0);
    can_get = 1;
    set_weight(1);
    return 1;
}

init(){
    add_action("_wield","wield"); add_action("_commit","commit");
}
_wield(str){
    if(!str){
	notify_fail("Wield what ?\n");
	return 0;
    }
    if(str=="knife"||str=="harakiri knife"||str=="razorsharp knife"){
	write("You fail to wield this knife.\n"+
	  "Maybe it is not meant to be wielded.\n");
	return 1;
    }
}
_commit(str){
    if(!str){
	notify_fail("Commit WHAT ??\n\n");
	return 0;
    }
    if(str=="suicide"||str=="suicide with knife"||str=="suicide with harakiri knife" ||
      str=="harakiri"){
write("Are you sure ???\n");
          shout(capitalize(this_player()->query_name())+" commited suicide in the old traditional way.\n");
          this_player()->hit_player(1000,3);
	return 1;
    }
}
