/***********************************************************
*   This is the northeast part of the mage-summonroom      *
***********************************************************/

#include "summon.h"

int openfl,page;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Northeast of the Summon room";
    long_desc="This is the northeast corner of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling. You notice a desk with a\n"+
              "big book located at the corner.\n";
    dest_dir=({ P+"summon6","south"
    	      ,P+"summon5","southwest"
	      ,P+"summon2","west"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes",
             "desk","A wooden desk",
             "book","The book is titled: HOW TO SUMMON A MONSTER",
          });
    page=0;
    }
  if(openfl) {
    openfl=page=0;
    tell_room(this_object(),"The book closes.\n");
  }
}

init() {
  ::init();
  add_action("open","open");
  add_action("close","close");
  add_action("read","read");
  add_action("turn","turn");
}

read(arg) {
  if(arg!="book") return;
  if(!openfl) {
    write("The book is closed. The title is: HOW TO SUMMON A MONSTER.\n");
    } else {
      if(!page)
      write(
"This is a DO-IT-YOURSELF guide to summon a monster in four steps.\n"+
"(C) 1992 by Llort the mage master.\n\n"+
"To summon a monster is very easy. You just have to perform the following\n"+
"four steps precisly and in the correct order.\n\n"+
"  1) Find a convenient room prepared with protection runes to bind\n"+
"     the monster.\n\n"+
"  2) Put something worth about ten times the level of the monster on\n"+
"     a magic pentagram at the center of this room.\n\n"+
"  3) Draw a magic octagon (containing of protection runes) around the\n"+
"     center of the room.\n\n"+
"  4) Step on the south corner of the octagon and intonate the words:\n"+
"       'yaczkl hruk dan ' followed by the name of the monster you\n"+
"       want to summon.\n\n"+
"                              --- 1 ---\n");
      else
      write(
"It is told that summoned mosters often react aggressive. But sometimes\n"+
"it seems possible to control the summoned monsters.\n"+
"If you think you can do this with the monster you summoned try to\n"+
"'command' the monster to the following actions:\n"+
"   -- follow ........ this should make the monster follow you\n"+
"   -- stay .......... this command is said to stop the monster\n"+
"                      from following you\n"+
"   -- leave ......... should release the monster from your control\n"+
"   -- kill .......... BEWARE, it is said that the monster isn't pleased\n"+
"                      if you force it to attack someone\n"+
"   -- <and much more> ... just try :)))"+
"\n                              --- 2 ---\n");
    }
  return 1;
}

open(arg) {
  if(arg!="book") return;
  if(openfl) write("The book is already open.\n");
  else {
    write("You open the book.\n");
    say(this_player()->query_name()+" opens the book.\n",this_player());
  }
  openfl=1;
  return 1;
}

close(arg) {
  if(arg!="book") return;
  if(openfl) {
    write("You close the book.\n");
    say(this_player()->query_name()+" closes the book.\n",this_player());
  } else write("The book is already closed.\n");
  openfl=0;
  return 1;
}

turn(arg) {
  if(arg!="page") return;
  if(!openfl) {
    write("You can't turn the page while the book is closed.\n");
  } else {
    write("You turn the page.\n");
    page=!page;
  }
  return 1;
}
