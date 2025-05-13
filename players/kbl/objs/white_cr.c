/* White Crystal */

int h;
int tim;

reset(arg)
{
  tim = 25;
  if(arg)
   return;
}

short()
{
  return "White Crystal";
}

long()
{
  write("This hunk of "+short()+" glows with internal power. Its fine\n");
  write("crystaline structure makes this piece very valuable.\n");
}

id(str)
{
  return str == "white crystal" || str == "White Crystal";
}

init()
{
  add_action("absorb","absorb");
  add_action("power","recharge");
}


absorb(str)
{
  if(!str)
   return;
  if(str == "all from white crystal")
  {
   if(tim > 0)
   {
    write("You absorb all remaining energy points.\n");
    this_player()->heal_self(tim);
    tim = 0;
    return 1;
   }
   write("There is no more energy to absorb!.\n");
   return 1;
  }
  if(str == "half from white crystal")
  {
    if(tim > 0)
    {
      write("You absorb half of "+tim+" energy points remaining.\n");
      this_player()->heal_self(tim/2);
      tim = tim/2;
      return 1;
    }
    write("There is no more energy to absorb!\n");
    return 1;
  }
}

get()
{
  return 1;
}

query_weight()
{
  return 1;
}

query_value()
{
  return 250 * tim;
}

query_name()
{
  return short();
}

query_alias()
{
  return "crystal";
}

query_alt_name()
{
  return "crystal";
}

set_tim(h)
{
  tim = h;
}

power(str)
{
  object ob;

  if(!str)
   return;
  switch(str)
  {
    case "star leaf":
    case "Star Leaf":
         if(ob = present("star leaf",this_player()))
         {
           tell_object(this_player(),"You recharge your Star Leaf!\n");
           ob->set_charge(50);
           tell_object(this_player(),"The white crystal shatters!\n");
           destruct(this_object());
           return 1;
         }
         tell_object(this_player(),"You do not have a Star Leaf!\n");
         return 1;
  }
}
