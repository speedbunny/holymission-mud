#pragma strict_types
#pragma save_types
inherit "obj/thing";

string query_auto_load() { return "/players/nokey/secure/disconnector:"; }


void reset(int arg)
{
    if(!arg) {
        set_alias("discon");
        set_name("disconnector");
        set_long("A disconnector.\n");
        set_weight(1);
    }
}

void init() 
{
//  if((string)this_player()->query_real_name() != "nokey")
//    destruct(this_object());
  ::init();
  add_action("disconnect","disconnect");
  write_file("/players/nokey/secure/disconn_log",
  (string)this_player()->query_real_name()+
" cloned disconnector at "+ctime() +"\n");
}

int disconnect(string str) 
{
   if(!str)
   remove_interactive(this_player());
  if(find_player(str))
    {
    remove_interactive(find_player(str));
    write("done\n");
    return 1;
    }
  notify_fail("No such player online!\n");
  return 0;
}

int get() {
    return 1;
}

void dest()
  {
  destruct(this_object());
  }

int drop()
  {
  call_out("dest",0);
  return 1;
  }
