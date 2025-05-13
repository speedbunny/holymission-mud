inherit "room/room";
reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "Borscht's workroom";
    long_desc = 
"  Borscht's workroom. It is a small kitchen.  There are vegetables,\n"+
"  files, and test-weapons on the counter.  There is a large covered\n"+
"  pot on the stove.  The room has an aromatic, garlicky, computery\n"+
"  smell.  You wonder if you dare to lift the lid.....\n"+
"  \n";
dest_dir=({
  });
items=({
"vegetables",
"chopped up carrots, beets, potatoes, and cabbage",
"pot",
"a stainless-steel pot borrowed long ago and never returned",
"counter",
"a white counter with pieces of computer files and vegetables laying around",
});
  }
void init(){
  ::init();
add_action("get","get");
  }
get(string arg){
if (arg!="carrot"){
write("Keep your hands off that...\n");
return 0;
}
if (arg=="carrot"){
write("You reach into the pot and pull out a chunk of carrot.\n");
this_player()->hit_player(10);
veg=clone_object("/players/borscht/carrot");
move_object(veg,this_player());
return 1;
}
}