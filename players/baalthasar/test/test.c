
inherit "room/room";

reset(arg){
 if (arg) return;
 set_light(1);
 short_desc="an empty room";
 long_desc="Hopefully this'll work! \n";
 dest_dir=({ "room/church","church"
	});
}
	
