inherit "/obj/weapon";

reset(arg)   {
   ::reset(arg);
  if (arg) return 1 ;
set_name("sword");
set_alias("longsword");
set_short("longsword");
set_long("A well made large, one-handed sword. \n");
set_class(15);
set_value(1000);
set_weight(3);
}
