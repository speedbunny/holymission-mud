inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("herring");
    set_alias("fish");
    set_level(8);
    set_short("A herring");
    set_long("A herring.  The filet makes a tasty soup.\n");
    set_no_steal(1);
    move_object(clone_object("players/emerald/lakmir/hfilet"),this_object());
}
