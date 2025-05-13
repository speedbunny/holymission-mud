inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Staircase to the Elan Drac Asylum";
  long_desc = 
      "You are standing at the base of a marble staircase that leads to the "+
      "Elan Drac Asylum.  There is a very important sign here that is at the "+
      "the bottom of the steps.  Each step is covered with a thick layer of "+
      "dust with some sparce footprints imbedded on them.  Several piles of "+
      "dung and puddles of urine can be seen on the banisters of the staircase.  "+
      "There is a path to the north of here.  "+
      "A foul stench coming from the asylum assaults your nose and waters at your eyes.\n";
  property=({
      "no_teleport",
      "no_attack",
  });
  smell="It smells like urine and dung.\n";
  dest_dir=({
      PK+"room/v2", "north",
      PK+"room/h5", "up",
  });
  items=({
      "ground", "It is filthy, smeared with urine and dung",
      "path", "A path leding north",
      "banister", "It is filthy, smeared with urine and dung",
      "urine", "Yellow urine",
      "piles", "Piles of dung",      
      "puddles", "Puddles of urine",
      "nose", "You cannot see your own face",
      "eyes", "You cannot see your own face",
      "face", "You cannot see your own face",
      "dung", "EEEEEEWWWWWW!!!  Brown Dung",
      "step", "Covered with thick dust and a few footprints",
      "footprints", "Sparce footprints imbedded in the dust",
      "staircase", "A marble staircase leading out of the asylum",
      "marble", "Marble that makes up a staircase",
      "dust", "Thick dust covering the steps",
      "asylum", "The Elan Drac Insane Asylum",
      "base", "The base of a marble staircase",
      "bottom", "The bottom of the steps",
      "steps", "Covered with thick dust and a few footprints",
      "layer", "Thick layer of dust",
  });
  clone_list=({
       1, 1, "sign", PK+"obj/sign", 0,
       2, 1, "board", "/boards/private_boards/saffrin_pk", 0,
  });
  ::reset();
  replace_program("room/room");
}
