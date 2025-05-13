inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    long_desc = "Path curves in a dense part of the forest. Sounds seem\n"+
                "different. The echo around seem to come from every\n"+
                "direction. Maybe you should listen to the sounds?\n";
    items = ({
              "forest","Very dense and dark. The branches sway overhead",
              "sounds","How can you examine sounds?",
             });
    hear_items += ({
                    "sounds","You hear the many sounds of the forest.",
                   });
    room_sound += ({
                    "Several different sounds echo through this room\n",
                    "You listen to the sounds of the forest.\n",
                   });
    dest_dir = ({
                 "/players/kbl/expa/for6","north",
                 "/players/kbl/expa/for8","west",
                });
    set_sound_dest("players/kbl/dungeon/dun16");
  }
}

init()
{
  ::init();
}
