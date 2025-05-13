inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("halberd");
  set_class(15);
  set_short("A guard halberd");
  set_long("This halberd is wielded by guards in Jug`s castle,\n" +
	   "it seems to be a good weapon.\n");
  set_value(1500);
  set_weight(3);
}
