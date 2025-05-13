inherit "obj/weapon.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Guard's Longsword");
  set_alt_name("sword");
  set_short("A Guard's Longsword");
  set_long("This is a longsword of Ace's Castle Guard.\n" +
           "It doesn't look like much of a weapon.\n");
  set_value(400);
   set_weight(2);
  set_class(13);
}
