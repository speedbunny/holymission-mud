inherit "/room/room";

void reset(int arg) {
  if(arg) return;
  set_light(0);

  short_desc="In the orc Caves";
  long_desc="Bones litter the floor and blood stains the walls of this "+
            "foul and decrepit cave.  The air is permeated with the "+
            "lingering stench of death.  From the west filter some strange "+
            "noises, sounding almost like a bar.\n";


  items=({"bones","Some of them look to be fairly recently deposited",
          "floor","The floor is littered with bones",
          "blood","A few fresh patches of red blood smeared on the walls",
          "walls","Ancient, crumbling stone walls, patched with blood",
          "air","The air is foul",
          "cave","A nasty cave inhabited by orcs",
          "bar","There might be a bar to the west of here",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci2","south",
             "/players/emerald/island/room/caves/room/ci6","north",
             "/players/emerald/island/room/caves/room/ci5","west",
           });

  smell="The stench of death.";

  ::reset(arg);
  replace_program("/room/room");

}
