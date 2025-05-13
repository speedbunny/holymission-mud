inherit "room/room";
#include "/players/tamina/defs.h"

object huorn;
status in_progress;
int counter;

void reset(int arg) 
{
  ::reset(arg);
  huorn = present("huorn");
  if (!huorn) 
  {
    huorn = clone_object(TMONS + "huorn");
    "/players/tamina/teds/random_treasure"->make_item(huorn, 22);
    move_object(huorn, this_object());
  }
    counter = 0;
  if (arg) return 0;

    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"This part of the forest almost looks like a garden\n"+
"The trees are in almost perfect rows and are in\n"+
"perfect shape. The sun shines brightly on a few\n"+
"daisies that have grown on the open paths between\n"+
"the trees. A small, picturesque clearing stands\n"+
"in the centre.\n";

    dest_dir = ({
    TFOREST + "rmK", "north",
    TFOREST + "rmE", "west",
    });

    items = ({
  "clearing",
"The clearing around you seems to be so idyllic and pleasant that you "+
"feel inexorably pulled towards entering the clearing...",
  "trees",
"They are tall, thin, and provide a lot of cool shade",
  "daisies",
"They are small, and very nice to look at in the sunshine",
    });
}

void init()
{
  ::init();
  AA("_enter", "enter");
}

int _enter(string str)
{
  if (str == "clearing")
  {
    if (present("huorn"))
    {
      write("The malevolent Huorn prevents you from entering its clearing !!\n");
      say("The Huorn prevents "+TPN+" from entering the clearing.\n");
      huorn->attack_object(TP);
      return 1;
    }
    if (in_progress)
    {
      write("But "+TPN+" is already in the clearing...\n");
      return 1;
    }
    if (counter >= 5)
    {
      write("Sadly, all the healing powers of the clearing have been used.\n"+
	    "Try again later...perhaps the sun will be stronger...\n");
      say(TPN+" steps into the clearing, but looks quite sad.\n");
      return 1;
    }
    write("You slowly step into the small clearing bathed in sunshine.\n"+
          "You feel the sun's rays glow all over you...\n");
    say(TPN+" steps into the clearing.\n");

    in_progress = 1;
    call_out("healer", 3, TP);
    return 1;
  }
  else
  {
    NFAIL("Enter what?\n");
    return 0;
  }
}

healer()
{
  int amount;

  TOBJ(TP, "You suddenly feel much more healthy !!\n");
  say(TPN+" looks much better for entering the Treant's Clearing.\n");

  amount = TP->query_alignment();

  switch(amount)
  {
    case -500 .. -300:
     TP->heal_self(1);
      break;

    case -299 .. -100:
     TP->heal_self(2);
      break;

    case -99 .. -1:
     TP->heal_self(5);
      break;

    case 0:
     TP->heal_self(7);
      break;

    case 1 .. 50:
     TP->heal_self(10);
      break;

    case 51 .. 99:
     TP->heal_self(20);
      break;

    case 100 .. 200:
     TP->heal_self(35);
      break;

    case 201 .. 450:
     TP->heal_self(50);
      break;

    case 451 .. 700:
     TP->heal_self(amount);
      break;

    default:
     TP->heal_self();
  }
  counter++;
  in_progress = 0;
  return 1;
} 
