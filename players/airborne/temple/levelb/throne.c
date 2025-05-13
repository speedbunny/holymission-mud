#define TP   this_player()
#define TPN  TP->query_name()

inherit "room/room";
int i;

reset(arg){
  set_light(1);
  short_desc= "Throne Room";
  long_desc =

"This room looks like it was once the throne room for a king. "
"Light emanates from the walls, giving this room a strange glow. "
"Near the north wall is a throne. The north wall is hidden by a "
"long black curtain.\n";

  dest_dir = ({"/players/airborne/temple/levelb/room10", "south"});
  items = ({ "throne", "A golden throne fit for a king",
	"curtains", "Long black curtains that look like they might be hiding something",
	"curtain", "Long black curtains that look like they might be hiding something",
	"walls", "You cannot see how, but the walls are glowing" });
	}

init(){
   ::init();
	add_action("sit","sit");
	add_action("move","move");
	i = 0;
	}

move(str){
   if(!str) str=query_verb();
   switch(str){
	case "curtains": 
	case "north":
	case "curtain":
		write("You brush aside the curtains and go north.\n");
		say(TPN+ " walks behind the curtains.\n");
	this_player()->move_player("leaves north#players/airborne/temple/levelb/hidden");
   return 1;
	default : return::move(str);
   }
}

sit(str){
  switch(str){
object sc;
	case "throne":
	case "on throne":  
	if(present("crown", this_player())){
		write("You feel like a king.\n");
		say(TPN+ " sits on the throne like royalty!\n");
  if (!sc) {
   if (i<1) {
	sc=clone_object("obj/treasure");
	sc->set_id("quest_scepter");
	sc->set_alias("scepter");
	sc->set_short("King's scepter");
	sc->set_long("A beautiful jewel encrusted scepter.\n");
	sc->set_value(2000);
	sc->set_weight(2);
	move_object(sc, this_object());
		write("A scepter mysteriously appears!\n");
		say("A beautiful scepter appears!\n");
      i=i+1;
   return 1 ;
 }
		return 1;
	}
	 else {
		write("You feel as though you aren't worthy\n");
		say("You feel as though" +TPN+ "weren't worthy to shine your boots.");
	return 1;
        }
return 1;
}
   default:
	write("What's your problem?\n");
	return 1;
 }
}
