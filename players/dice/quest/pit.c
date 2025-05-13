inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Pit";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
       "You are falling down back to earth.\n";
          items = ({
              });

   smell = "You smell nothing special.";
}
