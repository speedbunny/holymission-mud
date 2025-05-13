/*  This is the North-East Tower(3) Top  */

#include "/players/tamina/defs.h"

inherit "room/room";
  status opened;
  status pushed;
  int vial_found,scroll_found;
  int i, in_progress;
  object nimuae;

void reset(int arg) 
{
  vial_found = 0;  scroll_found = 0;
  if(arg) return 0;

     set_light(1);
     short_desc = "North-East Tower - top floor ";
     long_desc =
"   You have finally reached the top of the tallest of the towers in \n"+
"Camelot.  Cold bright light stings your eyes as they try to adapt to\n"+ 
"the drastic change in lighting.  After a few moments of blinking, you\n"+ 
"notice that this room is very bare like most other rooms in the deserted\n"+
"castle.\n"+  
"   There are four large, windows at the four major compass-points\n"+ 
"around the circular room.  There are piles of parchment littered around \n"+
"the floor.  Broken pieces of green glass lie in a pile in the corner, in \n"+ 
"amongst a mound of broken wood.  And apart from the intact wardrobe leaning\n"+
"against a wall, there is nothing else of interest in this room.\n";

     dest_dir = ({
   CROOMS + "ne_tower2", "down",
     });
    
      items = ({
  "stairs",
"Large stone steps descending into the pitch-darkenss above",
  "glass",
"Shattered, yet sharp fragments of glass vessels long broken",
  "wood",
"A pile of mouldy wood that might have been a shelf at one time",
  "parchment",
"Simple pieces of scroll, that you might be able to get and read..",
  "wardrobe",
"A closed, rather clean looking wooden closet",
  "windows",
"Which one?  There are four: north, south, east, west..",
  "window",
"Which one?  There are four: north, south, east, west..",
  "north window",
"You see a view of trees and fields stretching for miles, and miles "+
"over the rural countryside",
  "south window",
"You see a small squat tower in the foreground, and what would appear "+
"to be a long, winding path leading through several different coloured "+
"pavillions",
  "west window",
"You see out over the dirty looking castle of King Arthur that has "+
"sadly fallen into ruin since his departure.  There is another tower "+ 
"you can see from here:  it seems to have blood-red windows at the top "+
"floor",
  "east window",
"You can see out into the countryside here, with great rolling green "+
"hills, and the odd copse of alder or beech",
  "back wall",
"On closer examination, it seems as though you could push it aside..",
       });

}
void init() 
{
  ::init();
  add_action ("_open",          "open");
  add_action ("_push",          "push");
  add_action ("enter_wardrobe", "enter");
  add_action ("_search",        "search");
  call_out("nimuae", 7);
}

int nimuae()
{
  if (!present("nimuae"))
  {
    in_progress = 1;

    switch (i)
    {
      case 0:
    TRM (TO,
       "The wind starts to stir into a strange frenzy...\n");
       break;
      case 1:
    TRM (TO,
       "You suddenly feel very cold as the air around you chills.\n");
       break;
      case 2:
    TRM (TO,
       "In front of you, you see a wispy figure start to materialise.\n");
       break;
      case 3:
    TRM (TO,
       "You now see that the figure is a beautiful woman, a lady of\n"+
       "stunning, and supernatural beauty...\n");

    nimuae = CLO (CMONS + "nimuae");
    MO (nimuae, TO);
    call_out("nim_go", 50);
    in_progress = 0;
    i = 0;
    return 1;
       break;
    }
    if (i < 4)
    {
      i++;
      call_out("nimuae", 5);  
    }
    return 1;
  }
}

int nim_go()
{
  TRM (TO,
   "Nimuae sighs sadly at you.\n"+
   "She raises her arms above her head, and drops them down at her feet.\n"+
   "And is gone...\n");

  destruct(nimuae);
  return 1;
}

