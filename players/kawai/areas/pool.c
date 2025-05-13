inherit "room/room";


string query_env_name()
  {return "water";}

void reset(int arg)
  {object chest;
  if(!arg)
    {clone_list=({1,1,"leech","obj/monster",({"set_name","leech",
    "set_short","A giant leech",
    "set_level",14,
    "set_whimpy",-1,
    "set_aggressive",1,
    "set_al",-50,
    "set_long",
    "The giant leech wades around, waiting for its next host...\n"})});
    set_light(1);
    short_desc="The bottom of a pool";
    long_desc="You are swimming at the bottom of an underground pool.\n";
    items=({ "pool", "A damp, still pool"});
    dest_dir=({ "players/kawai/areas/wcave", "up", });}
  if(!chest=present("chest",this_object()))
    {move_object(chest=clone_object("/players/kawai/obj/cchest"),
    this_object());}
  chest->reset();
  ::reset(arg);}

status block(string str)
  {if(present("leech",this_object()))
    {write("The leech blocks you from doing that.\n");
    return 1;}
  return 0;}

void init() 
  {::init();
  add_action("block", "open");
  add_action("block","lock");
  add_action("block","close");
  add_action("block","get"); 
  add_action("block","take");
  add_action("block","unlock");
  add_action("block","put");
  add_action("block","picklock");
  add_action("block","knock");
  add_action("block","break");
  add_action("up", "up");
  add_action("block","turn");
  call_out("no_air",30,0);}

status up() 
  {if(this_player()->query_npc())
    {return 1;}
  remove_call_out("no_air");
  return 0;}

void no_air() 
  {if(environment(this_player())!=this_object()) 
    {return;}
  write("Your lungs are gasping for air, and you surface.\n");
  command("up",this_player());}
