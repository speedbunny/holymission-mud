inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("wolfen chainmail");
    set_alias("chainmail");
    set_type("armour");
    set_short("wolfen chainmail");
    set_long("A chainmail of good quality.  A picture of a wolfen in battle\n"+
	     "is etched upon the breastplate.\n");
    set_value(3000);
    set_ac(3);
    set_weight(3);

}
