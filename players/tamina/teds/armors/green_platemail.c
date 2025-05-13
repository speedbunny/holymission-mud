inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("Olive Green Platemail");
    set_alias("platemail");
    set_type("armour");
    set_short("Olive Green Platemail");
    set_long("It is made out some strange olive-green material.\n"+
	     "It feels very rigid and protective to the touch...\n");
    set_value(2000);
    set_weight(7);
    set_ac(4);
}
