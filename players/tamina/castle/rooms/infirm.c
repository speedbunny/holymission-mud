/*  This is the Infirmary  */

inherit "room/room";

#include "/players/tamina/defs.h"

status opened;
int gotten;

reset(arg) 
{
  gotten = 0;
  if (arg) return ;
   	
      	set_light(0);
	short_desc = "Infirmary";
	long_desc = 
"There are several tables, chairs, basins and cupboards in this room, \n"+
"giving rise to the assumption that this is a place of healing and rest.\n"+
"There is a closed, but dirty window against the far wall, letting in very\n"+
"little light.\n";

	dest_dir = ({
          CROOMS + "ncorridor2","southwest",
        });
	
	smell = "This would have been the strange odour that you smelled\n"+
		"outside, in the corridor.  It is a clean, sterilised smell\n"+
		"normally associated with infirmaries, and hospitals.\n";

	items = ({
  "tables",
"This would be where patients lay when they were being treated for their "+
"injuries and ailments",
  "basins",
"These are old, rusty iron buckets, where water was heated and kept",
  "cupboards",
"Large wooden cupboards, which are closed",
  "window",
"It is closed, but you can still see through the grime, and see a "+
"pleasant view of rolling green hills, and the occasional copse of beech",
     });

}

init() 
{
  ::init();
  AA("open", "open");
  AA("lie",  "lie");
  AA("get",  "get");
  AA("get",  "take");
}

int open (string str) 
{
  if (str == "cupboard")
  { 
    if (opened) 
    {
      write("But the cupboard is already opened...\n");
      say(TPN+" tries to open an opened cupboard!!\n");

      return 1;
    }
    write("You open the wooden door to the cupboard, and see a\n"+
          "single glass vial standing on a shelf.\n");
    say(TPN+" opens the cupboard to reveal a single glass vial on \n"+
        "a shelf.\n");

    opened = 1;
 
    return 1;
  }
  else
  {
    NFAIL("That will not open here.\n");
    return 0;
  }
}

int lie (string str) 
{
  if (str != "on table")
  {
    NFAIL("Why do you want to lie there?\n");
    return 0;
  }
  write("You lie down on the hard table, and sympathise with the poor\n"+
        "patients that had to be treated here.\n");   
  say(TPN+" lies down on one of the operating tables...\n");

  return 1;

}

int get (string str) 
{
  object vial; 

  if (str == "vial")
  {
    if (!opened)
    {
      write("Get what?\n");

      return 1;
    }
    if (gotten) 
    {
      write("That is not there any more!\n");
      say(TPN+" tries to take a vial that is not there!\n");

     return 1;
    }
    write("You get the vial from the shelf.\n");
    say(TPN+" takes a vial down from the shelf.\n");

    vial = CLO(COBJ + "vial");
    TR (vial, TP);

    gotten = 1;

    return 1;
  }
  else
  {   
    NFAIL("You cannot get that here...\n");
    return 0;
  }
}
