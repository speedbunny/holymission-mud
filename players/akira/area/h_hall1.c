inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Hall of Heroes.\n");
long_desc=("This part of the Hall of Heroes looks like a large banquet\n"+
           "hall. Long tables line the room. The walls are coverd with\n"+
           "with huge tapestries that honor all the guilds that fought\n"+
           "in the Wars. Along the top of the walls are runes writen in\n"+
           "gold. The floor is the same gold color and is very shinny.\n");
items=({"hall", "This is the Hall of Heroes",
        "walls", "They have magic runes on them",
        "tables", "They are very long and cover the whole room",
        "tapestries", "There is one for every guild from the Mage guild "+
                     "to the Psi Guild.",
        "floor", "It is a very bright gold color",
        "runes", "They cover the walls" });
dest_dir=({"/players/akira/area/shrine", "north",
           "/players/akira/area/h_hall", "south" });
property=({"no_teleport"});
}
