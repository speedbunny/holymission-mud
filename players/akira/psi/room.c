inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Psionicist Guild");
long_desc=("                   /\                             \n"+
           "                  /  \                             \n"+
           "                 /    \                           \n"+
           "                /------\                          \n"+
           "               /  (0)   \                        \n"+
           "              /----------\                          \n"+
           "             /_-_-_-_-_-_-\                       \n"+
           "                                                   \n"+
           "         -= PSIONICIST GUILD =-       \n"+
           "   (Akira still needs to code the rest)          \n"+
           "                                                 \n"+
           "                                                 \n");

dest_dir=({"/players/akira/psi/hall", "north",
           "/players/akira/psi/tower", "south" });
}
