inherit "room/room";

mixed stuff;

void reset(int arg)
  {object altar;
  if(!arg) 
    {clone_list=
     ({1,1,"denizen","players/sarge/monsters/changlng",0,
     2,1,"altar","players/sarge/objects/altar",0});
    set_light(1);
    short_desc="An ancient temple";
    long_desc=
     "You are in an ancient temple filled with an evil stench.  "+
     "The mist you have been traveling in has now formed the walls.  "+
     "of this temple. The very feeling of evil in this room makes "+
     "you break out in a cold sweat.\n";
    items=({
    "mist", "the same eerie mist you have been traveling through",
    "walls","they were formed out of the mist",
    "temple","The mighty temple of the Denizen",
    "floor","The floor appears to be nothing more than mist",
    "ceiling","If there is a ceiling in here it is hidden in the mist",
    "blood","the blood of the Denizen's last visitor"});
    dest_dir=({"players/warlord/quest1/room7","east",
     "players/warlord/quest1/room9","north"});}
  ::reset(arg);
  altar=present("altar",this_object());
  if(!present("heart",altar)) {
    altar->reset();}}

           
void init()
  {int got_one, i;
  object person;
  ::init();
  stuff = all_inventory(this_object());
  for(i=0;i<sizeof(stuff);i++)
    if(stuff[i] && interactive(stuff[i]) &&
    stuff[i] != this_player() && interactive(this_player()))
      {got_one = 1;
      if(stuff[i]->query_linkdeath())
        stuff[i]->move_player("magically#/room/purgatory");}
  if(got_one)
    {person=this_player()->query_name();
    say(person + " was blocked from entering this room.\n");
    this_player()->move_player("magically#/players/warlord/quest1/holding");}}
