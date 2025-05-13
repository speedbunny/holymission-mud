
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "Shrine of Magic Item destruction";

   long_desc = 
	"A stone altar rests in the middle of this tent." +
	"Barbarians come to this place to participate in" +
	"the ritual destruction of magic items. To take" +
	"the ritual, 'destroy <item>'.\n";

   dest_dir = ({
 	GROOMS+"camp3","east"
     });

}

init(){
 ::init();
 add_action("destroy","destroy");
}

destroy(arg) {
  if(present(arg, TP)) {
    switch (arg) {
    case "burst":
    case "little starburst":
    case "wizard's hat":
    case "ring of light":
    case "amulet of protection" :
    case "amulet":
    case "golden staff":
    case "scroll" :
    case "cloak of fighter king":
    case "helmet seeker":
    case "visor":
    case "sting":
    case "black knight's visor":
    case "starburst":
    case "wand":
    case "crystal ball":
    TP->add_exp(((present(arg,TP)->query_value())/10)*(TP->query_level()));
     destruct(present(arg,TP));
     write("You place the item on the altar and break it with your bare hands !\n");
      return 1;
      break;
     default:
     write("You would get no glory from destroying that.\n");
    return 1;
    break;
   }
  write("You don't have the "+arg+".\n");
  return 1;
   }
}
