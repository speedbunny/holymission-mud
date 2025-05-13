inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("vest");
   set_type("armour");
   set_size("small");
   set_short("A leather vest");
   set_long("A tattered leather vest stolen from the kender.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
}
