inherit "room/room";
reset(arg) 
{
    if (arg) return;
 
    set_light(1);
    short_desc = "Cavern with many exits";
    no_castle_flag = 0;
    long_desc = "In this cavern you have several directions you can take.\n"+
    "Look everywhere to carefully choose your direction, your destiny.\n";
    dest_dir = 
        ({"players/jewel/caverns/rooms/hard1", "northwest",
          "players/jewel/caverns/rooms/fun1", "west",
          "players/jewel/caverns/rooms/medi1", "southwest",
          "players/jewel/caverns/rooms/entrance", "east",
         });
    items = 
        ({"floor","A limestone floor with worn tracks leading in "+
                  "several directions",
    "walls","The walls are glowing!\n It is brightest "+
    "in one concentrated area.\n Maybe you can dig to investigate",
   "wall","The wall is glowing!\n It is brightest in one concentrated area.\n Maybe you can dig to investigate",
   "ceiling","The ceiling is still hidden in the darkness",
   "northwest","As you look northwest down the dark cavern, "+
                "a cold, cold wind\n"+ 
    "chills you to your very bones.  Surely, death awaits you there",
    "west","As you look west down the well-lit cavern, "+
            "you feel completely at ease",
          "southwest","As you look sowthwest down the dark cavern, "+
         "you feel a challenging\nadventure awaits you",
          "east","As you look east, you realize this leads back to the sea.",
        });
}
 
init()
{
    add_action("make_gcrystal", "dig");
    ::init();     
}
 
make_gcrystal(arg) 
{
    object gcrystal;
 
 
    if(arg == "wall")
    {
        gcrystal = clone_object("players/jewel/caverns/objs/gcrystal");
        move_object(gcrystal, this_player());
        write("You find a glowing crystal!  It's light is "+
                "nearly blinding.\n");
        return 1;
    }
    write("What are you going to dig?\n");
    return 1; 
}
 
 
query_light() {
    return 1;
}

