inherit "room/room";

object vamp_king;

reset(arg) {
int i;
object vamps;

  if (!present("vampire guest")) {
    for (i=0;i<6;i++)
    move_object(clone_object("/players/jewel/quest/vampire7"),this_object());
  } else {
    vamps=all_inventory(this_object());
    for(i=0;i<sizeof(vamps);i++) {
         if(vamps[i]->id("vampire guest"))
             vamps[i]->stop_hunter(1);
    }
  }
  if(!vamp_king) 
    move_object(vamp_king=clone_object("players/jewel/quest/vampire4"),
                this_object());

  if (!arg) {
    set_light(1);
    short_desc="The vampire party";
    long_desc=
  ("You have entered the room where the vampires have their parties.\n"+
   "You can see some vampires drinking blood from fine glasses and talking\n"+
   "in a low voice. A dark figure rises and leaves east\n");
    items=({
       "glasses","Fine glasses, filled with blood",
       "glass","A fine glass, filled with blood"
          });
    dest_dir=({
       "/players/jewel/quest/vtower6","south",
       "/players/jewel/quest/vtower8","east"
          });
  }
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(present("vampire king",this_object()))
    call_out("run_king",1);
  if(present("vampire guest")) {
    if(!this_player()->query_npc() && 
       !query_equip(this_player())) {
      call_out("kill_unvamp",2,this_player());
      add_action("east","east");
    } 
  }
}

run_king() {
  vamp_king->move_player("east#players/jewel/quest/vtower8");
}

east() {
  if(!present("vampire guest")) {
    this_player()->move_player("east#players/jewel/quest/vtower8");
  } else {
    write("Don't be silly, you can't force your way through the vampires.\n");
    kill_unvamp(this_player());
  }
  return 1;
}

kill_unvamp(pl) {
  object va;
  int i;

  va=all_inventory(environment(pl));
  for(i=0;i<sizeof(va);i++) {
    if(va[i]->id("vampire guest")) {
      va[i]->attack_object(pl);
    }
  }
}

query_equip(pl) {
object eq;
int i;
int th,ca;

  th=ca=0;
  eq=all_inventory(pl);
  for(i=0;i<sizeof(eq);i++) {
    if(eq[i]->query_wielded()) th=eq[i]->query_teeth();
    if(eq[i]->query_worn() && eq[i]->query_cape()) ca=1;
  }
  return (th && ca);
}
