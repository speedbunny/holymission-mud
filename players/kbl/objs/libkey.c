/* KBL's Library Key */

int on;

reset()
{
  on = 0;
}

short()
{
  return "KBL's Library Key";
}

long()
{
  write("This is " + short() + ".  There are two jeweled studs located on one\n");
  write("side of the key.  One has ON engraved next to it, the other has OFF\n");
  if (on)
   write("You see the ON stud is glowing a soft white color.\n");
  else
   write("You see the OFF stud is glowing a soft red color.\n");
}

id(str)
{
  return str == "library key" || str == "Library Key";
}

init()
{
  add_action("turn_on","turnon");
  add_action("turn_off","turnoff");
}


turn_on(str)
{
  if(!str)
   return;
  if(id(str))
  {
    write("The white jeweled stud glows, the key is functional.\n");
    on = 1;
    return 1;
  }
}

turn_off(str)
{
  if(!str)
   return;
  if(id(str))
  {
    write("The red jeweled stud glows and the white stud turns dark.\n");
    on = 0;
  }
}

get()
{
 return 1;
}

query_on()
{
  return on;
}

query_weight()
{
  return 1;
}

query_value()
{
  return 5000;
}

query_alias()
{
   return "key";
}

query_name()
{
  return short();
}

