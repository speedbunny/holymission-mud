inherit "obj/monster";
int count;
reset (arg) {
::reset (arg);
count=0;

set_name("Trolloc");
set_alias("trolloc");
set_long("It stands almost 8 feet tall and is almost as wide as\n"+
         "two people. For the most part it is covered in a thick\n"+
         "hair that looks and smells as if it has not ever been washed.\n"+
         "It has the face of a wolf with the teeth of a lion. Its eyes\n"+
         "burn with a hate for all that live!\n");
set_level(20);
set_al(-1000);
set_whimpy(20);
set_number_of_arms(2);
set_ac(10);
set_wc(10);
set_aggressive(1);
}
heart_beat(){
if(++count>4) {
random_move();
count= 0;
}
::heart_beat();
}
