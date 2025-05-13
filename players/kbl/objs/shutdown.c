get()
{
  return 1;
}

drop()
{
  return 0;
}

init()
{
  add_action("shut_us","shutdown");
  add_action("ss","ss");
}

shut_us(str)
{
  if(!str)
   return;
    "/obj/shut"->do_shut(str);
  return 1;
}

ss(str)
{
  object ob;

  if(!str)
   return;
  if(ob = find_living(str))
  {
   "/players/kbl/arch/ss"->start_shadow(ob);
   return 1;
  }
  return;
}

short()
{
  return "Kbl's shutdown tool";
}

long()
{
  write(short()+"\n");
}

id(str)
{
  return str == "tool" || str == "shutdown";
}
