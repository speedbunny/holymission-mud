inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A small squalid hut";
  long_desc="This is a squalid little hut.  There are no furnishings " +
            "beyond the very basics.  You feel that whoever lives here " +
            "is clearly used to living without any modern conveniences.\n";

  dest_dir=({"players/emerald/forest/f8-5","south", 
           });

  items=({"hut","Tiny and somewhat filthy",
          "furnishings","A rough wooden table and a pallet of straw",
        });

  clone_list=({
    1,1,"hermit","/players/moonchild/goblins/hermit",0,
  });

  ::reset();
  replace_program("/room/room");

}

