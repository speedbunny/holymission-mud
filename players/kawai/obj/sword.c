inherit "obj/weapon";

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_id("sword");
    set_weight(10);
    set_value(25000);
    set_class(90);
    set_short("A sacred sword");
    set_long("The sword is perhaps one of the most beautifully crafted weapons you\n"+
    "have ever seen!  The bladed is ingraved with powerful runes, although\n"+
    "you aren't sure of their meaning.  The blade is made of an unfamiliar\n"+
    "alloy, and is unusally strong and sharp.\n");}}


