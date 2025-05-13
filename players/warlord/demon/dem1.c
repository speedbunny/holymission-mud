inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc=" A curious little room\n";
long_desc=" You walked into a room which has a red aura about it. As you peer\n"+
"around the room, you notice that the walls are shimmering as if very hot.\n"+
"There is a curious little desk sitting in the corner. The floor is basically\n"+
"made of dirt\n";
items-({
"desk","The desk is quite black from something apparently hot hitting it.\n"+
       "You notice a a small bottle on the desk.",
"bottle","The bottle is small in size and has a small tag on it that reads"+ 
         "open if\nyou are really brave.",
