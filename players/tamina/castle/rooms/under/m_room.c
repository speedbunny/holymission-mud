/*  This is an Underground Maze - Room before Merlin */

#include "/players/tamina/defs.h"

inherit "room/room";
int woken, searched;

void reset(int arg) 
{
   searched = 0;
   if (arg) return ;

      	set_light(1);
	short_desc = "Merlin's Room";
	long_desc = 
"Here, you see a dead end to the Maze you have just passed through.\n"+
"This is a small, well-lit room, that is cluttered to say the least.\n"+
"There is a small wooden work-bench propped against one wall, with a\n"+
"chair pushed underneath it.  On top of the desk is a pile of parchment\n"+
"along with various writing implements.  There is also a bed in the \n"+
"corner, with a huddled lump in the middle of it.  Attached to one wall\n"+
"is a hat-rack of some sort.\n";

	dest_dir = ({
          UND + "rm140","west",
     });

	items = ({
    "bench",
  "An old wooden bench that is littered with parchment and quills",
    "chair",
  "A chair that seems to be the right size for a person who would "+
  "work at the work-bench",
    "bed",
  "A small straw mattress, with a sheet pulled up over the top. "+
  "There is a mound in the middle of the sheet..",
    "lump",
  "It is in the shape of a small humanoid figure.  You hear occasional "+
  "snoring noises coming from the mound",
    "mound",
  "It is in the shape of a small humanoid figure.  You hear occasional "+
  "snoring noises coming from the mound",
    "parchment",
  "Parchment of varying colours and sizes, each with complicated equations "+
  "and symbols scrawled in a spidery hand-writing",
    "quills",
  "Large feathers with sharpened, ink-blackened ends",
    "rack",
  "A wooden slat, with four extending pieces of wood.  Hanging from one of "+
  "these poles is large, pointy hat, made of a dark material.  And from "+
  "another is a large cloak, of a matching material",
    "hat-rack",
  "A wooden slat, with four extending pieces of wood.  Hanging from one of "+
  "these poles is large, pointy hat, made of a dark material.  And from "+
  "another is a large cloak, of a matching material",
    "hat",
  "A large, pointed hat, made of a black material.  There seem to a number "+
  "of pinpoints of light on the material itself..",    
    "cloak",
  "A heavy-looking cloak, made of a matching material to the hat.  "+
  "On a closer inspection, you notice that there are strange designs "+
  "of clusters, and constellations of stars",
    });

}
init() {
  ::init();
  add_action ("wake_up","wake");
  add_action ("search", "search");
}

int wake_up(string str) 
{
  object ob;
  
  if (str != "merlin") 
  {
   NFAIL("You can't wake that up!\n");
   return 0;
  } 
  if (woken) 
  {
    write("But why?  Merlin is already awake!!\n");
    return 1;
  }
  write("You vigorously shake the lump on the bed, trying to wake it up.\n");
  write("Suddenly an old man bursts out from under the sheet!\n"+
        "He grabs his cloak and hat from the hat-rack on the wall.\n");
  write("Merlin peers at you with frightened, weary eyes, and says: \n");
  write("  'What do you want with me?!?  I have not done anything wrong!!'\n");

  say(TPN+" wakes up the sleeping form in the bed.\n");

  ob = CLO(CMONS + "merlin");
  TR (ob, TO);

  woken = 1;

  return 1;
}

int search(string str) 
{
  object quill;

  if (str == "parchment")
  { 
    if (present("merlin"))
    {
      write("Merlin does not like people looking through his papers!\n");
      return 1;
    }
    if (searched) 
    {
      write("You search through the parchment, but find nothing of interest.\n");
      say(TPN+" rummages through the parchment, but looks disappointed...\n"); 

      return 1;
    }
    write("You sift through the parchment, and manage to find an unusual\n"+ 
          "looking quill...You decide to keep it before Merlin notices.\n");
    say(TPN+" steals a quill from Merlin's papers!!\n");

    quill = CLO(COBJ + "quill");
    TR (quill, TP);

    searched = 1;
    return 1;
  }
  if (str == "bed" || str == "lump" || str == "mound")
  {
    if (woken)
    {
      if (present("merlin", TO))
      {
        write("You try to look through Merlin's bed, but he prevents you!!\n");
	say(TPN+" tries to rummage through Merlin's bed while the old man watches !!\n");

 	return 1;
      }
      else
      {
        write("You find nothing of interest among the sheets of Merlin's bed.\n");
	say(TPN+" looks through Merlin's bed.\n");

    	return 1;
      }
    }
    else
    {
      write("You gently look through the sheets of the bed where the sleeping\n"+ 
      	    "form is snoring away.  You see what appears to be an elderly man,\n"+
  	    "who has a long white beard, and straggly white hair...\n"+
	    "Perhaps this is Merlin, whom you were sent to find...Maybe you\n"+
	    "should wake him...\n");
	say(TPN+" looks through the sheets where the sleeping form lies.\n");

      return 1;
    }
  }
  else
  {
    NFAIL("You search, but find nothing.\n");
    return 0;
  }
}
