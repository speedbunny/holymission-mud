inherit "obj/armour";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_name("cowboy hat");
    set_alias("hat");
    set_short("black cowboy hat");
    set_long("A black cowboy hat.\n");
    set_value(5);
    set_weight(1);
    set_ac(1);
    set_type("helmet");
}

init()
{
    ::init();
    add_action("do_clean", "swipe");
  add_action("do_find", "findarch");
}

int do_clean(string what)
{
    int i;
    if(what!="people")
	return 0;

    for(i = 0; i < sizeof(users()); i++)
    {
	if(environment(users()[i])==0)
	{
	    write("Cleaning up "+users()[i]->query_name()+".\n");
	    tell_object(users()[i], this_player()->query_name()+" thinks you're stuck in a bug..\n");
	    tell_object(users()[i], this_player()->query_name()+" tells you: You're free to try again, but if the same\n");
	    tell_object(users()[i], "    happens twice in a row, please give us time to fix the bug.\n");
	    destruct(users()[i]);
	}
    }
    return 1;
}

int do_find(string what)
{
  int i, j;
  object who;
  string file;

  if(!what || what=="" || sscanf(what, "%s %d", file, i)<2)
  {
    notify_fail("Usage: findarch <filename> <number>.\n");
    return 0;
  }

  for(j = i; j < i+1000; j++)
  {
    who = find_object("sys/"+file+"#"+j);
    if(who)
    {
      write(who->query_real_name()+" at "+file_name(environment(who))+"\n");
    }
  }
  write("That's all folks.\n");
  return 1;
}
