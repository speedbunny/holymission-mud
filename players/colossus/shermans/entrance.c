/* Edited by Colossus 022694 */

#pragma strict_types

inherit "room/room";

void close_door();

int open;

void reset(int arg){
    ::reset();
    if(open) {
	close_door();
	"players/sherman/tunnel1"->close_door();
    }
    if(arg) return;
    set_light(1);
    short_desc = "At a small hill that's unnaturally quiet";
    long_desc=
    "You are at the base of a small hill. Trees and bushes grow\n"+
    "up along the base of the hill. While the whole scene is very\n"+
    "beautiful you are unnerved at the lack of sounds. It's as though\n"+
    "there is absolutely no living creature here. Perhaps there is\n"+
    "something dark and sinister being covered up by this seemingly\n"+
    "peaceful facade.\n";
    items = ({
      "hill", "The hill is little more than a small rise that is\n"+
      "covered with trees and bushes that grow up from the\n"+
      "base of the hill",
      "trees", "The trees are mostly beech trees that grow on and\n"+
      "around the hill",
      "bushes", "The whole hill is covered with those bushes and\n"+
      "just as you are about to ignore them one catches\n"+
      "your eye as its shade is of a darker green, so dark\n"+
      "that it is almost black in color",
      "dark bush", "This bush is so dark that it is almost black and it\n"+
      "grows at the top of the hill. Perhaps this is a key\n"+
      "to discovering what is hidden in this area",
    });
}

void init(){
    ::init();
    add_action("west","west");
    add_action("search","search");
    add_action("down","down");
    add_action("open","open");
    add_action("close","close");
}

status open(string arg){
    if(arg!="trapdoor") return 0;
    if(open) write("It is already open.\n");
    else {
	write("You open the trapdoor\n");
	say((string)this_player()->query_name()+
	  " moves something inside the bushes.\n");
	"players/sherman/tunnel1"->open_door();
	open=1;
    }
    return 1;
}

status close(string arg){
    if(arg!="trapdoor") return 0;
    if(!open) write("It is already close.\n");
    else {
	write("You close the trapdoor\n");
	say(this_player()->query_name()+
	  " moves something inside the bushes.\n");
	"players/sherman/tunnel1"->close_door();
	open=0;
    }
    return 1;
}

void close_door(){
    open=0;
    tell_room(this_object(),"Something moves behind the bushes.\n");
}

void open_door(){
    open=1;
    tell_room(this_object(),"Something moves behind the bushes.\n");
}

status west(){
    write("You strangle through the bushes.\n");
    /* Cashimor, 5-2-1993, I moved your castle a little southward, to make
       the clash with Padrone's castle a little less... The church was
       lying right next to the peaceful pool... */
    this_player()->move_player("through the bushes#room/south/sforst16");
    return 1;
}

status search(string arg){
    if(arg=="dark bush") {
	write("You notice a trapdoor hidden in the bush.\n");
	return 1;
    }
}

status down(){
    if(!open) return 0;
    this_player()->move_player("disappears into the bushes#"+
      "players/sherman/tunnel1");
    return 1;
}

status query_open(){ return open; }
