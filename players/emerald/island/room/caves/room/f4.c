inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";
  long_desc="The eerie groaning and creaking noises created by the rubbing "+
            "of the tree branches past each other in the wind makes you "+
            "jump and startle.  The leaves rustle ominously, as if a storm "+
            "were brewing.  In the distance, the volcano grumbles in anger.\n";

  items=({"branches","Old, gnarled tree branches",
          "wind","It carries the foul stench of the volcano",
          "leaves","Thick leaves of oaks",
          "volcano","You are on an active volcanic island",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f5","east",
             "/players/emerald/island/room/caves/room/f3","west",
             "/players/emerald/island/room/caves/room/p8","south",
             "/players/emerald/island/room/caves/room/f8","north",
            });

  ::reset(arg);
  replace_program("/room/room");

}
