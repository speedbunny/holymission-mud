
inherit "/obj/monster";

reset(arg) 
{
  ::reset(arg);

 if (arg) return;

  set_name("ball fish");
  set_no_steal();
  load_chat(2,({"Bulp\n","P F F F F .....\n","B U L P\n"}) );
  set_alias("fish");
  set_race("fish");
  set_short("A pink ball fish");
  set_long("You see a pink sperical ball fish....Bulp\n");
  set_level(14);
  set_has_gills();
  set_al(10);
  set_spell_mess1("P F F F F F.........the ball fish pumps himself up");
  set_spell_mess2("P F F F F F.........the ball fish pumps himself up");
  set_chance(2);
  set_spell_dam(20);
  move_object(clone_object("players/whisky/obj/invis_potion"),this_object());
}
