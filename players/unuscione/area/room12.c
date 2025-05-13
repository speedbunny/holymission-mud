inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
object kbl;
string destr;

long(){
if(!present("kobold",env(TP))){
destr="Everything seems very quiet";
}
if(present("kobold",env(TP))){
destr="Several Kobold guards notice you and attack";
}
write(break_string("The passage levels out to an even three feet here. "+
	"Set into the floor are several pikes, on which are bloody heads "+
	"of some unfortunate Kender. The passage continues into darkness "+
	"to the east and west.  "+destr+".\n",65));
  write("     Obvious exits: west, east\n");
}
reset(arg){
if(arg) return;
set_light(0);
short_desc="Dungeon of Hilo";
dest_dir=({KPATH+"room13","west",
	   KPATH+"room11","east",
	});
if(!kbl){
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kobold"),TO);
}
}
init(){
 ::init();
 AA("look","look");
 AA("look","l");
  AA("_get","get");
  AA("_get","take");
}
look(arg){
if(!arg){
long();
return 1;
}
if(arg){
  switch(arg){
  case "at floor":
  write("There are several pikes set into the floor.\n");
  return 1;
  break;
  case "at pikes":
  case "at pike":
  write("They are set into the floor and have decapitated kender heads stuck on them.\n");
   return 1;
  break;
  case "at passage":
  long();
  return 1;
  break;
  case "at heads":
  case "at kender heads":
  case "at bloody heads":
  write("Maybe they are intended as a warning to keep out.\n");
  return 1;
  break;
  case "at kender":
  write("They are very dead.\n");
  return 1;
  break;
  default:
  return 0;
  break;
 return 1;
}
}
}
_get(str){
 if(str=="heads" || str=="head" || str=="bloody head" || str=="pike" || str=="pikes"){
 write("You can't take that.\n");
 return 1;
 }
else return 0;
}
