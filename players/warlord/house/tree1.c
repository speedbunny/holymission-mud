#define TP this_player()
#define TPN TP->query_name()
inherit"players/warlord/NEWSTUFF/room";
int i,j,k,l;
reset(arg) {
i=0;j=0;k=0;l=0;
    if (arg) return;
     set_light(1);
short_desc="Side of house.\n";
long_desc=
"You are on the west side of the house. You can see a tree here\n"+
"that goes up the side of the house. To the south you can see\n"+
"Skyler's flower garden.\n";
items = ({
         "flowers","The flowers are beautiful and smell nice. Pick one!\n"
                              +"There are red and white roses, carnations and orchids",
         "roses","The roses are long and beautiful",
         "red roses","The red roses are have long stems and are swaying in the breeze",
         "white roses","The white roses are long and beautiful looking",
         "carnations","The carnations are pink and lond stemmed",
         "orchids","The orchids are long and beautiful",
         "tree","You see a big tree with wooden wrungs. Maybe you can climb it",
        });
dest_dir=({
"players/warlord/house/tree2","up",
"players/warlord/house/back1","north",
         });
    }
init() {
add_action("pick","pick");
  ::init();
}
pick (arg) {
object ro1,ro2,orc,car,sword;
if (arg=="flowers") {
write("Which flower? Look at them and choose.\n");
return 1;
}
switch (arg) {
case "red rose":
if (i<12) {
ro1=clone_object("obj/treasure");
ro1->set_id("rose");
ro1->set_short("Red rose");
ro1->set_long("A long stem red rose.\n");
ro1->set_value(10);
ro1->set_weight(0);
move_object(ro1,(TP));
write("You have picked a red rose.\n");
say(TPN+" has picked a red rose.\n");
i=i+1;
}
else {
write("You have picked the red roses clean!\n");
say(TPN+" has picked the red roses clean!\n");
}
break;
return 1;
case "orchid":
case "orchids":
 if (k<12) {
orc=clone_object("obj/treasure");
orc->set_id("orchid");
orc->set_short("Orchid");
orc->set_long("A beautiful multicolorful orchid.\n");
orc->set_value(0);
orc->set_weight(0);
move_object(orc,(TP));
write("You have picked an orchid.\n");
say(TPN+" has picked an orchid.\n");
k=k+1;
}
else {
write("You have cleaned out all the orchids.\n");
say(TPN+ " has cleaned out all the orchids.\n");
}

break;
return 1;
case "carnation":
case "carnations":
if (l<12) {
car=clone_object("obj/treasure");
car->set_id("carnation");
car->set_short("Carnation");
car->set_long("This is a long stemmed carnation.\n");
car->set_value(0);
car->set_weight(0);
move_object(car,(TP));
write("You picked a beautiful carnation.\n");
say(TPN+" has picked a carnation.\n");
l=l+1;
}
else {
write("You cleaned out all the carnations.\n");
say (TPN+ " has cleaned out all the carnations.\n");
}
break;
return 1;
case "white rose":
if (j<12) {
ro2=clone_object("obj/treasure");
ro2->set_id("white rose");
ro2->set_short("White rose");
ro2->set_long("This is a beautiful white rose.\n");
ro2->set_value(0);
ro2->set_weight(0);
move_object(ro2,(TP));
write("You pick a white rose.\n");
say(TPN+" pickes a white rose.\n");
j=j+1;
}
else {
write("You have cleaned the black roses out\n");
say(TPN+" has cleaned out all the black roses\n");
}
break;
default:
write("There are none of those here.\n");
return 1;
}
return 1;
}

