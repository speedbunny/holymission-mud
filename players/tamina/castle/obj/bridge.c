/*  A Draw_Bridge for Camelot		*/
/*  coded for Holy Mission by Tamina	*/
/*  28-07-94				*/

#include "/players/tamina/defs.h"

string bridge;
status down;

int id (string str) 
{
  return str == "drawbridge" || str == "bridge";
}

string short()
{
  if (down)  
    return "A Lowered Drawbridge";
  else
    return "A Raised Drawbridge";
}

void long()
{
  if (down)
  {
    write("This the great Drawbridge of the castle, Camelot.\n"+
	  "At the moment, the bridge has been lowered over the moat\n"+
	  "so you can easily see across to the entrance to the \n"+
	  "castle, and the open portcullis hanging there.\n"+
	  "To lower the Drawbridge, you must be able to pull the\n"+
	  "rope on this side.\n");
  }  
  else
  {
    write("This is the great opening to the castle, Camelot.\n"+
	  "At the moment, the Drawbridge has not been lowered.\n"+
	  "If you want to enter the castle, you are going to have\n"+
	  "to lower the Bridge, by letting out the rope at the side\n"+
	  "of the path.\n");
  }
}

query_property (str)
{
  return str == "no_clean_up";
}

int get()
{
  return 0;
}

void init() 
{
  AA("_rope1",    "let");    /*  to let out rope + lower the brdge  */
  AA("_rope2",    "pull");   /*  to pull the rope + raise bridge    */
  AA("_bridge1",  "lower");  /*  to lower the bridge                */
  AA("_bridge2",  "raise");  /*  to raise the bridge                */
  AA("_forward1", "north");  /*  a check if the bridge is lowered   */
  AA("_forward2", "enter");  /*    ""        ""          ""         */
}

int _rope1(string str)      /*  to let out rope + lower the bridge  */
{
  if (str == "out rope" || str ==  "rope out" || str == "rope")
  { 
    if (TP->STR < 20)
    {
      write("You feel that you are too weak to let out the rope that\n"+
	    "would lower the bridge.  Perhaps you are not supposed to\n"+
            "enter here...?\n");
        say(TPN+" is too weak to let out the rope that would lower the \n"+
            "Drawbridge.\n");
      return 1;
    }
    if (down)
    {
      write("You can't let out any more rope, since the Bridge is\n"+
            "already lowered!\n");
        say(TPN+" tries to lower the Bridge when it is already lowered.\n");

      return 1;
    }
    write("You gently let out the rope from your side of the moat, and\n"+
	  "watch the Drawbridge lower, till it fully crosses the moat.\n"+
 	  "Now you can see into Camelot itself, which you are free to \n"+
 	  "enter also.\n");
    say(TPN+" gently lets out some rope from this side of the moat.\n"+
	"You can see that the Drawbridge has been geared to lower \n"+
	"itself at such a manoeuvre.\n"); 

    down = 1;
    return 1;
  }  
  else
  {
    NFAIL("Let out what?\n");
    return 0;
  }
}

int _rope2(string str)  /*  to pull the rope + raise the Bridge  */
{
  if (str == "rope")
  {
    if (TP->STR < 20)
    { 
      write("You are far too weak to pull the rope, which would raise\n"+
	    "the Drawbridge of Camelot.\n");
	say(TPN+" tries in vain to pull the rope, which you assume \n"+
	    "would raise the Drawbridge.\n");
	
      return 1;
    }
    if (!down)
    {
      write("You can't pull the rope, since the Bridge is already raised.\n");
      say(TPN+" tries to pull the rope to raise the Bridge when\n"+
          "it is already raised.\n");

      return 1;
    }
    write("You give the rope a good hefty pull, and see that the Drawbridge\n"+
	  "is starting to raise by itself.  You think that there must be \n"+
	  "sort of mechanism inside that makes the Bridge rise so effortlessly\n"+
	  "Indeed, you can hear the clicking of some sort of cogs turning.\n");
      say(TPN+" pulls on the rope, which sets off some sort of mechanism\n"+
	  "which in turn is making the Bridge raise again.\n");

    down = 0;
    return 1;
  }
  else
  {
    NFAIL("Pull what?\n");
    return 0;
  }
}

