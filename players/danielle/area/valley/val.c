inherit "room/room";


void reset(int arg){
     :: reset(arg);
     if(arg) return;

set_light(1);
short_desc="Valley of Fear";
long_desc="This is the Valley of Fear.  You get an eerie feeling as you\n"+
"walk through this place.  You wish you had an escape out of\n"+
"here.\n"+
"\n";

     dest_dir = ({
     });
replace_program("room/room");
}

