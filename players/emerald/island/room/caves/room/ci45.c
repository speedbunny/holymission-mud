inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the dark and rank orc caves.  To "+
            "the north, the hallway emerges into the light.  The "+
            "silhouettes of huge creatures can be seen at the entrance to "+
            "the hallway.  To the south, the passage leads into darkness.\n";

 items=({"caves","The dangerous orc caves",
         "hallway","To the north there is light",
         "silhouettes","The creatures that make them are QUITE large",
         "creatures","They must be terribly large",
         "entrance","The entrance to the hallway",
         "passage","The passage to the south is dark",
         "darkness","Thick, impenetrable blackness",
       });

  dest_dir=({"/players/emerald/island/room/caves/room/ci46","north",
             "/players/emerald/island/room/caves/room/ci43","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
