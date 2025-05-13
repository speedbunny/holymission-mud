inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("thief mask");
    set_type("helmet");
    set_short("thief mask");
    set_long("A mask to be worn by thieves so that thier identity may\n"+
	     "not be known.\n");
    set_value(500);
    set_ac(1);
    set_weight(1);

}
