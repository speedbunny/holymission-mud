
inherit "room/room";

#include "/players/apollo/guild/barb.h"
object conan;

void reset(int arg) {

 if(!conan){
    MO(CO(GMONSTERS+"conan"),TO);
   }
  if(arg) return;
   ::reset(arg);
   set_light(1);

   short_desc = "In the barbarian camp";
 
   long_desc =
	"The Barbarian camp runs right up to the mountain here. "+
	"This seems to be a meeting place for the people of the "+
	"camp. A large cave entrance opens in the face of the "+
	"mountain to the west.\n";

   dest_dir = ({
	GPATH+"room","west",
	GROOMS+"camp2","east",
     });

   items = ({
	"path", "It looks well used",
	"fire", "A large campfire burns here.  Legends say Barbarians\n"+
	        "can envision others in the fire",
	"plain", "A wild untamed land",
     });

   property = ({ "has_fire" });

   clone_list = ({ 1, 1, "campfire", GOBJS+"campfire", 0,
		   2, 3, "torch", "/obj/torch", 0
		});

   replace_program("/room/room");
   ::reset(arg);


}



init() {
 ::init();
}
