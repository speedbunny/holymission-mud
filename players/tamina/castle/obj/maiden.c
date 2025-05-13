/*  This is an Iron Maiden  */

#include "/players/tamina/defs.h"
status opened;

id (str) 
{ 
  return str == "iron maiden" || str == "maiden"; 
}

short () 
{ 
  return "An Iron Maiden";
}
  
long () 
{
  if (opened) 
  { 
    write (
"You are looking at the open front of a large Iron Maiden,\n"+
"which shows a black hole, with glints of the sharp metal \n"+
"spikes, entering into a passage, which must go somewhere...\n");
  } 
  else 
  { 
    write (
"You trace your hands over the frame of the Iron Maiden, and are\n"+ 
"surprised to feel a cold draft blowing feebly through the gap...\n"+
"Perhaps the Iron Maiden can be opened...\n");
  }
}

init() {
  add_action("search",        "search");
  add_action("open",          "open");
  add_action("close",          "close");
  add_action("enter_maiden",  "enter");
}

get () 
{
  return 0; 
}

int search (string str) 
{

  if (str != "maiden") 
  {
    NFAIL("You find nothing special.\n");
    return 0;
  }
  if (opened) 
  {
     write("But why do you need to search the Iron Maiden again?\n");
     say(TPN+" looks rather foolish as he tries to search an open door!\n");   
    return 1;
  }
  write("You run your fingers over the sides of the Iron Maiden, and are\n"+
        "surprised to find cold air wafting through gaps at the side.\n"+
        "Perhaps there is a door here to be opened...\n");
    say(TPN+" pokes around the fron of the Iron Maiden, and manages to find a\n"+
        "door!!\n");

  return 1;

}

int open (string str) 
{
  if (str == "maiden" || str == "iron maiden") 
  {
    if (opened) 
    {
      write("But why do you need to open the Iron Maiden?\n"+
	    "It is already open fool!\n");
        say(TPN+" looks rather foolish as "+TP->QPRO+" tries\n"+
            "to open an _open_ door!\n");   
      return 1;
    }
    if (TP->STR < 17)
    {
      write("You do not feel up to this task...\n");
      say(TPN+" looks very weak trying to open the Iron Maiden.\n");
      return 1;
    }
    write("You slowly, carefully pull open the front of the Iron Maiden.\n");
    say(TPN+" very carefully opens the front of the Iron Maiden.\n");

    opened = 1;

    return 1;
  }
  else 
  {
    write("What do you want to open?\n");
    return 1;
  }

}

int close (string str) 
{
  if (str == "iron maiden" || str == "maiden") 
  {
    if (!opened) 
    {
      write("How can you close it if it is not yet open?\n");
        say(TPN+" tries to close a _closed_ Iron Maiden...\n"+
	    "Weird...\n");
      return 1;
    }
    write("You close over the front of the Iron Maiden.\n");
    say(TPN+" closes the front of the Iron Maiden.\n");

    opened = 0;

    return 1;
  }
  else
  {
    write("What do you want to close?\n");
    return 1;
  }

}

int enter_maiden (string str) 
{
  if (str == "maiden" || str == "iron maiden")
  {
    if (!opened) 
    {
      NFAIL("How will you do that here?\n"+
   	    "There is a solid frontispiece on the maiden.\n");
      return 0;
    } 
    if (TP->DEX < 19) 
    { 
      write("You stab yourself on one of the spikes in the Iron Maiden, \n"+
            "and fail to move through into the passage.\n");

      TP->hit_player(45);

      return 1;
    }
    MPL(
"into the darkness beyond the Iron Maiden#players/tamina/castle/rooms/passage");
    say("The door slams across shut when "+TPN+" enters into the Maiden !!\n");

    opened = 0;
    return 1;
  }
  else
  {
    NFAIL("Enter what?\n");
    return 0;
  }

}
