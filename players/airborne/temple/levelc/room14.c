#define TP   this_player()
#define TPN  TP->query_name()

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc= "Dark passage";
  long_desc = "This room is just as dark as the rest of them. There is a rope\n"
	"hanging from the ceiling near the east wall.\n";
  dest_dir = ({"players/airborne/temple/levelc/room15", "north",
	"players/airborne/temple/levelc/room13", "south" });
  items = ({ "rope", "The rope appears to be a part of the ceiling" });

if(!present("malia", this_object())){
  object malia;
     	malia = clone_object("players/airborne/monsters/malia");
	move_object(malia, this_object());
			}
  if(!present("cat", this_object())){
  object cat;
	cat = clone_object("players/airborne/monsters/cat");
	move_object(cat, this_object());
			}
  if(!present("xiang", this_object())){
  object xiang;
	xiang = clone_object("players/airborne/monsters/xiang");
	move_object(xiang, this_object());
			}
}

init(){
   ::init();
	add_action("pull","pull");
	add_action("pull", "climb");
}

pull(str){
  if(!str) str=query_verb();
    switch(str){
  case "rope":
  case "on rope":
	write("You pull on the rope and fall through a trap in the floor!\n");
	write("You are falling!!\n");	
	write("Falling!!");
	write("\n");
	write("Falling!!\n");
	write("THUD!!!\n");
	say(TPN+ " falls through a hole in the floor!\n");
	this_player()->move_player("falls#players/airborne/temple/levelc/secret");
   return 1;
	notify_fail (write("Pull what"));
		}
}

