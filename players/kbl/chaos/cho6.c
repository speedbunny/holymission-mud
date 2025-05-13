/* Stronghold Main Entrance */

inherit "room/room";
int door_locked,door_opened;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    door_locked = 1;
    door_opened = 0;
    short_desc = "Stronghold main entrance";
    long_desc = "North is a large door leading into the Stronghold. The\n"+
                "door is highly polished high density dark crystal and\n"+
                "look too tough to smash. Other features of the door look\n"+
                "very very strange indeed. There's a beautiful key hole\n"+
                "on the left side of the door. Many symbols line this\n"+
                "entrance way. A natural bridge leads south across canyon.\n";
    dest_dir = ({"players/kbl/chaos/cho7","north",
                 "players/kbl/chaos/cho5","south"});
    items = ({"crystal","The dark crystal has streaks of white crystal\n"+
                        "running through it. The white seems to move\n"+
                        "within the black or is that visa versa?",
              "left","Looking left, facing north, you see the walls of the\n"+
                     "Stronghold go about 200 meters northeast, then slopes\n"+
                     "underground. No access to walls because of the razor\n"+
                     "sharp dark crystals sticking out of the ground\n",
              "right","Looking right, facing north, the wall ends 50 meters\n"+
                      "away. There is no access this way but a path has\n"+
                      "been started and is in progress. Alot of broken dark\n"+
                      "crystal is piled up here.\n",
              "sharp dark crystals","It looks like some pressure under the\n"+
                                    "surface has broken the dark crystal\n"+
                                    "slabs with razor sharp edges. You see\n"+
                                    "some bones laying amoung the slabs",
              "broken dark crystal","Useless crystal in large slabs piled here",
              "canyon","On the opposite side of the canyon, you see a weird\n"+
                       "sight. A rather large chunk of dark crystal is\n"+
                       "spinning in a wirlpool of flowing brown crystal and\n"+
                       "bumping against the side, causing it to splinter.\n"+
                       "The splinters fall into the brown crystal and\n"+
                       "vaporize. The vapors creep up the side of the canyon\n"+
                       "and disappear going south.\n",
              "Stronghold","The walls are not very high but you see many\n"+
                           "razor crystals lining the last 10 meters of\n"+
                           "this 20 meter high wall.\n"});
    property = "no_hide";
    smell = "The air is fresh here";
  }
}


init()
{
  ::init();
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("block","north");
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("ask","ask");
}

ask(str)
{
  if(!str)
   return;
  if(str == "door where is key" || str == "where is key")
  {
    write("Door tells you: Only the Captain is allowed that information!\n");
    write("Door tells you: Go away fleshling! You stink with alive power.\n");
    return 1;
  }
  if(str == "door for key")
  {
    write("Door tells you: I do not give keys out moron!\n");
    return 1;
  }
  if(str == "door about key")
  {
    write("Door tells you: I'm reporting you to Zesranotae! GO AWAY!!!\n");
    return 1;
  }
}

unlock(str)
{
  if(!str)
   return;
  if(str == "door")
  {
    if(door_locked)
    {
      if(!door_opened)
      {
        if(ck_key())
        {
          write("You unlock door to Stronghold.\n");
          say(this_player()->query_name()+" unlocks door to Stronghold.\n");
          door_locked = 0;
        }
        else
          write("Door tells you: You do not have the proper key.\n");
      }
      else
        write("Door tells you: Already open stupid!\n");
    }
    else
      write("Door tells you: Why don't you try opening me!\n");
    return 1;
  }
}

open(str)
{
  if(!str)
    return;
  if(str == "door")
  {
   if(!door_opened)
   {
    if(!door_locked)
    {
      door_opened = 1;
      write("You open the door to the Stronghold.\n");
      say(this_player()->query_name()+" open the door to the Stronghold.\n");
    }
    else
      write("Door tells you: Ya got to unlock me first! Go AWAY!\n");
   }
   else
     write("Door tells you: I am open! When will the fleshlings ever learn!\n");
   return 1;
  }
}

block()
{
  if(door_opened)
  {
    write("You leave through doorway to...\n");
    write("The door closes with a slam!\n");
   ::move(query_verb());
    say("The door closes behind "+this_player()->query_name()+".\n");
    door_opened = 0;
    return 1;
  }
  else
  {
    write("You bump into closed door!\n");
    say(this_player()->query_name()+" bumps into the closed door!\n");
    return 1;
  }
}


look_it(str)
{
  int val;
  if(!str)
   return;
  if(str == "at door" || str == "door")
  {
    say(this_player()->query_name()+" looks at door.\n");
    write("The door is very heavy and seems to glow with a internal power\n");
    write("of its own. The door almost looks like a face and the placement\n");
    write("of the hinges and metallic strappings its almost grinning at you!\n");
    val = random(16);
    if(val == 5)
     write("Door tells you: What are YOU looking at!!! Your face hurts me!\n");
    if(val == 11)
     write("Door tells you: Do ya got something better to do, eh? Like\n"+
           "open me or something. Hey! I hate fleshlings looking at me!\n");
   if(val == 15)
     write("Door tells you: You seen enough? Beat now. Stinking fleshling.\n");
    return 1;
  }
  if(str == "at entrance way" || str == "entrance way" || str == "entrance"
  || str == "at entrance")
  {
    say(this_player()->query_name()+" looks around the entrance way.\n");
    write("You see that the path you are on has been flattened out and\n");
    write("fused. Large broken pieces of crystal lay to the side of\n");
    write("this entrance way. Above the doorway north is a few symbols\n");
    write("in Chaos language:\n");
    if(this_player()->query_wis() > 18)
    {
      write("        ---   ---   ---   ---                ---------------\n");
  write("       /   \\ /   \\ /   \\ /   \\               |             |\n");
     write("         -     -     -     -                 ------    ------\n");
     write("         |     |     |     |                 |    |    |    |\n");
    write("        {}     {}   {}     {}                ()  ()    ()  ()\n");
     write("                     (SNOUOIETU CATIB RSENHI)\n");
      return 1;
    }
    write("             )!$p*hj_=           #4!3()#%\n");
    write("Looks like jibberish to you!!\n");
    return 1;
  }
  if(str == "at key hole" || str == "key hole")
  {
    say(this_player()->query_name()+" looks at key hole on Stronghold door.\n");
    write("The key hole is made of fused brown crystal. Its got chaotic\n");
    write("patterns scribed all over it. Looks fairly fancy. As you look\n");
    write("you see words you can read. They say, \"Ask me something\".\n");
    return 1;
  }
}

ck_key()
{
  int no_obj;
  object ob,gobj;

  no_obj = 0;
  ob = first_inventory(this_player());
  gobj = clone_object("players/kbl/objs/chaoskey");
  if(ob && gobj)
  {
    while(ob)
    {
      if(ob->query_name() == gobj->query_name())
      {
        write("Door smiles at you an says: You have the Stronghold key!\n");
        destruct(gobj);
        return 1;
      }
      else
        ob = next_inventory(ob);
    }
  }
  else
  {
    write("You don't have any inventory!!!\n");
    destruct(gobj);
    return;
  }
  if(no_obj == 0)
  {
   destruct(gobj);
   return;
  }
}
