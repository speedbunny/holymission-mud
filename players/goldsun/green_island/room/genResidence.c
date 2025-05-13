inherit "/room/room";

reset(arg){
if (!arg){
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
 }
 ::reset(arg);
}


