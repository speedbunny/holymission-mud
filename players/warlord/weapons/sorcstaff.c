inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("staff");
    set_short("Sorceror's Staff");
    set_alias("sorceror's staff");
    set_long("This staff is very powerful, it should be used only by a magicien.\n");
    set_class(20);
    set_weight(-1);
    set_value(4000);
    set_type(3);
  }
}
