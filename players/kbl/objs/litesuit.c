/* Light Beam Protection suit */

int worn;

reset(arg)
{
  if(arg)
   return;
  worn = 0;
}

short()
{
  return "Light Suit";
}

long()
{
  write("This is the " +short()+ " for protection against high intensity\n");
  write("light materials, but not any good as armour.\n");
}

id(str)
{
  return str == "light suit" || str == "Light Suit";
}

init()
{
  add_action("turn_on","turnon");
  add_action("shut_off","shutoff");
}

turn_on(str)
{
  if(!str)
   return;
  if(id(str))
  {
   write("A powerful glow envelopes you! The " +short()+ " is functional.\n");
   worn = 1;
   return 1;
  }
}

shut_off(str)
{
  if(!str)
   return;
  if(id(str))
  {
   write("The "+short()+"s glow shuts off.\n");
   worn = 0;
   return 1;
  }
}

get()
{
  return 1;
}

query_worn()
{
  return worn;
}

query_weight()
{
  return 1;
}

query_value()
{
  return 5000;
}

query_name()
{
 return short();
}

query_alias()
{
return "light suit";
}

query_alt_name()
{
  return "suit";
}
