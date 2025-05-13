inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("sheep");
    set_short("A wool sheep");
    set_long("A sheep eating the delicious grass of chantilly's garden.\n");
    set_level(2);
    set_size(2);
    load_chat(4,({ "BAEAEHEHEHehaheae eahhea ...\n" }) );
    set_al(10);
    set_whimpy();
    set_dead_ob(this_object());
    move_object(clone_object("players/whisky/garden/obj/shield"),this_object());
    command("wear shield");
  }
} 
monster_died(ob) {
  say("Suddenly, a hungry wolf arrives.\n");
  move_object(clone_object("players/whisky/garden/monster/wolf2"),
             environment(this_object()));
  return 0;
  }
