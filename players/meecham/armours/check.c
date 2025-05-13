inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_short("checker");
  set_long("This object checks for invisibility.\n");
}
init()
{
  ::init();
  add_action("check","check");
}
check(str)
{
  if(!str)
  {
    if(this_player()->query_invis())
      write("You are invisible.\n");
    return 1;
  }
  return 0;
}
