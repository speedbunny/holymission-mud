/* West pathway from KBLs castle turns north here */

inherit "room/room";
int mess;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    ::reset(arg);
    mess = 0;
    set_light(2);
    short_desc = "Sparse plant life and many rocks";
    long_desc = "Many rocks with small shrubs growing between them\n"+
                "makeup the area here. The mountain slopes steeply\n"+
                "south towards the valley and north the top of the\n"+
                "mountain chain is another 300 meters of so. East\n"+
                "is so rocky with huge boulders its impossible to\n"+
                "pass. West you see the narrow path going back to\n"+
               "a cliff, before approaching a castle. Huge spire of\n"+
               "rock juts up blocking most of your view of the castle\n"+
               "from here.\n";
    items = ({"rocks","Many different types of rocks. From huge boulders\n"+
                      "down to small stones",
              "small stones","Most have small bits of white quartz in them",
              "shrubs","Small scraggly looking bushes. Looks as if they\n"+
                       "have endured many harsh winters",
              "castle","Not much you can see from here",
              "spire","This rocky spire rises high into the air about\n"+
                      "1000 meters distant from here looking west",
              "valley","You can't see much because big boulders block most\n"+
                       "of your view of the valley"});
    dest_dir = ({"players/kbl/grounds/mount1","north",
                 "players/kbl/grounds/gro31","west"});
    smell = "Fresh air with a hint of decaying plant life";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("sou","south");
  add_action("eas","east");
  wind();
  life();
}

wind()
{
  if("/players/kbl/grounds/gro1"->query_wind_set())
   smell = "/players/kbl/grounds/gro1"->query_wind_smell();
  else
   smell = "Fresh air with a hint of decaying plant life";
}

life()
{
  int i;

  i = random(16);
  switch(i)
  {
    case 1:
    case 2:
     say("A small scorpion runs out from under a rock heading for another.\n");
     write("You see a scorpion on the ground.\n");
     mess = i;
     break;
    case 5:
    case 6:
    case 7:
    case 8:
     say("A gust of wind whips through swirling dust into your eyes.\n");
     write("A gust of wind whips through swirling dust into your eyes.\n");
     mess = i;
     break;
    case 11:
    case 12:
     say("A large bird flies overhead.\n");
     write("A large bird flies overhead.\n");
     mess = i;
     break;
  }
}

eas()
{
  say(this_player()->query_name()+" is blocked by many boulders going east.\n");
  write("You are blocked by many boulders from going east.\n");
  return 1;
}

sou()
{
  say(this_player()->query_name()+" makes it through the boulders, but\n"+
      "shys away from the extremely steep slope beyond and comes back.\n");
  write("You make it through the boulders but the slope is so steep you\n"+
        "shy away.\n");
  return 1;
}

look_it(str)
{
  string rock;
  int i;

  if(!str)
   return;
  i = random(3);
  switch(i)
  {
    case 0:
            rock = "large flat granite type rock";
            break;
    case 1:
            rock = "small bush";
            break;
    case 2:
            rock = "huge boulder to the east";
            break;
    case 3:
            rock = "large clump of dead grass";
            break;
    default:
            rock = "small stone";
            break;
  }
  if(str == "at bird" || str == "bird")
  {
    if(mess == 11 || mess == 12)
    {
      say(this_player()->query_name()+" looks up at bird heading north.\n");
      write("A rather large bird heading northward. Large black wings\n"+
            "with red wing tip feathers. As you watch it flies over the\n"+
            "mountain peak out of sight.\n");
      say("The bird flies over the mountain peak out of sight.\n");
      mess = 0;
      return 1;
    }
    else
    {
      write("What bird??\n");
      return 1;
    }
  }
  if(str == "at scorpion" || str == "scorpion")
  {
   if(mess == 1 || mess == 2)
    {
      say(this_player()->query_name()+" looks down at running scorpion.\n");
      write("A brown and white scorpion. Must be a mountain variety. It\n"+
            "disappears under a "+rock+".\n");
      say("The scoprion disappears under a "+rock+".\n");
      mess = 0;
      return 1;
    }
    else
    {
      write("What scorpion??\n");
      return 1;
    }
  }
}
