inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

    set_name("red wounded soldier");
	set_alt_name("soldier");
	set_short("A Red Wounded Soldier");
	set_level(12);
  set_long("Red soldiers that got slashed and cut up during the battle. They"+
" are brough back by fellow soldiers that cares enough. Those not dies.\n");
	set_gender(1);
	set_race("human");
	set_wimpy();
	set_al(0);

return 1;
  }
