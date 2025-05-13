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
  dest_dir=({PATH+"labr11","north",
             PATH+"labr12","northeast",
             PATH+"labr9","east",
             PATH+"labr8","southeast",
             PATH+"labr6","south",
             PATH+"labr6","southwest",
             PATH+"labr7","west",
             PATH+"labr10","northwest"});
  items=({"room","Just look around",
          "labrynth","A twisting maze of dark tunnels",
          "wall","A wall made of stone",
          "walls","The walls are carved of stone",
          "passage","Various passages lead off in all directions",
          "passages","They lead off in various directions",
          "ground","It is strewn with the bones of many like yourself",
          "floor","It is strewn with the bones of many like yourself",
          "bone","Looks like a tibia..",
          "bones","The bones of many, like you, got lost in this maze",
          "stone","The stone looks to be a blue and grey marble"});
   ::reset(arg);
   replace_program("room/room");}
  
