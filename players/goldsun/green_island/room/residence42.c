inherit "room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
  clone_list=
    ({1,1,"altar","/players/goldsun/white_tower/obj/altar",0});

 set_light(1);
 short_desc=("Residence of evil cyclops");
 long_desc=
    "You are inside of residence of evil Syracusos. It looks very nice.\n"+
    "Marble floor is shiny. High walls are made of light gray marble too.\n"+
    "There are pictures about greatest moments of cyclops' kingdom on them.\n"+
    "Tall columns are decorated too. Over this whole beauty is a large stony\n"+
    "vault.\n";

 smell="You smell rotten air.";

 items=({"castle",long_desc,
         "residence",long_desc,
         "walls","Walls of gray stone with history of cyclops' kingdom"
         });

 dest_dir=({ PATH + "residence39", "down"});

 }

 ::reset(arg);
 replace_program("/room/room");
}



