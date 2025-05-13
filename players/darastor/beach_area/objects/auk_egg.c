inherit "/obj/treasure";

void reset(int arg)
{
  ::reset(arg);
  if(!arg)
  {
     set_name("auk egg");
     set_alias("egg");
     set_short("The egg of a great auk");
     set_long("A single, large great auk egg. Since these eggs are rare "+
       "it might be quite valuable.\n");
     set_value(50);
     set_weight(1);
   }
}
