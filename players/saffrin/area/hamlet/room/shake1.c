inherit "room/room";
#include "/players/saffrin/defs.h"

object human;

reset(arg){

  if(arg)return;
      set_light(1);

      short_desc = "Shakespeare's Workroom";

      long_desc = 
        "Your are in one of the secret workrooms of William Shakespeare.  There is a "+
        "large desk along the south wall with papers pilled high on top of it.  A wastebasket "+
        "is under the desk with crumpled scarps falling out of it.  A single burning candle "+
        "is hanging on the wall.  On the walls there are several shelves with ink and "+
         "scrolls on them.  There appears to be a wooden stool in front of the desk.  "+
        "A small cot is along the north wall.\n";

      dest_dir=({
        HAM+"room/droom7", "down",
      });

      items=({
        "desk", "A large wooden desk with papers pilled on top",
        "papers", "They appear to be pieces of plays and poems",
        "plays", "The script of 'Midsummers Night Dream'",
        "poems" "Some of Shakespeare's sonnets",
        "sonnets", "Sonnets 6, 14, and 37",
        "wastebasket", "Filled with scrapes",
        "scrapes", "Bits of ink blotched papers",
        "candle", "A small burning candle on the wall", 
        "wall", "White walls with one candle hanging on the south side",
        "shelves", "Long wooden shelves holding ink and scrolls",
        "ink", "Little jars of black ink", 
        "jars", "Little jars of black ink",
        "scrolls", "Scrolls of paper",
        "stool", "A small wooden stool",
        "cot", "A small cot stuffed with hay",
        "hay", "Long tan pieces of hay", 
      });

      MOVE(CLONE(HAM+"npc/shake"),TO);
}
