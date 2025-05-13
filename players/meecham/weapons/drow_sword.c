inherit "obj/weapon";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("drow sword");
  set_alt_name("sword");
  set_class(19);
  set_value(1000);
  set_weight(5);
  set_short("A drow sword");
  set_long("This is a sword crafted by the evil drow elves.\n");
}
