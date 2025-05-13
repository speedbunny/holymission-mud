inherit "room/room";
#define TR tell_room
#define TPN this_player()->query_name()

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Mountain";

  long_desc="The mountain looks very steep here. It is covered with " +
            "ice and it looks very slick.  You wonder is there is any way "+
            "to climb to the top of the mountain from here. To the north " +
            "appears to be a small mountain village.\n";

  items=({"mountain","The mountain is very steep and icy",
          "village","You could probably get some climbing equipment there",
          "top","You really want to climb to the top of the mountain",
          "ice","You would need something to help you climb this",
        });

  dest_dir=({"players/emerald/good/light/light11","south",
             "/players/emerald/good/shops/shop_street1","north",
           });

  ::reset();

}
void init() {
  ::init();
  add_action("_climb","climb");
}


_climb(str) {
  object boots;
  boots = present("snow boots",this_player());
    if(!boots) {
      write("You try to climb the mountain, but you cannot get a grip\n"+
            "without something to help you climb. You slide back down the\n" +
            "mountain. You slide all the way to the base of the mountain.\n");
      TR("players/emerald/good/light/light11",TPN+" comes sliding into view.\n");
      say(TPN+ " slides down the mountain after trying to climb it.\n");
      this_player()->move_player("down#players/emerald/good/light/light11");
      return 1;
    }
    if(!boots->query_worn()) { 
      write("You MUST wear them first!.\n");
      return 1;
    }
    write("The snow boots dig right in and you climb like a goat.\n");
    say(TPN+" climbs up the mountain and is soon out of sight.\n");
    tell_room("players/emerald/good/light/light4",TPN+" arrives.\n");
    this_player()->move_player("up#players/emerald/good/light/light4");
    return 1;
}
