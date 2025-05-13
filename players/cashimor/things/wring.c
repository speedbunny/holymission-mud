/* This file was originally made by Bonzo, some edits by me to make it an
   engagement ring. It may be cloned if people want to get engaged...     */
inherit "/obj/armour";

string inscribed_name, inscriber_name;
int hush_up;
reset(arg)
{
    ::reset(arg);
    if (arg) return 0;
  set_name("ring");
set_alias("engagement ring");
set_short("An engagement ring");
set_long("This is obviously an engagement ring. There is even an\n"
       + "inscription on it.\n");
    set_ac(0);
    set_weight(1);
    set_value(10);
  set_type("ring");
}

init()
{
    ::init();
  add_action("inscribe","inscribe");
  add_action("read","read");
  add_action("hush","quit");
}

hush()
{
  hush_up = 1;
  return 0;
}

drop()
{
if(this_player()->query_real_name()=="cashimor")
     return 0;
  if(!hush_up)
    write("No way, you won't drop _that_!\n");
  return 1;
}

query_auto_load()
{
return "players/cashimor/things/wring:"+inscriber_name+"#"+inscribed_name;
}

init_arg(str)
{
  sscanf(str,"%s#%s",inscriber_name,inscribed_name);
}

inscribe(str)
{
  if(!str) return 0;

  if(inscribed_name)
    {
      write("There is already a name on it.\n");
      return 1;
    }
  inscribed_name = capitalize(str);
  inscriber_name = this_player()->query_name();
  return 1;
}
read(str)
{
  if(!id(str)) return 0;

  write("The inscription in this ring reads:\n"+
"I, "+inscriber_name+" hereby declare that I'm engaged to "+inscribed_name+"\n"+
    "till death do us part!\n");
  return 1;
}
