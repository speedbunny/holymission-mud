inherit "room/room";
query_no_teleport() { return 1; }
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Q";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
          items = ({
              });

    smell = " .";
}
init(){  
    ::init(); 
