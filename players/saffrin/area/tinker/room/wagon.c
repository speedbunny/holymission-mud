inherit "room/room";  
#include "/players/saffrin/defs.h" 

reset(arg){
    set_light(1);
    short_desc = "A Wagon";
    long_desc =
         "You are in the tinker wagon.  This wagon is used as a stage for"+
         " many different types of performances.  The curtains have been"+
         " made from patches of mismatched cloth.  There are candles "+
         "burning along the walls.  You can smell incense burning all"+
         " around you.  The tinkers love to sing and would be honored "+
         "if you joined them.\n";
    dest_dir=({
         TINK+"room/path6", "out",
    });
    items=({
         "candles", "Mulicolored candles burning along the walls",
         "incense", "Long, thin incense sticks that smell nice",
         "curtain", "Patched up curtain in many colors",
    });
    clone_list=({
          1, 2, "woman", TINK+"npc/twoman", 0,
          1, 2, "man", TINK+"npc/tman", 0,
    });
    ::reset();
}

init(){

  ::init();
    AA("_sing","sing");
  return 1;
}

_sing(){

    ME("You begin to dance wildly as you sing:\n");
    ME("   Yek, dui, trin,\n");
    ME("   Yek, dui, trin,\n");
    ME("   Let my luck from here begin.\n");
    ME("   Protect and keep ME all my days\n");
    ME("   And bring true love in all the ways.\n");
    ME("   Let my heart so joyful be;\n");
    ME("   Shoon, dick, te rig dre zi.\n");
    ME("\nYou stop dancing and notice everyone is staring at you.\n");
    say(CQN+" begins to dance wildly"+
        " and sing some strange words.\n");
    say(CQN+" you stare in shock.\n");

    return 1;
}
