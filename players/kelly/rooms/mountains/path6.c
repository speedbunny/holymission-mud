inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A plateau";
    long_desc="You are standing on a plateau on the mountains. To the east \n"+
     " the plateau falls steeply down. You can't see the foot of the valley.\n"+
     " But in the nearer east you can see the tops of two towers of a castle.\n"; 
    dest_dir=({
      "players/kelly/rooms/mountains/path5","north",
   });
   
   items=({
     "towers","The two towers belong to a marvelous castle",
     "valley","You can't see the bottom of the valley",
   });
}
