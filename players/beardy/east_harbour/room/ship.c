inherit"room/room";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="little ship",

   property=({"no_teleport"});
   // dest_dir=({"/players/whisky/seaworld/room/sw25","jump"});
    
  items=({"holes","Yes there are many of them"});
  }
}
