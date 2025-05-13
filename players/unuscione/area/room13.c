inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
string destr;
long(){
write(break_string("This is the entrance to the kobold lair.  This "+
	"place reeks of kobold feces and other dead things.  There is a "+
	"small table set up here with several small chairs set around it.  "+
	destr+"\n",65));
write("     Obvious exits: north, east\n");
}
reset(arg){
 if(arg) return 1;
 set_light(0);
 short_desc="Lair of the Kobolds";
 dest_dir=({KPATH+"lair1","north",
	 KPATH+"room12","east",
      });
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kobold"),TO);
MO(CO(MON+"kobold"),TO);
}
init(){

 ::init();
if(present("kobold",env(TP))){ destr="The kobolds see you and rush to attack!\n";}
if(!present("kobold",env(TP))){ destr="There doesn't seem to be any kobolds around.\n";}
  AA("_sit","sit");
  AA("_look","l"); AA("_look","look");
}
/*
_look(arg){
 if(!arg){
  long();
   return 1;
}
  if(arg){
   switch(arg){
*/
_sit(){
write("You really don't have the time to be sitting around.\n");
return 1;
}
_look(arg){
if(arg) return 0;
if(!arg) 
init();
long();
return 1;
}
