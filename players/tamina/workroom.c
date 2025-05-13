inherit "room/room";

#include        "/players/tamina/defs.h"
#define NME     "tamina"
#define CNAME   capitalize(NME)

int locked;
object glass;

void reset(int arg)
{
  if (arg) return 0;

        set_light(1);
        short_desc = CNAME+"'s Wonderful Workroom";
        long_desc =
"This is the workroom of "+CNAME+".  It is rather windy, because of the drafts\n"+
"whistling through the gap below the door. The room itself is sparsely \n"+
"decorated, because "+CNAME+" likes to have room to work in.\n"+
"There is a window on the left wall, a fire blazing in the far wall, \n"+
"with a large rug in front of the fire.  There is also a table and\n"+ 
"work-bench facing the window.\n";

        dest_dir=({
	    CROOMS + "draw_bridge",        "camelot",
	    "room/church",                 "church",
            "room/post",                   "post",
	    RROOMS + "gates",              "rivendell",
	    TEDS + "storage",              "store",
	    TPATH + "path1",               "ted",
  	    CASTLE + "room1",              "teleport",
	    PATH + "test",                 "test",
            "/obj/tick",                   "time", 
            "/players/uglymouth/workroom", "uglymouth", 
        });

        items = ({ 
  "air",
"The cold wind stings your nostrils",
  "floor",
"The floor is swept clean",
  "window",
"The view you see through the bay window is of a huge snow-capped "+
"peak, with several skiers moving down the slopes.  In fact, you "+
"can see one skier, who seems to be falling down the steep slope...\n"+
"It looks like Kaneda!!!!", 
  "fire", 
"This very large fire more than compensates for the drafts that "+
"are seeping through the door",
 "rug",
"A large, furry bear-rug, that looks very cosy, and inviting next "+ 
"to the fire",
 "table", 
"This wooden table is neatly covered in papers and pens each "+
"in their separate holder. Tamina is a very organised Wizard", 
  "bench", 
"A bench that does not look very comfortable to sit on...But "+
"you are at work, you dont necessarily want comfort to distract "+
"you..",
       });
        
       property = ({
        "no_sneak","no_steal","no_invisible",
        "no_camouflage",
                    });

    glass = CLO (OTH + "castle");
    MO (glass, TO);
}

int check()
{
  if (locked && TP->RNAME != "tamina") 
  {
    write("A powerful Plasma Elemental prevents you from seeing Tamina.\n"+
          "The Elemental says:\n"+
          "           Tamina is busy right now. Please try again later\n"+
          "You are transferred safely elsewhere.\n");
      say(TPN+" tries to enter but Tamina's command over the Elements is superior.\n"+
	  "She repels "+TP->QOBJ+".\n");
    MO (TP, "room/void");
    return 0;
  }          
}

void init() 
{
  object person;
  ::init();
  AA("lie",   "lie");
  AA("lock",  "say");
  AA("lock",  "'");
  AA("lock",  "\"");
  AA("lock"); add_xverb("'");

  if (TP->query_invis() && TP->RNAME != "tamina") 
    TP->set_vis();
  check();

  person = find_player("tamina");
  if (person && person != TP)
    TOBJ(person, 
  "\n-> WARNING <-  "+CAP(TP->RNAME)+" has just entered your workroom!!\n"); }

int lock(string str)
{
  if (!str && (str != "lock room" || str != "unlock room")) 
    return 0;

  if (str == "lock room")
  {
    if (TP->RNAME != "tamina")
    {
      write("Why are you trying to lock Tamina's Workroom ?\n");
      return 0;
    }
    TRM (TO,
  "Tamina combines the elements to create an imposing Plasma Elemental.\n"+
  "It looks at Tamina in deference, as she says:\n"+
  "                    'Protect my workroom.'\n"+
  "The Elemental fades into the surroundings of the workroom.\n"+
  "Tamina says: 'We will not be disturbed now.'\n");

     locked = 1;
     return 1;
  }
  if (str == "unlock room" || str == "unlock door")
  {
    TRM (TO,
  "Tamina dispels the Plasma Elemental.\n"+
  "The workroom feels exposed now...\n");
    locked = 0;
    return 1;
  }
}

int lie(string str) 
{
  if (str != "on rug") 
  {
    NFAIL("You cannot lie on that!\n");
    return 0;
  }
  write(
"You lie down on the rug in front of the crackling logs in the fire,\n"+
"and feel completely relaxed...\n");
  say(
TPN+" sprawls over the bear-rug, looking as if "+TP->QPRO+" is completely\n"+
"at ease...\n");

    return 1;

}

