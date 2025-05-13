inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("tuna");
    set_alias("fish");
    set_level(8);
    set_short("A tuna");
    set_long("A tuna.  The filet makes a tasty soup.\n");
    set_no_steal(1);
    move_object(clone_object("players/emerald/lakmir/tfilet"),this_object());
}
