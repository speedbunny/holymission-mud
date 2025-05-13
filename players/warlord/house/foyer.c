inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Foyer\n";
long_desc="This is the foyer to Skyler and Christian's home.\n"+
"The foyer is moderately decorated with an oriental rug and a \n"+
"brass chandelier overhead. The floor is made of wood.\n"+
          "To the west you see a doorway leading to a music room.\n"+
          "To the north is the kitchen. To the east is their living room.\n"+
          "There is also a staircase here leading upstairs.\n";
items=({
"chandelier","Made of brass with crystal trim",
"floor","Made of fine cedar wood",
"rug","Looks to be of oriental decent and handmade",
"doorway","This is a doorway to the music room",
"stairs","The stairs lead to the upstairs",
});
dest_dir=({
"/room/church","church",
"players/warlord/house/music_room","west",
"players/warlord/house/stairs","up",
"players/warlord/house/kitchen","north",
"players/warlord/house/living_room","east",
});
}
