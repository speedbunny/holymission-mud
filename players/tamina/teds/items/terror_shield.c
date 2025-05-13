static object owner;
static string own_name;

set_owner(object ob) 
{
  owner = ob;
  own_name = capitalize(owner->query_name());
  shadow(owner, 1);
}

can_put_and_get() 
{ 
  return 0; 
}

long() 
{
  tell_object(owner, this_player()->query_name()+" looked at you.\n");
  owner->long();

  write("You are terrified of "+owner->query_name()+"'s power and run away!!!!!\n\n");
  this_player()->run_away();
  return 1;
}
