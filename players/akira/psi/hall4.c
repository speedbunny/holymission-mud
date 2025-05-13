inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc="In a Large Hall";
long_desc=("This hall is huge. On both sides of it you can see\n"+
           "Psionicist's training there skills. Just to the north\n"+
           "of you is a very large set of stairs. Huge pillars stand\n"+
           "all around you. Who ever built this place must have wanted\n"+
           "you to feel small while you were in the tower.\n");
dest_dir=({"/players/akira/psi/stairs", "north",
           "/players/akira/psi/hall", "south",
           "/players/akira/psi/train3", "east",
           "/players/akira/psi/train1", "west",
           "/players/akira/psi/train2", "northwest" });
}
