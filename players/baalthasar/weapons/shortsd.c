inherit "/obj/weapon";

reset(arg)   {
   ::reset(arg);
  if (arg) return 1 ;
set_name("sword");
set_alias("shortsword");
set_short("shortsword");
set_long("A small common sword; you see nothing special");
set_class(14);
set_value(700);
set_weight(2);
}
