inherit "/obj/armour";
 
void reset(int arg) 
{
  ::reset(arg);
  if(arg==0) 
  {
     set_name("grasshopper helmet");
     set_alias("helmet");
     set_type("helmet");
     set_ac(0);
     set_short("A green grasshopper helmet");
     set_long("The strong armour of the green grasshopper.\n");
     set_value(30);
     set_weight(1);
  }
}

