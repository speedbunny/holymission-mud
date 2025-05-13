inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("demon horn");
  set_short("A sharp demon's horn");
  set_long("This demon's horn is sharp!  You could do some good damage\n" +
           "with this weapon.\n");
  set_alt_name("horn");
  set_class(15);
  set_value(1500);
  set_weight(3);
}
