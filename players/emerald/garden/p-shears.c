inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("pruning-shears");
  set_alias("shears");
  set_alt_name("shear");
  set_class(5);
  set_short("A pair of pruning-shears");
  set_long("This pruning-shears are used by the gardener to trim the\n" +
           "hedges in his garden. Maybe you could use it as weapon.\n");
  set_value(1);
  set_weight(1);
}
