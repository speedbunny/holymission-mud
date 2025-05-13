inherit "obj/monster";
#include <lw.h>

int id(string str)
  {return str=="man"||str=="lunatic"||str=="lunatic man";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_name("A lunatic man");
    set_alt_name("lunatic");
    set_race("human");
    set_level(50);
    set_gender(1);
    set_short("A lunatic man");
    set_long(lw("The man paces around the room, foaming and waving his arms.  As he walks around"+
    "he holds on to a small rock with a face painted on it.\n"));
    load_chat(30,({"The lunatic man tells you: A rock! A rock! My kingdom for a rock!\n",
    "The lunatic man tells you: Psst...wanna buy a pet rock?  Just type 'buy rock from man'!\n",
    "The lunatic man plays with a small stone.\n",
    "The lunatic man picks up a rock and starts drawing on it.\n",
    "The lunatic man bangs his head against the wall.\n"}));
    transfer(clone_object("players/kawai/obj/petrock"),this_object());}}

void init()
  {::init();
  add_action("buy","buy");}

status buy(string str)
  {object rock;
  if(!str||str!="rock from man")
    {notify_fail("Buy what?\n");
    return 0;}
  if(present("KROCK",this_player()))
    {notify_fail(
    "The man tells you: Get away!  You coveted my ice cream bar!\n");
    return 0;}
  if(this_player()->query_money()<500)
    {notify_fail(
    "The man tells you: Get lost, it's gonna cost you more than what ya got!\n");
    return 0;}
  if(transfer(rock=clone_object("players/kawai/obj/petrock"),this_player()))
    {destruct(rock);
    write("The man tells you: You don't really want it!\n");
    return 1;}
  tell_object(this_player(),"The lunatic scribbles on a rock then gives it to you.\n");
  this_player()->add_money(-500);
  return 1;}


