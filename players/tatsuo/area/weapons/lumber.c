inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("A piece of lumber");
    set_alias("wood");
    set_short("lumber");
 set_long("A sturdy piece of pinewood.\n");
    set_class(10);
    set_value(50);
    set_weight(5);

}


