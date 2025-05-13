
inherit "/obj/treasure";

void reset(int arg)
{
     if (arg == 0)
     {
       move_object(this_object(),"/room/south/sshore4");
       set_name("A beautiful villa");
       set_alias("villa");
       set_short("A beautiful villa");
       set_long(
       "You see a very beautiful villa. It's build into the lake\n"+
       "There is a small sign on the entrance saying:\n\n"+
       "                   Notud and Swifto\n\n"+
       "A magic door is leading into the inner of the house.\n");
     }
}

get()
{
  return 0;
}

void init()
{
   ::init();
   add_action("do_say","say");
   add_action("do_enter","enter");
}

int do_say(string arg)
{

    if (lower_case(arg)!="love") return 0;
    tell_room(environment(),
    this_player()->query_name()+" says: Swifto.\n");
    write("Suddenly the magic door opens and moves you into the villa !\n");
    this_player()->move_player(
    "into the villa#players/whisky/houses/swifto/entrance");
    return 1;
}

int do_enter(string arg)
{
    if (arg!="house" && arg!="villa") return 0;
    write("You cant enter the house without the right password.\n");
    return 1;
}
 
int do_open(string arg)
{
    if (arg!="door" && arg!="magic door") return 0;
    write("You cant enter the house without knowing the right password.\n");
    return 1;
}


