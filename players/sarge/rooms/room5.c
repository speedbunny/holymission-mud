inherit "room/room";
int exit_num;

void reset(int arg)
  {if(!arg)
    {set_light(1);
    short_desc="A misty tunnel",
    long_desc=
    "Grey mist swirls around your feet as you walk down this narrow tunnel.  "+
    "The stone walls are cold and damp, and covered with an unusual slime.  "+
    "Barely visible are pictures scrawled into stone walls, and faint "+
    "screams can be heard echoing throughout the tunnels.\n";
    items=({
    "stone","Thick granite, or so it seems.."
    "feet","Feet!  They're yours, be familiar with them!!!",
    "foot","A foot!  What else..",
    "tunnel","A misty tunnel.  Just look around",
    "slime","It's cold yet soft, and emits a faint glow which illuminates the tunnel",
    "mist","A dark grey mist that swirls around the tunnel",
    "floor","The mist blocks all sight of the floor",
    "ceiling","The mist is too thick above to make out the features of the ceiling",
    "walls","The stone walls are the only solid things you can see.  They are\n"
           "covered with a faintly glowing slime, and several pictures can still\n"+
           "be seen through the slime and mist",
    "wall","The stone wall is the only solid thing you can see.  It is covered\n"+
           "with a faintly glowing slime, and several pictures can still be\n"+
           "seen through the slime and mist",
    "pictures","You can barely make out what appear to be pictures of The\n"+
           "Denizen's recent victims",
    "picture","Oddly enough, it seems to be a picture of you",
    "victims","The pictures portray scenes of The Denizen's victims being\n"+
           "tortured",
    "victim","One prophetic looking picture looks just like you"});
    dest_dir=({"/room/well","leave",
    "/room/well","north",
    "/room/well","south",
    "/players/sarge/rooms/room3","east",
    "/players/sarge/rooms/room2","west"});}
  exit_num=random(4);}


void init()
  {::init();
  add_action("block","north");
  add_action("block","south");
  add_action("block","east");
  add_action("block","west");}


status block()
  {string dir;
  dir=query_verb();
  if(((dir=="north")&&(exit_num==0))||
  ((dir=="south")&&(exit_num==1))||
  ((dir=="east")&&(exit_num==2))||
  ((dir=="west")&&(exit_num==3)))
    {this_player()->move_player(dir+"#/players/sarge/rooms/room6");
    return 1;}
  else
    {write("You get lost in the mist.\n");
    return 0;}}



