inherit "room/room";
reset(tick){
if (tick) return;
set_light(1);

short_desc= ("In a Grand Hall.\n");
long_desc= ("This hall is huge. The ceiling seems to reach up forever.\n"+
            "There are huge pillars made of stone holding it up. The\n"+
            "floor is blood red and shines as if just cleaned. Passages\n"+
            "lead off in just about every direction.\n");
items=({"hall", "The grand hall of the temple",
        "pillars", "They are as black as night.",
        "floor", "It is blood red and very clean",
        "passages", "They lead in many directions",
        "ceiling", "It reaches up very high." });
dest_dir= ({"/players/akira/area/h_hall", "north",
            "/players/akira/area/hall1", "south",
            "/players/akira/area/hall3", "east",
            "/players/akira/area/hall2", "west" });
property=({"no_teleport"});
}
