/*coded by gandalf for the samurai guild*/
/*coded by gandalf forthe samurai guild*/
inherit "obj/armour";

 reset (arg) {
  ::reset(arg);
  if (arg) return;

   set_name("ring of light");
     set_alias("ring");
    set_type("armour");
   set_size ("any");
   set_short("The Ring of Light");
      set_long("Looking at this ring you can see it is made of fine gold.\n"+
	       "It also glows with a bright inner light.\n");
    set_weight(2);
    set_ac(0);
    set_light(1);
     set_value(5000);
 }
