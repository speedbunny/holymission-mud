#define NAME "colossus"
#define TP this_player()
#define TPN this_player()->query_real_name()

#define CNAME   capitalize(NAME)
inherit "room/room";
int shield;

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
	/* first we need some light in here */
	set_light(1);

	/* then lets set a short description in case we are in brief-mode */
	short_desc=CNAME + "' workroom",

	/* now the long standard room description */
	/* change this to fit your style *grin* */
	long_desc=
	"This is the workroom of "+CNAME+".\n" +
	"This is where Colossus makes new thoughts and ideas come alive\n" +
	"You see pictures hanging on the wall of Colossus' best friends\n" +
	"from the X-men. There are pictures of Storm, Wolverine, Cyclops\n" +
	"Havoc, Rogue, Jubilee, Archangel, Iceman, and Beast. There's a\n" +
	"chair and a desk with a workstation at one end of the room and\n" +
	"a comfortable sofa with a coffee table in the center of the room\n" +
	"Finally, there is a picture of Mikhail, Colossus' brother set apart\n" +
	"from the rest of the pictures in the other end of the room.\n";
	"from the rest of the pictures in the other end of the room. On his\n"+
	"computer is a small list which cheers him up.\n";
	"You see pictures of fellow X-men hanging on the wall. You see pictures of Rogue, Storm, Longshot, Wolverine, Cyclops, and Havoc.\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "/players/uglymouth/skills/discussroom", "skill",
	  "/players/colossus/guild/room", "vroom",
	  "players/colossus/test/testroom","testroom",
	  "players/colossus/test/proom.c","down",
	  "players/moonchild/misc/hut","hut",
	  "players/warlord/workroom","warlord",
	  "players/galadriel/boardhall","hall",
	  "room/church", "church",
	});

	/* here could follow some item descriptions, like ...*/
	items=({ 
	  "list", "Read it pal",
	  "air","It's very thin up here",
	  "picture","Which picture?",
	  "storm","A majestic lady with brown skin and white hair",
	  "iceman","A man with skin of ice",
	  "havoc","A powerful looking man who looks to be the twin of Cyclops",
	  "beast","A powerfully-built blue skinned man who resembles a gorilla",
	  "cyclops","A man wearing a red visor over his eyes",
	  "wolverine","A man looking a lot like his namesake with claws on the back of his hand",
	  "rogue","A beautiful lady with a stripe of white running down the middle of her brown hair",
	  "mikhail","Colossus' dear brother who became insane and killed himself",
	  "jubilee","A young vibrant girl with short black hair and shades",
	  "archangel","A blue skinned man with metal wings",
	});
    }
}
init() {
    ::init();
    add_action("set_shield", "shield");
    add_action("read_list", "read");
    check();
    if(!TP->short())
	TP->vis();
}
set_shield(str) {
    if(TPN!="colossus") {return;}
    if (!str) {
	write("Shield is set to "+shield+".\n");
	return 1;
    }
    if(str=="on") {
	write("You raise the shields.\n");
	say("Colossus raises the shields.\n");
	shield=1;
	return 1;
    }
    if(str=="off") {
	write("You power down the shield.\n");
	say("Colossus powers down the shield.\n");
	shield=0;
	return 1;
    }
    write("Set shield to what?\n");
    return 1;
}
check(){
    if(shield && !(TPN=="colossus")){
	write("Colossus does not wish you to enter at this time.\n");
	say(this_player()->query_name()+" tries to enter but is kicked out.\n");
	move_object(this_player(), "/room/church");
    }
}

read_list(str){
    if(!str)
	return notify_fail("Read what?\n");
    cat("/players/colossus/list");
}
