

/* shark2 */

inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);

  if (arg) return;
     set_name("shark");
     set_race("fish");
     set_aggressive(1);
     set_short("A big white Shark");
     set_long("A dangerous, female shark.\n");
     set_level(38);
     set_aggressive(1);
     set_has_gills();
     set_size(5);
     move_object(clone_object("players/whisky/seaworld/obj/teeth"),this_object());
     init_command("wield teeth");
}

run_away() { return 0; }
stop_fight() { return 0; }
