inherit "room/room";
#include "/players/baalthasar/shadows/path.h"

object raven;
  reset(arg) {
if(arg) return;

if (!raven) {
raven=clone_object("/players/baalthasar/shadows/monsters/raven");
clone_object("players/baalthasar/shadows/monsters/raven");
move_object(raven,this_object());
   }

set_light(1);
  short_desc = "Large oak in path";
if("players/baalthasar/shadows/mroad4"->query_raven())
  long_desc = "Blahblahblah\n";
else {
  long_desc = "     You come upon a massive withered oak branching out over \n"+
"the worn road.  The soucres of the shrieking immediately become \n"+
"evident as you spot several ravens perched upon the highest \n"+
"branches.  The shadows in the west appear to be a small forest \n"+
"seen from here.\n"+
"\n";
   }
items = ({
"ravens","Several ravens stare out into the mist",
"branches","The ravens are using them as a perch",
"shadow","It appearas to be some tree tops sticking up from the mist",
"shadows","They appear to be tree tops sticking up from the mist",
"tree","The large gnarled oak looks alive swaying in a gentle breeze",
"oak","The large gnarled oak looks alive swaying in a gentle breeze"
});
dest_dir = ({
   PATH + "/mroad5","northwest",
   PATH + "/mroad3","east"
});
   }
