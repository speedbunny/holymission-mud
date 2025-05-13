

inherit "room/room";
#pragma strict_types
#include <lw.h>
#include "/players/tatsuo/def.h"

status door, in_call_out;
string destr, ext;
object sunstaff;

int _climb(string str)
{
    MOVE("down the cliff face#players/tatsuo/ishikawa/jungle/jung56");
    return 1;
}

int _enter()
{
    if (door)
    {
	MOVE("into the cave#players/tatsuo/ishikawa/caves/c1");
	door = 0;
	destr = " Inscribed on the center of the stone slab is a glowing sigil. ";
	ext="    No obvious exits.";
	say("After "+TPN+" enters the cave, the opening disappears!\n");
	say("Once again the sigil stands guard over the entrance.\n");
	return 1;
    }
}

int _look(string str)
{
    if (door)
	return 0;
    if (str == "at sigil")
    {    
	write("You stare at the sigil. An intense fear overwhelms you. You run.\n");
	write("Oh no the Cliff!!! You fall.............\n");
	write("You land with a THUD. It hurts alot.\n");
	say(TPN + "falls screaming down the cliff face.\n");
       TP->misc_hit(50,2,0);
	move_object(this_player(),"players/tatsuo/ishikawa/jungle/jung56");
	return 1;   
    }
}

int _move(string str)
{
    if (str == "slab" || str == "stone slab")
    {
	write("Yeah right.\n");
	return 1;
    }
}

void opening(int stage)
{
    switch(stage)
    {
    case 0:
	writelw("As the setting sun strikes the crystal a brilliant "
	  + "beam of light emanates from the sun staff.\n");
	call_out("opening",4,1);
	break;
    case 1:
	write("The beam strikes the sigil, causing a blinding flash.\n");
	set_light(100);
	call_out("opening",4,2);
	break;
    case 2:
	write("You feel a rush of cold and damp air rush from the light.\n");
	call_out("opening",4,3);
	break;
    case 3:
	write("As the light dims, a dark opening stands where the sigil once was.\n");
	say(TPN+" does something and a brillant flash of light ensues.\n");
	say("A dark opening appears where the sigil once stood.\n");
	destr = " A dark opening appears to have taken the place of the sigil. ";
	ext = "    Obvious exits: enter";
	destruct(sunstaff);
	write("The Sunstaff shatters.\n");
	set_light(1);
	door = 1;
	in_call_out = 0;
	break;
    }
}

int _put(string str)
{
    if (door)
	return 0;
    if (str=="staff into hole" || str=="sunstaff into hole" || str=="staff in hole" || str=="sunstaff in hole" 
      || str=="sunstaff of amaterasu in hole" || str=="sunstaff of amaterasu into hole")
    {
	sunstaff= present("sunstaff",TP);
	if (!sunstaff)
	{
	    write("Put what where???\n");
	    return 1;
	}
	if (sunstaff)
	{
	    if (in_call_out)
	    {
		write("There is something in the eye of the serpent already.\n")
		;
		return 1;
	    }
	    write("You set the sunstaff into the eye of the serpent.\n");
	    call_out("opening",4,0);
	    in_call_out = 1;
	    return 1;
	}
    }
}

int _touch(string str)
{
    if (str == "sigil")
    {
	write("You burn yourself very badly!\n");
        TP->misc_hit(100,2,0);
	return 1;
    }
}

void long(string str)
{
    writelw("You arrive on a ledge halfway up the mountain.  The vegetation "
      + "on the side of the mountain here appears to have been burned away.  "
      + "A huge stone slab has been set to block the entrance of a cave."
      + destr
      + "The view of the island is spectacular from here.  To the west, "
      + "you can see a giant stone obelisk protruding from the jungle "
      + "canopy far below.  The sun is setting to the west.  In the middle "
      + "of the ledge is an engraving of a great oriental serpent.  You "
      + "could climb down from here safely if you tried.\n"
      + ext + "\n");
}

void reset(int arg)
{
    if (arg)
	return;
    set_light(1);
    destr=" Inscribed on the center of the stone slab is a glowing sigil. ";
    ext="    No obvious exits.";
    short_desc="Entrance to a Cave";
    items=({
      "canopy","The trees of the jungle form a natural canopy over the island",
      "center","There is a sigil in the center of the slab",
      "cliff","You are on a ledge that falls away over a cliff",
      "dragon","It is a very good engraving. The dragon looks fierce",
      "engraving","A great oriental dragon is carved into the ledge"
      + "The eye of the dragon is a two inch diameter hole",
      "hole","It is six inches deep and two inches in diameter",
      "island","The island of Ishikawa",
      "jungle","It is vast and dense",
      "ledge","There is an engraving of a dragon on the ledge",
      "mountain","A large mountain covered in vegetation",
      "obelisk","It lies to the west and is visible above the jungle canopy",
      "opening","It appears to open into the cave",
      "runes","You don't understand them",
      "serpent","It is a very good engraving. The dragon looks fierce",
      "side","You are on the side of this mountain",
      "slab","A large stone slab covering the entrance to the cave\n",
      "Runes are carved into its surface",
      "stone slab","A large stone slab covering the entrance to the cave",
      "Runes are carved into its surface",
      "sun","The sun shines over the engraving and onto the stone slab",
      "vegetation","It has been burned away from the cave entrance",
      "view","It is spectacular",
    });
    property = ({ "no_teleport" });
    in_call_out = 0;
}

void init()
{
    ::init();
    AA("_climb","climb");
    AA("_enter","enter");
    AA("_look","exa");
    AA("_look","look");
    AA("_look","l");
    AA("_move","move");
    AA("_move","lift");
    AA("_put","put");
    AA("_put","place");
    AA("_put","set");
}

