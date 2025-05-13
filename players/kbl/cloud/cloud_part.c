/* Cloud City Cloud Puzzle part */

int value,weight;
int part_num;
int thickness;
string inscrip,
       message,
       long_desc,
       short_desc,
       name,
       alt_name,
       alias_name;

reset(arg)
{
  if(!arg)
  {
    set("name","keystone");
    set("alt_name","bit");
    set("alias_name","part");
    set("part_num",1);
    set("value",1000);
    set("weight",1);
    set("short","Cloud City Cell System part");
    set("thick",2);
    set("read","Kbl is a tri-power entity.");
    set("inscrip","Ancient script states that Abstractness is Chaos, but\n"+
                  "Chaos is root of Order, therefore Abstractness is Order.\n");
  }
}

init()
{
  add_action("read","read");
}

set(com,var)
{
  switch(com)
  {
    case "name": name = var;
         break;
    case "alt_name": alt_name = var;
         break;
    case "alias_name": alias_name = var;
         break;
    case "short": short_desc = var;
         break;
    case "long": long_desc = var;
         break;
    case "part_num": part_num = var;
         break;
    case "weight": weight = var;
         break;
    case "value": value = var;
         break;
    case "thick": thickness = var;
         break;
    case "inscrip": inscrip = var;
         break;
    case "read": message = var;
         break;
  }
}

read(str)
{
  if(!str)
   return;
  if(!id(str))
   return;
  write(message);
  return 1;
}

id(str)
{
  return str == name || str == alt_name || str == alias_name;
}

inscrip()
{
  return inscrip;
}

query(com)
{
  switch(com)
  {
    case "name": return name;
          break;
    case "alt_name": return alt_name;
         break;
    case "alias_name": return alias_name;
         break;
    case "part_num": return part_num;
         break;
    case "weight": return weight;
         break;
    case "value": return value*=thickness;
         break;
    case "thick": return thickness;
         break;
    case "inscrip": return inscrip;
         break;
    case "read": return message;
         break;
    default: return -1;
         break;
  }
}

get()
{
  return 1;
}

query_value()
{
  return value*thickness;
}

short()
{
  return short_desc;
}

long()
{
  write(long_desc+"\nThis cloud part is "+thickness+" inch thick.\n");
}

query_weight()
{
  return thickness*weight;
}

query_alias()
{
  return alias_name;
}