int _open (string str) 
{
    opened = 0;

  if (str == "wardrobe") 
  { 
    if (opened) 
    {
      write("It is already open...\n");
      say(TPN+" looks a fool, trying to open an open wardrobe...\n");
    return 1;
    }
    write("You open the door in the wardrobe, and are intrigued by the\n"+
          "back wall...\n");
    say(TPN+" opens the wardrobe door.\n");

    opened = 1;
    return 1;
  }
  else 
  {
    NFAIL("Why do you want to open that?\n");
    return 0;
  }
}

int _push (string str) 
{
    pushed = 0;
  
  if (str == "back wall" || str == "back wall of wardrobe") 
  {
    if (!opened)
    {
      write("Push what?\n");
      return 1;
    }
    if (pushed) 
    {
      write("It is already pushed open...\n");
      return 0;
    }  
    if (TP->STR < 17) 
    {
      write("You feel the back wall resist your puny form.\n");
      return 1;
    }
    write(
"You manage with some effort to push aside the back wall of the wardrobe.\n"+
"Behind the wall, you see a small set of stairs leading down into the \n"+
"wardrobe...Perhaps you could enter now?\n");
    say(TPN+" pushes aside the back wall of the wardrobe, \n"+
        "revealing a secret passage!!\n");

    pushed = 1;
    return 1;
  } 
  else 
  {
    NFAIL("You cannot push that here.\n");
    return 0;
  }
}

int enter_wardrobe (string str) 
{   
  if (str == "wardrobe")
  {
    if (!pushed)
    {
      write("But thre is a wall at the back blocking your way...\n");
      return 1;
    }
    write("You squeeze yourself into the small passage, and descend into\n"+ 
          "the darkness...\n");
    say(TPN+" moves boldly into the dark passage in the wardrobe!\n");

    MPL("into the wardrobe#players/tamina/castle/rooms/wardrobe");

    return 1;  
  }
  else
  {
    NFAIL("You cannot do that here...\n");
    return 0;
  }

}

int _search (string str) 
{
  object vial, scroll;

  if (str == "glass" || str == "pieces of glass") 
  {
    if (vial_found) 
    {
      write("Your slash your hands into the pile of broken glass!\n");
      say(TPN+" cuts "+TP->QOBJ+"self on the pile of glass!!\n");

      if (TP->DEX < 29) 
      {
        HIT(40);
	return 1;
      }  
      else
      {
        HIT(20);
        return 1;
      }
    }
    if (TP->DEX < 29)  
    {
      write("You cut your hands on the glass!!\n"+
  	    "However, you do manage to find a small, intact vial in\n"+
  	    "amongst the glass.\n");
        say(TPN+" cuts "+TP->QOBJ+"self on the pile of glass!!\n");

       vial = CLO (COBJ + "vial");
       MO (vial, TP);
 
       vial_found = 1;
 
       HIT(40);

       return 1;
     }  
     else
     {
       write("You deftly avoid the sharp edges of glass, and are lucky\n"+
   	     "enough to find a small vial there.\n");
       say(TPN+" nimbly picks out a vial from the pile of broken glass.\n");

       vial = CLO (COBJ + "vial");
       TR (vial, TP);

       vial_found = 1;

       return 1;
     }
  }
  if (str == "parchment" || str == "scrolls") 
  {
    if (scroll_found) 
    {
      write("You find nothing amongst the pile of parchment.\n");
        say(TPN+" looks through the pile of parchment.\n");

      return 1;
     }
    write("You sift through the piles of parchment, and espy one\n"+
          "that looks interesting.  You deicide to take it...\n");
      say(TPN+" searches through the pile of parchment.\n");

    scroll = CLO("obj/thing");

    scroll->set_name("scroll");
    scroll->set_alias("parchment");
    scroll->set_short("An end Piece of Scroll");
    scroll->set_long(
"A small, torn part of a crumbling scroll.  It seems to be the end\n"+
"of a longer scroll.  But you might still be able to read it...\n");
    scroll->set_weight(0);
    scroll->set_value(20);
    scroll->set_read_file(COBJ + "scroll3.txt");

    TR (scroll, TP);
    scroll_found = 1;

    return 1;
  }  

}
