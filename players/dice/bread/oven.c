inherit "room/room";
object bread;
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Oven";
    long_desc=
    "You are inside an oven. The heat is tremendous here.\n"+
    "The flames are all around you and flaming hard.\n";
          items = ({
         "oven","A large oven, usually used to make bread",
         "heat","The heat is caused by the flames",
         "flames","Fire used to heat the oven",
              });
 dest_dir = ({
    "players/dice/rooms/bak_e","out"
   });
   smell = "The smell of burned bread is strong.";
}
init(){
 ::init();
 call_out("heet",1);
}
heet(){
write("\n\nYou scream in pain as the flames hurt you !!\n");
say(this_player()->query_name()+" screams in pain as "+
this_player()->query_pronoun()+" is burned by the flames.\n");
 this_player()->hit_player(30,3);
 this_player()->show_hp();
  call_out("heet2",1);
 return ;
}
heet2(){
if((!present(this_player(),this_object())||(this_player()->query_ghost()))){
remove_call_out("heet2");
 return 1;
}
call_out("heet",1);
return;
}
