/********************************************************
*   This is the center part of the mage-summonroom      *
********************************************************/

#define P	"players/llort/guild/tower/"

inherit "room/room";
#include "summon.h"

int octagon;

reset(arg) {
  if(!arg) {
    short_desc="Center of the Summon room";
    long_desc="This is the center of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling. You notice a big pentagram\n"+
              "engraved in the stonefloor.\n";
    set_light(1);
    dest_dir=({ P+"summon2","north"
    	      ,P+"summon3","northeast"
	      ,P+"summon6","east"
	      ,P+"summon9","southeast"
	      ,P+"summon8","south"
	      ,P+"summon7","southwest"
	      ,P+"summon4","west"
	      ,P+"summon1","northwest"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "pentagram","A golden pentagram engraved in the floor",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    enable_commands();
    }
}

catch_tell(arg) {
  tell_room(P+"summon2",arg);
  tell_room(P+"summon3",arg);
  tell_room(P+"summon4",arg);
  tell_room(P+"summon1",arg);
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

query_oct() { return octagon; }

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
  ::long(a);
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
  if(tmp=get_inv_list(P+"summon4")) {
    write("At the westwall you see: ");
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
  if(fl && get_inv_list(P+"summon5")) write("And here is : ");
}  
