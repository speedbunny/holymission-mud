/* Edited by Colossus:070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){

    if (!arg) {
	set_light(1);
	short_desc="A dimly light corridor";
	long_desc=
	"The stench of death is strong here. The source appears to be\n\
coming from the east. Two large stone gargoyles stand at either\n\
end of the corridor and the corridor itself is empty and devoid\n\
of any life.\n";
	items=({
	  "east", "To the east is the smell of death",
	  "gargoyles", "The gargoyles are hideous winged statues standing on\n\
either side of the corridor",
	  "corridor", "The corridor is a plain and very empty corridor, just too\n\
empty in fact",
	});
	dest_dir=({
	  "/players/sherman/vtower7","west",
	  "/players/sherman/vtower9","east"
	}); 
    }
}

void init(){
    object vam;

    ::init();
    if((vam=present("vampire king")) && (this_player()!=vam)) 
	call_out("run_vamp",2,vam);
}

void run_vamp(object vam){
    vam->move_player("east#players/sherman/vtower9");
    vam->set_aggressive(1);
}
