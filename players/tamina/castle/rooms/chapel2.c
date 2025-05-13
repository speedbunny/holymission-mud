/*  This is the Chapel  */

inherit "room/room";

#include "/players/tamina/defs.h"
#define ALT "/players/tamina/castle/rooms/altar"

object mob, obj, obj2;
int drunk,smelled,summoned;
status p1, p2, p3, p4;
string c1, c2, c3, c4, what, what2;

void reset(int arg) 
{
  ::reset(arg);

  drunk = 0;  smelled = 0;  summoned = 0;
  p1 = 0;   p2 = 0;   p3 = 0;   p4 = 0;

  if (arg) return 0;

    set_light(1);
    short_desc = "Holy Chapel ";
    long_desc = 
"As you enter here, you immediately recognise this place as being a\n"+ 
"small, but well-maintained Chapel.  Stained glass windows throw \n"+
"softly-coloured light onto the aisle and benches from the far eastern \n"+
"wall.  At the head of the aisle, there is a large altar.  Behind the \n"+
"small benches is a stone font.\n";

	dest_dir = ({
          CROOMS + "ncorridor2","west",
        });

	items = ({
  "font",
"@@check_font@@",
  "aisle",
"This is the long passageway between the benches and pews",
  "benches",
"Small wooden seats for the congregation to sit and pray upon.  By the "+
"number of benches, you guess this is a place for informal prayer",
  "window",
"This is a wondrously decorated display of fine craftsmanship, "+
"depicting scenes of miracles, great figures, and of course, King "+
"Arthur himself at his glorious wedding to Queen Guinever",
  "windows",
"This is a wondrously decorated display of fine craftsmanship, "+
"depicting scenes of miracles, great figures, and of course, King "+
"Arthur himself at his glorious wedding to Queen Guinever",
     });

  c1 = "/players/tamina/castle/obj/el_book"->query_code(1);
  c2 = "/players/tamina/castle/obj/el_book"->query_code(2);
  c3 = "/players/tamina/castle/obj/el_book"->query_code(3);
  c4 = "/players/tamina/castle/obj/el_book"->query_code(4);

}

void init() 
{
  ::init();
  add_action("_drink", "drink");
  add_action("_smell", "smell");
  add_action("_pray",  "pray");
  add_action("_get",   "get");
  add_action("_get",   "take");
  add_action("_put",   "put");
  add_action("_summon","summon");
  add_action("_mylook","exa");
  add_action("_mylook","look");
  add_action("_mylook","examine");
}

int _put(string str)
{
  if (sscanf(str, "%s on altar", what) == 1)
  {
    if (summoned)
    {
      write("But the altar is broken in twain !!\n");
      return 1;
    }
    obj = present(what, TP);
    if (obj)
    {
      write("You put the "+what+" on the altar.\n");
      say(TPN+" puts "+what+" on the altar.\n");
      if (obj->query_code(1) == c1)
        p1 = 1;
      if (obj->query_code(2) == c2)
        p2 = 1;
      if (obj->query_code(3) == c3)
        p3 = 1;
      if (obj->query_code(4) == c4)
        p4 = 1;
      transfer(obj, ALT);
      return 1;
    }
    else
    {
      write("But you don't have "+what+" anyway.\n");
      return 1;
    } 

  }  /* endif scanf */

}

int _summon(string str)
{
  if (str == "lord" || str == "elemental lord")
  {
    if (p1 && p2 && p3 && p4)
    {
      set_light(-5);
      write("A great darkness descends over the room.\n"+
	    "You hear an ear splitting crack, as the altar breaks in twain.\n");
      say(TPN+" recites an ancient summoning spell.\n");
      summoned = 1;
      call_out("come_here", 3);
      return 1;
    }
    write("But you do not have the necessary items present to summon\n"+
	  "anything here.\n");
    return 1;
  }
  else
  {
    NFAIL("Summon what?\n");
    return 0;
  }
}

int come_here()
{
  mob = clone_object(CMONS + "el_lord");
  transfer(mob, this_object());

  tell_room(TO,
    "The dread Elemental Lord appears in full and glorious majesty !!\n"+
    "Elemental Lord says:  On your knees, mortal !!");
  TP->look();
  p1 = 0;   p2 = 0;   p3 = 0;   p4 = 0;
  return 1;
}

int _mylook(string arg)
{
  if (arg == "altar" || arg == "at altar")
  {
    if (summoned)
    {
      write("The altar is broken in twain !!\n");
      return 1;
    }
    ALT->inventory();
    return 1;
  }
}

string check_font()
{
  if (drunk)
  {
    return "A small, but beatifully carved marble basin.  It is empty";
  }
  return
"A small, but beautifully carved marble basin, with some clear water "+
"still remaining at the bottom of the font";
}

int _get(string str)
{
  if (sscanf(str, "%s from altar", what2) == 1)
  {
    obj2 = present(what2, find_object(ALT));
    if (obj2)
    {
      write("You take the "+what2+" from the altar.\n");
      say(TPN+" takes a "+what2+" from the altar.\n");

      transfer(obj2, TP);
      return 1;
    }
    else
    {
      write("That is not on the altar at the moment.\n");
      return 1;
    }
  }
}

int _drink(string str) 
{
  if (str == "water from font")
  {
    if (drunk) 
    {
      write("There is no water left at the bottom of the font.\n");
      say(TPN+" desperately tries to lick the bottom of the font,\n"+ 
          "for every last drop!\n");

      return 1;
    }
    write("You drink the last drops of water from the bottom of\n"+
          "the font.  The cool liquid drips smoothly down your throat\n"+
          "leaving you feeling fully refreshed, and invograted!!\n");
    say(TPN+" drinks the water from the font, and starts to glow with \n"+
        "a strange aura...\n");

    TP->heal_self(10);
    drunk = 1;

    return 1;
  }
}

int _smell(string str) 
{
  if (smelled) 
  {
    write("You have had your fill of the air, and smell no \n"+
          "difference to the sweet air.\n");
    say(TPN+" takes another deep breath, but looks no different.\n");

    return 1;
  }
  write("You take a deep breath of the sweet, clean air in the Chapel,\n"+
        "and instantly feel refreshed, and more healthy.\n");
  say(TPN+" takes a deep inhalation of the air in the Chapel,\n"+
      "and looks much more healthier.\n");

  TP->heal_self(5);
  smelled = 1;

  return 1;
}

int _pray(string str)
{
  if (!str)
  {
    write("You kneel down before the altar, and start to pray to\n"+
	  TP->query_religion()+".  You feel calmed.\n");
    say(TPN+" kneels down and prays.\n");
    return 1;
  }
}

