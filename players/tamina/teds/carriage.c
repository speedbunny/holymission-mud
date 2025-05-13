inherit "obj/thing";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

    set_name("A horse-drawn Carriage"); 
    set_long( 
      "The carriage is made of sturdy oak. Even though the\n"+
      "carriage looks old, is looks strong enough to withstand\n"+
      "the strongest of storms. The carriage is ready to leave\n"+
      "when you are.\n");
    set_can_get(0);

}

int id(string str) 
{
  return str == "carriage" || str == "coach";
}

void init() 
{
  add_action("enter", "enter");
  "/players/tamina/teds/in_carriage"->set_find(TO);
}

int enter(string str) 
{
  if (str == "carriage" || str == "coach") 
  {
    say(TPN+" enters the carriage.\n");
    write("You enter the carriage.\n");
    MPL("into the carriage#/players/tamina/teds/in_carriage");
    return 1;
  }
  else
  {
    notify_fail("Enter what?\n");
    return 0;
  }
}
