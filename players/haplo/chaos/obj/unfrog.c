/* Reverse the effects of a frog curse */

short()
{
  return "A large blue leaf";
}

long()
{
  write("A large blue leaf with brown speckles. Looks tasty actually!\n");
}

id(str)
{
  return str == "leaf" || str == "blue leaf";
}

init()
{
  add_action("eat","eat");
  add_action("smell_it","smell");
}

eat(str)
{
  if(!str)
   return;
  if(str == "leaf")
  {
    write("You eat the whole leaf! Tastes like sand with honey!\n");
    say(this_player()->query_name()+" eats a blue leaf.\n");
    this_player()->frog_curse(0);
    destruct(this_object());
    return 1;
  }
}

smell_it(str)
{
  if(!str)
   return;
  if(id(str))
  {
    write("The leaf smells like honey... Ummmm\n");
    say(this_player()->query_name()+" smells a blue leaf.\n");
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
  return 200;
}

query_alias()
{
  return "leaf";
}

query_alt_name()
{
  return "blue leaf";
}
