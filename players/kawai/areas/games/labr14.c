inherit "room/room";

#define PATH "/players/kawai/areas/games/"


void reset(int arg) 
  {set_light(0);
  property=({"no_teleport","lab"});
  short_desc="A dark tunnel";
  long_desc="You are lost somewhere in the middle of a dark labrynth.  "+
  "The stale air and cold, stone walls drain your soul of hope.  "+
  "You fear this may be your final resting place, just like the fate of "+
  "those many adventurers before you; their tales long forgotten and "+
  "their secrets held only in the bones scattered around the floor.  Passages lead "+
  "off in all sorts of directions, twisting and turning, void of any logic.\n";
  dest_dir=({PATH+"labr12","north",
             PATH+"labr2","northeast",
             PATH+"labr15","east",
             PATH+"labr9","southeast",
             PATH+"labr13","south",
             PATH+"labr10","southwest",
             PATH+"labr6","west",
             PATH+"labr3","northwest"});
  items=({"room","Just look around",
          "labrynth","A twisting maze of dark tunnels",
          "passage","Various passages lead off in all directions",
          "passages","They lead off in various directions",
          "wall","A wall made of stone",
          "walls","The walls are carved of stone",
          "ground","It is strewn with the bones of many like yourself",
          "floor","It is strewn with the bones of many like yourself",
          "bone","Looks like a tibia..",
          "bones","The bones of many, like you, got lost in this maze",
          "stone","The stone looks to be a blue and grey marble"});
   ::reset(arg);
   replace_program("room/room");}
  
