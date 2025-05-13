inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("cod");
    set_alias("fish");
    set_level(8);
    set_short("A cod");
    set_long("A cod.  The filet makes a tasty soup.\n");
    set_no_steal(1);
    move_object(clone_object("players/emerald/lakmir/cfilet"),this_object());
}
