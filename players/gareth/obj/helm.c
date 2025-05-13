inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("helm");
    set_alias("adamantine helm");
    set_type("helmet");
    set_ac(2);
    set_size(3);
    set_short("A glowing helm");
    set_long("An adamantine helmet, it's inscibed with the phrase\n"+
    " 'The mind is the greatest weapon'\n");
    set_weight(1);
    set_value(1000);
    }
}
wear(arg) {
  if((this_player()->query_race() != "elf") &&
     (this_player()->query_race() != "half-elf")) {
    write("You must be of elven decent to wear this armour.\n"); 
    return 1;
   }
   return ::wear(arg);
  }
  query_mage_wear() {return 1;}
