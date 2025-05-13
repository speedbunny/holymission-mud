inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A side street";

  long_desc="Leavng the busy main thoroughfare behind you, you have reached " +
            "the relative peace and quiet of a side street.  The cobbles " +
            "are worn and cracked in places, but seem to be in generally " +
            "good shape otherwise.  There are houses to the north and " +
            "south.  Light shines from their windows.\n";

  dest_dir=({"/players/emerald/town/t16","east",
             "/players/emerald/town/t14","west",
           });

  items=({"cobbles","Old paving cobbles, somewhat worn with age",
          "street","A small side street",
          "light","It shines from the windows of the houses",
          "windows","Light shines through the glass panes",
          "houses","The dwelling places of humans",
  });

  ::reset(arg);
   replace_program("/room/room");

}
