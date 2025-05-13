inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

object sunstaff, ob1;

int avd;
reset(arg){
if(arg) return;
set_light(1);
sunstaff=CO("/players/tatsuo/ishikawa/obj/sunstaff");
MO(sunstaff, this_object());
short_desc="Inside the Obelisk";
long_desc=break_string(
	"A large stone altar is the only feature in this chamber "+
	"The air is damp, and hard to breathe. The floor is covered "+
	"with dust.  The centuries of neglect are evident.\n",65);
items=({"dust","@@query_dust@@",
	"altar","The resting place of the Sunstaff of Amaterasu",
	"chamber", long_desc,
	"air","It's still invisible",
	"floor","It is covered with a layer of dust",
     });
dest_dir=({ IPATH+"jung88","out" });
property= ({"no_teleport"});
if(!ob1){
ob1=CO(MAN+"pan-lung");
MO(ob1,TO);
}
}
query_dust(){
 write("You find a pressure plate trap under the dust, and wisely avoid it.\n");
 avd=1;
 return 1;
}
init(){
::init();
AA("_search","search");
AA("_get","get");
AA("_get","take");
}
_search(arg){
  if(arg=="dust" || arg=="floor" || !arg){
   query_dust();
   return 1;
  }
 else return 0;
}
_get(str){
  if(avd==0){
 if(str=="sunstaff" || str=="all" || str=="sunstaff of amaterasu"){
   write("Steel spikes swing down from the roof and impale you!\n");
   write("You are knocked out of the obelisk!\n");
          TP->misc_hit(75,2,0);
TP->setmin("is thrown from the obelisk, landing in a bloody heap at your feet");
   MOVE("violently out of the obelisk#players/tatsuo/ishikawa/jungle/jung88");
   call_out("return_min",5);
   return 1;
}
}
else return 0;
}
return_min(){
  TP->setmin("arrives");
  return 1;
}
