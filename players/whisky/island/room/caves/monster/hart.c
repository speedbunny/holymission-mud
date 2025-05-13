inherit "/obj/monster";

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("hart");
   set_level(10);
   set_size(4);
   set_alias("big hart");
   set_short("A big aggressive hart");
   set_long("Quick run away it looks dangerous.\n");
   set_race("animal");
   set_spell_mess1("The hart hits you with it's antler");
   set_spell_mess2("The hart hurts you badly");
   set_chance(20);
   set_spell_dam(4);
   move_object(clone_object("/players/whisky/meadow/obj/antlers"),
               this_object());
}
}
