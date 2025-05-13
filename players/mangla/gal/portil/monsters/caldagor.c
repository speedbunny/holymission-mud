inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("lord Caldagor");
      set_alt_name("caldagor");
      set_short("Lord Caldagor the Rampant");
      set_long("He looks wise and noble and you feel he hides a dark secret.\n");
      set_gender(1);
      set_level(37);
      set_al(215);
      set_weight(1000); /*Cant take this corpse away*/
      set_race("human");
      set_dead_ob(this_object());
      load_chat(15,({
	"Lord Caldagor kicks the wall.\n",
	"Lord Caldagor says: There are things I must do.\n",
	"Lord Caldagor says: I have laboured for too long in this hell hole.\n",
	"Lord Caldagor says: I own an important peace of the puzzle.\n"
      }));
      load_a_chat(40,({
	"Lord Caldagor screams: Stop this insolence.\n",
	"Lord Caldagors image fades away briefly.\n",
	"Lord Caldagor screams: Stop fool, stop!\n",
	"Lord Caldagor says: Are we not fighting for the same side?\n"
      }));
}

monster_died(ob) {
	"/players/portil/rooms/tunnel/cell3.c"->just_killed(this_object()->query_attack());
	return 0;
}
