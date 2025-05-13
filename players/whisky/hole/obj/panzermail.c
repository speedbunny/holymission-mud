inherit "obj/armour";

 reset (arg) {
  ::reset(arg);
  if (arg) return;

   set_name("panzermail");
    set_alias("mail");
    set_type("armour");
    set_size(5);
    set_short("The Panzermail");
    set_long("The mighty protection of Gorgurack.\n"+
             "It looks like a big skin full with\n"+
             "spikes and steel plates, but it seems\n"+
             "much too big for a human to wear.\n");
    set_weight(2);
    set_ac(4);
    set_value(2000);
 }
