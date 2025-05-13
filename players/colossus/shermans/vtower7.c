/* Edited by Colossus:070994 */

#pragma strict_types

inherit "room/room";

object vamp_king;

status query_equip(object pl);
void kill_unvamp(object pl);

void reset(int arg){
    int i;
    object *vamps;

    if (!present("vampire guest")) {
	for (i=0;i<6;i++)
	    move_object(clone_object("/players/sherman/vampire7"),this_object());
    } else {
	vamps=all_inventory(this_object());
	for(i=0;i<sizeof(vamps);i++) {
	    if(vamps[i]->id("vampire guest"))
		vamps[i]->stop_hunter(1);
	}
    }
    if(!vamp_king) 
	move_object(vamp_king=clone_object("players/sherman/vampire4"),
	  this_object());

    if (!arg) {
	set_light(1);
	short_desc="The vampire party";
	long_desc=
	"This happens to be a ballroom of some sort. The room is brightly by\n\
candles and tapestries line the walls. Works of art are present around\n\
the room and music from an unseen source echoes throughout. A large\n\
banquet table is set in the middle of the room and a punch bowl sits\n\
squarely in the middle. The curious thing about the punch bowl is that\n\
it is the only item of food present and that it holds a thick red liquid\n\
that strongly resembles blood.\n";
	items=({
	  "table", "The table is made of solid oak",
	  "candles", "The candles around the room light up the room nicely",
	  "tapestries", "Tapestries of myriad designs hang on the walls",
	  "art", "Artwork of extreme value are displayed throughout the room",
	  "bowl", "The bowl is set squarely in the middle of a large table containing\n"+
	  "a thick red liquid you can only guess to be blood",
	});
	dest_dir=({
	  "/players/sherman/vtower6","south",
	  "/players/sherman/vtower8","east"
	});
    }
}

void init(){
    ::init();
    if((int)this_player()->query_npc()) return;
    if(present("vampire king",this_object()))
	call_out("run_king",1);
    if(present("vampire guest")) {
	if(!this_player()->query_npc() && 
	  !query_equip(this_player())) {
	    call_out("kill_unvamp",2,this_player());
	    add_action("east","east");
	} 
    }
}

void run_king(){
    vamp_king->move_player("east#players/sherman/vtower8");
}

status east(){
    if(!present("vampire guest")) {
	this_player()->move_player("east#players/sherman/vtower8");
    } else {
	write("Don't be silly, you can't force your way through the vampires.\n");
	kill_unvamp(this_player());
    }
    return 1;
}

void kill_unvamp(object pl){
    object *va;
    int i;

    va=all_inventory(environment(pl));
    for(i=0;i<sizeof(va);i++) {
	if(va[i]->id("vampire guest")) {
	    va[i]->attack_object(pl);
	}
    }
}

status query_equip(object pl){
    object *eq;
    int i;
    int th,ca;

    th=ca=0;
    eq=all_inventory(pl);
    for(i=0;i<sizeof(eq);i++) {
	if(eq[i]->query_wielded()) th=(int)eq[i]->query_teeth();
	if(eq[i]->query_worn() && eq[i]->query_cape()) ca=1;
    }
    return (th && ca);
}
