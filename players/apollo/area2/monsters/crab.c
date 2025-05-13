
inherit "/obj/monster";

void reset (int arg) {
  ::reset(arg); 
  if (arg) return;

    set_name("crab");
    set_alias("little crab");
    set_short("A little crab");
    set_long("A smart little crab\n");
    set_level(1);
    set_has_gills();
    set_size(1);
    set_race("fish");

    move_object(clone_object("players/apollo/area2/obj/shell"),
	this_object());

}
