inherit "obj/thing";

reset(arg)
{
  if(!arg)
  {
    set_short("forcer");
    set_name("forcer");
  }
}

string victim, comm;
object ob;

int aforce(string arg)
{
  sscanf(arg,"%s %s",victim,comm);
  ob = find_living(victim);
  command(comm,ob);
  write("You force "+victim+" to "+comm+"\n");
 return 1;
}

get(){
return 1;}
init()
{
   add_action("aforce","aforce");
}
