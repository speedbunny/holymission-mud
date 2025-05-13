inherit "room/room";

#define PATH "/players/kawai/areas/games/"


void reset(int arg) 
  {set_light(0);
  property=({"no_teleport","lab"});
  clone_list=({1,1,"lunatic","obj/monster",
   ({"set_name","lunatic",
   "set_alias","man",
   "set_alt_name","adventurer",
   "set_aggressive",1,
   "set_level",17,
   "set_gender",1,
   "set_chance",55,
   "set_whimpy",-1,
   "set_spell_dam",40,
   "set_spell_mess1","The lunatic tackles you and bites your fingers.",
   "set_spell_mess2","The lunatic trips you and jumps on your stomach!",
   "set_short","Lunatic adventurer",
   "set_long",
   "The lunatic is one of the more recent additions to the labrynth.\n"+
   "Like yourself, he failed the Grand Wizards challenge, and is living\n"+
   "out the rest of his life scavenging for food among the rotting \n"+
   "corpses and small rodents.  Gazing into his eyes you can only tell\n"+
   "that he is far, far gone....\n"})});
  short_desc="A dark tunnel";
  long_desc="You are lost somewhere in the middle of a dark labrynth.  "+
  "The stale air and cold, stone walls drain your soul of hope.  "+
  "You fear this may be your final resting place, just like the fate of "+
  "those many adventurers before you; their tales long forgotten and "+
  "their secrets held only in the bones scattered around the floor.  Passages lead "+
  "off in all sorts of directions, twisting and turning, void of any logic.\n";
  dest_dir=({PATH+"labr3","north",
             PATH+"labr13","northeast",
             PATH+"labr10","east",
             PATH+"labr9","southeast",
             PATH+"labr8","south",
             PATH+"labr1","southwest",
             PATH+"labr4","west",
             PATH+"labr2","northwest"});
  items=({"room","Just look around",
          "labrynth","A twisting maze of dark tunnels",
          "passage","Various passages lead off in all directions",
          "wall","A wall made of stone",
          "walls","The walls are carved of stone",
          "passages","They lead off in various directions",
          "ground","It is strewn with the bones of many like yourself",
          "floor","It is strewn with the bones of many like yourself",
          "bone","Looks like a tibia..",
          "bones","The bones of many, like you, got lost in this maze",
          "stone","The stone looks to be a blue and grey marble"});
   ::reset(arg);
   replace_program("room/room");}
  
