#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";
object soul, knight;
int coins, hpcount;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Colossus Knights of the Round Table Shop";
    long_desc =
    "This is a musty shop run by an old man wearing a funny hat and wearing\n"+
    "spectacles. He squints at you then shows you the list of his services.\n"+
    "\n\n"+
    "	Welcome to my humble store. I rent knights that will help you\n"+
    "	in all that you do. They are faithful companions and will be\n"+
    "	with you to the end. How comknightent these knights are will\n"+
    "	depend on how much you're willing to pay for their services.\n"+
    "	We do live in a market economy after all you know? Anyway, if\n"+
    "	you wish to purchase their services the syntax for buying the\n"+
    "	knights is spend <amount> where amount is the amount of money\n"+
    "	you wish to spend on them.\n"+
    "	If you would like a set of instructions to go along for commanding\n"+
    "	your knight, simply 'request manual'.\n";

    dest_dir = ({
      "/players/colossus/mearth/tree1", "south",
    });
}


init(){
    ::init();
    add_action("spend", "spend");
    add_action("request", "request");
}

spend(str){
    if(!str) return 0;
    if(sscanf(str, "%d", coins)==1){
	if(coins<2000 || coins>12000){
	    write("Knights are priced between 2000 and 12000 coins.\n");
	    return 1;
	}
	if(TP->query_money()<coins){
	    write("You don't have that many coins.\n");
	    return 1;
	}
	if(present("knight soul", this_player())){
	    write("You already own a knight. Maximum is one knight per customer.\n");
	    return 1;
	}
	hpcount=coins/1000;
	this_player()->add_money(-coins);
	knight=clone_object("/players/colossus/knights/knight");
	soul=clone_object("/players/colossus/knights/knight_soul");
	knight->patch_owner(this_player()->query_real_name());
	knight->set_level(hpcount);
	knight->set_ac(hpcount/3);
	if(hpcount<6) knight->set_ac(2);
	if(hpcount<3) knight->set_wc(6);
	knight->set_hp(20*hpcount);
	move_object(knight, this_object());
	move_object(soul, this_player());
	write("Your noble knight enters in a grand flourish.\n");
	say(TPN+"'s knight enters and bows before you.\n");
	write_file("/players/colossus/data/knight", this_player()->query_real_name()+" for "+coins+" on "+ctime(time())+"\n");
	return 1;
    }
}
request(str){
    if(str!="manual") return 0;
    if(present("manual", this_player())) {
	write("You've already got a manual.\n");
	return 1;
    }
    write("Colossus appears before you and hands you a manual.\n");
    move_object(clone_object("/players/colossus/knights/manual"), this_player());
    return 1;
}
