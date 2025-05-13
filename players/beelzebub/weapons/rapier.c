
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("Rapier");
  set_alias("rapier");
  set_class(11);
  set_short("A rapier");
  set_long("This weapon is most commonly found on skeletons. \n" +
           "It is a fairly light and very sharp weapon. \n");
  set_value(2500);
  set_weight(2);
  return 1;
}

