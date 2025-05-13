inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){

  short_desc = "Goblin Barracks";
  long_desc =
"  A dozen cots line the walls here and the stench of flesh and sweat is\n"+
"  overpowering.  Lying on the cots are various pieces of shattered armour.\n"+
"  Several dirty rags lie all around the floor.\n";
  set_light(1);
  dest_dir = ({
    sr+"/room203","east",
    sr+"/room205","west",
  });
  items = ({
    "walls",
    "Mould covers sections of the walls",
    "rags",
    "These rags lie on the floor on clumps, they may be clothes",
    "cots",
    "Mouldy green cots lie along the wall.",
    "Pieces of shattered goblin armour lie on the cots",
  });
    clone_list = ({ 1, 3, "monster", sm+"/goblin_fighter.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
}
