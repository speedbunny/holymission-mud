inherit "obj/monster";
#define ENV environment
object who;

reset(arg) {
    ::reset(arg);
    if(!arg) {
      set_name("Saffrin's Teddy Bear");
      set_alias("bear");
      set_short("Saffrin's Teddy Bear");
      set_long("Saffrin's soft and fuzzy teddy bear.  He smiles at you.\n");
      set_race("teddy bear");
      set_hp(1000000);
      set_level(100);
      set_wc(1000);
      set_ac(1000);
      set_aggressive(0);
    }
}

heart_beat() {
    ::heart_beat();
    who=find_player("saffrin");
    if (who && ENV(who)) {
      if (ENV(who) != ENV(this_object())) {
          say("Saffrin's Teddy Bear trots off after Saffrin.\n");
          move_object(this_object(),ENV(who));
          say("Saffrin's Teddy Bear pops in the room following Saffrin.\n");
      }
    }
}
