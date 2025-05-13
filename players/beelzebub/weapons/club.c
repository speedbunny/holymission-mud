
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("Club");
  set_alias("club");
  set_class(13);
  set_short("A club");
  set_long("A long thick peice of wood with spikes jutting out of it. \n" +
           "It looks very dangerous. \n");
  set_value(2000);
  set_weight(4);
  return 1;
}

