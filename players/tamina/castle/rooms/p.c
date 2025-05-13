inherit "room/room";

#include "/players/tamina/defs.h"

status fire, earth, water, air;

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

     set_light(1);
     short_desc = "Room of Portals";
     no_obvious_msg = "";
}

void init() 
{
  add_action("bring_portal", "create");
  add_action("enter_it",     "enter");
  ::init();
}

int bring_portal(string str)
{
  object key;

  if (str == "fire gate")
  {
    key = present("fire key", TP);  // Ruby_code
    if (key)
    {
      if (!fire)
      {
        write("You smash the ruby against one of the walls, in an attempt\n"+
	      "to open a gate to another dimension.\n");
        say(TPN+" throws a ruby against one of the walls.\n");

	destruct(key);
        fire = 1;
        return 1;
      }
      write("But there is already a gate to the Elemental Plane of Fire.\n");
      return 1;
    }
    write("But you don't have the key to create a gate to the Elemental\n"+
	  "Plane of Fire.\n");
    return 1;
  }
  else if (str == "water gate")
  {
    key = present("water key", TP);  //  Wooden Pipe_code
    if (key)
    {
      if (!water)
      {
        write("You throw the pipe against one of the walls, in an attempt\n"+
	      "to open a gate to another dimension.\n");
        say(TPN+" throws a wooden pipe against one of the walls.\n");

	destruct(key);
	water = 1;
        return 1;
      }
      write("But there is already a gate to the Elemental Plane of Water.\n");
      return 1;
    }
    write("But you don't have the key to create a gate to the Elemental\n"+
	  "Plane of Water.\n");
    return 1;
  }
  else if (str == "earth gate")
  {
    key = present("earth key", TP);   // Diamond Ring_code
    if (key)
    {
      if (!earth)
      {
        write(
	"You smash the diamond ring against one of the walls, in an attempt\n"+
	"to open a gate to another dimension.\n");
        say(TPN+" throws a diamond ring against one of the walls.\n");

	destruct(key);
	earth = 1;
        return 1;
      }
      write("But there is already a gate to the Elemental Plane of Earth.\n");
      return 1;
    }
    write("But you don't have the key to create a gate to the Elemental\n"+
	  "Plane of Earth.\n");
    return 1;
  }
  if (str == "air gate")
  {
    key = present("air key", TP);   // Silver Necklace_code
    if (key)
    {
      if (!air)
      {
        write("You smash the necklace against one of the walls, in an attempt\n"+
	      "to open a gate to another dimension.\n");
        say(TPN+" throws a silver necklace against one of the walls.\n");

	destruct(key);
	air = 1;
        return 1;
      }
      write("But there is already a gate to the Elemental Plane of air.\n");
      return 1;
    }
    write("But you don't have the key to create a gate to the Elemental\n"+
	  "Plane of Air.\n");
    return 1;
  }
}

int close_fire()
{
    TRM(TO,
     "The gate to the Plane of Fire vanishes !\n");
    fire = 0;
    return 1;
}

int close_earth()
{
    TRM(TO,
     "The gate to the Plane of Earth vanishes !\n");
    earth = 0;
    return 1;
}

int close_water()
{
    TRM(TO,
     "The gate to the Plane of Water vanishes !\n");
    water = 0;
    return 1;
}

int close_air()
{
    TRM(TO,
     "The gate to the Plane of Air vanishes !\n");
    air = 0;
    return 1;
}

int enter_it(string str) 
{
  if (str == "red" || str == "red portal")
  {
    if (fire)
    {
      write("You step boldly into the Red Portal.\n"); 
      MPL("through the Red Portal, to another dimension!#players/tamina/castle/planes/fire/rm1");
      call_out("close_fire", 60);
      return 1;
    }
    write("There is no such portal here.\n");
    return 1;
  }    
  else if (str == "blue" || str == "blue portal")
  {
    if (water)
    {
      write("You step boldly through the Blue Portal.\n");
    MPL("through the Blue Portal to another dimension!#players/tamina/castle/planes/water/rm1");
      call_out("close_water", 60);
      return 1;
    }
    write("There is no such portal here.\n");
    return 1;
  }
  else if (str == "brown" || str == "brown portal")
  {
    if (earth)
    {
      write("You step boldly through the Brown Portal.\n");
    MPL("through the Brown Portal into another dimension!#players/tamina/castle/planes/earth/rm1");
      call_out("close_earth", 60);
      return 1;
    }
    write("There is no such portal here.\n");
    return 1;
  }
  else if (str == "white" || str == "white portal")
  {
    if (air)
    {
      write("You step boldly through the White Portal.\n");
    MPL("through the White Portal into another dimension!#players/tamina/castle/planes/air/rm1");
      call_out("close_air", 60);
      return 1;
    }
    write("There is no such portal here.\n");
    return 1;
  }
  else 
  {
    NFAIL("What do you wish to enter?\n");
    return 0;
  }
  return 1;
}

int long(string str)
{
  if (str == "at room" || str == "room")
  {
    write("It is too plain to go into any great detail.\n");
    return 1;
  }
  if (str == "portal" || str == "at portal")
  {
    if (fire || earth || water || air)
    {
      write("Which portal do you wish to look at?\n");
      return 1;
    }
    else
    {
      write("There are no portals here.\n");
      return 1;
    }
    return 1;
  }
  if (str == "portals" || str == "at portals")
  {
    if (fire || earth || water || air)
    {
      write("These look like supernatural gateways.  There are softly\n"+
	    "glowing auras eminating from each of the Portals: \n");
      if (fire)
        write("Red");
      if (water)
	write(", Blue");
      if (earth)
	write(", Brown");
      if (air)
	write(", and White");
      write(".  You feel a distinctively strong magical power from\n"+
	    "these Portals.\n");
      return 1;
    }
    else
    {
      write("There are no portals here.\n");
      return 1;
    }
  }
  if (str == "red portal" || str == "at red portal")  // FIRE - Ruby
  {
    if (!fire)
    {
      write("There is no red portal here.\n");
      return 1;
    }
    write("You can sense a powerful heat eminating from the glowing\n"+
	  "Red Portal.\n");
    return 1;
  }
  if (str == "blue portal" || str == "at blue portal")  // WATER - Pipe
  {
    if (!water)
    {
      write("There is no blue portal here.\n");
      return 1;
    }
    write("From inside the Blue Portal, you can feel a sensual calming, but\n"+
	  "also a terrible strength.\n");
    return 1;
  }
  if (str == "brown portal" || str == "at brown portal" || str == "hole" ||
	str == "at hole" || str == "brown hole") // EARTH - D_Ring
  {
    if (!earth)
    {
      write("There is no brown portal here.\n");
      return 1;
    }
    write("Once you turn your attention to the Brown Portal, you sense an\n"+
	  "enormous, claustrophobic pressure pushing on you.\n");
    return 1;
  }
  if (str == "white portal" || str == "at white portal" || 
	str == "ceiling" || str == "at ceiling") // AIR - S_Neck 
  {
    if (!air)
    {
      write("There is no white portal here.\n");
      return 1;
    }
    write("From the White Portal, you can sense a wonderful feeling of\n"+
	  "pure freedom, of nothing to hold you down.\n");
    return 1;
  }
  write("This is a very plain, square-shaped room.\n");
  if (earth)
    write("There is a dark brown hole in the floor.\n");
  if (fire)
    write(" There is a glimmering red portal on one wall.\n");
  if (water)
    write(" There is a shimmering blue portal against one wall.\n");
  if (air)
    write("    There is no ceiling, only a white portal in its place.\n");
  write("You feel a tremendous magical presence here.\n");
    return 1;
}
