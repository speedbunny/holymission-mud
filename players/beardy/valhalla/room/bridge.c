inherit"room/room";
#include "../valhalla.h"

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Tower bridge of Valhalla.",
  long_desc=
	"Tower bridge of Valhalla.\n"+
       "       You are standing on the tower bridge of Valhalla. It is made\n"+
	"out of real ancient wood and no worm ever got through it. Long\n"+
	"steel chains are fixed on both sides of the bridge and you see some\n"+
	"guards patroling it. Especially Heimdell the god-guard of the bridge\n"+
	"of Valhalla.\n";
    
  items=({
	"bridge","It looks very well",
	"chains","They are really strong",
	"wood","It is good ancient wood",
	"guard","You see some guards, hanging around in the castle",
	"guards","You see some guard, hanging around in the castle",
	});

  dest_dir =
	({
	ROOM + "floor001","north",
	"/players/beardy/asgard/room/start002","southwest",
	});

  smell = "The air smells divine";
  CM("heimdell");
  TCM("guard","floor003");
  TCM("guard","floor028");
  TCM("guard","floor010");
  TCM("guard","floor019");
  TCM("guard","floor020");
  TCM("guard","floor015");
  TCM("guard","floor024");
  TCM("slime","well003");
  TCM("slime","well004");
  TCM("rabbit","garden003");
  TCM("rabbit","garden015");
  TCM("rabbit","garden011");
  TCM("sparrow","garden020");
  TCM("sparrow","garden012");
  TCM("frog","garden013");
}

int move(string str)
{ if(query_verb()=="north")
  { if(present("heimdell"))
    { tell_room(this_object(),"The god says: Piss off, we don't need you in there.\n");
    }
  else
    this_player()->move_player("Gangway of Valhalla#players/beardy/valhalla/room/floor001");
  return 1;
  }
  return ::move(str);
}
