inherit "obj/armour";
#include "/players/meecham/def.h"
object ob;
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Cloak of invisibility");
  set_ac(0);
  set_weight(3);
  set_value(7500);
  set_alias("cloak");
  set_type("plate");
  set_short("Cloak of invisibility");
  set_long("You have found a cloak of invisibility.  Just:  wear cloak  and\n"+
    "have fun scaring your friends!\n");
}
init()
{
  ::init();
}
wear(str)
{
  if(TP->query_invis())
  {
    write("You are already invisible.  Leave this cloak for someone who needs "+
      "it.\n");
    MO(TO(),env(TP));
    return 1;
  }
  if(env(TP)->query_property("no_hide"))
  {
    notify_fail("You can't seem to get the cloak tied.\n");
    return 0;
  }
  if(TO()->query_worn())
  {
    write("You are already wearing it!\n");
    return 1;
  }
  ::wear(str);
  write("You slip the cloak over your shoulders and fade from view...\n");
  say(TP->query_name() + " slowly fades out of sight!");
  TP->set_invis();
  return 1;
}
remove(str)
{
  if(!TO()->query_worn())
  {
    write("But you're not wearing it.\n");
    return 1;
  }
  ::remove(str);
  TP->set_vis();
  move_object(TP,env(TP));
  write("You remove the cloak and show yourself again.\n");
  say(TP->query_name() + " " + TP->query_msgin() + ".\n");
  return 1;
}
drop(str)
{
  if(TO()->query_worn())
  {
    TP->set_vis();
    move_object(TP,env(TP));
    if(worn_by)
      worn_by->stop_wearing(TO());
  }
  ::drop(str);
}
