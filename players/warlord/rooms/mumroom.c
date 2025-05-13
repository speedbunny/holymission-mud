 

inherit "players/warlord/NEWSTUFF/room";
object o1,o2,o3;
int i;

reset(arg) {
 i=0;
 if (!o1){ 
   o1=clone_object("players/warlord/monsters/mummy");
   move_object(o1,this_object());
  }
 if (!o2){
   o2=clone_object("players/warlord/monsters/mummy");
   move_object(o2,this_object());
 }
 if (!o3){
   o3=clone_object("players/warlord/monsters/mummy");
   move_object(o3,this_object());
 }
  
 if (arg) return;
    set_light(1);
    short_desc = "Mummy room";
    long_desc = 
     "This room is filled with some small ugly mummies.. Why are they here?\n"+
     "This room is richly decorated with paintings and tapestries\n";
    items=({
      "paintings",
      "All the pictures are of ancient Egypt. They look searchable",
      "tapestries",
      "The tapestries are fine quality wool from Egypt",
    });
    dest_dir=({
"players/warlord/pyramid/p8","south",
        });
}
init() {
::init();
  add_action("search","search");
}

search(str) {
 if ((str=="painting") ||(str=="the painting")){
 object book;
 if (i<1) {
   write("You find a secret compartment with a book in it.\n");
   book=clone_object("obj/treasure");
   book->set_id("old book");
   book->set_short("Old book");
   book->set_alias("book");
   book->set_long("This book is from ancient Egypt.\n");
   book->set_value(100);
   book->set_weight(2);
   transfer(book,this_object());
   i=i+1;
   return 1;
 }
 }
 else {
   write("You find nothing of interest.\n");
   return 1;
 }
}