int _bridge1(string str)  /*  to lower the Bridge  */
{
  if (str == "bridge" || str == "drawbridge")
  {
    if (TP->STR < 20)
    {
      write("You feel that you are too weak to lower the bridge.\n"+
            "Perhaps you are not supposed to enter here...?\n");
        say(TPN+" is too weak to lower the Drawbridge.\n");
      return 1;
    }
    if (down)
    {
      write("Why do you want to lower the Bridge when it is already down?\n");
        say(TPN+" tries to lower the Bridge when it is already lowered.\n");

      return 1;
    }
    write("You gently let out the rope from your side of the moat, and\n"+
          "watch the Drawbridge lower, till it fully crosses the moat.\n"+
 	  "Now you can see into Camelot itself, which you are free to \n"+
 	  "enter also.\n");
    say(TPN+" gently lets out some rope from this side of the moat.\n"+
	"You can see that the Drawbridge has been geared to lower \n"+
	"itself at such a manoeuvre.\n"); 

    down = 1;
    return 1;
  }  
  else
  {
    NFAIL("Lower what?\n");
    return 0;
  }
}

int _bridge2(string str)  /*  raising the Drawbridge  */
{
  if (str == "drawbridge" || str == "bridge")
  {
    if (TP->STR < 20)
    { 
      write("You are far too weak to raise the Drawbridge of Camelot.\n");
      say(TPN+" tries in vain to raise Camelot's Drawbridge.\n");	
      return 1;
    }
    if (!down)
    {
      write("You can't raise the Drawbridge, since it already has been raised.\n");
      say(TPN+" tries to pull the rope to raise the Bridge when\n"+
            "it is already raised.\n");
      return 1;
    }
    write("You give the rope a good hefty pull, and see that the Drawbridge\n"+
	  "is starting to raise by itself.  You think that there must be \n"+
	  "sort of mechanism inside that makes the Bridge rise so effortlessly\n"+
	  "Indeed, you can hear the clicking of some sort of cogs turning.\n");
      say(TPN+" pulls on the rope, which sets off some sort of mechanism\n"+
	  "which in turn is making the Bridge raise again.\n");

    down = 0;
    return 1;
  }
  else
  {
    NFAIL("Raise what?\n");
    return 0;
  }
}

int _forward1(string str)  /*  Trying to go "north"  */
{
  if (!down)
  {
    write("Without there being any Drawbridge across the moat, \n"+
	  "you simply walk right over the edge, and land with a \n\n"+
	  "\n             * * *  S P L A S H  * * *              \n\n"+
	  "You are in the moat!\n");
      say(TPN+" rather stupidly tries to enter Camelot, when there is\n"+
	  "no Drawbridge lowered!!\n");

    MPL("into the moat!#/players/tamina/castle/rooms/moat");

    HIT(19);

    return 1;
  } 
  else
  {
    write("You boldly walk across the Drawbridge, pausing with curiosity\n"+
	  "to peek over into the moat.\n\n"+
	  "There, you see very dirty water, and a strange swirling across\n"+
	  "the surface of the water...\n\n");
    say(TPN+" walks swiftly across the lowered Drawbridge, after\n"+
	"paling when he looked over the edge, into the moat...\n");

    MPL("north#/players/tamina/castle/rooms/entrance");

    return 1;
  }
}

int _forward2(string str)  /*  Trying to "enter castle"  */
{
  if (str == "castle" || str == "camelot")
  {
    if (!down)
    {
      write("How foolish!!  How do you expect to enter Camelot, when the\n"+
	    "Drawbridge has not been lowered??  You walk over the edge.\n\n"+
	    "\n                * * *  S P L A S H  * * *              \n\n"+
	    "You are in the moat!\n\n");
      say(TPN+" rather foolishly thinks he can enter Camelot without \n"+
	  "the use of a Drawbridge!\n");

      MPL("into the moat!#/players/tamina/castle/rooms/moat");
      HIT(19);
      return 1;
    } 
    else
    {
      write("You boldly walk across the Drawbridge, pausing with curiosity\n"+
	    "to peek over into the moat.\n\n"+
	    "There, you see very dirty water, and a strange swirling across\n"+
	    "the surface of the water...\n");
      say(TPN+" walks swiftly across the lowered Drawbridge, after\n"+
	  "paling when he looked over the edge, into the moat...\n");

      MPL("into Camelot#/players/tamina/castle/rooms/entrance");

      return 1;
    }
  }
}
