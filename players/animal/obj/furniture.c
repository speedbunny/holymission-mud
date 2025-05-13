inherit "obj/treasure";
 
object sitter;
string name,title,short_desc,sit_desc;
 
get()
{
  write(short_desc+" is secured to the floor.\n");
  return 0;
}
 
query_sitter()
{
  return sitter;
}
 
set_short(str)
{
  short_desc = str;
}
 
short()
{
  if(sitter)
  return short_desc+sit_desc;
  return short_desc;
}
 
init()
{
  ::init();
  add_action("sit_chair","sit");
  add_action("stand_up","stand");
}
 
sit_chair(str)
{
  string on_what,a,b;
 
  if(sscanf(this_player()->query_title(),"%s()%s",a,b))
    return 0;
 
  if(!str || sscanf(str,"on %s",on_what)!=1)
    {
      write("Sit on what?\n");
      return 1;
    }
 
  if(!id(on_what))
    {
      return 0;
    }
 
  if(sitter)
    {
      write(name + " is already relaxing on it.\n");
      return 1;
    }
 
  sitter=this_player();
  name=sitter->query_name();
  title=sitter->query_title();
 
  write("You relax.\n");
  say(name+" relaxs.\n");
 
  sitter->set_title(title+" (relaxing)");
  sit_desc=" ("+name+")";
  return 1;
}
 
get_off_chair()
{
  sitter->set_title(title);
  sit_desc=0;
  sitter=0;
  return 1;
}
 
stand_up()
{
  if(this_player()==sitter)
    {
      write("You stand up.\n");
      say(name+" stands up.\n");
      get_off_chair();
      return 1;
    }
  return 0;
}
 
exit(ob)
{
  if(ob && ob==sitter)
    {
      say(name+" stands up as "+ob->query_pronoun()+" leaves.\n");
      get_off_chair();
    }
}

