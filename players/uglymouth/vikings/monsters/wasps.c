/* just some nasty wasps */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("wasps");
      set_alias("swarm");
      set_alt_name("swarm of wasps");
      set_short("A swarm of wasps");
      set_long("A swarm of very angry wasps. \n");
      set_level(1);
      set_hp(80);
      set_aggressive(1);
      set_race("wasps");

      }
   }
