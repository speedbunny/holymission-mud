inherit "obj/treasure";
reset(arg)
{
  ::reset(arg);
  if (arg) return;
   set_name("rose");
  set_short("A small rose");
  set_long("This small rose is very beautiful to look at.\n");
  set_weight(0);
  set_value(0);
}
_smell(str)
{
  if((!str) || !id(str)) return 0;
  write("You smell the sweet fragrance of the rose.\n");
  return 1;
}
init()
{
::init();
  add_action("_smell", "smell");
}

