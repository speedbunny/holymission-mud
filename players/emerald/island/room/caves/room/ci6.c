inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc Caves";

  long_desc="You are lurking about in the orc caves.  The presence of orcs "+
            "can be strongly felt.  The walls are stained with blood, old "+
            "bones crunch underfoot, and the smell of death fills the air.  "+
            "The sound of haggling comes from the east.\n";

  items=({"caves","The caves of the orcs",
          "walls","Old stone walls splashed with blood",
          "blood","Some of the blood stains look to be recently deposited",
          "bones","The bones of long-forgotten adventurers",
          "air","It reeks of death and decay",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci4","south",
             "/players/emerald/island/room/caves/room/ci7","north",
             "/players/emerald/island/room/caves/room/shop","east",
           });

  smell="The overpowering stench of death.";

  ::reset(arg);
  replace_program("/room/room");

}
