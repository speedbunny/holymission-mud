inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village Hut";
long_desc=break_string(
    "The hut opens up to a large room with a table covered with tea and rare oriental "+
     "foods. Behind the table is a man who appears to be worried and bothered. There "+
     "are five portraits on the wall. There is a breeze drifting through the hut "+
     "The straw matt in the corner appears to be the bed of the man.\n",65);


items = ({
   "mat","It is a small sleeping mat made of straw",
   "table","The table is low to the ground and looks very old. It appears to be made of teak",
    "teak","It is wood",
    "straw","It is used to make mats. Do we have to tell you everything?",
    "cushions","They are worn but look comfortable",
   "portrait","Look at portrait1, portrait2, etc.",
   "portraits","Look at portrait1, portrait2, etc ",
   "portrait1","It is a picture of KYODAI the mighty ninja assassin the first to slay kyoshi",
   "portrait2","It is a picture of BAER the deadly monk",
    "portrait3","It is a picture of DEMOLIAN master of all guilds",
    "portrait5","It is a picture of SAFFRON the half-dryad enchanter",
   "portrait4","It is a picture of LAMORACK the stealthy killer",
   "tea","You can see steam coming from the herbal tea",
   "food","Rare oriental delecacies"
	});
  if(!ob){
  move_object(clone_object("/players/tatsuo/ishikawa/chatters/moto"), this_object());
}
property=({
   "no_telport"
	});
dest_dir=({
    CPATH+"hut4","south"
    });
}
