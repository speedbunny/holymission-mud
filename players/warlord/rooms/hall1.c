inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A hallway\n";
long_desc="This is a very narrow passage way. The floor is covered in blood\n"+
          "and bones.\n";
items=({
"bones","You see a lot of bones laying around and they are all picked clean",
"blood","The blood looks fairly recent",
      });
dest_dir=({
"players/warlord/rooms/hounroom","north",
"players/warlord/rooms/ghouroom","south",
         });
}
