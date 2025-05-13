inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a valley";
  long_desc="You're in a valley in the mountains.\n"+
   "To the east the valley get closer.\n"+
   "To the west lies a small plain area.\n";

  dest_dir=({
	"players/bobo/krooms/mountains/valley4n","north",
	"players/bobo/krooms/mountains/valley3s","east",
	"players/bobo/krooms/mountains/plain2","northwest",
	"players/bobo/krooms/mountains/plain3","southwest",
   });
  
   items=({
     "area","It's a small and grassy plain, some clouds are hanging in the sky",
   });
 
}
 
