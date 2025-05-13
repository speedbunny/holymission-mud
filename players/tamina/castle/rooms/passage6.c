/*  This is the Secret Passage  */

#include "/players/tamina/defs.h"

inherit "room/room";
   int pushed;

reset(arg) {
   if (arg) return ;

      	set_light(-2);
	short_desc = "Secret Passage";

	dest_dir = ({
          CROOMS + "passage5","northwest",
     });

	items = ({
  "passage",
"The walls look the same, apart from the one at the west side "+
"of the passage, which appears to be made from a slightly different "+
"material than the others..",
     });

}

long()
{
    write(
  "You managed to get past the voracious Dust Demon, and find yourself\n"+ 
  "at the end of the dark passage.  This is where the passage ends.\n"+
  "On closer inspection however, the walls seem to be slightly strange...\n");
    if (pushed)
    {
      write(
  "You also see that the west wall is slightly ajar...\n");
    }
    write(
  "                The only obvious exit is northwest.\n");
    return 1;
}

void init()
{
  ::init();
  add_action("my_look", "look");
  add_action("my_look", "exa");
  add_action("my_look", "examine");
  add_action("push",  "push");
  add_action("enter", "enter");
}

int my_look(string str)
{
  if (str == "passage" || str  == "walls" || str == "at passage" || str  == "at walls")
  {
    write(
"They all look the same, apart from the one at the west side\n"+
"of the passage, which appears to be made from a slightly different\n"+
"material than the others...\n");
    return 1;
  }
  if (str ==  "west" || str == "at west")
  {
    if (pushed)
    {
      write("The west wall is slightly ajar.\n"+
	    "Perhaps you can enter it...?\n");
      return 1;
    }
    write(
"It looks very weak, as though you could easily push it aside.\n");
    return 1;
  }
  if (str == "west wall" || str == "at west wall")
  {
    if (pushed)
    {
      write("The west wall is slightly ajar.\n"+
	    "Perhaps you can enter it...?\n");
      return 1;
    }
    write("It looks very flimsy, as though you could push it aside.\n");
    return 1;
  }
}

int push(string str) 
{
  if (pushed) 
  {
    write("The wall has already been pushed aside!\n");
    say(TPN+" tries to push aside a wall that is not there !!\n");
    return 1;
  }
  if (str != "west wall")
  {
    NFAIL("Push what?\n");
    return 0;
  }
  write(
"The wall moves to the side easily. So strong are you, that you \n"+
"over-balance, and fall through the hole that you have just found!!\n");
  say(TPN+" exerts "+TP->QPOS+" strength, to push aside the end wall, \n"+
"revealing a hole, which "+TP->QPRO+" promptly falls into!!\n");

    MPL("through the hole#players/tamina/castle/rooms/bedroom");

    pushed = 1;

    return 1;
}

int enter(string str)
{
  if (str != "west wall")
  {
    NFAIL("Perhaps you should try and enter the 'west wall'...\n");
    return 0;
  }
  write("You push yourself through the west wall, moving you into\n"+
        "another room...\n");
  say(TPN+" moves through a hole in the west wall.\n");
  
  MPL("through the hole#players/tamina/castle/rooms/bedroom");

  return 1;
}
