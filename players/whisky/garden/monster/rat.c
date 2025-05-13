inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("rat");
    set_alias("black rat");
    set_short("A big black rat");
    set_long("It looks as it is very hungry.\n");
    set_race("animal");
    set_level(2);
    set_size(1);
    set_al(-100);
    set_aggressive(1);
    move_object(clone_object("players/whisky/garden/obj/cheese"),
    this_object());
    move_object(clone_object("players/whisky/garden/obj/rat_fur"),
    this_object());
  }
}
 
 
