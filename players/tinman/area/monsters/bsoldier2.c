inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

    set_name("blue wounded soldier");
	set_alt_name("soldier");
	set_short("A Blue Wounded Soldier");
	set_level(12);
  set_long("A wounded soldier brought back to the sleeping tents by"+
" fellow soldiers. He has cuts and bruises all over.\n");
	set_gender(1);
	set_race("human");
	set_wimpy();
	set_al(0);

return 1;
  }
