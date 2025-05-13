#define NAME "trout"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#include "/players/trout/define.h"
#define RN TP->query_real_name()
int shield;
string who;

int i;
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
	short_desc= "Trout's Aquarium Workroom";

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
	"You are standing in a large aquarium. It is filled with "+
	"water, but you can somehow breath! Large rocks and kelp "+
	"litter the floor. In the corner is a old diving suit, with "+
	"a tube running to the top of the tank!\n";
      

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
	     "diving suit", "Looks like it pumps oxygen into the tank"
		});
        /* Properties can be set like the following */
        property = ({
		      "no_sneak", "no_steal",
		    "no_invisible", "no_assassination", "no_camouflage",
                    });
        /* Smell is set like this... */
	smell = "It smells fishy!";
    }
}

init()
{
  ::init();
 AA("set_shield", "shield");
  AA("expel", "expel");
  AA("join", "join");
  AA("drain", "drain");
AA("_nuke", "nuke");
AA("_hunt", "hunt");
  check();
  }

join(){
  if(RN!="trout" && RN!="krack"){ return;}
  else{
	    move_object(clone_object("/players/trout/psi/soul/soul"), TP);
		write("You join the psi guild.\n");
		return 1;
	  }
	}
set_shield(str) {
if((RN !="akira") && (RN !="trout") && (RN !="exos")) return;
  if(!str) {
    write("Defense field is currently " + shield +".\n");
    return;
 }

if(str == "on") {
write("You power up the point deflector system, blocking everyone "+
	"from this room!\n");
say ("Trout activates a deflector shield around this room!\n");
  shield=1;
   return 1;
}

if(str == "off") {
write("You power down the point deflector system\n");
say("Trout lowers the point deflector system.\n");
   shield=0;
   return 1;
}
}

check() {
if(shield && (RN !="akira") && (RN !="exos") && (RN !="trout")){
write("Trout has raised his deflector system. You cannot enter!\n");
say(TPN+" tried to enter Trout's Aquarium, but was blocked!\n");
MO(TP, "/players/gareth/think");
  }
  return 1;
}

expel(arg) {
  object player;
if((RN !="akira") && (RN !="exos") && (RN !="trout"))
return;
if(!arg) {
    write("Who do you want to expel?\n");
   return 1;
    }
 player = present (arg, TO);
  if(!player) {
 write("That person is not here.\n");
    return 1;
  }
  write("You kick " + TPN + " out of your room.\n");
  player->move_player ("to the church#/room/church");
 tell_room(TO, TPN + "got transported else where.\n");
 return 1;
  }
int _nuke(string arg){
object env, *ob;
int i, j;
	if(!arg){ write("Nuke who?\n"); return 1;}
	if(arg== "trout"){ 
		write("Like Trout would let you nuke him in his own "+
		"workroom!\n");
		this_player()->hit_player(1000);
 say(capitalize(this_player()->query_real_name())+" tried to nuke Trout"+
	" and was punished!\n");
		return 1;
	}
	else{
  object who;
	who= find_living(arg);
        if(who->query_immortal()){
                write("Why nuke a wiz, its no fun!\n");
		return 1;
		}
	who->hit_player(10000);
	write("You destroy "+arg+" with a tactical nuke!\n"+
		"      xxxx\n"+
		"    xxxxxxxx\n"+
		"   xxxxxxxxxx\n"+
		"      xxxx\n"+
		"       xx\n"+
		"       xx \n"+
		"       xx \n"+
		"xxxxxxxxxxxxxxxxxx\n"+
		"BOOOOOOOOOOOOOOOOM\n"+
		"xxxxxxxxxxxxxxxxxx\n"); 
	tell_object(who, "You just got nuked!!\n"+
		"    xxxx\n"+
		"  xxxxxxxx\n"+
		"xxxxxxxxxxxx\n"+
		"    xxxx \n"+
		"     xx\n"+
		"     xx\n"+
		"     xx\n"+
		"xxxxxxxxxxxxx\n"+
		"BOOOOOOOOOOM!\n"+
		"xxxxxxxxxxxxx\n"+
		"\n");
	return 1;
	}

}
int _hunt(string arg){
    object who, where;
   string victim;
	if(!arg){
		write("Useage: hunt down <victim> \n");
		return 1;
		}
	sscanf(arg, "down %s", victim);
	if(!victim){
		write("Hunt down who?\n");
		return 1;
		}
	who= find_living(victim);
	if(!who){
		write("You can't find "+capitalize(victim)+"!\n");
		return 1;
		}
	where= environment(who);
	MO(CO("/players/trout/mobs/raider"), where);
	write("You send a temporal raider after "+capitalize(victim)+"!\n");
	tell_room(where, "A rift appears, and a temporal raider jumps out "+
	"and attacks you!\n");
	return 1;
	}
