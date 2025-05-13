inherit "room/room";

#include "/players/tamina/defs.h"

status down;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    set_light(1);
    short_desc = "Castle Gate";
    long_desc =
"You are at the draw-bridge of the great castle, Camelot, the\n"+
"legendary seat of the noble King Arthur.  Ahead of you is an open\n"+
"portcullis hanging from great chains.  The darkly vacant gate with\n"+
"the sharp points of the portcullis wavering above, make the scene \n"+
"look quite ominous... The castle itself is unfortunately looking in\n"+ 
"a very bad state at the moment... Perhaps the stories circulating\n"+ 
"about the King were true, after all...\n"+
"@@chk_bridge@@";

    dest_dir = ({
      CROOMS + "entrance", "north",
      TPATH + "black", "south",
      TFOREST + "rm8", "east",
      TFOREST + "rm7", "west",
     });
    
    items = ({
    "portcullis",
  "The iron spikes of the portcullis swaying high above the ground look "+
  "sharp, depsite the obvious age of the gates themselves",
    "rope",
  "This is a coiled rope, leading over the Drawbridge, into the entrance "+
  "of the castle itself.  You presume it to be some mechanism for opening "+
  "the Bridge to the castle",
    "castle",
  "The sad absence of King Arthur, and his many Knights have meant that "+
  "Camelot has fallen into considerable disrepair in recent times",
    });

}

void init()
{
  add_action("_bridge1",  "lower");
  add_action("_bridge2",  "raise");
  add_action("_forward1", "north");
  ::init();
}

string chk_bridge()
{
  if (down)
    return "There is a lowered drawbridge.\n";
  else
    return "There is a raised drawbridge.\n";
}

int _bridge1(string str)    /*  To lower the drawbridge  */
{
  if (str == "bridge" || str == "drawbridge")
  {
    if (TP->STR < 19)
    {
      write("You are too weak to lower the drawbridge.\n"+
	    "Perhaps you are not supposed to enter here...?\n");
      say(TPN+" fails to lower the drawbridge.\n");
      return 1;
    }
    if (down)
    {
      write("But the drawbridge has already been lowered.\n");
      return 1;
    }
    write("You gently let out some rope to lower the drawbridge.\n"+
	  "The wooden bridge completely covers the moat, and you\n"+
	  "can now see into the castle itself.\n");
    say(TPN+" lowers the drawbridge.\n");

    down = 1;
    return 1;
  }
  else
  {
    NFAIL("Lower what?\n");
    return 0;
  }
}

int _bridge2(string str)  /*  To raise the drawbridge  */
{
  if (str == "bridge" || str == "drawbridge")
  {
    if (TP->STR < 23)
    {
      write("You are far too weak to raise the drawbridge.\n");
      say(TPN+" fails to raise the drawbridge.\n");
      return 1;
    }
    if (!down)
    {
      write("But the drawbridge is already raised.\n");
      return 1;
    }
    write("You give the rope a good pull, and watch the drawbridge\n"+
	  "start to rise.\n");
    say(TPN+" raises the drawbridge.\n");

    down = 0;
    return 1;
  }
  else
  {
    NFAIL("Raise what?\n");
    return 0;
  }
}

int query_down()
{
  return down;   /*  If bridge is lowered, down is true  */
}

int _forward1()
{
  if (!down)
  {
    write("Without there being any drawbridge across the moat, you\n"+
	  "simply walk right over the bank, into the moat.\n\n"+
	  "\n     * * *  S P L A S H  * * *\n\n");
    say(TPN+" walks over the bank, into the moat.\n");

    MPL("into the moat!#/players/tamina/castle/rooms/moat");
    return 1;
  }
  else
  {
    write("You boldly walk across the drawbridge, pausing with \n"+
	  "curiosity to peek at the moat as you pass.\n");
    MPL("north#/players/tamina/castle/rooms/entrance");

    return 1;
  }
}
