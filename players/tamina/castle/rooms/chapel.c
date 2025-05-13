/*  This is the Chapel  */

inherit "room/room";

#include "/players/tamina/defs.h"
#define ALT "/players/tamina/castle/obj/altar"

object mob, obj, obj2, altar;
int drunk,smelled,summoned;
status p1, p2, p3, p4;
string s1, s2, s3, s4, what;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    drunk = 0;  smelled = 0;  summoned = 0;
    p1 = 0;   p2 = 0;   p3 = 0;   p4 = 0;
    set_light(1);
    short_desc = "Holy Chapel ";
    long_desc = 
"As you enter here, you immediately recognise this place as beinga small,\n"+
"but well-maintained Chapel.  Stained glass windows throw softly-coloured\n"+
"light onto the aisle and benches from the far eastern wall.  It would seem\n"+
"by the number of benches that this was only a private Chapel, a place for\n"+
"informal prayer.  Behind the small benches is a large stone font, standing\n"+
"magnificently in a bright shaft of light.\n";

	dest_dir = ({
          CROOMS + "ncorridor2","west",
        });

	items = ({
  "font",
"@@check_font@@",
  "aisle",
"This is the long passageway between the benches and pews",
  "benches",
"Small wooden seats for the congregation to sit and pray upon",
  "window",
"This is a wondrously decorated display of fine craftsmanship, "+
"depicting scenes of miracles, great figures, and of course, King "+
"Arthur himself at his glorious wedding to Queen Guinever",
     });

  s1 = "/players/tamina/castle/obj/el_book"->query_part(1);
  s2 = "/players/tamina/castle/obj/el_book"->query_part(2);
  s3 = "/players/tamina/castle/obj/el_book"->query_part(3);
  s4 = "/players/tamina/castle/obj/el_book"->query_part(4);

    altar = clone_object("players/tamina/castle/rooms/altar");
    move_object(altar, TO);
}

void init() 
{
  ::init();
  add_action("_drink", "drink");
  add_action("_smell", "smell");
  add_action("_get",   "get");
  add_action("_get",   "take");
  add_action("_put",   "put");
  add_action("_summon","summon");
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

int _put(string str)
{
  if (sscanf(str, "%s on altar", what) == 1)
  {
    if (!present(altar))
    {
      write("There is no altar here !\n");
      return 1;
    }
    obj = present(what, TP);
    if (what == s1)
    {
      if (obj)
      {
        write("You put the "+what+" on the altar.\n");
        say(TPN+" puts "+what+" on the altar.\n");
        transfer(obj, ALT);
	p1 = 1;
	return 1;
      }
      else
      {
	write("But you don't have "+what+" anyway.\n");
	return 1;
      } 
    }
    if (what == s2)
    {
      if (obj)
      {
        write("You put the "+what+" on the altar.\n");
        say(TPN+" puts "+what+" on the altar.\n");
        transfer(obj, ALT);
	p2 = 1;
	return 1;
      }
      else
      {
	write("But you don't have "+what+" anyway.\n");
	return 1;
      } 
    }
    if (what == s3)
    {
      if (obj)
      {
        write("You put the "+what+" on the altar.\n");
        say(TPN+" puts "+what+" on the altar.\n");
        transfer(obj, ALT);
	p3 = 1;
	return 1;
      }
      else
      {
	write("But you don't have "+what+" anyway.\n");
	return 1;
      } 
    }
    if (what == s4)
    {
      if (obj)
      {
        write("You put the "+what+" on the altar.\n");
        say(TPN+" puts "+what+" on the altar.\n");
        transfer(obj, ALT);
	p4 = 1;
	return 1;
      }
      else
      {
	write("But you don't have "+what+" anyway.\n");
	return 1;
      } 
    }
    write("You put "+what+" on the altar.\n");
    transfer(obj, ALT);
    return 1;

  }  /* endif scanf */

}

int _summon(string str)
{
  if (str == "lord" || str == "elemental lord")
  {
    if (p1 && p2 && p3 && p4)
    {
      set_light(-2);
      TP->look();
      write("A great darkness descends over the room.\n"+
	    "You hear an ear splitting crack, as the altar breaks in twain.\n");
      say(TPN+" recites an ancient summoning spell.\n");

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

  tell_room(ENV,
    "The dread Elemental Lord appears in full and glorious majesty !!\n"+
    "Elemental Lord says:  On your knees, mortal !!");
  destruct(altar);
  return 1;
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
  if (sscanf(str, "%s from altar", what) == 1)
  {
    obj2 = present(what, find_object(ALT));
    if (obj2)
    {
      write("You take the "+what+" from the altar.\n");
      say(TPN+" takes a "+what+" from the altar.\n");

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

