
inherit "obj/treasure";
/* Coded by Axlrose for the barbarian guild */

reset(arg) {
  ::reset(arg);
  if (arg) return;

    set_name("a piece of pure iron");
    set_alias ("iron");
    set_alias("iron");
    set_short("A piece of pure iron");
    set_long("A piece of iron, in its purest form.\n");
    set_value(10);
    set_weight(2);
}
