inherit "/obj/weapon";

reset(arg)   {
   ::reset(arg);
  if (arg) return 1 ;
set_name("mace");
set_short("mace");
set_long("A long iron rod with a diamond shape head make this cruel \n"      
+"bludgeon. \n");
set_class(15);
set_value(1000);
set_weight(3);
}
