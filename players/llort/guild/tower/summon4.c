/******************************************************
*   This is the west part of the mage-summonroom      *
******************************************************/

#define P	"players/llort/guild/tower/"

inherit "room/room";
#include "summon.h"

int octagon;

reset(arg) {
  if(!arg) {
    short_desc="West of the Summon room";
    long_desc="This is the western part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    set_light(1);
    dest_dir=({ P+"summon1","north"
    	      ,P+"summon2","northeast"
    	      ,P+"summon5","east"
    	      ,P+"summon8","southeast"
    	      ,P+"summon7","south"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    enable_commands();
    }
}

init() {
  ::init();
  add_action("draw","draw");
  call_out("dest_octa",1,this_player());
}

dest_octa(tp) {
  if(octagon) {
    tell_object(tp,"As you enter this part of the room, you destroy the"+
          " protection\nrunes drawn on the floor.\n");
    say(tp->query_name()+" destroys the protection runes on the floor.\n",tp);
    catch_tell(tp->query_name()+" destroys the protection runes "+
          "at the west of the room.\n");
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
  tell_room(P+"summon3",arg);
  tell_room(P+"summon1",arg);
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
  if(tmp=get_inv_list(P+"summon3")) {
    write("At the northeast corner you see: ");
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
  if(fl && get_inv_list(P+"summon4")) write("And here is : ");
}  
  

