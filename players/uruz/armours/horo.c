inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("other");
   set_name("horo");
   set_ac(1); 
  set_short("A large Horo");
  set_long("Several large pieces of cloth, sewn together into a triangle. "+
	"One end is tied at the neck/head and the other is tied to the "+
	"waist. It was usually worn by horseman. When riding, the cloth fills"+
	" with wind, and balloons out behind the rider. Some riders wore a "+
	"wicker frame with it, so it would work all the time. In either case "+
	"the horo protects the wearer from attacks from the rear. It is "+
	"brightly decorated with the symbol of the Tokugawa family. \n");
   set_value(3000);
   set_weight(5);
   return 1;
}


