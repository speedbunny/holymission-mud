#define TP this_player()
#define TPN this_player()->query_name()
#define TR tell_room

inherit "/room/room";

int passage_open;

void reset(int arg) {

passage_open=0;

  if(arg) return;

  set_light(0);

  short_desc="A small and dingy room";
  long_desc="You are in a small and stinky room.  You smell freshly burnt " +
            "hair in the air.  An old hag lives here, and she does not " +
            "appreciate visitors@@extralong@@.\n";

  dest_dir=({"/players/emerald/good/evil/evil3","north",
             "/players/emerald/good/evil/evil7","east",
           });

  smell="The malodorous scent of burned hair";

  items=({"room","A small room.  There might be something here to find",
        });

  property=({"no_sneak",});
  clone_list=({
    1,1,"hag","obj/monster", ({
      "set_name","hag",
      "set_alias","hag",
      "set_level",12,
      "set_long","The hag is old and evil looking.\n",
      "set_ac", 4,
      "set_hp", 250,
      "set_wc", 12,
      "set_aggressive",0,
      "set_chance",20,
      "set_spell_mess1","The hag points and shrieks!",
      "set_spell_mess2","The hag points at you and shrieks!",
      "set_spell_dam",25,
      "set_al",-750,
    }),
    -1,1,"stone","obj/treasure",({
      "set_id","black stone",
      "set_alias","stone",
      "set_short","A black stone",
      "set_long","A dark black stone.  Your gaze is lost in its depths.\n",
      "set_value",500,
      "set_weight",1,
    }),
    2,1,"owl","obj/monster", ({
      "set_name","black owl",
      "set_alias","owl",
      "set_short","A black owl",
      "set_long","The owl is large and black.  He stares at you menacingly.\n",
      "set_level",6,
      "set_ac", 2,
      "set_wc", 5,
    }),
  });

  ::reset();

}

extralong() {
  if(passage_open==1) return ".  There is a trap door leading down";
  return "";
}

void init() {
  ::init();
  add_action("_search","search");
  add_action("_down","down");
}


_down(){
  if (!passage_open) 
    return 0;
  if (present("hag")) {
    write("The hag blocks your way!\n");
    return 1;
  }
  TP->move_player("down#players/emerald/good/evil/evil24");
  return 1;
}

_search(str){
  if (!str) str = "room";
  if (str=="room") {
    write("A careful search reveals a trap door in the floor!\n");
    say(TPN+" finds a trap door leading down.\n");
    passage_open=1;
    return 1;
  }
}
