/* 
   Cloud Cell system - part of a multi layered cloud cell system that has
   adventures trapped in a layered environment. Depending on the depth and 
   access of their cloud control wand is to how far into the they can go into 
   the interior of the cloud cell system to find the puzzle they 
   need for quest and maybe find their way into the depths of the cloud city.
*/

#include "/players/kbl/cloud/cloud.h"
#include "/players/kbl/cloud/cell.h"

mixed  *cell_dest;
string name, 
       add_cmd,
       *events,
       cell_long;

int    cell_density, 
       cell_type, 
       cell_conn, 
       cell_access;

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  object ob;

  if(!find_object("/players/kbl/cloud/kbl_cloud"))
   call_other("/players/kbl/cloud/kbl_cloud","???");
  ob = find_object("/players/kbl/cloud/kbl_cloud");
  set_light(1);
  set_name("Cloud Control");
  set_long("You are inside the very soul of the CCCS.\n");
  events = ({
             "A vapory cloud rushes by",
             "Several rumbles of thunder move though here",
             "The clouds look like clovers",
             "Something flys by to your right",
             "Many voices sing in your head from the wind blowing by",
             "A flash of lightning occurs close by followed by thunder",
             "The wind picks up a bit",
             "Something flies by rapidly below you",
             "Several smaller clouds rush by below you",
            });
  cell_dest = ({
                "KBLS",ob,
               });
  set_density(5);
  set_type(5);
  set_conn(1);
  set_access(10);
}

init()
{
  if(!bounce())
  {
    write("You are not allowed access directly into a cloud cell!!! You are\n"+
          "being bounced out. Go buy a cloud control wand.\n");
    transfer(TP,SCREEN);
    return;
  }
  if(events)
   event();
  add_action("look","look");
  add_action("look","l");
  add_action("look","exa");
  add_action("quit","quit");
  add_action("connect","enter");
}

event()
{
  if(random(random(random(100))) > 45)
    tell_object(TO,events[random(sizeof(events))]+".\n");
}

short()
{
  return name +".\n";
}

line() 
{ 
  write("\t********************************************************\n");
}

bit(str) 
{ 
  return extract((CP(str)+"                   "),0,19); 
}

/* Basic query functions */

query_cell_density() { return cell_density; }
query_cell_conn() { return cell_conn; }
query_add_cmd() { return add_cmd; }
query_name() { return name; }
query_cell_dest() {  return cell_dest; }
query_access() { return cell_access; }
query_type() { return cell_type; }
query_conn_lines() 
{ 
  if(!cell_conn) 
   return random(cell_density*5)+2;
  else 
   return cell_conn;
}
query_cell_type() 
{
   switch(cell_type)
   {
     case 0: return "White";
     case 1: return "Red";
     case 2: return "Green";
     case 3: return "Blue";
     case 4: return "Yellow";
     case 5: return "Guard";
   }
}

/* Basic set functions */

set_name(str) { name = str; }
set_type(cell) { cell_type = cell; }
set_conn(conn) { cell_conn = conn; }
set_density(den) { cell_density = den; }
set_access(acc) { cell_access = acc; }
set_long(str) { cell_long = str; }

look(str)
{
  if(!str)
  {
    write(cell_long);
    cell_conn();
    other_cmds();
    return 1;
  }
}

other_cmds()
{
  int i;

  if(!add_cmd)
   return;
  for(i=1;i<sizeof(add_cmd);i+=2)
    write("\t"+extract((add_cmd[i-1]+"             "),0,10)+"  "+
          add_cmd[i]+".\n");
}

cell_header()
{
  write("\t\tAccess\tCell Id  \t\tCode\n");
}

connect(str)
{
  int i,true;
  object ob,old;

  if(!str)
  {
    line();
    cell_header();
    line();
    for(i=1;i<sizeof(cell_dest);i+=2)
    {
      if(cell_dest[i])
       write("\t\t["+cell_dest[i]->query_access()+"] "+
            "\t"+cell_dest[i-1]+" :\t\t"+cell_dest[i]->query_cell_type()+"\n");
    }
    line();
    return 1;
  }
  true = 0;
  i=1;
  while(i<=(sizeof(cell_dest)-1) && !true)
  {
    if(str == cell_dest[i-1])
    {
      if(cell_dest[i])
      {
        if(!access(i-1))
        {
          write("You are denied access!\n");
          return 1;
        }
        true = 1;
        tell_room(cell_dest[i]," <<>> You sense "+CTPRN+" has entered this"+ 
                  " cell. <<>>\n");
        old = ETP;
        transfer(TP,cell_dest[i]);
        tell_room(old," <<>> You sense "+CTPRN+" has left this cell. <<>>\n");
        write(" <<>> You transfer to "+ob->query_name()+" <<>>\n");
      }
    }
    i+=2;
  }
  if(!true)
    write(" <<>> Unable to transfer to "+str+" <<>>\n");
  return 1;
}

cell_conn()
{
  write("\tNumber of connecting cells: "+query_cell_conn()+"\n");
  conn_line_runners();
}

conn_line_runners()
{
  object rx, test;
  string pla, name;
  int i,j;

  pla = allocate(40);
  rx = first_inventory(E(TP));
  write("\tCell skippers: ");
  i = 0;
  while(rx)
  {
   name = rx->QRN;
   if(name)
   {
    if(find_player(name))
    {
      pla[i] = name;
      i++;
    }
   }
   rx = next_inventory(rx);
  }
  if(!i)
  {
    write("NONE\n");
    return 1;
  }
  j = 0;
  write("\n");
  while(i > 0)
  {
    if(i == 1)
    {
      write("\t"+bit(pla[j])+"\n");
      i--;
      j++;
    }
    if(i == 2)
    {
      write("\t"+bit(pla[j])+bit(pla[j+1])+"\n");
      i-=2;
      j+=2;
    }
    if(i > 2)
    {
      write("\t"+bit(pla[j])+bit(pla[j+1])+bit(pla[j+2])+"\n");
      i-=3;
      j+=3;
    }
  }
  return 1;
}

bounce()
{
  object ob;

  ob = present("cloud_control",TP);
  if(!ob || !ob->query("cont_on"))
   return;
  return 1;
}

access(i)
{
  object ob;
  int enter_type;

  ob = present("cloud_control",TP);
  if(ob)
  {
    switch(ob->query("type"))
    {
      case "White":
      case "white":
           enter_type = 0;
           break;
      case "Red":
      case "red":
           enter_type = 1;
           break;
      case "Green":
      case "green":
           enter_type = 2;
           break;
      case "Blue":
      case "blue":
           enter_type = 3;
           break;
      case "Yellow":
      case "yellow":
           enter_type = 4;
           break;
      case "Security":
      case "security":
           enter_type = 5;
           break;
    }
    if(cell_dest[i+1]->query_type() > enter_type)
     return;
    if(cell_dest[i+1]->query_type() == enter_type)
     if(cell_dest[i+1]->query_access() > ob->query(AC))
      return;
    if(cell_dest[i+1]->query_type() == enter_type) 
     if(cell_dest[i+1]->query_cell_density() > ob->query(DN))
      return;
    return 1;  /* You gain access to this cloud cell */
  }
}
