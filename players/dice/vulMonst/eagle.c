inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("eagle");
    set_alias("eagle");
    set_alt_name("**");
    set_short("A eagle");
    set_long("A large eagle living way up in the mountains.\n");
    set_race("eagle");
    set_level(10);
    set_al(10);
    set_hp(150);
    set_ep(50);
    set_aggressive(0);
    load_a_chat(15,({"The eagle tried to bite you.\n",
	"The eagle slammed you with it's wing.\n",}));
    set_whimpy(0);
    return 1;
}


init(){
    ::init();
    add_action("mount","mount");
}
mount(str){
    if(!str){
	notify_fail("Mount what ??\n");
	return 0;
    }
    if(str=="eagle"||str=="large eagle"){
	write("You attempt to mount the eagle.\n"+
	  "But this wild animal does not want to be mounted and attacks.\n");
	say(capitalize(this_player()->query_name()+" tries to mount an eagle"+
	    ", but the eagle does not want to be mounted and attacks.\n"));
	this_object()->set_aggressive(1);
	attack_object(this_player());
	return 1;
    }
}
