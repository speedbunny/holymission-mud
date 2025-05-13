inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("helmet");
   set_name("hanburi");
   set_ac(1); 
   set_short("A small Hanburi");
   set_long("This is basically a hardened leather skullcap.  Not up to\n"+
      "Samurai standards but it works when needed.\n");
   set_value(50);
   set_weight(4);
   return 1;
}


