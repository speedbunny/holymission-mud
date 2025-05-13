inherit "room/room";

void reset(int arg) 
  {if(!arg) 
    {set_light(1);
    short_desc="Limbo";
    long_desc= 
    "The power of The Denizen has sent you to this mystical place.  You "+
    "sense it may simply be a pen of some sort, to hold you at bay until "+
    "he feels it is the proper time for you to return.  Directions seem "+
    "meaningless here, and you simply tend to float about, or are you "+
    "still?  You do feel capable of leaving this place to return to "+
    "somewhere more familiar, and even think you can muster the strength "+
    "to enter The Denizen's lair, should he allow it.\n";
     dest_dir=({"/room/well","leave",
     "/players/warlord/quest1/room8","enter"});}
   ::reset();
   replace_program("room/room");}
 
