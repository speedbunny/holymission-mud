inherit "/obj/container";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("cupboard");
    set_alias("bag");
    set_max_weight(12);
    set_short("A cupboard");
    set_long("A brown wooden cupboard for the cooking tools.\n");
    set_value(0);
    set_weight(1);
    set_can_get(0);
  }
    move_object(clone_object("/players/emerald/lakmir/spoon"),this_object());
    move_object(clone_object("/players/emerald/lakmir/bottle"),this_object());
    move_object(clone_object("/players/emerald/lakmir/bowl"),this_object());
}
