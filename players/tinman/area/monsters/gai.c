inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

    set_name("gai");
	set_short("Gai");
	set_level(6);
  set_long("Gai is the chinese word for chicken like in moo goo gai pan. Well"+
" guess what this is?.....:)\n");
	set_gender(1);
	set_race("chicken");
	set_wimpy();
	set_al(0);

return 1;
  }
