/***********************************************************
*   This is the northeast part of the mage-summonroom      *
***********************************************************/

#define P	"players/llort/guild/tower/"

inherit "room/room";
#include "summon.h"

int octagon,openfl,page;

reset(arg) {
  if(!arg) {
    short_desc="Northeast of the Summon room";
    long_desc="This is the northeast corner of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling. You notice a desk with a\n"+
              "big book located at the corner.\n";
    set_light(1);
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
    enable_commands();
    page=0;
    }
  if(openfl) {
    openfl=page=0;
    tell_room(this_object(),"The book closes.\n");
  }
}

init() {
  ::init();
  add_action("draw","draw");
  add_action("open","open");
  add_action("close","close");
  add_action("read","read");
  add_action("turn","turn");
  call_out("dest_octa",1,this_player());
}

read(arg) {
  if(arg!="book") return;
  if(!openfl) {
    write("The book is closed. The title is: HOW TO SUMMON A MONSTER.\n");
/*  } else if(this_player()->query_guild()!=5)  {
      write("The letters seem to dance before your eyes. You can't read "+
            "a word.\n"); */
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

dest_octa(tp) {
  if(octagon) {
    tell_object(tp,"As you enter this part of the room, you destroy the"+
          " protection\nrunes drawn on the floor.\n");
    say(tp->query_name()+" destroys the protection runes on the floor.\n",tp);
    catch_tell(tp->query_name()+" destroys the protection runes "+
          "at the northeast corner of the room.\n");
    octagon=0;
  }
} 

draw(arg) {
  object ch;
  if(arg!="octagon") return;
  if(!(ch=present("chalk",this_player()))) {
    write("You can't draw anything without chalk.\n");
    return 1;
  } else ch->reduce();
  if(octagon) {
    write("You redraw this part of the octagon.\n");
  } else {
    write("You draw part of the runes, to bind a monster, on the floor.\n");
    octagon=1;
  }
  say(this_player()->query_name()+" draws something on the floor.\n",
      this_player());
  return 1;
}

catch_tell(arg) {
  tell_room(P+"summon2",arg);
  tell_room(P+"summon1",arg);
  tell_room(P+"summon4",arg);
  tell_room(P+"summon5",arg);
  tell_room(P+"summon6",arg);
  tell_room(P+"summon7",arg);
  tell_room(P+"summon8",arg);
  tell_room(P+"summon9",arg);
}

move(arg) {
  int i;
  if((i=member_array(query_verb(),dest_dir))==-1) return 1;
  if(this_player()->short())
    catch_tell(this_player()->query_name()+" moves "+ 
           dest_dir[i]+".\n");
  move_object(this_player(),dest_dir[i-1]);
  if(this_player()->short())
    tell_room(this_object(),this_player()->query_name()+" moves "+ 
           dest_dir[i]+".\n");
  environment(this_player())->long();
  INVLIST;
  return 1;
}

get_inv_list(room) {
  object ob;
  string tmp;
  int i;

  tmp="";
  if(!(ob=find_object(room))) return 0;
  ob=all_inventory(ob);
  for(i=0;i<sizeof(ob);i++) if(ob[i]->short() && ob[i]!=this_player())
    tmp+=capitalize(ob[i]->short())+"\n";
  return tmp=="" ? 0 : tmp;
}

test_oct() {
  return(call_other(P+"summon1","query_oct") &&
     call_other(P+"summon2","query_oct") &&
     call_other(P+"summon3","query_oct") &&
     call_other(P+"summon4","query_oct") &&
     call_other(P+"summon6","query_oct") &&
     call_other(P+"summon7","query_oct") &&
     call_other(P+"summon8","query_oct") &&
     call_other(P+"summon9","query_oct") );
}

query_oct() { return octagon; } 

set_oct(a) { octagon=a; }

long(a) {
  string tmp;
  int fl,i;

  if(a) {
    switch(a) {
      case "engravings": 
      case "engraving": 
      case "rune":
      case "runes":
        i=member_array(a,items);
        if(i!=-1) items[i+1]= this_player()->query_guild() == 5 ?
          "Some powerful runes to help prison the summoned monsters" :
          "Some strange magical runes";
        break;
    }
    return ::long(a);
  }
  
  fl=0;
  tmp=long_desc;
  if(test_oct()) {
    long_desc+="There is a big protection octagon drawn around the center "+
               "of the room.\n";
  } else if(octagon) 
    long_desc+="You notice part of a protection octagram on the floor.\n";
  ::long(a);
  long_desc=tmp;

  if(tmp=get_inv_list(P+"summon1")) {
    write("At the northwest corner you see: ");
    write(tmp);  fl=1;
  } 
  if(tmp=get_inv_list(P+"summon2")) {
    write("At the northwall you see: ");
    write(tmp); fl=1;
  } 
  if(tmp=get_inv_list(P+"summon4")) {
    write("At the westwall you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon5")) {
    write("At the center you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon6")) {
    write("At the eastwall you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon7")) {
    write("At the southwest corner you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon8")) {
    write("At the southwall you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon9")) {
    write("At the southeast corner you see: ");
    write(tmp);  fl=1;
  }
  if(fl && get_inv_list(P+"summon3")) write("And here is : ");
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
