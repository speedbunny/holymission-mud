inherit "obj/monster";

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_name("dwarf");
    set_short("A young dwarf");
    set_long("The young dwarf sits around and plays with its toys.\n");
    set_gender(1);
    set_race("dwarf");
    load_chat(15,({"The dwarf says: I like to play! Don't you?\n",
    "The dwarf sits and plays with its toys.\n",
    "The dwarf screams: WAAAHHHHH!\n"}));
    set_level(6);}}
