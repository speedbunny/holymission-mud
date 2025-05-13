inherit "room/room";

reset(arg) {
  int i;
  if (!present("ghost")) {
    for (i=0;i<5;i++)
    move_object(clone_object("/players/jewel/quest/ghost2"),this_object());
  }
  if (arg) return;
  set_light(0);
  short_desc="The second level of the vampire tower";
  long_desc=
    ("This is the second level of the vampire tower, some ghosts of the \n"+
     "people the king killed before are stopping you\n");
  items=({
    "ghosts","Some lost souls",
    "ghost","A lost soul"
        });
  dest_dir=({
    "/players/jewel/quest/vtower4","up",
    "/players/jewel/quest/vtower2","down"
           });
}

init() {
  ::init();
  if(present("ghost")) {
    if(query_teeth(this_player())) {
      call_out("kill_vamp",2,this_player());
      add_action("up","up",1);
      }
    }
  }

up() {
  if(!present("ghost")) {
     this_player()->move_player("up#players/jewel/quest/vtower4");
  } else { 
    write("The ghosts block your way.\n");
    kill_vamp(this_player());  
  }
  return 1;
}

kill_vamp(pl) {
  object gh;
  int i;

  gh=all_inventory(environment(pl));
  for(i=0; i<sizeof(gh); i++) {
    if(lower_case(gh[i]->query_name())=="ghost") {
      gh[i]->attack_object(pl);
      }
    }
  }

query_teeth(pl) {
  object th;
  int i;

  th=all_inventory(pl);
  for(i=0;i<sizeof(th);i++) {
    if(th[i]->query_wielded()) return th[i]->query_teeth();
  }
} 
      
