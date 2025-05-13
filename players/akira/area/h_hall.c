inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Hall of Heroes.\n");
long_desc=("This huge Hall is the Great Hall of Heroes. Large pillars\n"+
           "shoot from the floor to the ceiling. Along the walls stand\n"+
           "statues of long forgotten heroes of the Summoner Wars. Behind\n"+
           "the statues are gold runes that cover the walls themselves.\n"+
           "The floor is also a gold color that seems to shine like the\n"+
           "sun.\n");
items=({"hall", "This is the Hall of Heroes",
       "statues", "They are of long forgotten heroes",
       "pillars", "They are gold colored and hold up the ceiling",
       "walls", "They are covered with magic runes", 
       "runes", "They are some type of magic rune"
       "floor", "It shines like the sun." });
dest_dir=({"/players/akira/area/h_hall1", "north",
           "/players/akira/area/g_hall", "south" });
property=({"no_teleport"});
}
