/* Zesranotae's private chambers */

inherit "room/room";
#include "/players/kbl/header/T.h"

object slayer;
int    potion;
int    here;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    potion = 4;
    here = 1;
    set_light(1);
    short_desc = "Zesranotae's private chambers";
    long_desc = "This places looks more like a lab than a private\n"+
                "chambers for the Arch DOC. The room is filled with\n"+
                "with devices of unknown origin and portraits of past\n"+
                "Arch DOCs' line the walls. Light is provided by a glowing\n"+
                "orb and the light seems to be directed mostly onto a case\n"+
                "in the southeast corner. No furnishings can be seen here.\n"+
                "There are several pictures on the walls here...\n";
    items = ({"flasks", "Glass containers with blue, green and red liquids",
              "pictures","Only one of interest. It shows a tree house\n"+
                         "with the Arch DOC playing with human kids..",
              "beakers","Long thin neck with a wide bottom"});
    dest_dir = ({"players/kbl/chaos/cvoid","portal"});
    smell = "Refreshing odor of pine trees hangs in the air";
    property = "no_hide","no_steal";
  }
  here = 1;
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("look_it","l");
  add_action("look_it","exa");
  add_action("tree","children");
  add_action("drink","drink");
  add_action("tree","kids");
  add_action("drink","get");
  add_action("herb","tree");
  add_action("seven","seven");
}

seven()
{
  say("A voice speaks within the room: What does the symbols on the\n"+
      "Stronghold mean to you?\n");
  write("A voice speaks within this room: What does the symbols on the\n"+
        "Stronghold mean?\n");
  write("Voice thinks to you: What do they represent?\n");
  return 1;
}

herb(str)
{
  if(!str)
   return;
  if(str == "house")
  {
    write("A voice thinks to you: Tree house?? Thats too simple.\n");
    return 1;
  }
}

tree(str)
{
  if(!str)
   return;
   if(str == "playing")
  {
    if(here && !(this_player()->query_quests("AnySlayer")) )
    {
     if(TP->query_level() < 12)
     {
       write("Kbl speaks in your mind: Come back when you higher level.\n");
       return 1;
     }
      say(this_player()->query_name()+" spoke the magic words!!\n");
      say(this_player()->query_name()+" removes sword from case.\n");
      write("You speak the magic words. The case opens!\n");
      slayer = clone_object("players/kbl/objs/slayer");
      transfer(slayer,this_object());
      this_player()->set_quest("AnySlayer");
      write("You have just solved the AnySlayer quest!!!\n");
      log_file("kbl.quest","This player: "+CTPRN+" solved ANySlayer on: "+
               ctime(time())+"\n");
      this_player()->add_exp(10000);
      write("You feel more experienced\n");
      here = 0;
      return 1;
    }
    else
    {
      write("Sorry, someone beat ya to it!\n");
      return 1;
    }
  }
}

drink(str)
{
  if(!str)
   return;
  if(str == "potion")
  {
   if(potion > 0)
   {
    say(this_player()->query_name()+" drinks a potion from off of a device.\n");
    write("You drink one of the potions on the device.\n");
    this_player()->heal_self(200);
    write("You feel MUCH better.\n");
    potion-=1;
    return 1;
   }
   else
   {
     write("No more potions remaining.\n");
     return 1;
   }
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at devices" || str == "devices")
  {
    if(potion > 0)
     write("On top of a device there's a potion holder with "+potion+" remaining.\n");
    else
     write("There's a potion holder on top of a device, but its empty.\n");
    write("The rest of the devices look like alchemist tools. Flasks and\n");
    write("beakers hold all sorts of colorful liquids. Most have shapes\n");
    write("that you've never seen before.\n");
    return 1;
  }
  if(str == "at case" || str == "case")
  {
    if(here)
    {
      say(this_player()->query_name()+" looks at case with sword in it.\n");
      write("You see a beautiful sword inside of a multicolored case.\n");
      write("Case is made of solid energy. Unbreakable. Maybe its got a\n");
      write("coded key word to open it.\n");
      return 1;
    }
    else
    {
     say(this_player()->query_name()+" looks at empty case.\n");
     write("Nice looking energy case, but nothing is in it.\n");
      return 1;
    }
  }
  if(str == "at orb" || str == "orb")
  {
    say(this_player()->query_name()+" looks at orb.\n");
    write("You just see a globe of permanent light. Nothing special.\n");
    write("You go to touch it and it gives you a mild shock!\n");
    say(this_player()->query_name()+" recieves a mild shock from orb.\n");
    return 1;
  }
  if(str == "at portraits" || str == "at portraits")
  {
    say(this_player()->query_name()+" looks at portraits.\n");
    write("These portraits were done in holographic images. As you look at\n");
    write("each portrait, it seems to move and scowl at you. DOC must like\n");
    write("this because scowling is a natural look for them.\n");
    write("There is one blank Portrait.\n");
    return 1;
  }
}
