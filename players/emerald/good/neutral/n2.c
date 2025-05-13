inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="Misty cloud world";
  long_desc="Cold tendrils of mist free themselves from the clouds, "+
            "lazily curling through the path.  Some unseen force must be "+
            "at work, keeping the clouds from crowding the path and "+
            "erradicating it.  A hint of a breeze stirs along the path.\n";

  dest_dir=({"/players/emerald/good/neutral/n1","south",
             "/players/emerald/good/neutral/n3","northeast",
           });

  items=({"tendrils","Wisps of cloud brush against you",
          "mist","Omnipresent swirling mists",
          "clouds","Huge clouds threaten to squeeze the path into oblivion",
          "path","A small path leading northeast and south",
          "breeze","A small force of gently moving air",
        });

  clone_list=({
    1,1,"elemental","obj/monster",({
      "set_name","wind elemental",
      "set_short","A wind elemental",
      "set_alias","elemental",
      "set_long","The swirling mists have formed themselves into a vaguely "+
                 "discernible, humanoid form.\n",
      "set_level",12,
      "set_alignment",10,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
