inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are sneaking through the secret orc caves.  The main "+
            "corridor leads north and south.  Off to the south, a dark "+
            "stairway leads further into unknown horrors.  The floor is "+
            "covered with drops of fresh blood.  Strange grunting noises "+
            "come from the west.\n";

  items=({"caves","The secret orc caves",
          "corridor","The corridor leads north and south",
          "stairway","It leads down to the lower level",
          "floor","The floor is covered in fresh blood",
          "drops","Bright red drops of blood",
          "blood","It is quite fresh",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci28","north",
             "/players/emerald/island/room/caves/room/ci25","south",
             "/players/emerald/island/room/caves/room/ci27","west",
          });

  ::reset(arg);
  replace_program("/room/room");

}
