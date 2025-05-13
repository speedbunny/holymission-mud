inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Balcony";
    long_desc="You're on the balcony of the house. You have a magnificent "
            + "sight on both the track coming out of the village and the "
            + "sea.\n";
    set_light(1);
    smell="You immediately notice the salt smell of the sea.";
    items=({"balcony","Don't worry! It won't collapse",
            "track","@@show_track",
            "sea","It's blue and green and a jetty runs into it",
            "village","It looks pretty in the sunlight"});
    dest_dir=({"players/cashimor/extend/floor","south"});
  }
}

init() {
  ::init();
  "players/cashimor/extend/hall"->walk_above();
}

show_track() {
int i;
object all;
string msg;

  msg="You look at the track below you:\n"
    + "room/vill_shore4"->query_long();
  all=all_inventory(find_object("room/vill_shore4"));
  for(i=0;i<sizeof(all);i++) msg+=all[i]->short()+".\n";
  msg+="It looks very interesting";
  return msg;
}
