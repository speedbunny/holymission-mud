inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("cooking pan");
    set_alias("pan");
    set_short("a cooking pan");
 set_long("This pan is cast iron.  If you try really hard you could\n"+
	  "probably hit someone with it too.\n");
    set_class(5);
    set_value(500);
    set_weight(2);

}


