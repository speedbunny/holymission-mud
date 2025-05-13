inherit "obj/weapon";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("long sword");
  set_alt_name("sword");
  set_weight(3);
  set_value(850);
  set_class(15);
  set_short("a long sword");
  set_long("This long sword looks as if it could do some damage!\n");
}
