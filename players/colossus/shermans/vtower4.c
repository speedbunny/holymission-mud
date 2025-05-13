#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc="The third level of the tower";
    long_desc=
    "Standing on the third floor of the tower, you see dimly\n\
lit hallways that lead to empty rooms. The hallways are\n\
lit by almost burnt out torches hanging from sconces.\n\
A feeling of loss and hurting pervades this area.\n";
    items=({
      "room", "Dimly lit hallway with empty rooms",
      "torches", "You consider taking the torches but they're almost burnt out",
      "sconces", "On the iron sconces are torches",
    });
    dest_dir=({
      "/players/sherman/vtower5","up",
      "/players/sherman/vtower3","down"
    });
}
