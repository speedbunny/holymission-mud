inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

	set_name("ngaow");
	set_short("Ngaow");
	set_level(7);
  set_long("A ngaow looks like a cow, smells like a cow, and it sounds like"+
" a moo coming from it.......hmmmm....what could this ngaow be?\n");
	set_gender(1);
	set_race("cow");
	set_wimpy();
	set_al(0);

return 1;
  }
