inherit "room/room";

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1); 
    short_desc="The Tower Roof";
    long_desc="You are on the roof on Padrone's private tower. At your back"
             +" the slate roof curls round to either side. As you look out"
             +" over the surrounding area, you see a large forest stretch out"
             +" below you, with a few trails running randomly through it."
             +" Further to the west you can see a large range of mountains."
             +" There are several castles dotted around the land, as if people"
             +" have simply built them wherever they wanted to. To the east"
             +" and north you can see a village close to the eastern edge of"
             +" the forest. Beyond that is the sea. Another mountain range"
             +" stretches across the horizon to the north.\n";
    dest_dir=({
      "/players/padrone/tower/hall","down",
    });
    items=({
      "roof","The tower has a circular state roof",
      "slates","Large slates from the mountains in the west form the circular"
              +" roof of the tower",
      "forest","A large expanse of trees stretches out to the west. You can"
              +" just make out a few trails winding their way through it",
      "trees","A large expanse of trees stretches out to the west. You can"
             +" just make out a few trails winding their way through it",
      "trails","A few trails wind their way through the forest below",
      "paths","A few trails wind their way through the forest below",
      "castles","There are castles dotted all over the land",
      "village","",
      "sea","You can see mist rising from the sea in the distance to the"
           +" east",
      "mountains","Large mountain ranges fill the horizon to the north and"
                 +" west",
    });
  }
}
