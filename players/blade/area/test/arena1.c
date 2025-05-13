/***********************************************************
*   This is the northwest part of the mage-summonroom      *
***********************************************************/

#define FPATH	"players/blade/area/test/"

inherit "room/room";
#include "/players/blade/ftp/summon.h"

reset(arg) {
  if(!arg) {
    short_desc="Northwest in the Arena";
    long_desc="Northwest in the Arena.  This is where you have come to\n"
              "fight a battle to the death.  You hope fervently that it\n"+
              "is not your death.  The walls of the arena loom high around\n"+
              "you, and you realize there is no other way out.  Torches\n"+
              "blaze from high on the wall, barely lighting the area.  The\n"+
           "crowds watch you from atop the high walls, screaming for blood.\n";
    set_light(1);
    dest_dir=({FPATH+"arena2","east"
    	      ,FPATH+"arena4","south"
	      ,FPATH+"arena5","southeast"
	    });
       items=({
"wall","It rises high enough so that you cannot climb out",
"floor",
   "The floor is covered with sand so the combatants don't slide on the blood",
"ceiling",
   "It is high above you, and only a few specks of blood mar its surface",
"sand","Brown colored sand that is caked with blood in places",
"torches","Torces blaze high upon the arena walls, lighting the place",
"crowds","Hoards of people, yelling and screaming for blood",
});
    property=({"no_teleport"});
    enable_commands();
    }
}

init() {
  ::init();
  }

catch_tell(arg) {
  tell_room(FPATH+"arena2",arg);
  tell_room(FPATH+"arena3",arg);
  tell_room(FPATH+"arena4",arg);
  tell_room(FPATH+"arena5",arg);
  tell_room(FPATH+"arena6",arg);
  tell_room(FPATH+"arena7",arg);
  tell_room(FPATH+"arena8",arg);
  tell_room(FPATH+"arena9",arg);
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

long(a) {
  string tmp;
  int fl,i;

  if(a) {
    return ::long(a);
  }
  
  fl=0;
  tmp=long_desc;
  ::long(a);
  long_desc=tmp;

  if(tmp=get_inv_list(FPATH+"arena2")) {
    write("In the north section you see:: ");
    write(tmp); fl=1;
  } 
  if(tmp=get_inv_list(FPATH+"arena3")) {
    write("In the northeast section you see: ");
    write(tmp);  fl=1;
  } 
  if(tmp=get_inv_list(FPATH+"arena4")) {
    write("In the west section you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(FPATH+"arena5")) {
    write("In the center you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(FPATH+"arena6")) {
    write("In the east section you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(FPATH+"arena7")) {
    write("In the southwest section you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(FPATH+"arena8")) {
    write("In the south section you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(FPATH+"arena9")) {
    write("At the southeast corner you see: ");
    write(tmp);  fl=1;
  }
  if(fl && get_inv_list(FPATH+"arena1")) write("And here is : ");
}  
  








